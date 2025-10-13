/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** Map
*/

#include "Map.hpp"
#include "Computer.hpp"
#include "Core.hpp"
#include "Wall.hpp"
#include "WallGrief.hpp"
#include <time.h>

void Map::constructBorder(int const &width, int const &height)
{
    std::string border = "";
    std::string middle = "";
    std::string middleEmpty = "";
    int modX = width % 2 == 0 ? 2 : 2;
    int modY = height % 2 == 0 ? 2 : 2;

    for (std::size_t i = 0; i < width; i++)
        border.push_back('X');
    this->content_.push_back(border);
    for (std::size_t i = 0; i < width; i++)
        middle.push_back(i == 0 || i == width - 1 || i % modX == 0 ? 'X' : ' ');
    for (std::size_t i = 0; i < width; i++)
        middleEmpty.push_back(i == 0 || i == width - 1 ? 'X' : ' ');
    for (std::size_t i = 1; i < height - 1; i++)
        this->content_.push_back(i % modY && i != 1 && i != height - 2 ? middle : middleEmpty);
    this->content_.push_back(border);
}

void Map::constructSpawn(int const &width, int const &height)
{
    this->content_[height - 2][1] = ' ';
    this->content_[height - 2][2] = ' ';
    this->content_[height - 3][1] = ' ';
    this->content_[height - 3][2] = ' ';
    this->content_[height - 2][width - 2] = ' ';
    this->content_[height - 2][width - 3] = ' ';
    this->content_[height - 3][width - 2] = ' ';
    this->content_[height - 3][width - 3] = ' ';
    this->content_[1][width - 2] = ' ';
    this->content_[1][width - 3] = ' ';
    this->content_[2][width - 2] = ' ';
    this->content_[2][width - 3] = ' ';
    this->content_[1][1] = ' ';
    this->content_[1][2] = ' ';
    this->content_[2][1] = ' ';
    this->content_[2][2] = ' ';
}

void Map::proceduralGeneration(int const &width, int const &height)
{
    float z = 0;
    float x = 0;
    blb::Vector3f<float> size = blb::Vector3f<float>(10, 10, 10);

    std::srand(time(NULL));
    this->constructBorder(width, height);
    for (std::size_t i = 1; i < (height - 1); i++) {
        for (std::size_t j = 1; j < (width - 1); j++) {
            int value = rand() % 2;
            int value2 = rand() % 3;
            int value3 = rand() % 25;

            if (value == 0 || value2 == 0 || value3 == 0) {
                if (this->content_[i][j] != 'X')
                    this->content_[i][j] = 'O';
            }
        }
    }
    this->constructSpawn(width, height);
    for (std::string &s : this->content_) {
        for (char c : s) {
            switch(c) {
                case 'X':
                    blb::Core::addEntities(new Wall(blb::Vector3f<float>(x, 0, z), size));
                    break;
                case 'O':
                    blb::Core::addEntities(new WallGrief(blb::Vector3f<float>(x, 0, z), size));
                    break;
                default: break;
            }
            x += size.x * 2;
        }
        x = 0;
        z += size.y * 2;
    }
    this->setX(x);
    this->setZ(z);

}

void Map::draw()
{
    //let empty
}

void Map::unload()
{

}

std::vector<std::string> Map::getMap()
{
    return this->content_;
}
