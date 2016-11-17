/*
Controlling the movement of any GameObject

*/



#ifndef CONTROLLER_H
#define CONTROLLER_H

//#include "Component.h"

//#include "GameObjectInstance.h"
#include "Component.h"
#include "InputManager.h"
#include <stdio.h>

//class GameObjectInstance;
extern InputManager* gpInputManager;


class Controller: public Component{

public:
	Controller();
	void DoMovement();
	void Update();
	void Serialize(FILE** fpp);

	~Controller();
public:
	//InputManager* mpIM;
	float speed;

};


#endif