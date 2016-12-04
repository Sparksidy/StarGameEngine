#include "GameObjectManager.h"
#include "Transform.h"
#include "Controller.h"
#include "Body.h"

GameObjectInstance* GameObjectManager::LoadObject(char* filePath)
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
					char verticesName[256];
					pInst->AddComponent(COMPONENT_SPRITE);
					Sprite* pSp = (Sprite *)pInst->GetComponent(COMPONENT_SPRITE);
					pSp->mpOwner = pInst;

					fscanf(fp, "%s", verticesName);
					printf("String: %s \n", verticesName);
					pSp->SerializeVertices(verticesName);
					//pSp->Serialize(&fp);

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

	return pInst;


}



void GameObjectManager::LoadLevel(char* levelPath)
{
	GameObjectInstance* pInst = new GameObjectInstance();

	FILE* levelP;
	levelP = fopen(levelPath, "r");

	char stringName[256];
	memset(stringName, 0, 256 * sizeof(char));

	while (fscanf(levelP, "%s", stringName) != EOF)
	{
		if (0 == strcmp("Player", stringName))
		{
			
			fscanf(levelP, "%s", stringName);
			pInst = LoadObject(stringName);
			Transform* pTr = (Transform *)pInst->GetComponent(COMPONENT_TRANSFORM);
			Sprite* pSp = (Sprite *)pInst->GetComponent(COMPONENT_SPRITE);
			pSp->mType = SHIP;
			fscanf(levelP, "%f %f\n", &pTr->mPosition.x, &pTr->mPosition.y);
			printf("%f %f\n", pTr->mPosition.x, pTr->mPosition.y);
				
		}
		if (0 == strcmp("Bullet", stringName))
		{
			fscanf(levelP, "%s", stringName);
			pInst = LoadObject(stringName);
			Transform* pTr = (Transform *)pInst->GetComponent(COMPONENT_TRANSFORM);
			Sprite* pSp = (Sprite *)pInst->GetComponent(COMPONENT_SPRITE);
			pSp->mType = BULLET;
			fscanf(levelP, "%f %f\n", &pTr->mPosition.x, &pTr->mPosition.y);
			printf("%f %f\n", pTr->mPosition.x, pTr->mPosition.y);

		}

	}

	



}



