#include <Adafruit_NeoPixel.h>
#include "i_animation.hpp"
namespace Animations
{
    class Rainbow : public IAnimation
    {
    public:
        void update(Adafruit_NeoPixel &strip);
        uint32_t Wheel(byte WheelPos, Adafruit_NeoPixel &strip);

    private:
        uint16_t i = 0, j = 0;
    };
}