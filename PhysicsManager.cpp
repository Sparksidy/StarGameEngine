#include "PhysicsManager.h"
#include "GameObjectManager.h"
#include "Body.h"
#include "CollisionManager.h"

extern CollisionManager* gpCollisionManager;
//extern GameObjectManager* gOM;

PhysicsManager::PhysicsManager()
{


}


PhysicsManager::~PhysicsManager()
{


}
void PhysicsManager::Integrate(float deltaTime, float gravity, GameObjectManager* pTrGameObjManager)
{

	for (GameObjectInstance* pObj : pTrGameObjManager->mGameObjects)
	{
		Body* pBody = (Body*)pObj->GetComponent(COMPONENT_BODY);
		if (NULL != pBody)
		{
			pBody->Integrate(deltaTime * 0.001, gravity);
		}
	}

	//Reset the Contacts
	gpCollisionManager->ResetContacts();

	unsigned int objectNum = pTrGameObjManager->mGameObjects.size();

	for (unsigned int i = 0; i < objectNum; i++)
	{
		Body* pBody1 = (Body *)pTrGameObjManager->mGameObjects[i]->GetComponent(COMPONENT_BODY);

		for (unsigned int j = i + 1; j < objectNum; j++)
		{
			Body* pBody2 = (Body *)pTrGameObjManager->mGameObjects[j]->GetComponent(COMPONENT_BODY);

			if (pBody1 == NULL)
				continue;

			if (pBody2 == NULL)
				continue;

			gpCollisionManager->CheckCollisionAndGenerateContacts(pBody1->mShape, pBody1->Xpos, pBody1->Ypos, pBody2->mShape, pBody2->Xpos, pBody2->Ypos);
			printf("Position: %f %f", pBody1->Xpos, pBody2->Xpos);


		}
	}
	

	//Commit CHanges back to transform
	for (GameObjectInstance* pObj : pTrGameObjManager->mGameObjects)
	{
		Body* pBody = (Body *)pObj->GetComponent(COMPONENT_BODY);

		if (NULL != pBody)
		{
			Transform* pTr = (Transform *)pObj->GetComponent(COMPONENT_TRANSFORM);
			pTr->mPosition.x = pBody->Xpos;
			pTr->mPosition.y = pBody->Ypos;
		}
	}


	


}
