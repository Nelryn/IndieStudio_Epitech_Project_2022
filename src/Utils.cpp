/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-alexis.picard
** File description:
** this is an epitech project
*/

#include "Utils.hpp"
#include <string>
#include <fstream>
#include <iostream>

std::vector<std::string> Utils::readDirectory(const std::string &filepath)
{
    std::vector<std::string> filesList;

    return filesList;
}

std::vector<std::string> Utils::readFile(std::string const &filepath)
{
    std::ifstream file(filepath);
    std::vector<std::string> tab;

    if (file.is_open()) {
        std::string str;

        while (std::getline(file, str))
            tab.push_back(str);
    } else {
        std::cerr << "File " << filepath << " does not exist" << std::endl;
        exit(84);
    }
    file.close();
    return tab;
}

std::vector<std::string> Utils::split(std::string const &str, std::string const &regex)
{
    size_t pos = 0;
    std::string token = "";
    std::string s = str;
    std::vector<std::string> tab;

    while ((pos = s.find(regex)) != std::string::npos) {
        token = s.substr(0, pos);
        tab.push_back(token);
        s.erase(0, pos + regex.length());
    }
    tab.push_back(s);
    return tab;
}