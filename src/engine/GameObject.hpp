#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
public:
    virtual ~GameObject() = default;
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    int getLayerIndex() const { return layerIndex; }

protected:
    GameObject(int layerIndex = 0) : layerIndex(layerIndex) {}

private:
    int layerIndex;
};

#endif // GAMEOBJECT_H