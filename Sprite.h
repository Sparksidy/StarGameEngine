#ifndef SPRITE_H
#define SPRITE_H
#include <stdio.h>
#include <SDL.h>
#include "Component.h"
#include <string>
#include "GameObjectInstance.h"
#include "ResourceManager.h"


class GameObjectInstance;

class Sprite: public Component{

public:
	Sprite():Component(COMPONENT_SPRITE){
		mSurface = NULL;
	}
	
	~Sprite();

	void AddSprite(SDL_Surface* surface);
	
	
	 void Update(){}

	 void Serialize(FILE** fpp);

	 void LoadSprite(char* path);
	

public:
	SDL_Surface* mSurface;

	

};



#endif