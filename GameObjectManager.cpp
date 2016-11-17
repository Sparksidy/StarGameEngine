#include "GameObjectManager.h"
#include "Transform.h"
#include "Controller.h"
#include "Body.h"

void GameObjectManager::LoadObject(char* filePath)
{
	
	GameObjectInstance* pInst = new GameObjectInstance();

	FILE* fp;
	fp = fopen(filePath, "r");

	char stringName[256];
	memset(stringName, 0, 256 * sizeof(char));

	//While we reach the end of file
	while (fscanf(fp, "%s\n", stringName) != EOF)
	{
		
				//Comparing the transform string
				if (0 == strcmp("Transform", stringName))
				{
					
					pInst->AddComponent(COMPONENT_TRANSFORM);
					Transform* pTr = (Transform *)pInst->GetComponent(COMPONENT_TRANSFORM);
					pTr->mpOwner = pInst;
					pTr->Serialize(&fp);

				}
				if (0 == strcmp("Sprite", stringName))
				{
					
					pInst->AddComponent(COMPONENT_SPRITE);
					Sprite* pSp = (Sprite *)pInst->GetComponent(COMPONENT_SPRITE);
					pSp->mpOwner = pInst;
					pSp->Serialize(&fp);

				}
				if (0 == strcmp("Controller", stringName))
				{
					
					pInst->AddComponent(COMPONENT_CONTROLLER);
					Controller* pCtr = (Controller *)pInst->GetComponent(COMPONENT_CONTROLLER);
					pCtr->mpOwner = pInst;
					pCtr->Serialize(&fp);

				}
				if (0 == strcmp("Body", stringName))
				{
					pInst->AddComponent(COMPONENT_BODY);
					Body* pBody = (Body*)pInst->GetComponent(COMPONENT_BODY);
					pBody->mpOwner = pInst;
					pBody->Serialize(&fp);

				}

			

	}

		
	

	mGameObjects.push_back(pInst);


}

void GameObjectManager::LoadLevel(char* levelPath)
{
	FILE* levelP;
	levelP = fopen(levelPath, "r");

	char stringName[256];
	memset(stringName, 0, 256 * sizeof(char));

	while (fscanf(levelP, "%s", stringName) != EOF)
	{
		if (0 == strcmp("Player", stringName))
		{
			fscanf(levelP, "%s", stringName);
			LoadObject(stringName);

		}
		if (0 == strcmp("Enemy", stringName))
		{
			fscanf(levelP, "%s", stringName);
			LoadObject(stringName);

		}

	}


}


