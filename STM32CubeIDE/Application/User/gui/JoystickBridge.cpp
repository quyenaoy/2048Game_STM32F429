#include "JoystickBridge.hpp"
#include <stdint.h>
#include <gui/common/FrontendApplication.hpp>

extern "C" void setJoystickFromMain(uint16_t x, uint16_t y)
{
    FrontendApplication* app = static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    app->getModel()->setJoystickValues(x, y);
}
