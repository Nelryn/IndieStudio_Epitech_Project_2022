/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** WallGrief
*/

#include "WallGrief.hpp"
#include "Collider.hpp"
#include "Core.hpp"
#include "PlayState.hpp"

WallGrief::WallGrief(blb::Vector3f<float> const &position, blb::Vector3f<float> const &size)
{
    this->setPosition(position);
    this->setSize(size);
    this->mod_ = blb::Model3D();
    this->mod_.ModelFromModel(blb::Core::FindModel("maison"));
    this->mod_.setPosition(position);
    this->_cube = blb::Cube();
    this->mod_.setSize(size);
    this->addComponent(new blb::Collider(std::shared_ptr<Entity>(this)));
}

WallGrief::~WallGrief()
{
}

void WallGrief::setColor(Color newColor)
{
    this->_color = newColor;
}

void WallGrief::update()
{
    for (auto &it : this->_components)
        it->update();
}

void WallGrief::draw()
{
    this->mod_.ModelExDraw(this->mod_._model, this->getPositionV3(), {0, 0, 0}, 0, {10, 7, 10}, this->_color);
}

void WallGrief::unload()
{
    this->mod_.ModelUnload(this->mod_._model);
    UnloadTexture(this->mod_._texture);
    blb::Core::removeEntities(this);
}
