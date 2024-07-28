#include "Text.h"

Text::Text(const std::string &text, float x, float y, int fontSize, Color color,
           HorizontalAlignment hAlign, VerticalAlignment vAlign, int layerIndex)
    : GameObject(layerIndex), text(text), x(x), y(y), fontSize(fontSize), color(color), hAlign(hAlign), vAlign(vAlign) {}

void Text::update()
{
    // No update logic for static text
}

void Text::draw()
{
    int textWidth = MeasureText(text.c_str(), fontSize);
    int textHeight = fontSize; // Assuming height is approximately equal to font size
    float drawX = x;
    float drawY = y;

    switch (hAlign)
    {
    case HorizontalAlignment::CENTER:
        drawX -= textWidth / 2.0f;
        break;
    case HorizontalAlignment::RIGHT:
        drawX -= textWidth;
        break;
    case HorizontalAlignment::LEFT:
    default:
        break;
    }

    switch (vAlign)
    {
    case VerticalAlignment::MIDDLE:
        drawY -= textHeight / 2.0f;
        break;
    case VerticalAlignment::BOTTOM:
        drawY -= textHeight;
        break;
    case VerticalAlignment::TOP:
    default:
        break;
    }

    DrawText(text.c_str(), static_cast<int>(drawX), static_cast<int>(drawY), fontSize, color);
}