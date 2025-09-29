#include <gui/screen2_screen/Screen2View.hpp>
#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <touchgfx/Unicode.hpp>
#include <string.h>
#include <touchgfx/Color.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/TypedText.hpp>

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();

    // Test trực tiếp wildcard với chuỗi số Unicode để xác định lỗi font/cấu hình
    static const touchgfx::Unicode::UnicodeChar testNum[] = { '1', '2', '3', '4', 0 };
    HighScore.setWildcard(testNum);
    HighScore.invalidate();
    Score.setWildcard(testNum);
    Score.invalidate();

    // Khởi tạo buffer và gán cho wildcard để tránh lỗi ???
    touchgfx::Unicode::snprintf(highScoreBuffer, 16, "%d", 0);
    HighScore.setWildcard(highScoreBuffer);
    touchgfx::Unicode::snprintf(scoreBuffer, 16, "%d", 0);
    Score.setWildcard(scoreBuffer);

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

void Screen2View::updateScore(uint32_t score, uint32_t highscore)
{
    memset(highScoreBuffer, 0, sizeof(highScoreBuffer));
    touchgfx::Unicode::snprintf(highScoreBuffer, 16, "%d", (int)highscore);
    HighScore.setWildcard(highScoreBuffer);
    HighScore.invalidate();
    memset(scoreBuffer, 0, sizeof(scoreBuffer));
    touchgfx::Unicode::snprintf(scoreBuffer, 16, "%d", (int)score);
    Score.setWildcard(scoreBuffer);
    Score.invalidate();
}

void Screen2View::onGameOver()
{
    // Không làm gì cả, đã xóa phần hiển thị game over
}
