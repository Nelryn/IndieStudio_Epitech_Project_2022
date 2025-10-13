/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** Map
*/

#pragma once
#include <vector>
#include <string>
#include "Utils.hpp"
#include "EModel.hpp"
#include "Entity.hpp"
#include "PlayState.hpp"

class PlayState;

class Map : public blb::Entity {


    public:
        Map() = default;
        ~Map() = default;

        void createFromFile(std::string const &fileName);
        void proceduralGeneration(int const &width, int const &height);
        void draw(void) override;
        void update(void) override {}
        void unload() override;
        std::vector<std::string> getMap();

    private:
        void constructBorder(int const &width, int const &height);
        void constructSpawn(int const &width, int const &height);

    protected:
    private:
        std::vector<std::string> content_;
        float width_ = 0;
        float height_ = 0;
};
