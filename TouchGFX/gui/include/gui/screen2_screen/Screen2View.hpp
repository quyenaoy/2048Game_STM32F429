#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <gui/containers/CustomContainer.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void updateGrid(uint16_t matrix[4][4]);
    virtual void resetButtonEvent() override;
    virtual void updateScore(uint32_t score, uint32_t highscore);
    virtual void onGameOver();
protected:
    CustomContainer* containers[4][4];
    Unicode::UnicodeChar highScoreBuffer[16];
    Unicode::UnicodeChar scoreBuffer[16];
    bool showGameOver = false;
    touchgfx::Box gameOverBox;
    // Sử dụng TextArea thường, không dùng Unicode đặc biệt
    touchgfx::TextArea gameOverText;
    // Buffer cho text cứng (ASCII)
    char gameOverMsg[32];
};

#endif // SCREEN2VIEW_HPP
