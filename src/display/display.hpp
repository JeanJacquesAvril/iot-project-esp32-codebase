#include <TFT_eSPI.h>

class Display
{

public:
    void init();
    void test();
    void update();

private:
    TFT_eSPI _tft = TFT_eSPI();
    TFT_eSprite _img = TFT_eSprite(&_tft);
    int _i = 0;
};