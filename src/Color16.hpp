#pragma once

namespace ESP32_LED_PANEL 
{
    class Color16
    {
    public:
        static constexpr uint16_t rmask = 0b0000000000001111;
        static constexpr uint16_t gmask = 0b0000000011110000;
        static constexpr uint16_t bmask = 0b0000111100000000;
  
        inline Color16()
          : _val(0) {
        }
  
        inline Color16(const uint16_t r, const uint16_t g, const uint16_t b)
          : Color16()
        {
            _val |= r;
            _val |= (g << 4);
            _val |= (b << 8);
        }
  
        inline uint16_t r() const {
            return _val & rmask;
        }
  
        inline uint16_t g() const {
            return (_val & gmask) >> 4;
        }
  
        inline uint16_t b() const {
            return (_val & bmask) >> 8;
        }
  
        inline uint16_t value() const {
            return _val;
        }
  
    private:
        uint16_t _val;
    };
}