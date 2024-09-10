#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <commons.h>
#include <player.h>
#include <enms.h>
#include <checkCollision.h>
#include <projectile.h>
#include <sceneManager.h>
#include <sounds.h>


//This class handles checking collisions in the drawScene()
class collisionManager
{
    public:
        collisionManager(); //default contructor
        virtual ~collisionManager(); //destructor


        void handleLevelEnemyCollision(int, enms [], player*, checkCollision*, sceneManager*, sounds*); //method that handles checking for collisions between
        //an array of enemies and the player
        //inputs are the size of the enemies array, the enemies array of the enemies that we want to check collisions, the player,
        //a checkCollisions object to actually make the collision checks, a sceneManager object, and a sounds object so that we may play
        //a player hurt sound if needed

        void handlePlayerHitEnemy(int, projectile [], int, enms[], checkCollision*, sceneManager*, player*, sounds*, int); //method that handles checking for collisions
        //between player projectiles and an array of enemies
        //inputs are the size of projectile array, the projectile array, size of enemies array, the enemies array of enemies we want to check collisions, a sceneManager object,
        //a sounds object to play the enemy death sounds, and the level number that the player is in ie 1, 2, or 3

        clock_t iFrames; //timer variable used to give the player invincibility frames
    //this will prevent player taking damage when the level has just started

    protected:

    private:
};

#endif // COLLISIONMANAGER_H
