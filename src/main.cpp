#include <stdio.h>
#include "LedPanel.h"

using namespace ESP32_LED_PANEL;

extern "C" void app_main()
{
    // printf("Hello world!\n");
    // fflush(stdout);

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

    LedPanel panel(panelSetup);

    for(;;) 
    {
      panel.update();
    }
}