#ifndef SCENE_H
#define SCENE_H

#include "GameObject.hpp"
#include <vector>
#include <memory>
#include <algorithm>

class Scene
{
public:
    virtual ~Scene() = default;
    virtual void init();
    virtual void update();
    virtual void draw();
    void addObject(const std::shared_ptr<GameObject> &object);

protected:
    std::vector<std::shared_ptr<GameObject>> objects;
};

#endif // SCENE_H
