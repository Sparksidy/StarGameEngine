/*
// GLEW
#define GLEW_STATIC
#include <glew.h>

// GLFW
#include <glfw3.h>
#include "Shader.h"
#include "MeshInstance.h"
#include "matrix.h"
#include <stdlib.h>
#include <string>

#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>



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
#include "EventManager.h"



//For File import
#include "stdio.h"
#include "string.h"
#include "matrix.h"

CollisionManager* gpCollisionManager;
InputManager* gpInputManager;
GameObjectManager* gOM;
EventManager* gpEventManager;
//Function Prototypes


int main(int argc, char* args[])
{
	/*if(AllocConsole()){
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
	gOM = new GameObjectManager();
	PhysicsManager* PM = new PhysicsManager();
	gpEventManager = new EventManager();
	

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
	

	//gOM->LoadLevel("level1.txt");
	gOM->LoadObject("file.txt");
	

			
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

		gpEventManager->Update(pF->GetFrameTime() * 0.001);
	

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
		//printf("Number of Contacts: %d \n", gpCollisionManager->mContacts.size());

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
*/


#include <SDL.h>


//For File import
#include "stdio.h"
#include "string.h"
#include "matrix.h"





#include <iostream>

// GLEW
#define GLEW_STATIC
#include <glew.h>

// GLFW
#include <glfw3.h>
#include "Shader.h"
#include "MeshInstance.h"
#include "matrix.h"
#include <stdlib.h>
#include <string>




#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>


#include "stdio.h"
#include "InputManager.h"
#include "FrameRateController.h"
#include "ResourceManager.h"
#include "Sprite.h"
#include "Transform.h"
#include "GameObjectInstance.h"
#include "GameObjectManager.h"
#include "Controller.h"
#include "PhysicsManager.h"
#include "CollisionManager.h"
#include "EventManager.h"




CollisionManager* gpCollisionManager;
InputManager* gpInputManager;
GameObjectManager* gOM;
EventManager* gpEventManager;
FrameRateController* pF;

//Function Prototypes
void Wrap(GameObjectInstance* pInst);


using namespace std;
// Window dimensions

#define BULLET_SPEED 4.0f

const GLuint WIDTH = 1000, HEIGHT = 800;

static GameObjectInstance* sgpShip;


// The MAIN function, from here we start the application and run the game loop
int main(int argc, char* args[])
{
	//---------------------------------------------------------------------------------------------------------------------------------
	//Setting up SDL
	int error = 0;

	// Initialize SDL
	if ((error = SDL_Init(SDL_INIT_VIDEO)) < 0)
	{
		printf("Couldn't initialize SDL, error %i\n", error);
		return 1;
	}

	SDL_Window *mainWindow;
	SDL_GLContext mainContext;
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	
	mainWindow = SDL_CreateWindow("Main",
									SDL_WINDOWPOS_UNDEFINED,
								    SDL_WINDOWPOS_UNDEFINED,
									800,
									600,
									SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	if (!mainWindow)
		printf("Unable to create the window\n");

	mainContext = SDL_GL_CreateContext(mainWindow);

	//SDL_GL_SetSwapInterval(1);



	
	//---------------------------------------------------------------------------------------------------------------------------------
	//Setting up OpenGL


	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();

	//Managers
	gpInputManager = new InputManager();
	ResourceManager* rm = new ResourceManager();
	Controller* cm = new Controller();
	 pF = new FrameRateController(30);
	gOM = new GameObjectManager();
	PhysicsManager* PM = new PhysicsManager();
	gpEventManager = new EventManager();


	gpCollisionManager = new CollisionManager();

	
	//----------------------------------------------------------------------------------------------------------------------------------

	gOM->LoadLevel("level1.txt");
	
	//gOM->LoadObject("triangle2.txt");
	//gOM->LoadObject("triangle2.txt");
	//gOM->LoadObject("triangle3.txt");
	//gOM->LoadObject("triangle4.txt");

	
	bool appIsRunning = true;
	// Game loop
	while (true == appIsRunning)
	{
		pF->FrameStart();

		//Using the Shader
		Shader shader("C:\\Desktop\\Integrated\\GameEngine\\30-11 Latest\\School Teachings Engine\\Game Engine\\vertex.vs", "C:\\Desktop\\Integrated\\GameEngine\\30-11 Latest\\School Teachings Engine\\Game Engine\\fragment.frag");
		shader.Use();

		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				appIsRunning = false;
			}
		
		}
		//Physics manager for body
		PM->Integrate(pF->GetFrameTime(), 0.0f, gOM);

		//Update Loop
		for (GameObjectInstance* pObj : gOM->mGameObjects)
		{
			Sprite* pSp = (Sprite*)pObj->GetComponent(COMPONENT_SPRITE);
			Component* pController = (Component *)pObj->GetComponent(COMPONENT_CONTROLLER);
			for (auto i : pObj->mComponents)
			{
				i->Update();
			}

			//Store the ship object
			if (pController)
			{
				sgpShip = pObj;
			}

		}

		

		//Clearing the buffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Send to shaders and draw Draw Loop
		for (GameObjectInstance* pObj : gOM->mGameObjects)
		{
			
			//Get the transformation matrice
			Transform* pTr = (Transform*)pObj->GetComponent(COMPONENT_TRANSFORM);
			Sprite* pSp = (Sprite*)pObj->GetComponent(COMPONENT_SPRITE);

			if (NULL == pTr || NULL == pSp)
			{
				continue;
			}
			
			//Wrapping the ship
			if (pSp->mType == SHIP)
			{
				Wrap(pObj);
			}

			//Passing values to the shader
			GLuint transformLoc = glGetUniformLocation(shader.Program, "transform");
			glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(pTr->mpTransform));


			//Draw Object
			pSp->DrawMesh();
		

		}

		
		
	
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		// Swap the screen buffers
		//glfwSwapBuffers(window);
		SDL_GL_SwapWindow(mainWindow);

		pF->FrameEnd();
	}

	// Terminate GLFW, clearing any resources allocated by GLFW.
	//glfwTerminate();

	//delete(pGM);
	SDL_GL_DeleteContext(mainContext);
	SDL_DestroyWindow(mainWindow);

	SDL_Quit();


	//getchar();
	return 0;
}

void Wrap(GameObjectInstance* pInst)
{
	Transform* pTr = (Transform*)pInst->GetComponent(COMPONENT_TRANSFORM);

	if (pTr->mPosition.x > 1.2f || pTr->mPosition.x < -1.2f)
	{

		pTr->mPosition.x = -pTr->mPosition.x;

	}
	
	if (pTr->mPosition.y > 1.2f || pTr->mPosition.y < -1.2f)
	{

		pTr->mPosition.y = -pTr->mPosition.y;

	}

}

