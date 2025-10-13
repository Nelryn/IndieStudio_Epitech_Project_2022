/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** Computer
*/

#pragma once

#include <vector>
#include <string>
#include "Player.hpp"
#include "type/Vector3.hpp"

class Computer : public virtual Player {
    public:
        Computer(std::vector<std::string> const &map,
                    blb::Vector3f<float> const &position,
                    blb::Vector3f<float> const &size,
                    int id,
                    std::string const &texturePath);

        virtual ~Computer() = default;
        Computer() = default;
        void update() override;
        void draw() override;
        Computer *setTexture(std::string const &texture);
        Computer *setMap(std::vector<std::string> const &map);
    private:
        void retrievePosition(int x, int y, int width, int height, int rand, float deltaTime);
    protected:
    private:
        std::vector<std::string> _map;
        blb::Vector3f<float> _direction = blb::Vector3f<float>(0,0,0);
        blb::Vector3f<float> _savePos = blb::Vector3f<float>(0,0,0);
        blb::Vector3f<float> goTo = blb::Vector3f<float>(0,0,0);
};
