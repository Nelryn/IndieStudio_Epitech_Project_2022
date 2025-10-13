/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** MenuState
*/

#include <memory>
#include "MenuState.hpp"
#include "SettingState.hpp"
#include "Window.hpp"
#include "LoadState.hpp"
#include <chrono>
#include <thread>

MenuState::MenuState()
{
    std::string nb1 = "1";
    std::string nb2 = "2";
    std::string nb3 = "3";
    std::string nb4 = "4";
    core = blb::Core::getInstance();
    control = new blb::Controler(0);
    this->updated = false;
    this->text1 = new blb::Text(nb1, {500.0f, 350.0f}, 24.f);
    this->text2 = new blb::Text(nb2, {500.0f, 350.0f}, 24.f);
    this->text3 = new blb::Text(nb3, {500.0f, 350.0f}, 24.f);
    this->text4 = new blb::Text(nb4, {500.0f, 350.0f}, 24.f);
    _nbPlayer = 1;
    _isMusic = false;
}

MenuState::~MenuState()
{
    delete(control);
}

bool MenuState::update()
{
    if (this->updated == false) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        this->updated = true;
        return (true);
    }
    blb::AGamestate::update();

    if (_isMusic == false) {
        _musicMenu.PlaySoundmulti();
        _isMusic = true;
    }
    _mousePoint = {GetMousePosition().x, GetMousePosition().y};
    _btnAction = false;
    blb::Event event = control->getEvent();

    if (_newGame.CollideButton(_mousePoint, _newGame)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            std::shared_ptr<blb::AGamestate> state(new PlayState(_nbPlayer));
            this->updated = false;
            _isMusic = false;
            _musicMenu.StopSoundmulti();
            core->pushGameState(state);
            _btnState = 2;
        }
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            _btnAction = true;
    } else
        _btnState = 0;
    _newGame._src.y = _btnState * 150000 * _frameheight;

    if (_rarrow.CollideButton(_mousePoint, _rarrow)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            std::shared_ptr<blb::AGamestate> state(new LoadState);
            this->updated = false;
            _isMusic = false;
            _musicMenu.StopSoundmulti();
            core->pushGameState(state);
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
            std::shared_ptr<blb::AGamestate> state(new LoadState);
            this->updated = false;
            _isMusic = false;
            _musicMenu.StopSoundmulti();
            core->pushGameState(state);
            _btnState = 2;
        } else
            _btnState = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            _btnAction = true;
    } else
        _btnState = 0;
    _larrow._src.y = _btnState * (float)_larrow._txt._txt.height;

    if (_rarrowNb.CollideButton(_mousePoint, _rarrowNb)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            this->updated = false;
            if (_nbPlayer < 4)
                _nbPlayer++;
            _btnState = 2;
        } else
            _btnState = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            _btnAction = true;
    } else
        _btnState = 0;
    _rarrowNb._src.y = _btnState * (float)_rarrowNb._txt._txt.height;

    if (_larrowNb.CollideButton(_mousePoint, _larrowNb)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            this->updated = false;
            if (_nbPlayer > 1)
                _nbPlayer--;
            _btnState = 2;
        } else
            _btnState = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            _btnAction = true;
    } else
        _btnState = 0;
    _larrowNb._src.y = _btnState * (float)_larrowNb._txt._txt.height;

    if (_setting.CollideButton(_mousePoint, _setting)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            std::shared_ptr<blb::AGamestate> state(new SettingState);
            this->updated = false;
            _isMusic = false;
            _musicMenu.StopSoundmulti();
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

void MenuState::load()
{
    //PATH
    const std::string menuSound = "./resources/MusicMenu.ogg";
    // SOUND LOADING
    _musicMenu.Loadsound(menuSound);
    _musicMenu.SetSoundvolume(1.0f);

    // BACKGROUND IMG
    std::string path = "./resources/grey-bg.png";
    _texture._txt = _texture.LoadTxt(path);

    _frameheight = (float)_newGame._txt._txt.height;

    path = "./resources/Nblack_game.png";
    _newGame.CreateButton(path, 2.0f, 4.0f, 2.0f, 5.0f, 0.0f, 0.0f);
    path = "./resources/Rarrow.png";
    _rarrow.CreateButton(path, 1.0f, 2.0f, 1.0f, 2.0f, 10.0f, 0.0f);
    path = "./resources/Larrow.png";
    _larrow.CreateButton(path, 6.0f, 2.0f, 0.5f, 2.0f, 0.0f, 0.0f);
    path = "./resources/L_arrow.png";
    _larrowNb.CreateButton(path, 2.0f, 2.0f, 0.5f, 2.0f, 70.0f, 0.0f);
    path = "./resources/R_Arrow.png";
    _rarrowNb.CreateButton(path, 2.0f, 2.0f, 1.0f, 2.0f, (-150.0f), 0.0f);
    path = "./resources/setting_icon.png";
    _setting.CreateButton(path, 1.0f, 10.0f, 1.0f, 2.0f, 10.0f, 0.0f);

    _textBox = {core->win->getScreenWidth()/2.0f - 30.0f,
    core->win->getScreenHeight() / 2.0f - 25.0f, (float)50, (float)50};
}

void MenuState::draw()
{
    blb::Shape shaper;

    _texture.DrawTxtEx(_texture, {0,0}, 0, 1, {blb::Colors::_white.x,
        blb::Colors::_white.y, blb::Colors::_white.z, blb::Colors::_white.w});
    _newGame.DrawButton({blb::Colors::_white.x, blb::Colors::_white.y,
    blb::Colors::_white.z, blb::Colors::_white.w}, {blb::Colors::_transparent.x,
    blb::Colors::_transparent.y, blb::Colors::_transparent.z, blb::Colors::_transparent.w});
    _rarrow.DrawButton({blb::Colors::_white.x, blb::Colors::_white.y,
    blb::Colors::_white.z, blb::Colors::_white.w}, {blb::Colors::_transparent.x,
    blb::Colors::_transparent.y, blb::Colors::_transparent.z, blb::Colors::_transparent.w});
    _larrow.DrawButton({blb::Colors::_white.x, blb::Colors::_white.y,
    blb::Colors::_white.z, blb::Colors::_white.w}, {blb::Colors::_transparent.x,
    blb::Colors::_transparent.y, blb::Colors::_transparent.z, blb::Colors::_transparent.w});
    _larrowNb.DrawButton({blb::Colors::_white.x, blb::Colors::_white.y,
    blb::Colors::_white.z, blb::Colors::_white.w}, {blb::Colors::_transparent.x,
    blb::Colors::_transparent.y, blb::Colors::_transparent.z, blb::Colors::_transparent.w});
    _rarrowNb.DrawButton({blb::Colors::_white.x, blb::Colors::_white.y,
    blb::Colors::_white.z, blb::Colors::_white.w}, {blb::Colors::_transparent.x,
    blb::Colors::_transparent.y, blb::Colors::_transparent.z, blb::Colors::_transparent.w});
    _setting.DrawButton({blb::Colors::_white.x, blb::Colors::_white.y,
    blb::Colors::_white.z, blb::Colors::_white.w}, {blb::Colors::_transparent.x,
    blb::Colors::_transparent.y, blb::Colors::_transparent.z, blb::Colors::_transparent.w});

    shaper.RectangleDraw(_textBox.x, _textBox.y, _textBox.width, _textBox.height,
    {255, 255, 255, 255});

    switch (_nbPlayer) {
    case 1:
        this->text1->Draw();
        break;
    case 2:
        this->text2->Draw();
        break;
    case 3:
        this->text3->Draw();
        break;
    case 4:
        this->text4->Draw();
        break;
    default:
        break;
    }
}

void MenuState::unload()
{
    _musicMenu.Unloadsound();
}
