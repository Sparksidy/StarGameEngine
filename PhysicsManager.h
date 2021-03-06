#ifndef PHYSICS_MANAGER_H
#define PHYSICS_MANAGER_H
#include "GameObjectManager.h"

class CollideEvent : public Event
{
public:

	CollideEvent() :Event(EVENT_TYPE::COLLIDE)
	{

	}

public:

	GameObjectInstance* pObj1;
	GameObjectInstance* pObj2;

};

class PhysicsManager{

public:
	PhysicsManager();
	~PhysicsManager();
	void Integrate(float deltaTime, float gravity, GameObjectManager* pGameObjManager);


};

#endif