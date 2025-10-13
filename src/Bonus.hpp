/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** Bonus
*/

#pragma once

#include "Entity.hpp"
#include "Cube.hpp"
#include "blb.hpp"
#include "Model3D.hpp"

typedef enum bonus {
    VOID,
    FIRE,
    SPEED,
    BOMB
} bonus_type;

class Bonus : public blb::Entity {
    public:
        Bonus(blb::Vector3f<float> pos);
        ~Bonus();

        bonus_type type;
        blb::Cube cube;
        blb::Model3D walk;
        blb::Model3D lightning;
        blb::Model3D redBomb;
        blb::Model3D bombax;

        void update() override;
        void draw() override;
        void unload() override;
        void giveBonus(std::shared_ptr<blb::IEntity> &ent);

    protected:
    private:
};
