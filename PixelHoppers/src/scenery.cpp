#include "scenery.h"

scenery::scenery()
{
    //ctor
}

scenery::~scenery()
{
    //dtor
}


scenery::scenery(float xPos, float yPos, float zPos, float xScale, float yScale, float zScale, string sName)
{

    //Set Texture values
    xMax = 1.0;
    xMin = 0.0;
    yMax = 0.0;
    yMin = 1.0;

    //Set position using inputs
    position.x = xPos;
    position.y = yPos;
    position.z = zPos;

    //Set scale factor using inputs
    scale.x = xScale;
    scale.y = yScale;
    scale.z = zScale;



    //Set name using input
    name = sName;


}


//Draw the scenery in the scene
void scenery::drawScenery()
{

    glColor3f(1.0,1.0,1.0); //set color to white to prevent color bleed
    bTex->binder(tex); //bind the texture

    glTranslatef(position.x, position.y, position.z); //translate
    glScalef(scale.x, scale.y, scale.z); //apply scale factor

    //Draw the scenery
    glBegin(GL_POLYGON);
       glTexCoord2f(xMin,yMax);
       glVertex3f(-1.0, -1.0,0.0);

       glTexCoord2f(xMax,yMax);
       glVertex3f(1.0, -1.0,0.0);

       glTexCoord2f(xMax,yMin);
       glVertex3f(1.0, 1.0,0.0);

       glTexCoord2f(xMin,yMin);
       glVertex3f(-1.0,1.0,0.0);

    glEnd();

}

//Initialize the scenery
void scenery::initScenery(char* fileName)
{

   bTex->loadTexture(fileName,tex); //load the texture image


   //Set texture values
    xMax = 1.0;
    xMin = 0.0;
    yMax = 1.0;
    yMin = 0.0;

}

void scenery::setPosition(float xPos, float yPos, float zPos)
{

    position.x = xPos;
    position.y = yPos;
    position.z = zPos;

}


