#include "button.h"

button::button()
{
    //ctor



    //Set default button positions
    position.x = 0.0;
    position.y = 0.0;
    position.z = -2.0;

    //Set default button scale factor
    scaleFactor.x = 1.0;
    scaleFactor.y = 1.0;
    scaleFactor.z = 1.0;

    wasPressed = false;

    name = ""; //default name

    startTime = clock(); //start timer
}


button::button(float xPos, float yPos, float zPos, float xScale, float yScale, float zScale)
{

    //Set texture values
    xMax = 1.0;
    xMin = 0.0;
    yMax = 0.0;
    yMin = 1.0;

    //Set button positions using input
    position.x = xPos;
    position.y = yPos;
    position.z = zPos;

    //Set button scale factor using inputs
    scaleFactor.x = xScale;
    scaleFactor.y = yScale;
    scaleFactor.z = zScale;

    wasPressed = false;

    name = ""; //default name

    startTime = clock(); //start timer

}

button::button(float xPos, float yPos, float zPos, float xScale, float yScale, float zScale, string buttonName)
{

    //Set texture values
    xMax = 1.0;
    xMin = 0.0;
    yMax = 0.0;
    yMin = 1.0;

    //Set button positions using input
    position.x = xPos;
    position.y = yPos;
    position.z = zPos;

    //Set button scale factor using inputs
    scaleFactor.x = xScale;
    scaleFactor.y = yScale;
    scaleFactor.z = zScale;

    wasPressed = false;

    name = buttonName; //set name using input

    startTime = clock(); //start timer

}



button::~button()
{
    //dtor
}



//Draw the button in the scene
void button::drawSquare()
{


    glColor3f(1.0,1.0,1.0); //set texture color to white to prevent color bleed
    bTex->binder(tex); //bind the button texture

    glTranslatef(position.x, position.y, position.z); //translate
    glScalef(scaleFactor.x, scaleFactor.y, scaleFactor.z); //apply scale factor

    //Draw the button
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

//Button Initialization
void button::initButton(char* fileName)
{

    bTex->loadTexture(fileName,tex); //load the texture from image


    //Set texture values
    xMax = 1.0;
    xMin = 0.0;
    yMax = 1.0;
    yMin = 0.0;

}


//Set Button Position
void button::setPosition(float xPos, float yPos, float zPos)
{

    //Set x, y, z, position using input position
    position.x = xPos;
    position.y = yPos;
    position.z = zPos;

}




