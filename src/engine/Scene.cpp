#include "Scene.hpp"

void Scene::init()
{
    for (auto &object : objects)
    {
        object->init();
    }
}

void Scene::update()
{
    for (auto &object : objects)
    {
        object->update();
    }
}

void Scene::draw()
{
    for (auto &object : objects)
    {
        object->draw();
    }
}

void Scene::addObject(const std::shared_ptr<GameObject> &object)
{
    objects.push_back(object);
    std::sort(objects.begin(), objects.end(), [](const std::shared_ptr<GameObject> &a, const std::shared_ptr<GameObject> &b)
              { return a->getLayerIndex() < b->getLayerIndex(); });
}