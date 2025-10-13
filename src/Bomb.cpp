/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include "PlayState.hpp"
#include "Wall.hpp"
#include "Core.hpp"
#include "Player.hpp"
#include "Bonus.hpp"

Bomb::Bomb(blb::Vector3f<float> const &position, float factor)
{
    this->setPosition(position);
    this->_bomb_model.ModelFromModel(blb::Core::FindModel("bomb"));
    this->_factor = factor;
    this->_range = factor;
}

Bomb::~Bomb()
{
}

void Bomb::bonusPosition(std::vector<blb::Vector3f<float>> &positions, int factor)
{
    if (this->_factor != 2)
        return;
    positions.push_back(blb::Vector3f<float>(
        this->_position.x + (WORLD_TILE_SIZE_X * factor),
        this->_position.y,
        this->_position.z)
    );
    positions.push_back(blb::Vector3f<float>(
        this->_position.x -( WORLD_TILE_SIZE_X * factor),
        this->_position.y,
        this->_position.z)
    );
    positions.push_back(blb::Vector3f<float>(
        this->_position.x,
        this->_position.y,
        this->_position.z + (WORLD_TILE_SIZE_Z * factor))
    );
    positions.push_back(blb::Vector3f<float>(
        this->_position.x,
        this->_position.y,
        this->_position.z - (WORLD_TILE_SIZE_Z * factor))
    );
}

void Bomb::basicPosition(std::vector<blb::Vector3f<float>> &positions)
{
    positions.push_back(blb::Vector3f<float>(
        this->_position.x + WORLD_TILE_SIZE_X,
        this->_position.y,
        this->_position.z)
    );
    positions.push_back(blb::Vector3f<float>(
        this->_position.x - WORLD_TILE_SIZE_X,
        this->_position.y,
        this->_position.z)
    );
    positions.push_back(blb::Vector3f<float>(
        this->_position.x,
        this->_position.y,
        this->_position.z + WORLD_TILE_SIZE_Z)
    );
    positions.push_back(blb::Vector3f<float>(
        this->_position.x,
        this->_position.y ,
        this->_position.z - WORLD_TILE_SIZE_Z)
    );
}

void Bomb::getGrieffedEntity(std::shared_ptr<blb::Entity> const &entity)
{
    WallGrief *wall = dynamic_cast<WallGrief *>(entity.get());

    if (wall != nullptr) {
        if (this->positions.empty()) {
            this->basicPosition(this->positions);
            this->bonusPosition(this->positions, this->_factor);
        }
        for (auto &it : positions) {
            if (wall->coordContain(it)) {
                wall->setColor(RED);
                this->destroyableWall.push_back(wall);
                return;
            }
        }
    }
}

void Bomb::destroyWall(WallGrief *it)
{
    if (it == nullptr)
        return;
    for (auto &vir : blb::Core::getEntities()) {
        if (it == vir.get()) {
            if (vir != nullptr) {
                vir.reset();
                if (std::rand() % 4 == 0)
                    blb::Core::addEntities(new Bonus(it->getPositionV3()));
                blb::Core::removeEntities(it);
            }
        }
    }
}

bool Bomb::inRange(blb::Vector3f<float> const &pPos, blb::Vector3f<float> const &pSize)
{
    blb::Vector3f<float> check = blb::Vector3f<float>(0, 0, 0);
    check.x = pPos.x > _position.x ? (pPos.x - (pSize.x / 2)) - this->_position.x: (pPos.x + (pSize.x / 2)) - this->_position.x;
    check.z = pPos.z > _position.z ? (pPos.z - (pSize.z / 2)) - this->_position.z: (pPos.z + (pSize.z / 2)) - this->_position.z;
    float x = round(std::abs(check.x) / WORLD_TILE_SIZE_X);
    float z = round(std::abs(check.z) / WORLD_TILE_SIZE_Z);

    if (x > _range || z > _range)
        return false;
    if (x >= 1 && z >= 1)
        return false;
    if (x >= 0.0 && x <= _range || z >= 0.0 && z <= _range)
        return true;
    return false;
}

void Bomb::killPlayer()
{
    for (auto &it : blb::Core::getEntities()) {
        Player *player = dynamic_cast<Player *>(it.get());

        if (player == nullptr)
            continue;
        if (this->inRange(player->getPositionV3(), player->getSizeV3())) {
            it.reset();
            blb::Core::removeEntities(player);
        }
    }
}

void Bomb::update()
{
    if (this->destroyableWall.empty()) {
        for (auto &it : blb::Core::getEntities()) {
            if (it != nullptr)
                this->getGrieffedEntity(it);
        }
    }
    _deltaTime += blb::Core::GetTimeFrame();
    if (_deltaTime > 3) {
        _explose = true;
        this->killPlayer();
        for (auto &it : this->destroyableWall)
            this->destroyWall(it);
        blb::Core::removeEntities(this);
    }
}

void Bomb::draw()
{
    this->_bomb_model.ModelDraw(this->_bomb_model._model, this->_position, 2, WHITE);
}

bool Bomb::getExplose(void)
{
    return _explose;
}

void Bomb::unload()
{
    this->_bomb_model.ModelUnload(this->_bomb_model._model);
    UnloadTexture(this->_bomb_model._texture);
    blb::Core::removeEntities(this);
}
