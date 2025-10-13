/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** Wall
*/

#include "Wall.hpp"
#include "raylib.h"
#include "Core.hpp"
#include <time.h>

Wall::Wall(blb::Vector3f<float> const &position, blb::Vector3f<float> const &size)
{
    this->setPosition(position);
    this->setSize(size);
    this->mod = blb::Model3D();
    this->mod.ModelFromModel(blb::Core::FindModel("maison"));
    this->mod.setPosition(position);
    this->mod.setSize(size);
    this->model_.setPosition(position);
    this->model_.setSize(size);
    this->addComponent(new blb::Collider(std::shared_ptr<Entity>(this)));
}

Wall::~Wall()
{
}

void Wall::update()
{
    float deltaTime = GetFrameTime();

    for (auto &it : this->_components)
        it->update();
}

void Wall::draw()
{
    this->mod.ModelExDraw(this->mod._model, this->getPositionV3(), {0, 1, 0}, -90, {10, 7, 10}, WHITE);
    this->mod.ModelWiresDraw(this->mod._model, this->getPositionV3(), 1, BLACK);
}

void Wall::unload()
{
    this->mod.ModelUnload(this->mod._model);
    UnloadTexture(this->mod._texture);
    blb::Core::removeEntities(this);

}
