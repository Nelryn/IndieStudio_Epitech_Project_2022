/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** BonusCollider
*/

#include "BonusCollider.hpp"
#include "Player.hpp"
#include "Bonus.hpp"

BonusCollider::BonusCollider(std::shared_ptr<blb::Entity> const &entity)
{
    this->_name = "BonusCollider";
    this->cube_ = blb::Cube();
    this->_entity = entity;
}

BonusCollider::~BonusCollider()
{

}

void BonusCollider::collisionHandlement(std::shared_ptr<blb::IEntity> it)
{
    if (this->isColliding(this->_entity, it)) {
        Bonus *bonus = dynamic_cast<Bonus *>(this->_entity.get());
        if (bonus != nullptr) {
            bonus->giveBonus(it);
        } 
    }
}

bool BonusCollider::isColliding(std::shared_ptr<blb::IEntity> const &entity1,
    std::shared_ptr<blb::IEntity> const &entity2)
{
    return (
        (((entity1->getX()) <= (entity2->getX() + entity2->getSizeX())) && (((entity1->getX()) + entity1->getSizeX()) >= entity2->getX())) &&
        (((entity1->getY()) <= (entity2->getY() + entity2->getSizeY())) && (((entity1->getY()) + entity1->getSizeY()) >= entity2->getY())) &&
        (((entity1->getZ()) <= (entity2->getZ() + entity2->getSizeZ())) && (((entity1->getZ()) + entity1->getSizeZ()) >= entity2->getZ()))
    );
}


void BonusCollider::update(void)
{
    this->entities_ = blb::Core::getEntities();

    for (auto &it : this->entities_) {
        if (this->_entity != it) {
            Player *player = dynamic_cast<Player *>(it.get());
            if (player != nullptr) {
                this->collisionHandlement(it);
            }
        }
    }

}
