#include "rainbow.hpp"
namespace Animations
{
    void Rainbow::update(Adafruit_NeoPixel &strip)
    {
        for (i = 0; i < strip.numPixels(); i++)
        {
            strip.setPixelColor(i, Wheel((i + j) & 255, strip));
        }
        strip.show();
        j++;
        if (j >= 256)
        {
            j = 0;
            _current_cycle++;
        }
    }

    // Input a value 0 to 255 to get a color value.
    // The colours are a transition r - g - b - back to r.
    uint32_t Rainbow::Wheel(byte WheelPos, Adafruit_NeoPixel &strip)
    {
        WheelPos = 255 - WheelPos;
        if (WheelPos < 85)
        {
            return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
        }
        if (WheelPos < 170)
        {
            WheelPos -= 85;
            return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
        }
        WheelPos -= 170;
        return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    }
}
