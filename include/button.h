#ifndef BUTTON_H
#define BUTTON_H

#include <GL/gl.h>

#include<textureLoader.h>
#include<commons.h>
#include<time.h>


//Button class used to implement the buttons that player can click on various screens
class button
{
    public:
        button(); //default constructor
        button(float, float, float, float, float, float); //overloaded constructor that takes x, y, z positions and x, y, z scale factor inputs
        button(float, float, float, float, float, float, string); //overloaded constructor, //inputs are position, scaleFactor, and name
        virtual ~button(); //destructor


        float xMax,xMin,yMax,yMin; //variables that help us with button texture coordinates
        vec3 position; //x, y, z position of the button
        vec3 scaleFactor; //x, y, z scale factor for the button


        void drawSquare(); //draw the button on the screen
        void initButton(char *); //initialize the button
        //void checkIfButtonPress();

        void setPosition(float, float, float); //set the x, y, z position of the button
        //this method is primarily used to move the pause menu buttons relative to the player

        textureLoader *bTex = new textureLoader(); //load the texture for the button

        clock_t startTime; //timer variable

        GLuint tex; //texture handler

        bool wasPressed;

        string name; //name of the button, used to determine which button was pressed when user clicks with mouse

    protected:

    private:
};

#endif // BUTTON_H
