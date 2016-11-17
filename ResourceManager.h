#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>
#include <unordered_map>
#include "GameObjectInstance.h"

struct SDL_Surface;

class ResourceManager{

public:
	ResourceManager();
	~ResourceManager();

	SDL_Surface *GetSurface(char* path);

public:
	std::unordered_map<std::string, SDL_Surface*>mSurface;


};



#endif