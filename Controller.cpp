#include "Controller.h"
#include "GameObjectInstance.h"

Controller::Controller():Component(COMPONENT_CONTROLLER){
	//mpIM = new InputManager();
	
}

void Controller::Update(){

	if (gpInputManager != NULL)
	{
		if (mpOwner)
		{
			//Updating the keyboard state
			gpInputManager->Update();

			Transform* pTr = (Transform *)mpOwner->GetComponent(COMPONENT_TRANSFORM);

			if (pTr)
			{
				//Checking for keypress events

				if (gpInputManager->IsPressed(SDL_SCANCODE_UP)){
					pTr->mPosition.y -= speed * 0.5f;
				
				}
				else if (gpInputManager->IsPressed(SDL_SCANCODE_DOWN)){
					pTr->mPosition.y += speed * 0.5f;

				}
				else if (gpInputManager->IsPressed(SDL_SCANCODE_LEFT)){
					pTr->mPosition.x -= speed * 0.5f;
				}
				else if (gpInputManager->IsPressed(SDL_SCANCODE_RIGHT)){
					pTr->mPosition.x += speed * 0.5f;

				}


			}


		}
		
		


	}
	

		

}


Controller::~Controller(){

}

void Controller::Serialize(FILE** fpp)
{
	fscanf(*fpp, "%f ", &speed);
	
}