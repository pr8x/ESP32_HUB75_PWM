//FreeRTOS/ESPIDF
#pragma once
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"

#include "Color16.hpp"

namespace ESP32_LED_PANEL
{
	class LedPanel
	{
	public:
		struct Config
  		{
	      gpio_num_t r1;
	      gpio_num_t g1;
	      gpio_num_t b1;
	      gpio_num_t r2;
	      gpio_num_t g2;
	      gpio_num_t b2;
	      gpio_num_t A;
	      gpio_num_t B;
	      gpio_num_t C;
	      gpio_num_t D;
	      gpio_num_t LAT;
	      gpio_num_t OE;
	      gpio_num_t CLK;
  		};

  		LedPanel(const Config& config);
  		~LedPanel();

  		void update();

  	private:
  		Config _config;
	};
}