#include "ResourceManager.h"
#include "SDL_surface.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

ResourceManager::ResourceManager(){


}
ResourceManager::~ResourceManager(){
	for(auto &i : mSurface)
		SDL_FreeSurface(i.second);

	mSurface.clear();

}
SDL_Surface* ResourceManager:: GetSurface(char* path){

	SDL_Surface* pSurfaces = mSurface[path];

	//Found
	if(pSurfaces!= NULL)
		return pSurfaces;
	//Not Found
	pSurfaces = SDL_LoadBMP(path);

	if(pSurfaces != NULL)
		mSurface[path] = pSurfaces;

	return pSurfaces;

}




