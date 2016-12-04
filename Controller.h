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
#include "EventManager.h"

//class GameObjectInstance;
extern InputManager* gpInputManager;

class PlayerHitEvent : public Event
{
public:
	PlayerHitEvent() :Event(EVENT_TYPE::PLAYER_HIT)
	{

	}
	~PlayerHitEvent(){};
};


class Controller: public Component{

public:
	Controller();
	void DoMovement();
	void Update();
	void Serialize(FILE** fpp);
	void HandleEvent(Event* ev);

	~Controller();
public:
	//InputManager* mpIM;
	float speed;

};


#endif