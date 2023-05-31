#ifndef EFFECT_H
#define EFFECT_H

class GameEntity; // Forward declaration

class Effect {
public:
    virtual void apply(GameEntity& entity) = 0;
};

#endif // EFFECT_H
