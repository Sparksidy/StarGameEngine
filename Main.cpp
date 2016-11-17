#include <SDL.h>
#include "stdio.h"
#include "InputManager.h"
#include "FrameRateController.h"
#include "windows.h"
#include "ResourceManager.h"
#include "Sprite.h"
#include "Transform.h"
#include "GameObjectInstance.h"
#include "GameObjectManager.h"
#include "Controller.h"
#include "PhysicsManager.h"
#include "CollisionManager.h"


//For File import
#include "stdio.h"
#include "string.h"
#include "matrix.h"

CollisionManager* gpCollisionManager;
InputManager* gpInputManager;

//Function Prototypes

int main(int argc, char* args[])
{
	if(AllocConsole()){
		FILE* file;

		freopen_s(&file, "CONOUT$", "wt", stdout);
		freopen_s(&file, "CONOUT$", "wt", stderr);
		freopen_s(&file, "CONOUT$", "wt", stdin);
		

		SetConsoleTitle(L"Engine");

	}

	SDL_Window *pWindow;
	int error = 0;
	bool appIsRunning = true;
	SDL_Surface* pWindowSurface = NULL;


	

	//Managers
	gpInputManager = new InputManager();
	ResourceManager* rm = new ResourceManager();
	Controller* cm = new Controller();
	FrameRateController* pF = new FrameRateController(30);
	GameObjectManager* gOM = new GameObjectManager();
	PhysicsManager* PM = new PhysicsManager();
	

	gpCollisionManager = new CollisionManager();
	

	// Initialize SDL
	if((error = SDL_Init( SDL_INIT_VIDEO )) < 0 )
	{
		printf("Couldn't initialize SDL, error %i\n", error);
		return 1;
	}

	pWindow = SDL_CreateWindow("SDL2 window",		// window title
		SDL_WINDOWPOS_UNDEFINED,					// initial x position
		SDL_WINDOWPOS_UNDEFINED,					// initial y position
		800,										// width, in pixels
		600,										// height, in pixels
		SDL_WINDOW_SHOWN);

	// Check that the window was successfully made
	if (NULL == pWindow)
	{
		// In the event that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	//Get the window surface
	pWindowSurface = SDL_GetWindowSurface(pWindow);


	//load the paricular object
	//LoadObject(pInst,rm);

	//Resource Manager loads the object
	//rm->LoadObject(pInst);
	

	gOM->LoadLevel("level1.txt");
	//gOM->LoadObject("file2.txt");
	

			
	//Update the surface
	SDL_UpdateWindowSurface(pWindow);

	// Game loop
	while(true == appIsRunning)
	{
		
		pF->FrameStart();

		
		SDL_Event e;
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				appIsRunning = false;
			}
			
		}
		//Update Loop
		for (GameObjectInstance* pObj :gOM->mGameObjects)
		{
			for (auto i : pObj->mComponents)
			{
				i->Update();
			}
			

		}
		
		//Physics manager 
		PM->Integrate(pF->GetFrameTime(), 1.0f, gOM);

		

		//Clears the surface
		SDL_FillRect(pWindowSurface, NULL, 0x000000);


		//Draw Loop
		for (GameObjectInstance* pObj : gOM->mGameObjects)
		{
			Sprite* pSp = (Sprite *)pObj->GetComponent(COMPONENT_SPRITE);
			Transform* pTr = (Transform *)pObj->GetComponent(COMPONENT_TRANSFORM);

			if (NULL == pTr || NULL == pSp)
			{
				continue;

			}

			SDL_Rect Dest_R;
			Dest_R.x = pTr->mPosition.x;
			Dest_R.y = pTr->mPosition.y;

			SDL_BlitSurface(pSp->mSurface, NULL, pWindowSurface, &Dest_R);

		}
		
		SDL_UpdateWindowSurface(pWindow);

		//Prints the number of contacts
		printf("Number of Contacts: %d \n", gpCollisionManager->mContacts.size());

		pF->FrameEnd();

	}

	
	delete rm;
	//elete pm;
	//delete pF;
	delete gpInputManager;
	delete gOM;
	delete PM;


	// Close and destroy the window
	SDL_DestroyWindow(pWindow);

	// Quit SDL subsystems
	SDL_Quit();

	return 0;
}
