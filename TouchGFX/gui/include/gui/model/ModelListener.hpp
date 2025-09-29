#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <stdint.h>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void processJoystick(uint16_t x, uint16_t y) {}
    virtual void updateMatrix(uint16_t matrix[4][4]) {}
    virtual void updateScore(uint32_t score, uint32_t highscore) {}
    virtual void onGameOver() {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
