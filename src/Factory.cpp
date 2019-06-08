#include "Factory.hh"
#include "Drone.hh"
#include "Obstacle.hh"

Factory* Factory::Instance = nullptr;

Factory *Factory::getInstance()
{
    if(Instance==nullptr)
        Instance = new Factory();
    return Instance;
}

shared_ptr<SceneObject> Factory::CreateObject(Type T)
{
    switch(T)
    {
        case RO_Drone:  {shared_ptr<SceneObject> object = Drone::CreateDrone();    return object;}
        case RO_Obstacle: {shared_ptr<SceneObject> object = Obstacle::CreateObstacle();     return object;}
    }
    return nullptr;
}