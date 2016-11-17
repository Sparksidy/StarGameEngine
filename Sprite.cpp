#include "Sprite.h"



Sprite::~Sprite(){


}

void Sprite::AddSprite(SDL_Surface* surface){
	mSurface = surface;

}


void Sprite::Serialize(FILE** fpp)
{
	char spriteFileName[256];
	memset(spriteFileName, 0, 256 * sizeof(char));
	//Reading file location and storing them in the component
	fscanf(*fpp, "%s",spriteFileName);
	LoadSprite(spriteFileName);
	
}

void Sprite::LoadSprite(char* path)
{
	
	ResourceManager* rm = new ResourceManager();
	mSurface = rm->GetSurface(path);
	


}

			



 

