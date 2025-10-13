/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** Wall
*/

#pragma once
#include "Entity.hpp"
#include "EModel.hpp"
#include "type/Vector3.hpp"
#include "Collider.hpp"
#include "Model3D.hpp"

class Wall : public blb::Entity {
    public:
        Wall(blb::Vector3f<float> const &position, blb::Vector3f<float> const &size);
        ~Wall();

        void update() override;
        void draw() override;
        void unload() override;

    protected:
    private:
        blb::Cube model_;
        blb::Model3D mod;
        float z = 0;
        bool down = false;
        unsigned char r = 0;
        unsigned char g = 0;
        unsigned char b = 0;
};
