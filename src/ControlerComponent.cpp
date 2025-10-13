/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** ControlerComponent
*/


#include "ControlerComponent.hpp"
#include "blb.hpp"
#include "raylib.h"
#include "Entity.hpp"

ControlerComponent::ControlerComponent(int i)
{
    this->_name = "Controler";
    this->remote = new blb::Controler(i);
    this->_core = blb::Core::getInstance();
}

ControlerComponent::~ControlerComponent()
{

}

void ControlerComponent::update(void)
{
    blb::Event event = this->remote->getEvent();
    blb::Vector3f<float> vect(0, 0, 0);
    float deltaTime = GetFrameTime();

    if (!this->remote->isConnected())
        return;
    switch (event)
    {
    case blb::Event::LEFT:
        this->_entity->setVelocityZ(-15 * deltaTime);
        return;
        break;

    case blb::Event::RIGHT:
        this->_entity->setVelocityZ(15 * deltaTime);
        return;
        break;
    case blb::Event::UP:
        this->_entity->setVelocityX(15 * deltaTime);
        return;
        break;
    case blb::Event::DOWN:
        this->_entity->setVelocityX(-15 * deltaTime);
        return;
        break;
    default:
        vect = this->remote->getAxisLeftMove();
        this->_entity->setVelocity({-vect.y * deltaTime * 20, vect.z * deltaTime * 20, vect.x * deltaTime * 20});
    }
}

blb::Event ControlerComponent::getKeyPressed()
{
    return this->remote->getEvent();
}
