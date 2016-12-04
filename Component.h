/*
	Abstract class for the components
	GameObjects are composed of components
*/
#ifndef COMPONENT_H
#define COMPONENT_H

#include <stdio.h>
#include "EventManager.h"


enum COMPONENT_TYPE{
	COMPONENT_TRANSFORM,
	COMPONENT_SPRITE,
	COMPONENT_CONTROLLER,
	COMPONENT_BODY,

};

class GameObjectInstance;

class Component{

public:
	Component(unsigned int Type){
		mpOwner = nullptr;
		mType = Type;
	}
	
	virtual void Update()=0;
	virtual void Serialize(FILE **fpp){}
	virtual void HandleEvent(Event* ev){};

	virtual ~Component(){}


public:
	GameObjectInstance* mpOwner;
	unsigned int mType;


};

#endif