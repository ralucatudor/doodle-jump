#pragma once

#include <memory>
#include <functional>
#include "Doodler.hpp"
#include "Platform.hpp"
#include "BaseEntity.hpp"

template<typename T, class R>
using Lambda = std::function<T(const std::shared_ptr<R> &)>;

class GameEngine
{
public:
    void checkCollision(std::vector<std::shared_ptr<BaseEntity>>& entities);

private:
    std::shared_ptr<BaseEntity> doodler;

    const Lambda<bool, BaseEntity> isDoodler = [&](const std::shared_ptr<BaseEntity> &entity) -> bool {
        return (dynamic_cast<Doodler*>(entity.get()));
    };

    const Lambda<void, BaseEntity> applyForEach = [&](const std::shared_ptr<BaseEntity>& entity) -> void {
        if (doodler == nullptr || isDoodler(entity))
        {
            return;
        }
        processCollision(entity);
    };

    void processCollision(const std::shared_ptr<BaseEntity>&);

    bool doesIntersect(const std::shared_ptr<BaseEntity>&) const;
};