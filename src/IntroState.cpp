/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** IntroState
*/

#include "IntroState.hpp"
#include <chrono>
#include <thread>
#include "MenuState.hpp"
#include <string>

IntroState::IntroState()
{
    std::string studio = "blb Studio";
    core = blb::Core::getInstance();
    this->text1 = new blb::Text(studio, {400.0f, 650.0f}, 64.f);
    _isMusic = false;
}

IntroState::~IntroState()
{
}

bool IntroState::update()
{
    blb::AGamestate::update();

    for (int i = 0; i != 100; i++) {
        if (i % 100 == 0)
            _fade -= 0.004f;
    }
    if (_isMusic == false && _fade <= 0.8) {
        _musicIntro.PlaySoundmulti();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        _musicBubble.PlaySoundmulti();
        _isMusic = true;
    }
    if (_fade <= 0) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        std::shared_ptr<blb::AGamestate> state(new MenuState());
        _musicIntro.StopSoundmulti();
        _musicBubble.StopSoundmulti();
        // _musicIntro.Unloadsound();
        // _musicBubble.Unloadsound();
        core->pushGameState(state);
    }
    return (true);
}

void IntroState::draw()
{
    _texture.DrawTxtEx(_texture, {200.0f, 0.0f}, 0, 1,
        _texture.fadeColor({blb::Colors::_white.x, blb::Colors::_white.y,
        blb::Colors::_white.z, blb::Colors::_white.w}, _fade));

    // DRAW STUDIO TEXT

    this->text1->DrawFade(_fade);
}

void IntroState::load()
{
    std::string path = "./resources/blbl_V3.png";
    _texture._txt = _texture.LoadTxt(path);

    const std::string introSound = "./resources/IntroGame.ogg";
    const std::string bubbleSound = "./resources/goute.ogg";
    _musicIntro.Loadsound(introSound);
    _musicBubble.Loadsound(bubbleSound);

    _musicIntro.SetSoundvolume(1.0f);
    _musicBubble.SetSoundvolume(1.0f);
}

void IntroState::unload()
{
    _musicIntro.Unloadsound();
    _musicBubble.Unloadsound();
}
