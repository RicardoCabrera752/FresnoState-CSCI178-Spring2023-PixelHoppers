#ifndef CHECKCOLLISION_H
#define CHECKCOLLISION_H
#include<commons.h>


//Class used to check if a collision has occurred between player, enemy, or player projectile
class checkCollision
{
    public:
        checkCollision(); //default constructor
        virtual ~checkCollision(); //destructor


    bool isRadialCollision(float , float , float , float , float, float); //method used to check if a collision between
    //enemy and player has occurred
    //primary use is to implement player getting hurt from enemy touching them

    bool isPlayerHitEnemy(float, float, float, float, float, float); //method used to check if a collision between
    //player projectile and enemy has occurred
    //primary use is to implement player attack hurting enemy


    clock_t iFrames; //timer variable used to give the player invincibility frames
    //this will prevent player taking damage when the level has just started


    //Vestigial methods from class lecture on collisions
    bool isLinearCollision(float , float );
    bool isSphereCollision(vec3 , vec3 );
    bool isQuadCollision(vec2 , vec2 );

    protected:

    private:
};

#endif // CHECKCOLLISION_H
