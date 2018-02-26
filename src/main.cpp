#include <stdio.h>
#include "LedPanel.h"
#include <cmath>

using namespace ESP32_LED_PANEL;

extern "C" void app_main()
{
    LedPanel::Config panelSetup;
    panelSetup.r1 = GPIO_NUM_23;
    panelSetup.g1 = GPIO_NUM_22;
    panelSetup.b1 = GPIO_NUM_1;

    panelSetup.r2 = GPIO_NUM_3;
    panelSetup.g2 = GPIO_NUM_21;
    panelSetup.b2 = GPIO_NUM_19;

    panelSetup.A = GPIO_NUM_18;
    panelSetup.B = GPIO_NUM_5;
    panelSetup.C = GPIO_NUM_17;
    panelSetup.D = GPIO_NUM_16;

    panelSetup.LAT = GPIO_NUM_4;
    panelSetup.CLK = GPIO_NUM_2;
    panelSetup.OE  = GPIO_NUM_15;

    auto panel = new LedPanel(panelSetup);

    //DEMO
    panel->clear({0,0,0});
    for(uint8_t y = 0; y < LedPanel::Height; ++y) {
      for(uint8_t x = 0; x < LedPanel::Width; ++x) {
        panel->setColor(x,y, {uint16_t(std::ceil(std::sin(x)) * 15), uint16_t(std::ceil(std::cos(y)) * 15), 0});
      }
    }

    for(;;) {
      panel->update();
    }
}