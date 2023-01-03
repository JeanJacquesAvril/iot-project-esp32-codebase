#include "i_dialog.hpp"
namespace Dialogs
{
    class Reservation : IDialog
    {
    public:
        Reservation(TFT_eSPI &tft) : IDialog(tft)
        {
            _sprite.createSprite(128, 128);
            _x = 0;
            _y = 0;
        };
        void setName(String name)
        {
            this->_name = name;
        }
        void setTimeSlot(uint8_t start_h, uint8_t start_m, uint8_t end_h, uint8_t end_m)
        {
            this->_start_h = start_h;
            this->_start_m = start_m;
            this->_end_h = end_h;
            this->_end_m = end_m;
        }
        void setAvailable(bool available)
        {
            this->_available = available;
        }
        void update()
        {
            _sprite.fillRect(0, 0, 127, 127, TFT_BLACK);
            _sprite.drawRoundRect(3, 3, 127 - 6, 127 - 6, 8, TFT_ORANGE);
            _sprite.drawLine(3, 20, 127 - 3, 20, TFT_ORANGE);

            _sprite.drawString(_available ? "Frei" : "Reserviert", 5, 20);
            String start = _start_h + ":" + _start_m;
            String end = _end_h + ":" + _end_m;
        }

    private:
        bool _available = true;
        String _name = "Mustermann";
        uint8_t _start_h;
        uint8_t _start_m;
        uint8_t _end_h;
        uint8_t _end_m;
    };
} // namespace Dialogs
