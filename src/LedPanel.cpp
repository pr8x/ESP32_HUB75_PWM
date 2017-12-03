#include "LedPanel.h"

namespace ESP32_LED_PANEL
{
    LedPanel::LedPanel(const Config& config)
        : _layer(0), _config(config)
    {
        uint64_t pinMask = (0x1 << config.r1);
        pinMask |= (0x1 << config.g1);
        pinMask |= (0x1 << config.b1);
        pinMask |= (0x1 << config.r2);
        pinMask |= (0x1 << config.g2);
        pinMask |= (0x1 << config.b2);

        _rgbClearMask = pinMask;

        pinMask |= (0x1 << config.A);
        pinMask |= (0x1 << config.B);
        pinMask |= (0x1 << config.C);
        pinMask |= (0x1 << config.D);

        _abcdClearMask = pinMask;

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

    void LedPanel::clear(const Color16& color)
    {
        for(uint8_t y = 0; y < Height; ++y) 
            for(uint8_t x = 0; x < Width; ++x) 
                _buffer[x][y] = color;
    }

    void LedPanel::setColor(
        const uint8_t x,
        const uint8_t y,
        const Color16& color)
    {
        _buffer[x][y] = color;
    }

    void LedPanel::update()
    {
        for(uint8_t y = 0; y < Height / 2; ++y)
        {
            for(uint8_t x = 0; x < Width; ++x) 
            {
                _mask = 0x0;

                //R1,G1,B1
                if (_buffer[x][y].r() > _layer)
                    _mask |= 0x1 << _config.r1;

                if (_buffer[x][y].g() > _layer)
                    _mask |= 0x1 << _config.g1;

                if (_buffer[x][y].b() > _layer)
                    _mask |= 0x1 << _config.b1;

                //R2,G2,B2
                if (_buffer[x][y + Height / 2].r() > _layer)
                    _mask |= 0x1 << _config.r2;

                if (_buffer[x][y + Height / 2].g() > _layer)
                    _mask |= 0x1 << _config.g2;

                if (_buffer[x][y + Height / 2].b() > _layer)
                    _mask |= 0x1 << _config.b2;

                GPIO.out_w1tc = _rgbClearMask;
                GPIO.out_w1ts = _mask;

                GPIO.out_w1ts = (0x1 << _config.CLK);
                GPIO.out_w1tc = (0x1 << _config.CLK);
            }

            _mask = 0x0;

            if(y & 0x1)
                _mask |= 0x1 << _config.A;
            if(y & 0x2)
                _mask |= 0x1 << _config.B;
            if(y & 0x4)
                _mask |= 0x1 << _config.C;
            if(y & 0x8)
                _mask |= 0x1 << _config.D;

            GPIO.out_w1tc = _abcdClearMask;
            GPIO.out_w1ts = _mask;

            GPIO.out_w1ts = (0x1 << _config.LAT);
            GPIO.out_w1tc = (0x1 << _config.LAT);
        }

        if (_layer++ > 14) 
            _layer = 0;
    }
}