/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** Player
*/

#include "Player.hpp"
#include "PlayState.hpp"
#include "ControlerComponent.hpp"
#include "Bomb.hpp"
#include "raylib.h"
#include <iostream>

Player::~Player()
{
}

Player::Player(
        blb::Vector3f<float> const &position,
        blb::Vector3f<float> const &size,
        int player,
        std::string const &texture
    )
{
    unsigned int avoidable = 0;
    this->collider_ = new blb::Collider(std::shared_ptr<blb::Entity>(this));
    this->controler = new ControlerComponent(player);
    this->controler->initialize(std::shared_ptr<blb::Entity>(this));
    this->addComponent(this->controler);
    this->addComponent(this->collider_);
    this->setPosition(position);
    this->setSize(size);
    this->cube = blb::Cube();
    this->_model = blb::Model3D();
    this->_model.ModelLoad("./resources/girl_armature_.iqm");
    this->_model._texture = LoadTexture(texture.c_str());
    this->_model.MaterialTextureSet(&this->_model._model.materials[0], MATERIAL_MAP_DIFFUSE, this->_model._texture);
    this->_model._anim = LoadModelAnimations("./resources/girl_armature_.iqm", &avoidable);
    this->bombMax = 1;
    this->rangeBomb = 1;
    this->_speedMultiplier = 2;
}


void Player::checkBombPosition(blb::Vector3f<float> const &bombPos)
{
    for (auto &it : blb::Core::getEntities()) {
        if (it != nullptr) {
            if (it->coordContain(bombPos))
                return;
        }
    }
    blb::Core::addEntities(dynamic_cast<blb::Entity *>(new Bomb(bombPos, rangeBomb)));
    this->bombReady--;
}

void Player::handleAnimation()
{
    if (this->animationFrames >= this->_model._anim->frameCount - 1)
        this->opposite = true;
    if (this->animationFrames == 0)
        this->opposite = false;
    if (this->animTime >= this->animDelay) {
        if (this->opposite)
            this->animationFrames--;
        if (!this->opposite)
            this->animationFrames++;
        this->animTime = 0;
    }
    this->_model.ModelAnimationUpdate(this->_model._model, this->_model._anim[0], this->animationFrames);
}

void Player::bombInstantiate()
{
    if (this->controler->getKeyPressed() == blb::Event::A) {
        if (this->bombReady > 0) {
            blb::Vector3f<float> position = blb::Vector3f<float>(
                this->_position.x + (this->_size.x / 2),
                this->_position.y + (this->_size.y / 2),
                this->_position.z + (this->_size.z / 2)
            );
            blb::Vector3f<float> bombPos = blb::Vector3f<float>(
                position.x - ((int)position.x % WORLD_TILE_SIZE_X),
                position.y - ((int)position.y % WORLD_TILE_SIZE_Y),
                position.z - ((int)position.z % WORLD_TILE_SIZE_Z)
            );
            this->checkBombPosition(bombPos);
        }
    }
}

void Player::bombCoolDown()
{
    this->bombCd += blb::Core::GetTimeFrame();
    if (this->bombCd >= 5) {
        if (this->bombReady < this->bombMax) {
            this->bombReady++;
        }
        this->bombCd = 0;
    }
}

void Player::addBomb()
{
    if (this->bombMax < 3) {
        this->bombMax++;
    }
}

void Player::addSpeed()
{
    if (this->_speedMultiplier < 3) {
        this->_speedMultiplier += 0.2;
    }
}

void Player::addfire()
{
    if (this->rangeBomb != 2) {
        this->rangeBomb == 2;
    }
}

void Player::update()
{
    this->_position += this->_velocity;
    this->animTime += blb::Core::GetTimeFrame();

    this->getRotation();
    this->handleAnimation();
    this->handleAnimation();
    this->bombCoolDown();
    for (auto &it : this->_components)
        it->update();
    this->bombInstantiate();
}

void Player::getRotation()
{
    this->_rotation = this->controler->remote->getAxisLeftMove();

    if (this->controler->remote->isConnected()) {
        if (_rotation.x < 0.02)
            _angle = -190;
        if (_rotation.x > 0.0)
            _angle = 190;
        if (_rotation.y > 0.0)
            _angle = 355;
        if (_rotation.y < 0.0)
            _angle = 18.75;
        if (_rotation.x > 0.0 && _rotation.y < 0.0)
            _angle = 195.5;
        if (_rotation.x > 0.0 && _rotation.y > 0.0)
            _angle = 197;
        if (_rotation.x < 0.0 && _rotation.y < 0.0)
            _angle = 200.5;
        if (_rotation.x < 0.0 && _rotation.y > 0.0)
            _angle = 198.5;
    }

}

void Player::setVelocityX(float const &x)
{
    this->_velocity.x += x * this->_speedMultiplier;
}

void Player::setVelocityY(float const &y)
{
    this->_velocity.y += y * this->_speedMultiplier;
}

void Player::setVelocityZ(float const &z)
{
    this->_velocity.z += z * this->_speedMultiplier;
}

void Player::setVelocity(blb::Vector3f<float> const &pos)
{
    blb::Vector3f<float> vel = blb::Vector3f<float>(
        pos.x * this->_speedMultiplier,
        pos.y * this->_speedMultiplier,
        pos.z * this->_speedMultiplier
    );
    this->_velocity = vel;
}

void Player::draw()
{
    this->animTime += blb::Core::GetTimeFrame();
    this->_model.TransformXYZ({0, _angle, 0});
    this->_model.ModelDraw(this->_model._model, this->getPositionV3(), 10, WHITE);
}

void Player::unload()
{
    this->_model.ModelUnload(this->_model._model);
    UnloadTexture(this->_model._texture);
    blb::Core::removeEntities(this);

}
