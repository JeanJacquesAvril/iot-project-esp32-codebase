#include <Adafruit_NeoPixel.h>
#include "animations/rainbow.hpp"
#define PIN 13
struct AnimationQueueItem
{
    Animations::IAnimation *animation;
    AnimationQueueItem *next = nullptr;
    ~AnimationQueueItem()
    {
        // free(animation);
        delete animation;
    }
};
class Led
{
public:
    void init();
    void update();
    void off();
    /*!
    @brief Sets the brightness of the LEDs
    @param level value between 0=off and 255=max
    */
    void setBrightness(u_int8_t level);
    void queueAnimation(Animations::IAnimation *animation);
    void clearQueue();
    void setSingleColor();
    void setRainbow();

    void resetAnimation();
    void stopAnimation();
    void resumeAnimation();

private:
    AnimationQueueItem *queue = nullptr;
    Adafruit_NeoPixel strip = Adafruit_NeoPixel(20, PIN, NEO_GRB + NEO_KHZ800);
    unsigned long next_update = 0;
};