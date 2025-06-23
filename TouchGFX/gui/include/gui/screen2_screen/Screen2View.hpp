#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <gui/containers/CustomContainer.hpp>

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void updateGrid(uint16_t matrix[4][4]);
    virtual void resetButtonEvent() override;
protected:
    CustomContainer* containers[4][4];
};

#endif // SCREEN2VIEW_HPP
