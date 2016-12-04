#include "Controller.h"
#include "GameObjectInstance.h"
#include "FrameRateController.h"
#include "GameObjectManager.h"

extern EventManager* gpEventManager;
extern FrameRateController* pF;
extern GameObjectManager* gOM;



Controller::Controller():Component(COMPONENT_CONTROLLER){
	
}

void Controller::Update(){

	if (gpInputManager != NULL)
	{
		
		if (mpOwner)
		{
			//Updating the keyboard state
			gpInputManager->Update();

			Transform* pTr = (Transform *)mpOwner->GetComponent(COMPONENT_TRANSFORM);
			Body* pBdy = (Body *)mpOwner->GetComponent(COMPONENT_BODY);

			if (pTr)
			{
				
				//Checking for keypress events
				if (gpInputManager->IsPressed(SDL_SCANCODE_UP))
				{


					if (NULL != pBdy)
					{

						float accelerationValue = 0.8f;

						pBdy->AccX = accelerationValue * cosf((pTr->mAngle + 90) *3.14 / 180);
						pBdy->AccY = accelerationValue * sinf((pTr->mAngle + 90) *3.14 / 180);


					}

				}
				if (gpInputManager->IsPressed(SDL_SCANCODE_DOWN))
				{

					if (NULL != pBdy)
					{

						float accelerationValue = -3.0f;

						pBdy->AccX = accelerationValue * cosf(pTr->mAngle + 90)*3.14 / 180;
						pBdy->AccY = accelerationValue * sinf(pTr->mAngle + 90)*3.14 / 180;

					}


				}
				if (gpInputManager->IsPressed(SDL_SCANCODE_LEFT))
				{

					pTr->mAngle += 0.3f * pF->GetFrameTime();

				}
				if (gpInputManager->IsPressed(SDL_SCANCODE_RIGHT))
				{

					pTr->mAngle -= 0.3f *pF->GetFrameTime();
					

				}
				if (gpInputManager->IsPressed(SDL_SCANCODE_SPACE))
				{
					

					
					//Get the bullet object
					for (GameObjectInstance* pObj : gOM->mGameObjects)
					{
						
						Sprite* pSp = (Sprite*)pObj->GetComponent(COMPONENT_SPRITE);

						for (auto i : pObj->mComponents)
						{
							if (pSp->mType == BULLET)
							{
								Transform* bulletpTr= (Transform*)pObj->GetComponent(COMPONENT_TRANSFORM);

								
								bulletpTr->mPosition = pTr->mPosition;	
								bulletpTr->mAngle = pTr->mAngle;

								Body* bulletBody = (Body *)pObj->GetComponent(COMPONENT_BODY);
								GameObjectInstance* ship = pTr->mpOwner;

								Body* shipBody = (Body *)ship->GetComponent(COMPONENT_BODY);

								bulletBody->VelX = 0;
								bulletBody->VelY = 0;


								if (NULL != bulletBody)
								{
									#define BULLET_SPEED 40.0f
									

									bulletBody->AccX = shipBody->AccX + (BULLET_SPEED * cosf((pTr->mAngle + 90) *3.14 / 180));
									bulletBody->AccY = shipBody->AccY + (BULLET_SPEED * sinf((pTr->mAngle + 90) *3.14 / 180));


								}
								//printf("Bullet Angle: %f\n", bulletpTr->mAngle);
								printf("Ship Angle: %f\n", pTr->mAngle);
						
							}
						}
					}


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

void Controller::HandleEvent(Event* ev)
{
	if (ev->mType == EVENT_TYPE::COLLIDE)
	{
		Body* pBody = (Body *)mpOwner->GetComponent(COMPONENT_BODY);
		pBody->Xpos = 0.0f;
		pBody->Ypos = 0.0f;

		PlayerHitEvent* pHitEvent = new PlayerHitEvent();
		pHitEvent->mtimer = 3.0f;
		gpEventManager->AddEvent(pHitEvent);

		
	}

	
	

}