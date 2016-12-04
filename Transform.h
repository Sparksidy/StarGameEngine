#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vector2D.h"
#include "Matrix2D.h"
#include "Component.h"
#include "GameObjectInstance.h"
#include "EventManager.h"
#include <stdio.h>

#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>


class GameObjectInstance;

class Transform:  public Component{

public:
	Transform():Component(COMPONENT_TRANSFORM){
		
		mPosition.x = 0;
		mPosition.y = 0;

		mScaleX = 1.0f;
		mScaleY = 1.0f;

		mAngle = 0.0f;

		//Matrix2DIdentity(&mpTransform);
		
	
	}
	
	void Update();

	void Serialize(FILE** fpp);
	void HandleEvent(Event* ev);


	~Transform(){}


public:
	Vector2D mPosition;
	float mScaleX, mScaleY;
	float mAngle;

	glm::mat4 mpTransform;



};

#endif