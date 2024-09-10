#ifndef SCENERY_H
#define SCENERY_H


#include <commons.h>
#include <textureLoader.h>
#include <time.h>


//Scenery class used to draw decoration, player health, and other objects in the scene that are
//not buttons, backgrounds, fonts, players, enemies, or projectiles
class scenery
{
    public:
        scenery(); //default constructor
        scenery(float, float, float, float, float, float, string); //overloaded constructor takes position and scale factor input
        //also takes scenery name as input
        virtual ~scenery(); //destructor


        void drawScenery(); //method used to draw the scenery in the scene
        void initScenery(char *); //initialize with image

        vec3 position; //x, y, z position
        vec3 scale; //x, y, z scale factors

        float xMin, yMin, xMax, yMax; ////values that help us get a frame, for the texture

        textureLoader *bTex = new textureLoader(); //load the texture for the scenery

        clock_t startTime; //timer variable
        //this would be used for animated scenery such as a fire or torch

        GLuint tex; //texture handler

        void setPosition(float, float, float);

        string name; //name of the scenery


    protected:

    private:
};

#endif // SCENERY_H
