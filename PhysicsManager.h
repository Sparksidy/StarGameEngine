#ifndef PHYSICS_MANAGER_H
#define PHYSICS_MANAGER_H
#include "GameObjectManager.h"

class PhysicsManager{

public:
	PhysicsManager();
	~PhysicsManager();
	void Integrate(float deltaTime, float gravity, GameObjectManager* pGameObjManager);


};

#endif