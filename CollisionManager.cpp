#include "CollisionManager.h"
#include "Math2D.h"

//Forward Declare the functions
bool CheckCollisionCircleCircle(Shape* shape1, float xPos1, float yPos1, Shape* shape2, float xPos2, float yPos2, std::list<Contact*> &mContacts);
bool CheckCollisionCircleRectangle(Shape* shape1, float xPos1, float yPos1, Shape* shape2, float xPos2, float yPos2, std::list<Contact*> &mContacts);
bool CheckCollisionRectangleCircle(Shape* shape1, float xPos1, float yPos1, Shape* shape2, float xPos2, float yPos2, std::list<Contact*> &mContacts);
bool CheckCollisionRectangleRectangle(Shape* shape1, float xPos1, float yPos1, Shape* shape2, float xPos2, float yPos2, std::list<Contact*> &mContacts);




CollisionManager::CollisionManager() :mContacts()
{

	mCollisionTable[(int)Shape::Type::CIRCLE][(int)Shape::Type::CIRCLE] = CheckCollisionCircleCircle;
	mCollisionTable[(int)Shape::Type::CIRCLE][(int)Shape::Type::RECTANGLE] = CheckCollisionCircleRectangle;
	mCollisionTable[(int)Shape::Type::RECTANGLE][(int)Shape::Type::CIRCLE] = CheckCollisionRectangleCircle;
	mCollisionTable[(int)Shape::Type::RECTANGLE][(int)Shape::Type::RECTANGLE] = CheckCollisionRectangleRectangle;

}

//-------------------------------------------------------------------------------------------------------------------------

CollisionManager::~CollisionManager()
{

}
//-------------------------------------------------------------------------------------------------------------------------
void CollisionManager::ResetContacts()
{
	for (auto c : mContacts)
	{
		delete c;
	}
	mContacts.clear();

}
//-------------------------------------------------------------------------------------------------------------------------

bool CollisionManager::CheckCollisionAndGenerateContacts(Shape* shape1, float xPos1, float yPos1, Shape* shape2, float xPos2, float yPos2)
{
	printf("Here in the function pointer\n");
	//Function Pointer
	return mCollisionTable[(int)shape1->mType][(int)shape2->mType](shape1, xPos1, yPos1, shape2, xPos2, yPos2, mContacts);
}

//Individual Collision Functions
//-------------------------------------------------------------------------------------------------------------------------
/*
Checks collision between a Circle and a Circle

*/
bool CheckCollisionCircleCircle(Shape* shape1, float xPos1, float yPos1, Shape* shape2, float xPos2, float yPos2, std::list<Contact*> &mContacts)
{
	printf("Here in Circle \n");

	//Check for Circle to Circle Collision here

	
		//If Collision,

			//Create Contact
			Contact* pC = new Contact();

			//Save the Body Owner
			pC->mBodies[0] = shape1->mBodyOwner;
			pC->mBodies[1] = shape2->mBodyOwner;

			//Add it to the list of Contacts
			mContacts.push_back(pC);

			return false;
			
	
	
	

}


//-------------------------------------------------------------------------------------------------------------------------

/*
Checks collision between a Circle and a Rectangles
*/
bool CheckCollisionCircleRectangle(Shape* shape1, float xPos1, float yPos1, Shape* shape2, float xPos2, float yPos2, std::list<Contact*> &mContacts)
{

	//Check Collision Here

	//If Collision,

	//Create Contact
	Contact* pC = new Contact();

	//Save the Body Owner
	pC->mBodies[0] = shape1->mBodyOwner;
	pC->mBodies[1] = shape2->mBodyOwner;

	//Add it to the list of Contacts
	mContacts.push_back(pC);

	return false;

}
//-------------------------------------------------------------------------------------------------------------------------
/*
Checks collision between a Rectangle and a Circel
*/
bool CheckCollisionRectangleCircle(Shape* shape1, float xPos1, float yPos1, Shape* shape2, float xPos2, float yPos2, std::list<Contact*> &mContacts)
{
	//Check Collision Here



	//If Collision,

	//Create Contact
	Contact* pC = new Contact();

	//Save the Body Owner
	pC->mBodies[0] = shape1->mBodyOwner;
	pC->mBodies[1] = shape2->mBodyOwner;

	//Add it to the list of Contacts
	mContacts.push_back(pC);

	return false;

}

//-------------------------------------------------------------------------------------------------------------------------

/*
	Checks collision between a Rectangle and a Rectangle
*/

bool CheckCollisionRectangleRectangle(Shape* shape1, float xPos1, float yPos1, Shape* shape2, float xPos2, float yPos2, std::list<Contact*> &mContacts)
{
	
	ShapeRectangle* pRect1 = (ShapeRectangle *)shape1;
	ShapeRectangle* pRect2 = (ShapeRectangle *)shape2;

	bool CollisionResult;

	float leftA, leftB;
	float rightA, rightB;
	float topA, topB;
	float bottomA, bottomB;

	leftA = xPos1 - pRect1->width / 2;
	leftB = xPos2 - pRect2->width / 2;

	rightA = xPos1 + pRect1->width / 2;
	rightB = xPos2 + pRect2->width / 2;

	topA = yPos1 + pRect1->height / 2;
	topB = yPos2 + pRect2->height / 2;

	bottomA = yPos1 - pRect1->height / 2;
	bottomB = yPos2 - pRect2->height / 2;


	if (leftA > rightB || leftB > rightA || topA < bottomB || topB < bottomA)
		CollisionResult = false;
	else
		CollisionResult = true;


	//If Collision,

	if (CollisionResult)
	{
		printf("Here in Collision Rectangle \n");
		//Create Contact
		Contact* pC = new Contact();

		//Save the Body Owner
		pC->mBodies[0] = shape1->mBodyOwner;
		pC->mBodies[1] = shape2->mBodyOwner;

		//Add it to the list of Contacts
		mContacts.push_back(pC);


	}

	return CollisionResult;
	

}

//-------------------------------------------------------------------------------------------------------------------------
