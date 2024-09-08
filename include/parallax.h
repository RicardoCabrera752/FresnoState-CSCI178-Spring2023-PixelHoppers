#ifndef PARALLAX_H
#define PARALLAX_H
#include <GL/gl.h>

#include<textureLoader.h>
#include<time.h>

//Parallax class for level background images
class parallax
{
    public:
        parallax(); //default constructor
        virtual ~parallax(); //desctructor

        void drawSquare(float, float); //draw the background in the scene
        void initParallax(char *); //initialization with background image
        void scroll(bool,string, float); //method to implement parallax scroll functionality

        float xMax,xMin,yMax,yMin; //values that help us get a frame

        textureLoader *bTex = new textureLoader(); //load the texture

        clock_t startTime; //timer variable for animation

        GLuint tex; //texture hanlder


    protected:

    private:
};

#endif // PARALLAX_H
