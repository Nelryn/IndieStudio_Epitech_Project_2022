/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** Bonus
*/

#include "Bonus.hpp"
#include <cstdlib>
#include "type/Colors.hpp"
#include "Player.hpp"
#include "BonusCollider.hpp"

Bonus::Bonus(blb::Vector3f<float> position)
{
    this->type = (bonus_type)(std::rand() % 4);
    if (this->type == 0)
        this->type = BOMB;
    this ->_position = position;
    this->setSize({2, 2, 2});
    this->addComponent(new BonusCollider(std::shared_ptr<blb::Entity>(this)));
    this->redBomb.ModelFromModel(blb::Core::FindModel("red_bomb"));
    this->bombax.ModelFromModel(blb::Core::FindModel("bomb"));
    this->lightning.ModelFromModel(blb::Core::FindModel("lightning"));
    this->lightning.TransformXYZ({1.5, 0, 0});
}

Bonus::~Bonus()
{

}

void Bonus::giveBonus(std::shared_ptr<blb::IEntity> &ent)
{
    Player *player = dynamic_cast<Player *>(ent.get());

    if (player != nullptr) {
        switch (this->type)
        {
        case FIRE:
            player->addfire();
            break;
        case SPEED:
            player->addSpeed();
            break;
        case BOMB:
            player->addBomb();
            break;
        default:
            break;
        }
        blb::Core::removeEntities(this);
    }

}


void Bonus::update()
{
    for (auto &it : this->_components) {
        it->update();
    }
}

void Bonus::draw()
{
    switch (this->type)
    {
    case FIRE:
        this->redBomb.ModelDraw(this->redBomb._model, this->_position, 2, RED);
        break;
    case SPEED:
        this->lightning.ModelDraw(this->lightning._model, this->_position, 2, YELLOW);
        break;
    case BOMB:
        this->bombax.ModelDraw(this->bombax._model, this->_position, 1, YELLOW);
        break;
    default:
        break;
    }
}

void Bonus::unload()
{
    this->bombax.ModelUnload(this->bombax._model);
    UnloadTexture(this->bombax._texture);
    blb::Core::removeEntities(this);
}
