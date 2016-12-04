#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include "GameObjectInstance.h"
#include <vector>

class GameObjectManager{
public:
	GameObjectManager()
	{
	}
	~GameObjectManager()
	{

	}
	GameObjectInstance* LoadObject(char* filePath);
	void LoadLevel(char* Levelpath);
	
	
public:
	
	std::vector<GameObjectInstance *> mGameObjects;
	

};

#endif