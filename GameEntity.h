#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <tuple>

class GameEntity {
public:
    GameEntity(int x, int y, char type) : position(std::make_tuple(x, y)), type(type) {}
    std::tuple<int, int> getPos() { return position; }
    char getType() { return type; }
    void setType(char type){this->type = type;} 
    void setPos(int x, int y){position = std::make_tuple(x,y);}
    virtual ~GameEntity() {}

protected:
    std::tuple<int, int> position;
    char type;
};

#endif // GAMEENTITY_H
