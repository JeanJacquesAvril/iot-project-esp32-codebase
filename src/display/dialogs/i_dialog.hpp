#include <TFT_eSPI.h>
namespace Dialogs
{
    class IDialog
    {
    public:
        IDialog(TFT_eSPI &tft) : _sprite(TFT_eSprite(&tft)){};
        virtual bool shouldUpdate();
        void draw()
        {
            _sprite.pushSprite(_x, _y);
        };
        void setCoordinates(u_int16_t x, u_int16_t y)
        {
            this->_x = x;
            this->_y = y;
        }

    protected:
        TFT_eSprite _sprite;
        u_int16_t _x;
        u_int16_t _y;
        u_int _delay;
    };

}