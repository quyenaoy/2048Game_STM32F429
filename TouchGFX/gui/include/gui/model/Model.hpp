#ifndef MODEL_HPP
#define MODEL_HPP

#include <stdint.h>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void setJoystickValues(uint16_t x, uint16_t y);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void initBoard();
    void resetGame(); // reset lại ma trận và sinh 2 số 2 ngẫu nhiên
    uint16_t joyX = 0;
    uint16_t joyY = 0;
    uint16_t matrix[4][4];

//    void initBoard();

    void spawnRandomTile(); // tạo ô mới

protected:
    ModelListener* modelListener;

private:

};

#endif // MODEL_HPP
