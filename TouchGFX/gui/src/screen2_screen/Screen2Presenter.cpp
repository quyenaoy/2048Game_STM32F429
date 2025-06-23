#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

Screen2Presenter::Screen2Presenter(Screen2View& v)
    : view(v)
{

}

void Screen2Presenter::activate()
{

}

void Screen2Presenter::deactivate()
{

}

void Screen2Presenter::processJoystick(uint16_t x, uint16_t y)
{
    const int center = 128;
    const int threshold = 0;

    if (x < center - threshold)
    {
        model->moveLeft();
    }else if (x > center + threshold)
    {
    	model->moveRight();
    }else if (y < center - threshold)
    {
        model->moveUp();
    }
    else if (y > center + threshold)
    {
    	model->moveDown();
    }

}

void Screen2Presenter::updateMatrix(uint16_t matrix[4][4])
{
    view.updateGrid(matrix);
}
