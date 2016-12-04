#include "GameObjectInstance.h"

Component* GameObjectInstance::GetComponent(unsigned int mType)
{
	for (auto c : mComponents)
	{
		if (c->mType == mType)
		{
			return c;
		}
		
	}
	
	return NULL;
}

void GameObjectInstance::AddComponent(unsigned int mType)
{
	Component* newComponent = NULL;
	switch (mType)
	{
	case COMPONENT_TRANSFORM:
		newComponent = new Transform();
		break;
	case COMPONENT_SPRITE:
		newComponent = new Sprite();
		break;
	case COMPONENT_CONTROLLER:
		newComponent = new Controller();
		break;
	case COMPONENT_BODY:
		newComponent = new Body();
		break;
	}
	//Push it to the list
	mComponents.push_back(newComponent);

}

void GameObjectInstance::HandleEvent(Event* ev)
{
	for (auto i : mComponents)
	{
		i->HandleEvent(ev);
	}
}