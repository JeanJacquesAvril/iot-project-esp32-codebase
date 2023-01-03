#include "display.hpp"
#include <TFT_eSPI.h>
void Display::init()
{
    _tft.init();
    _tft.setRotation(0);
    _tft.fillScreen(TFT_BLACK);
    Serial.println("Display started!");
}

void Display::test()
{
    _img.drawRect(4, 4, 120, 120, TFT_RED);
    _img.setFreeFont(&FreeMono9pt7b); // Select free font
    _img.setTextSize(1);
    // tft.setTextColor(TFT_WHITE);
    _img.setCursor(0, 9);
    _img.println("hallo Welt");
    _img.setCursor(5, 128);
    _img.println("Super duper");
    _img.drawPixel(127, 127, TFT_RED);
    _img.drawPixel(0, 0, TFT_RED);
    int x = 0;
    while (x < 128)
    {
        _tft.drawPixel(127 - x, x, TFT_DARKCYAN);
        x++;
    }
}

void Display::update()
{

    _i++;
    _img.setTextColor(TFT_RED, TFT_BLACK, true);
    _img.setTextFont(0);
    _img.setCursor(12, 128 / 2 - 6);

    _img.println(_i);
    // sleep(1);
    _img.pushSprite(0, 0);
}