/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** PlayState
*/

#include "PlayState.hpp"
#include "Player.hpp"
#include "ICamera.hpp"
#include "WallGrief.hpp"
#include "blb.hpp"
#include "ControlerComponent.hpp"
#include "raylib.h"
#include "Bonus.hpp"
#include "Computer.hpp"
#include <chrono>
#include <thread>
#include <typeinfo>

PlayState::PlayState(int nbPlayer)
{
    _nbPlayer = nbPlayer;
    this->core = blb::Core::getInstance();
    controler = new blb::Controler(0);
    this->updated = false;
    this->_ismusic = false;
    _mainTrack = new blb::Audio();
}

PlayState::PlayState()
{
}

void PlayState::load()
{
    std::size_t i = 0;
    this->map = new Map();
    this->map->proceduralGeneration(13, 13);
    blb::Vector3f<float> target = blb::Vector3f<float>(75, 33.2, 118);
    this->camera = new blb::Cam3D(blb::Vector3f<float>(-458, 312, 118),
                                        target,
                                        blb::Vector3f<float>(1, 0, 0),
                                        45,
                                        CAMERA_PERSPECTIVE);

    blb::Core::addEntities(this->map);
    for (i = 0; i < _nbPlayer; i++)
        blb::Core::addEntities(new Player(_spawnArray[i], {10, 10, 10}, i, _textureArray[i]));
    for (; i < 4 ; i++)
        blb::Core::addEntities(new Computer(map->getMap(), _spawnArray[i], {10, 10, 10}, i, _textureArray[i]));
    blb::Core::getInstance()->setCamera(camera);
    this->_camEndPos = blb::Vector3f<float>(this->camera->getPos().x,
                                            this->camera->getPos().y,
                                            this->camera->getPos().z);
    _bS = {0.0f, 0.0f, (float)1024, (float)720};

    // PATH MUSIC GAME
    const std::string musicTrack = "../resources/MainTrack.ogg";
    // SOUND
    _mainTrack->Loadsound(musicTrack);
    _mainTrack->SetSoundvolume(0.2f);
}

PlayState::~PlayState()
{
    delete(controler);
}

bool PlayState::cutScene()
{
    float deltaTime = blb::Core::GetTimeFrame();

    if (this->endScene)
        return (true);
    if (this->camera->getPos().x >= -68)
        this->endScene = true;
    this->camera->setPos({this->camera->getPos().x + 100 * deltaTime, this->camera->getPos().y, this->camera->getPos().z});
    return false;
}

bool PlayState::pauseHandlement(float const &deltaTime, int &statePause, blb::Shape &shaper)
{
    if (buttonReady) {
        if ((this->controler->getEvent() == blb::Event::START && statePause == 1)
                                        || (IsKeyDown(KEY_F1) && statePause == 1)) {
            statePause = 0;
            buttonReady = false;
            return (bool)!statePause;
        }
        if ((this->controler->getEvent() == blb::Event::START && statePause == 0)
                                    || (IsKeyDown(KEY_F2) && statePause == 0)) {
            statePause = 1;
            buttonReady = false;
            return (bool)!statePause;
        }
    }
    if (!buttonReady)
        this->buttonCd += deltaTime;
    if (this->buttonCd >= this->buttonTimePadding) {
        buttonReady = !buttonReady;
        this->buttonCd = 0;
    }
    if (statePause == 0)
        shaper.RectangleDraw(_bS.x, _bS.y, _bS.width, _bS.height, {0, 0, 0, 100});
    return (bool)!statePause;
}

bool PlayState::update()
{
    static int statePause = 1;
    std::size_t numb = 0;
    blb::Shape shaper;
    float deltaTime = blb::Core::GetTimeFrame();

    DrawFPS(0, 0);
    //if (_ismusic == false) {
    //    _mainTrack->PlaySoundmulti();
    //    _ismusic = true;
    //}
    if (!this->cutScene())
        return true;
    if (IsKeyDown(KEY_SPACE)) {
        for (auto &it : this->_entities) {
            if (it == nullptr)
                continue;
            if (dynamic_cast<WallGrief *>(it.get()) != nullptr) {
                it.reset();
                this->_entities.erase(this->_entities.begin() + numb);
            }
            numb++;
        }
    }
    if (this->pauseHandlement(deltaTime, statePause, shaper))
        return true;
    blb::AGamestate::update();
    return (true);
}

void PlayState::draw()
{
}

void PlayState::unload()
{
    // _mainTrack.StopSoundmulti();
    // _mainTrack.Unloadsound();
}
