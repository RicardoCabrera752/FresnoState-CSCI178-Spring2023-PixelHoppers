#ifndef PLAYER_H
#define PLAYER_H
#include <GL/gl.h>

#include <textureLoader.h>
#include <commons.h>
#include <sounds.h>
#include<sceneManager.h>

//Player Class
class player
{
    public:
        player(); //default constructor

        virtual ~player(); //destructor

        vec3 scaleSize; //width, height, length, 3 values
        vec3 verts[4]; //four corners of quad, 12 values
        enum acts{IDLE,WALKR,WALKL,JUMP,WALKRJUMP, WALKLJUMP, WALKRATTACK, WALKLATTACK, JUMPATTACK, ATTACK,DIE}; //actions
        //IDLE -> idle ie do nothing
        //WALKR -> move right
        //WALKL -> move left
        //JUMP -> jump
        //ATTACK -> player attack
        //DIE -> dead


        float runSpeed; //x direction movement speed
        float jumpSpeed; //y direction movement speed


        float health; //current player health
        //this will decrease then hit by an enemy

        float maxHealth; //maximum health of the player
        //this is used to reset the player health to full

        float score; //the player's score
        //this could be used to implement a scoring system


        float attackDamage; //the player's attack damage
        //this will determine how much damage player projectiles do to enemies


        bool isShooting;
        bool isJumping;
        bool isMovingLeft;
        bool isMovingRight;


        acts actionTrigger; //action trigger

        void drawPlayer(); //draw the player in the scene
        void playerInit(char*, int, int); //player initialization
        //inputs are filename, hframes, vframes
        void actions(acts, sounds*, sceneManager*); //handle player actions

        int hFrames; //horizontal number of frames
        int vFrames; //vertical number of frames


        vec3 pPos; //x, y, z position of the player

        float xMax, yMax, xMin, yMin; //values that help us get a frame
        GLuint tex; //texture handler
        textureLoader *tLoad = new textureLoader(); //load the player texture

        char playerDir; //to find out where the player is heading

        float playerVelocity; //player initial jump velocity
        float playerTheta; //player jump angle
        float t; //timer for player jump

        //Check player jump status
        bool startJumping;
        bool stopJumping;

        clock_t startTime; //timer variable for player animation



        void resetPlayer(); //hard reset of player stats

        void softResetPlayer(); //soft reset of player stats


        //Unused variables
        int numJumps; //number of jumps a player can perform
        //this could be used to implement double jump

        float attackCooldown;

        int weaponType;


        //Unused methods
        string getHealth();

        string getScore();



    protected:

    private:
};

#endif // PLAYER_H
