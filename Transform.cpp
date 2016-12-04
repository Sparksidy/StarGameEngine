#include "Transform.h"
#include <string>
#include <iostream>

using namespace std;


void Transform::Serialize(FILE** fpp)
{
	//Reading the x and y positions and storing them in the component
	fscanf(*fpp, "%f %f %f", &mScaleX, &mScaleY, &mAngle);
	
}
void Transform::HandleEvent(Event* ev)
{
	if (ev->mType == EVENT_TYPE::PLAYER_HIT)
	{
		printf("After 3 seconds\n");
	}
	
}

void Transform::Update()
{
	//Compute the transformation matrice every frame
	

	glm::mat4 trans;
	trans = glm::translate(trans, glm::vec3(mPosition.x, mPosition.y, 0.0f));

	glm::mat4 scale;
	scale = glm::scale(scale, glm::vec3(mScaleX ,mScaleY, 0.0f));

	glm::mat4 rotate;
	rotate = glm::rotate(rotate, glm::radians(mAngle), glm::vec3(0.0f, 0.0f, 1.0f));

	glm::mat4 intermediate;
	intermediate = scale * rotate;

	mpTransform = trans * intermediate ;


}
