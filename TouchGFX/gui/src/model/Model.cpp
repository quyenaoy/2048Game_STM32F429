#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string.h>
#include "main.h"
#include <cstdio>
#include <stm32f4xx_hal.h>

// ====== Joystick Queue extern ======
extern volatile JoystickDir joystickQueue;
extern volatile uint8_t joystickBusy;

Model::Model() : modelListener(0)
{
    srand(HAL_GetTick());
    spawnRandomTile();
    spawnRandomTile();

}

void Model::tick()
{
    // Chỉ xử lý khi không busy và queue có hướng
    if (!joystickBusy && joystickQueue != JOY_NONE)
    {
        joystickBusy = 1;
        switch (joystickQueue)
        {
            case JOY_LEFT: moveLeft(); break;
            case JOY_RIGHT: moveRight(); break;
            case JOY_UP: moveUp(); break;
            case JOY_DOWN: moveDown(); break;
            default: break;
        }
        joystickQueue = JOY_NONE; // Xóa queue sau khi xử lý
    }

    // Nhưng sau đó Model phải cập nhật view nếu game thay đổi
    if (modelListener)
        modelListener->updateMatrix(matrix);         // bắt buộc phải có nếu matrix thay đổi
    // Sau khi update xong, cho phép nhận hướng mới
    joystickBusy = 0;
}

void Model::setJoystickValues(uint16_t x, uint16_t y)
{
    joyX = x;
    joyY = y;
}


// ===== Hàm sinh ô số ngẫu nhiên =====

void Model::spawnRandomTile()
{
    int emptyCount = 0;
    int emptyCells[16][2];

    // Tìm ô trống
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (matrix[i][j] == 0)
                emptyCells[emptyCount][0] = i, emptyCells[emptyCount++][1] = j;

    if (emptyCount == 0) return;

    int index = rand() % emptyCount;
    int row = emptyCells[index][0];
    int col = emptyCells[index][1];

    matrix[row][col] = (rand() % 10 < 9) ? 2 : 4; // 90% là 2, 10% là 4
}



void Model::moveLeft()
{
    bool moved = false;
    for (int i = 0; i < 4; ++i)
    {
        int merged[4] = {0};
        for (int j = 1; j < 4; ++j)
        {
            if (matrix[i][j] == 0) continue;
            int col = j;
            while (col > 0 && matrix[i][col - 1] == 0)
            {
                matrix[i][col - 1] = matrix[i][col];
                matrix[i][col] = 0;
                --col;
                moved = true;
            }
            if (col > 0 && matrix[i][col - 1] == matrix[i][col] && !merged[col - 1])
            {
                matrix[i][col - 1] *= 2;
                matrix[i][col] = 0;
                merged[col - 1] = 1;
                moved = true;
            }
        }
    }
    if (moved)
        spawnRandomTile();
}

void Model::moveUp()
{
    bool moved = false;
    for (int j = 0; j < 4; ++j)
    {
        int merged[4] = {0};
        for (int i = 1; i < 4; ++i)
        {
            if (matrix[i][j] == 0) continue;
            int row = i;
            while (row > 0 && matrix[row - 1][j] == 0)
            {
                matrix[row - 1][j] = matrix[row][j];
                matrix[row][j] = 0;
                --row;
                moved = true;
            }
            if (row > 0 && matrix[row - 1][j] == matrix[row][j] && !merged[row - 1])
            {
                matrix[row - 1][j] *= 2;
                matrix[row][j] = 0;
                merged[row - 1] = 1;
                moved = true;
            }
        }
    }
    if (moved)
        spawnRandomTile();
}

void Model::moveRight()
{
    bool moved = false;
    for (int i = 0; i < 4; ++i)
    {
        int merged[4] = {0};
        for (int j = 2; j >= 0; --j)
        {
            if (matrix[i][j] == 0) continue;
            int col = j;
            while (col < 3 && matrix[i][col + 1] == 0)
            {
                matrix[i][col + 1] = matrix[i][col];
                matrix[i][col] = 0;
                ++col;
                moved = true;
            }
            if (col < 3 && matrix[i][col + 1] == matrix[i][col] && !merged[col + 1])
            {
                matrix[i][col + 1] *= 2;
                matrix[i][col] = 0;
                merged[col + 1] = 1;
                moved = true;
            }
        }
    }
    if (moved)
        spawnRandomTile();
}

void Model::moveDown()
{
    bool moved = false;
    for (int j = 0; j < 4; ++j)
    {
        int merged[4] = {0};
        for (int i = 2; i >= 0; --i)
        {
            if (matrix[i][j] == 0) continue;
            int row = i;
            while (row < 3 && matrix[row + 1][j] == 0)
            {
                matrix[row + 1][j] = matrix[row][j];
                matrix[row][j] = 0;
                ++row;
                moved = true;
            }
            if (row < 3 && matrix[row + 1][j] == matrix[row][j] && !merged[row + 1])
            {
                matrix[row + 1][j] *= 2;
                matrix[row][j] = 0;
                merged[row + 1] = 1;
                moved = true;
            }
        }
    }
    if (moved)
        spawnRandomTile();
}
