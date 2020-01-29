
#ifndef STRIP_H
#define STRIP_H

#include "colors.h"
#include "cyclehandler.h"

class StripShowAction : public Action
{
public:
    StripShowAction(Strip* strip);

    CallbackStatus call();

protected:
    Strip* m_strip;
};

class Strip
{
public:
    Strip(ColorPin* pins);

    void move_towards(double* colors);

    void show();
    void hide();
    void clear();

protected:
    ColorPin* m_pins;

    bool m_shown;
    friend class StripShowAction;

    static const uint8_t num_pins = 3;
};

class RGBStrip : public Strip
{
public:
    using Strip::Strip;

    void commit_rgb(RGB rgb);

    void set_rgb(RGB rgb);
    void set_hsv(uint16_t hue, double sat, double val);

protected:
    static const uint8_t num_pins = 3;
};

class RGBWStrip : public RGBStrip
{
public:
    using RGBStrip::RGBStrip;

    void commit_rgbw(RGBW rgbw);

    void set_rgbw(RGBW rgbw);
    void set_hsv(uint16_t hue, double sat, double val);

protected:
    static const uint8_t num_pins = 4;
};

#endif // STRIP_H