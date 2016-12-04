#ifndef SPRITE_H
#define SPRITE_H
#include <stdio.h>
//#include <SDL.h>
#include "Component.h"
#include <string>
#include "GameObjectInstance.h"
//#include "ResourceManager.h"
#include "EventManager.h"

#include <windows.h>
#include <iostream>
#include <stdio.h>

#include <glew.h>
#include <gl/gl.h>
#include "matrix.h"

#define MAX_VERTICES 500

enum ShapeType {
	SHIP,
	BULLET,
	ASTEROID,

	NUM
};


class GameObjectInstance;

class Sprite: public Component{

public:
	Sprite():Component(COMPONENT_SPRITE){
		//mSurface = NULL;

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		active = false;

		
	}
	
	~Sprite();

	//void AddSprite(SDL_Surface* surface);
	
	
	 void Update(){}

	 void Serialize(FILE** fpp);

	 void SerializeVertices(char* filePath);

	 void DrawMesh();
	 void LoadMesh();

	 //void LoadSprite(char* path);
	 void HandleEvent(Event* ev);
	

public:
	//SDL_Surface* mSurface;
	GLuint VAO, VBO, EBO;
	GLfloat vertices[MAX_VERTICES];

	unsigned int mType;
	bool active;
	

};



#endif