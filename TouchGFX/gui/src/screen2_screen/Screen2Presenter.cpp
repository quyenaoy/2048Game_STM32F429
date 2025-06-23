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
	const uint16_t THRESHOLD = 20;
	    if (x < 128 - THRESHOLD) model->moveLeft();
	    else if (x > 128 + THRESHOLD) model->moveRight();
	    else if (y < 128 - THRESHOLD) model->moveUp();
	    else if (y > 128 + THRESHOLD) model->moveDown();

}

void Screen2Presenter::updateMatrix(uint16_t matrix[4][4])
{
    view.updateGrid(matrix);
}

void Screen2Presenter::onNewGameButtonPressed()
{
    if (model) {
        model->resetGame();
    }
}
