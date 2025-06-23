#include <gui/screen2_screen/Screen2View.hpp>

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();

    // Gán container từ màn hình thiết kế
        containers[0][0] = &customContainer11;
        containers[0][1] = &customContainer12;
        containers[0][2] = &customContainer13;
        containers[0][3] = &customContainer14;
        containers[1][0] = &customContainer21;
        containers[1][1] = &customContainer22;
        containers[1][2] = &customContainer23;
        containers[1][3] = &customContainer24;
        containers[2][0] = &customContainer31;
        containers[2][1] = &customContainer32;
        containers[2][2] = &customContainer33;
        containers[2][3] = &customContainer34;
        containers[3][0] = &customContainer41;
        containers[3][1] = &customContainer42;
        containers[3][2] = &customContainer43;
        containers[3][3] = &customContainer44;
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::updateGrid(uint16_t matrix[4][4])
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            containers[i][j]->setNumber(matrix[i][j]); // tự viết hàm này trong CustomContainer
}

void Screen2View::resetButtonEvent()
{
    presenter->onNewGameButtonPressed();
}
