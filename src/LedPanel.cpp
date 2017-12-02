#include "LedPanel.h"

namespace ESP32_LED_PANEL
{
	LedPanel::LedPanel(const Config& config)
		: _config(config)
	{
		uint64_t pinMask = 0;
		pinMask |= (0x1 << config.r1);
		pinMask |= (0x1 << config.g1);
		pinMask |= (0x1 << config.b1);

		pinMask |= (0x1 << config.r2);
		pinMask |= (0x1 << config.g2);
		pinMask |= (0x1 << config.b2);

		pinMask |= (0x1 << config.A);
		pinMask |= (0x1 << config.B);
		pinMask |= (0x1 << config.C);
		pinMask |= (0x1 << config.D);
		pinMask |= (0x1 << config.LAT);
		pinMask |= (0x1 << config.OE);
		pinMask |= (0x1 << config.CLK);

	    gpio_config_t io_conf;
	    io_conf.intr_type = GPIO_INTR_DISABLE;
	    io_conf.mode = GPIO_MODE_OUTPUT;
	    io_conf.pin_bit_mask = pinMask;
	    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
	    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
	    gpio_config(&io_conf);
	}

	LedPanel::~LedPanel()
	{
	}

	void LedPanel::update()
	{
		//just a dirty quick demo...
		// {
		// 	gpio_num_t* p = reinterpret_cast<gpio_num_t*>(&_config);
		// 	int i = 0;
		// 	while (i++ != 13) gpio_set_level(*p++, 1);
		// }

		// vTaskDelay(1000/portTICK_PERIOD_MS);

		// {
		// 	gpio_num_t* p = reinterpret_cast<gpio_num_t*>(&_config);
		// 	int i = 0;
		// 	while (i++ != 13) gpio_set_level(*p++, 0);
		// }

		// vTaskDelay(1000/portTICK_PERIOD_MS);


		
	}
}