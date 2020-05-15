#pragma once

#include <memory>
#include <functional>

#include "BaseEntity.hpp"
#include "Doodler.hpp"

#include "Platform.hpp"
#include "RegularPlatform.hpp"
#include "FastPlatform.hpp"
#include "SlowPlatform.hpp"

template<typename T, typename R>
using Lambda = std::function<T(const std::shared_ptr<R> &)>;

// Game engine responsible for collision detection
class GameEngine
{
public:
    void checkCollision(std::vector<std::shared_ptr<BaseEntity>>& entities);
private:
    std::shared_ptr<Doodler> doodler;

    const Lambda<bool, BaseEntity> isDoodler = [&](const std::shared_ptr<BaseEntity> &entity) -> bool {
        return (dynamic_cast<Doodler*>(entity.get()));
    };

    const Lambda<void, BaseEntity> processCollisionForEach = [&](const std::shared_ptr<BaseEntity>& entity) -> void {
        if (doodler == nullptr || isDoodler(entity)) {
            return;
        }
        processCollision(entity);
    };

    void processCollision(const std::shared_ptr<BaseEntity>&);

    bool doesIntersect(const std::shared_ptr<BaseEntity>&) const;
};