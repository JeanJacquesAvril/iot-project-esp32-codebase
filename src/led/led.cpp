#include "led.hpp"

using namespace Animations;
void Led::init()
{
    strip.begin();
    strip.setBrightness(10);
    // strip.show(); // Initialize all pixels to 'off'
    auto animation = new Rainbow();
    animation->setCycles(5);
    animation->setCycleDelay(10);
    queueAnimation(animation);
}
void Led::update()
{
    if (queue == nullptr || next_update > millis())
    {
        return;
    }
    IAnimation *animation = queue->animation;
    if (animation->pendingCycle())
    {
        animation->update(strip);
        next_update = millis() + animation->getCycleDelay();
    }
    else
    {
        AnimationQueueItem *temp = queue;
        queue = temp->next;
        delete temp;
        if (queue == nullptr)
            off();
        next_update = 0;
    }
}
void Led::queueAnimation(IAnimation *animation)
{
    AnimationQueueItem *new_animation = new AnimationQueueItem{};
    new_animation->animation = animation;
    if (queue == nullptr)
    {
        queue = new_animation;
    }
    else
    {
        AnimationQueueItem *last;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = new_animation;
    }
}

void Led::clearQueue()
{
    AnimationQueueItem *tempQueue = queue;
    queue = nullptr;
    while (tempQueue != nullptr)
    {
        AnimationQueueItem *temp = tempQueue;
        tempQueue = temp->next;
        delete temp;
    }
}
void Led::off()
{
    strip.clear();
    strip.show();
}
void Led::setBrightness(uint8_t level)
{
    strip.setBrightness(level);
}
void Led::setSingleColor() {}
void Led::setRainbow() {}
void Led::resetAnimation() {}
void Led::stopAnimation() {}
void Led::resumeAnimation() {}
