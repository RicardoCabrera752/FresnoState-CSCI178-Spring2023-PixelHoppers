#ifndef FONTS_H
#define FONTS_H

#include<commons.h>
#include<textureLoader.h>

//Character set structure
typedef struct{

    char letter;
    float xMin, xMax, yMin, yMax;
    float offset;
    vec3 fontSize;

}charSet;

//Fonts class used to display text on the screen
class Fonts
{
    public:
        Fonts(); //default contructor
        Fonts(float, float, float); //overloaded constructor with x, y, z position inputs
        Fonts(float, float, float, float, float, float); //overloaded constructor with position and scale inputs
        virtual ~Fonts(); //destructor
        void initFonts(char*, int, int); //initialize the fonts with image file name and hframes and vframes

        void buildFonts2(string); //build the fonts using an input string
        //this will determine what the text on the screen says

        void drawFonts(int); //method used to draw a character of the fonts in the scene
        void drawFontsInScene(); //method used to draw the entire fonts in the scene

        charSet C[1024]; //character set

        vec3 rotation; //x, y, z rotation angles
        vec3 pos; //x, y, z, postitions
        vec3 scaleFactor; //x, y, z scale factors


        void setPosition(float, float, float); //method used to set the position of the fonts in the scene
        //takes x, y, z position input
        //primarily used to draw the fonts for pause menu

        int cCnt; //character counter
        GLuint tex; //texture handler

        int hFrames; //horizontal number of frames
        int vFrames; //vertical number of frames

        textureLoader *tLoad = new textureLoader(); //load the texture image for the fonts

        //Vestigial method from fonts lecture
        void buildFonts(char*);

        //Vestigial properties from fonts lecture
         float zoom;


    protected:

    private:
};

#endif // FONTS_H
