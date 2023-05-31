#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "GameEntity.h"
#include "Effect.h"

class Explosion : public GameEntity, public Effect {
public:
    Explosion(int x, int y) : GameEntity(x, y, 'E') {}
    void apply(GameEntity& entity) override {
        entity.setType('X');
        entity.setPos(-1,-1);
        
    }
};

#endif // EXPLOSION_H
