/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** WallGrief
*/

#pragma once
#include "Entity.hpp"
#include "Cube.hpp"
#include "type/Vector3.hpp"
#include "Model3D.hpp"

class WallGrief : public blb::Entity {
    public:
        WallGrief(blb::Vector3f<float> const &position, blb::Vector3f<float> const &size);
        ~WallGrief();

        void setColor(Color newColor);
        void update() override;
        void draw() override;
        void unload() override;

    protected:
    private:
        blb::Model3D mod_;
        blb::Cube _cube;
        Color _color = GREEN;
};
