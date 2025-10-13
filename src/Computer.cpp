/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** Computer
*/

#include "Computer.hpp"
#include "PlayState.hpp"
#include "Collider.hpp"
#include <time.h>

Computer::Computer(std::vector<std::string> const &map,
                    blb::Vector3f<float> const &position,
                    blb::Vector3f<float> const &size,
                    int id,
                    std::string const &texturePath)
{
    (void)id;
    this->_map = map;
    setPosition(position);
    setSize(size);
    this->_model.ModelLoad("./resources/girl_armature_.iqm");
    this->_model._texture = LoadTexture(texturePath.c_str());
    this->_model.MaterialTextureSet(&this->_model._model.materials[0], MATERIAL_MAP_DIFFUSE, this->_model._texture);
    this->addComponent(new blb::Collider(std::shared_ptr<Player>(this)));
}

Computer *Computer::setTexture(std::string const &texture)
{
    this->_model._texture = LoadTexture(texture.c_str());

    return this;
}

Computer *Computer::setMap(std::vector<std::string> const &map)
{
    _map = map;
    return this;
}

void Computer::update()
{
    int r = rand() % 4;
    int x = this->_position.x / WORLD_TILE_SIZE_X;
    int z = this->_position.z / WORLD_TILE_SIZE_Z;
    int width = _map.size();
    int height = _map[0].size();
    float deltaTime = blb::Core::GetTimeFrame();
    this->_position += this->_velocity;

    if (goTo.x != 0) {
        if (_savePos.x >= goTo.x) {
            if (_position.x <= goTo.x) {
                _velocity = {0, 0, 0};
                goTo = {0, 0, 0};
                _savePos = {0, 0, 0};
            }
        }
        if (_savePos.x <= goTo.x) {
            if (_position.x >= goTo.x) {
                _velocity = {0, 0, 0};
                goTo = {0, 0, 0};
                _savePos = {0, 0, 0};
            }
        }
    }
    if (goTo.z != 0) {
        if (_savePos.z >= goTo.z) {
            if (_position.z <= goTo.z) {
                _velocity = {0, 0, 0};
                goTo = {0, 0, 0};
                _savePos = {0, 0, 0};
            }
        }
        if (_savePos.z <= goTo.z) {
            if (_position.z >= goTo.z) {
                _velocity = {0, 0, 0};
                goTo = {0, 0, 0};
                _savePos = {0, 0, 0};
            }
        }
    }
    this->retrievePosition(x, z, width, height, r, deltaTime);
    for (auto &it : this->_components)
        it->update();
}

void Computer::draw()
{
    this->_model.ModelDraw(_model._model, this->_position, 10, WHITE);
}

void Computer::retrievePosition(int x, int z, int width, int height, int rand, float deltaTime)
{
    if (goTo.x != 0 || goTo.y != 0 || _velocity.x != 0 || _velocity.y != 0)
        return;
    if (rand == 0) {
        if (x + 1 < width && _map[x + 1][z] != 'O' && _map[x + 1][z] != 'X') {
            this->_velocity.x = 15 * deltaTime;
            this->_savePos = this->_position;
            this->goTo = {(float)(x + 1) * WORLD_TILE_SIZE_X, 0, 0};
        }
    }
    if (rand == 1) {
        if (x - 1 > 2 && _map[x - 1][z] != 'O' && _map[x - 1][z] != 'X') {
            this->_velocity.x = -15 * deltaTime;
            this->_savePos = this->_position;
            this->goTo = {(float)(x - 1) * WORLD_TILE_SIZE_X, 0, 0};
        }
    }
    if (rand == 2) {
        if (z - 1 > 2 && _map[x][z - 1] != 'O' && _map[x][z - 1] != 'X') {
            this->_velocity.z = -15 * deltaTime;
            this->_savePos = this->_position;
            this->goTo = {0, 0, (float)(z - 1) * WORLD_TILE_SIZE_Z};
        }
    }
    if (rand == 3) {
        if (z + 1 < height && _map[x][z + 1] != 'O' && _map[x][z + 1] != 'X') {
            this->_velocity.z = 15 * deltaTime;
            this->_savePos = this->_position;
            this->goTo = {0, 0, (float)(z + 1) * WORLD_TILE_SIZE_Z};
        }
    }
}
