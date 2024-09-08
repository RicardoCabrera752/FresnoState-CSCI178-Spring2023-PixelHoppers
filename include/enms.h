#ifndef ENMS_H
#define ENMS_H

#include <GL/gl.h>

#include <textureLoader.h>
#include <commons.h>
#include <time.h>
#include <sceneManager.h>


//Enemies class
class enms
{
    public:
        enms(); //default constructor
        virtual ~enms(); //destrcutor

        void drawEnemy(sceneManager*); //method to draw the enemy in the scene

        void setSpawnPositon(float, float, float); //method to set the spawn position of the enemies
        //inputs are x, y, and, z positions

        void initEnemy(GLuint, int, int); //enemy initialization with image file name and hframes and vframes
        void enemyTexture(char*); //call texture loader

        enum acts{IDLE,WALKR,WALKL,ROLLR,ROLLL,JUMP,ATTACK,DIE}; //actions for enmeies
        //IDLE -> idle state ie do nothing
        //WALKR -> move to the right
        //WALKL -> move to the left
        //ROLLR -> knockback to the right
        //ROLLL -> knockback to the left
        //JUMP -> jump
        //ATTACK -> attack the player
        //DIE -> death

        void actions(sceneManager*); //method to handle enemy actions
        acts action; //action handler

        int hFrames; //horizontal number of frames
        int vFrames; //vertical number of frames

        vec3 ePos; //x, y, z position of the enemy
        vec2 eSize; // x, y, z, scale factor for enemy
        vec2 eSpeed; //move speed, x and y direction

        vec3 eRot; //x, y, z rotation angles
        clock_t startTime; //timer variable for animation

        float xMax, yMax, xMin, yMin; //values that help us get a frame, for the texture
        GLuint tex; //texture handler
        textureLoader *tLoad = new textureLoader(); //load the texture image

        float theta; //angle of enemy roll
        float velocity; //speed of enemy roll
        float t; //t is time on projectile motion

        char enemyDir; //direction the enemy is facing, will help determine movement direction
        //'R' -> right
        //'L' -> left

        float enemyHealth; //heath stat for enemies
        //this will decrease as the enemy takes damage from player projectiles

        float defaultHealth; //default health stat for enemies
        //when the enemies are reset, this will be used to set enemyHealth back to default value

        float enemyDamage; //the amount of damage the enemy does to the player when touching them

        bool alive; //boolean used to determine if an enemy is alive or dead
        //this will decide if we should draw the enemy in the scene or check for collisions

        string enemyName; //the name of the enemy type
        //"Skel" -> skeleton
        //"Fiend" -> Fiend

        clock_t finishRoll; //timer variable used to determine knockback distance when colliding with player

        //Vestigial methods from enemies lecture
         void placeEnemy(vec3); //x, y, z, position of enemy placement


    protected:

    private:
};

#endif // ENMS_H
