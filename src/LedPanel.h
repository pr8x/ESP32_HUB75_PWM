#pragma once

extern "C" {
	#include "freertos/FreeRTOS.h"
	#include "freertos/task.h"
	#include "esp_system.h"
	#include "esp_spi_flash.h"
    #include "driver/gpio.h"
}

#include "Color16.hpp"

namespace ESP32_LED_PANEL
{
	class LedPanel
	{
	public:
		static constexpr uint8_t Width = 64;
		static constexpr uint8_t Height = 32;

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

  		void clear(const Color16& color);
  		void setColor(const uint8_t x, const uint8_t y, const Color16& color);
  		void update();

  	private:
		uint32_t _mask;
  		uint32_t _layer;
  		uint32_t _abcdClearMask;
  		uint32_t _rgbClearMask;
  		Color16 _buffer[64][32];
  		Config _config;
	};
}