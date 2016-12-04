#include "Sprite.h"



Sprite::~Sprite(){

	//Clearing up the VAO and VBO
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

}

//void Sprite::AddSprite(SDL_Surface* surface){
//	mSurface = surface;
//
//}


void Sprite::Serialize(FILE** fpp)
{
	//char spriteFileName[256];
	//memset(spriteFileName, 0, 256 * sizeof(char));
	////Reading file location and storing them in the component
	//fscanf(*fpp, "%s",spriteFileName);
	////LoadSprite(spriteFileName);

	
	
}
//
//void Sprite::LoadSprite(char* path)
//{
//	
//	ResourceManager* rm = new ResourceManager();
//	mSurface = rm->GetSurface(path);
//	
//
//
//}
void Sprite::HandleEvent(Event* ev)
{


}

void Sprite::DrawMesh() {
	this->LoadMesh();

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);


}

void Sprite::LoadMesh() {


	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//For position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	//For Colour
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


}

void Sprite::SerializeVertices(char* filePath)
{
	FILE* fpInput;
	int tcols, trows = 0;
	char buffer[255];
	static float **MapData;

	fpInput = fopen(filePath, "r");

	if (!fpInput)
	{
		printf("Unable to open the file");
		return;

	}

	//Retrieve the rows and cols
	for (int i = 0; i<4; i++)
	{

		fscanf(fpInput, "%s", buffer);

		if (i == 1) {
			tcols = atoi(buffer);


		}
		if (i == 3) {
			trows = atoi(buffer);

		}


	}

	printf("Rows: %d, Cols: %d\n", trows, tcols);


	//cout << "Inside vertices" << endl;
	for (int rows = 0; rows < trows; rows++)
	{
		for (int cols = 0; cols < tcols; cols++)
		{
			fscanf(fpInput, "%s", buffer);

			vertices[rows * tcols + cols] = atof(buffer);


		}


	}

	//for (int i = 0; i < 24; i++)
	//{
	//	cout << vertices[i] << "\t";
	//}


}
			



 

