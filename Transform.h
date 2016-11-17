#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vector2D.h"
//#include "Matrix2D.h"
#include "Component.h"
#include "GameObjectInstance.h"

#include <stdio.h>

class GameObjectInstance;

class Transform:  public Component{

public:
	Transform():Component(COMPONENT_TRANSFORM){
		
		mPosition.x = 0;
		mPosition.y = 0;
		mScaleX = 0;
		mScaleY = 0;
		mAngle = 0;

		//Matrix2DIdentity(mpTransform);

	
	}
	
	void Update(){}

	void Serialize(FILE** fpp);

	~Transform(){}

	


	

public:
	Vector2D mPosition;
	unsigned int mScaleX, mScaleY;
	float mAngle;

	//Matrix2D* mpTransform;



};

#endif