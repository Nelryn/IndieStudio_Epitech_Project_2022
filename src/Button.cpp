/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** Button
*/

#include "Button.hpp"

namespace blb {
    Button::Button()
    {
        this->core = blb::Core::getInstance();
    }

    Button::~Button()
    {
    }

    bool Button::CollideButton(Vector2f _mousePoint, blb::Button _button)
    {
        if ((_mousePoint.x <  _button._hitbox.x +  _button._hitbox.width && _mousePoint.x >  _button._hitbox.x) &&
            (_mousePoint.y <  _button._hitbox.y +  _button._hitbox.height && _mousePoint.y >  _button._hitbox.y))
            return (true);
        return (false);
    }

    void Button::CreateButton(std::string path, float screenWidth, float screenHeight,
        float width, float height, float minusWidth, float minusHeight)
    {
        _txt._txt = _txt.LoadTxt(path);
        _frameheight = (float)_txt._txt.height / 1;
        _src = {0, 0, (float)_txt._txt.width, (float)_frameheight * 1};

        _hitbox = {(float)core->win->getScreenWidth() / screenWidth - _txt._txt.width / width - minusWidth,
        (float)core->win->getScreenHeight() / screenHeight - _txt._txt.height / height - minusHeight,
                (float)_txt._txt.width, (float)_txt._txt.height};
    }

    void Button::DrawButton(Vector4u color, Vector4u tint)
    {
        _txt.DrawTxtRec(_txt ,{_src.x, _src.y, _src.width, _src.height},
            {_hitbox.x, _hitbox.y}, {color.x, color.y, color.z, color.w});
        RectangleDraw(_hitbox.x, _hitbox.y,
            _hitbox.width,_hitbox.height, {tint.x, tint.y, tint.z, 5});
    }
}
