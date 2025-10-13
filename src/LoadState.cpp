/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** LoadState
*/

#include "LoadState.hpp"
#include "PlayState.hpp"
#include "MenuState.hpp"
#include "SettingState.hpp"
#include <thread>
#include <chrono>


LoadState::LoadState()
{
    core = blb::Core::getInstance();
    this->updated = false;
}

LoadState::~LoadState()
{
}

bool LoadState::update()
{
    if (this->updated == false) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        this->updated = true;
        return (true);
    }
    blb::AGamestate::update();

    _mousePoint = {GetMousePosition().x, GetMousePosition().y};
    _btnAction = false;

    if (_lbutton.CollideButton(_mousePoint, _lbutton)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            std::shared_ptr<blb::AGamestate> state(new PlayState(2));
            core->pushGameState(state);
            _btnState = 2;
        } else
            _btnState = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            _btnAction = true;
    } else
        _btnState = 0;
    _lbutton._src.y = _btnState * _frameheight;

    if (_rarrow.CollideButton(_mousePoint, _rarrow)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            core->popGameState();
            _btnState = 2;
        } else
            _btnState = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            _btnAction = true;
    } else
        _btnState = 0;
    _rarrow._src.y = _btnState * (float)_rarrow._txt._txt.height;

    if (_larrow.CollideButton(_mousePoint, _larrow)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            core->popGameState();
            _btnState = 2;
        } else
            _btnState = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            _btnAction = true;
    } else
        _btnState = 0;
    _larrow._src.y = _btnState * (float)_larrow._txt._txt.height;

    if (_setting.CollideButton(_mousePoint, _setting)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            std::shared_ptr<blb::AGamestate> state(new SettingState);
            this->updated = false;
            core->pushGameState(state);
            _btnState = 2;
        } else
            _btnState = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            _btnAction = true;
    } else
        _btnState = 0;
    _setting._src.y = _btnState * (float)_setting._txt._txt.height;

    return (true);
}

void LoadState::load()
{
    std::string path = "./resources/grey-bg.png";
    _texture._txt = _texture.LoadTxt(path);

    _frameheight = (float)_lbutton._txt._txt.height;

    path = "./resources/Lblack_game.png";
    _lbutton.CreateButton(path, 2.0f, 4.0f, 2.0f, 5.0f, 0.0f, 0.0f);
    path = "./resources/Rarrow.png";
    _rarrow.CreateButton(path, 1.0f, 2.0f, 1.0f, 2.0f, 10.0f, 0.0f);
    path = "./resources/Larrow.png";
    _larrow.CreateButton(path, 6.0f, 2.0f, 0.5f, 2.0f, 0.0f, 0.0f);
    path = "./resources/setting_icon.png";
    _setting.CreateButton(path, 1.0f, 10.0f, 1.0f, 2.0f, 10.0f, 0.0f);
}

void LoadState::draw()
{
    blb::Shape shaper;

    _texture.DrawTxtEx(_texture, {0,0}, 0, 1, {blb::Colors::_white.x,
        blb::Colors::_white.y, blb::Colors::_white.z, blb::Colors::_white.w});

    _lbutton.DrawButton({blb::Colors::_white.x, blb::Colors::_white.y,
        blb::Colors::_white.z, blb::Colors::_white.w}, {blb::Colors::_white.x,
        blb::Colors::_white.y, blb::Colors::_white.z, blb::Colors::_white.w});
    _rarrow.DrawButton({blb::Colors::_white.x, blb::Colors::_white.y,
        blb::Colors::_white.z, blb::Colors::_white.w}, {blb::Colors::_white.x,
        blb::Colors::_white.y, blb::Colors::_white.z, blb::Colors::_white.w});
    _larrow.DrawButton({blb::Colors::_white.x, blb::Colors::_white.y,
        blb::Colors::_white.z, blb::Colors::_white.w}, {blb::Colors::_white.x,
        blb::Colors::_white.y, blb::Colors::_white.z, blb::Colors::_white.w});
    _setting.DrawButton({blb::Colors::_white.x, blb::Colors::_white.y,
        blb::Colors::_white.z, blb::Colors::_white.w}, {blb::Colors::_white.x,
        blb::Colors::_white.y, blb::Colors::_white.z, blb::Colors::_white.w});
}

void LoadState::unload()
{

}
