#ifndef TEXT_H
#define TEXT_H

#include "GameObject.h"
#include "raylib.h"
#include <string>

enum class HorizontalAlignment
{
    LEFT,
    CENTER,
    RIGHT
};

enum class VerticalAlignment
{
    TOP,
    MIDDLE,
    BOTTOM
};

class Text : public GameObject
{
public:
    Text(const std::string &text, float x, float y, int fontSize, Color color,
         HorizontalAlignment hAlign = HorizontalAlignment::LEFT,
         VerticalAlignment vAlign = VerticalAlignment::TOP,
         int layerIndex = 0);

    void update() override;
    void draw() override;

private:
    std::string text;
    float x, y;
    int fontSize;
    Color color;
    HorizontalAlignment hAlign;
    VerticalAlignment vAlign;
};

#endif // TEXT_H