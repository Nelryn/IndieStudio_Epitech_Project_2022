/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-team.bodzen
** File description:
** BonusCollider
*/

#pragma once

#include "blb.hpp"
#include "IEntity.hpp"


class BonusCollider : public blb::AComponent {
    public:
        BonusCollider(std::shared_ptr<blb::Entity> const &entity);
        ~BonusCollider();

        bool isColliding(std::shared_ptr<blb::IEntity> const &entity1,
            std::shared_ptr<blb::IEntity> const &entity2);

        void collisionHandlement(std::shared_ptr<blb::IEntity> it);

        void update() override;

    protected:
        std::vector<std::shared_ptr<blb::Entity>> entities_;
        blb::Cube cube_;
    private:
};
