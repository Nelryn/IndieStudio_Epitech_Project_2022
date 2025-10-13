/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** SettingState
*/

#include <memory>
#include "Window.hpp"
#include "SettingState.hpp"
#include <chrono>
#include <thread>

SettingState::SettingState()
{
    core = blb::Core::getInstance();
    this->updated = false;
}

SettingState::~SettingState()
{
}

bool SettingState::update()
{
    if (this->updated == false) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        this->updated = true;
        return (true);
    }
    blb::AGamestate::update();

    int display;
    _sourceRec.y = 0 * _frameheight;
    _mousePoint = {GetMousePosition().x, GetMousePosition().y};
    _btnAction = false;

    if (fullScreen.CollideButton(_mousePoint, fullScreen)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            this->updated = false;
        } else
            _btnState = 1;
    } else if (plus.CollideButton(_mousePoint, plus)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            this->updated = false;
            _btnState = 2;
        } else
            _btnState = 1;
    } else if (minus.CollideButton(_mousePoint, minus)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            this->updated = false;
            _btnState = 2;
        } else
            _btnState = 1;
    }  else if (_return.CollideButton(_mousePoint, _return)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            this->updated = false;
            core->popGameState();
            _btnState = 2;
        } else
            _btnState = 1;
    } else
        _btnState = 0;
    _sourceRec.y = _btnState * _frameheight;
    return (true);
}

void SettingState::load()
{
    std::string path = "./resources/settings.png";
    std::string full = "./resources/full.png";
    std::string volup = "./resources/volup.png";
    std::string voldown = "./resources/voldown.png";
    std::string ret = "./resources/cross.png";
    std::string iconVol = "./resources/volumeIcon.png";

    _texture._txt = _texture.LoadTxt(path);
    fullScreen.CreateButton(full, 10.0f, 1, 1, 1, 0, 0);
    _return.CreateButton(ret, 1, 10.0f, 1, 2.0f, 10.0f, 0);
    _iconVol.CreateButton(iconVol, 2.5f, 2.0f, 1, 1, 0, 0);
    plus.CreateButton(volup, 1.5f,  2.0f, 2.0f, 1, 50.0f, 0);
    minus.CreateButton(voldown, 2.0f,  2.0f, 1, 1, -10.0f, 0);
}

void SettingState::draw()
{
    _texture.DrawTxtEx(_texture, {0,0}, 0, 1, {blb::Colors::_white.x,
        blb::Colors::_white.y, blb::Colors::_white.z, blb::Colors::_white.w});
    fullScreen.DrawButton({blb::Colors::_white.x, blb::Colors::_white.y,
        blb::Colors::_white.z, blb::Colors::_white.w}, {blb::Colors::_white.x,
        blb::Colors::_white.y, blb::Colors::_white.z, blb::Colors::_white.w});
    plus.DrawButton({blb::Colors::_white.x, blb::Colors::_white.y,
        blb::Colors::_white.z, blb::Colors::_white.w}, {blb::Colors::_white.x,
        blb::Colors::_white.y, blb::Colors::_white.z, blb::Colors::_white.w});
    minus.DrawButton({blb::Colors::_white.x, blb::Colors::_white.y,
        blb::Colors::_white.z, blb::Colors::_white.w}, {blb::Colors::_white.x,
        blb::Colors::_white.y, blb::Colors::_white.z, blb::Colors::_white.w});
    _return.DrawButton({blb::Colors::_white.x, blb::Colors::_white.y,
        blb::Colors::_white.z, blb::Colors::_white.w}, {blb::Colors::_white.x,
        blb::Colors::_white.y, blb::Colors::_white.z, blb::Colors::_white.w});
    _iconVol.DrawButton({blb::Colors::_white.x, blb::Colors::_white.y,
        blb::Colors::_white.z, blb::Colors::_white.w}, {blb::Colors::_white.x,
        blb::Colors::_white.y, blb::Colors::_white.z, blb::Colors::_white.w});
}

void SettingState::unload()
{

}
