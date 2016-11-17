#include "Transform.h"
#include <string>



void Transform::Serialize(FILE** fpp)
{
	//Reading the x and y positions and storing them in the component
	fscanf(*fpp, "%f %f",&mPosition.x,&mPosition.y);
	
}