#ifndef PROJECTILE_H
#define PROJECTILE_H



#include <textureLoader.h>
#include <commons.h>
#include <sceneManager.h>

//Projectile class for player projectiles
//could be extended for enemy projeciles
class projectile
{
    public:
        projectile(); //default constructor
        virtual ~projectile(); //destructor


        vec3 scaleSize; //x, y, z scale factors
        vec3 position; //x, y, z position
        vec3 rotation; //x, y, z rotation angles

        char direction; //direction of the projectile
        //'R' = right
        //'L' = left

        int hFrames; //horizontal number of frames
        int vFrames; //vertical number of frames


        GLuint tex; //texture handler
        textureLoader *tLoad = new textureLoader(); //texture loader method


        string projectileType; //type of projectile
        //"P" -> player

        bool alive; //boolean to determine if a projectile is alive or dead

        enum acts{MOVER, MOVEL, IDLE}; //projectile action states
        //MOVER means projectile is moving right
        //MOVEL means projectile is moving left
        //IDLE mean no movement

        void actions(sceneManager*); //handle different actions
        acts action; //action trigger

        float xMax, yMax, xMin, yMin; //values that help us get a frame, for the texture


        vec2 speed; //move speed, x and y direction
        float t; //t is time on projectile trajectory
        float theta; //angle of projectile trajectory in radians
        float velocity; //initial velocity of projectile

        clock_t startTime; //timer variable


        void drawProjectile(sceneManager*); //draw the projectile in the scene



        void initProjectile(GLuint, int, int); //projectile initialization


        void projectileTexture(char*); //load projectile texture

        void placeProjectile(float, float, float); //set the position of a projectile, inputs are x, y, z position
        //primarily used to set the projectile off the map when it is dead



        //unused
        void updateProjectile(); //update projectile position
        acts actionTrigger;

    protected:

    private:
};

#endif // PROJECTILE_H
