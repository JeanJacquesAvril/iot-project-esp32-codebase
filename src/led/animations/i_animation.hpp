namespace Animations
{
    class IAnimation
    {
    public:
        // /*!
        // @brief initializes the animation
        // @param strip the Adafruit_NeoPixel that displays the animation
        // */
        // IAnimation();
        /*!
        @brief   executes the next animation cycle
        */
        virtual void update(Adafruit_NeoPixel &strip);
        bool pendingCycle()
        {
            return _max_cycles == 0 || _max_cycles > _current_cycle;
        }
        void setCycles(unsigned int cycles)
        {
            this->_max_cycles = cycles;
        }
        void setCycleDelay(u_int delay)
        {
            this->_delay = delay;
        }
        u_int getCycleDelay()
        {
            return _delay;
        }

    protected:
        unsigned int _current_cycle = 0;
        unsigned int _max_cycles = 0;
        u_int _delay = 80;
    };
}