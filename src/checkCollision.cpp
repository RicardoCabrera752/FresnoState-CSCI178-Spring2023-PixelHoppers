#include "checkCollision.h"

checkCollision::checkCollision()
{
    //ctor

    iFrames = clock(); //start iFrames timer
}

checkCollision::~checkCollision()
{
    //dtor
}



//Check for enemy player collision
bool checkCollision::isRadialCollision(float x1, float x2, float y1, float y2, float r1, float r2)
{

    //if (r1 + r2 < d) return true else return false
    // d = sqrt((x2-x1)^2 + (y2-y1)^2)

    if(clock() - iFrames > 4000){ //if the player does not have iFrames

        if(sqrt(pow(x1-x2, 2) + pow(y1-y2,2)) < r1 + r2 ){ //determine if collision occurred
            return true;
        }else{
            return false;
        }

        iFrames = clock(); //reset iFrames

    }
}



//Check for player projectile enemy collision
bool checkCollision::isPlayerHitEnemy(float x1, float x2 , float y1, float y2, float r1 , float r2)
{
         //if (r1 + r2 < d) return true else return false
        // d = sqrt((x2-x1)^2 + (y2-y1)^2)


        if(sqrt(pow(x1-x2, 2) + pow(y1-y2,2)) < r1 + r2 ){ //determine if collision occurred
            return true;
        }else{
            return false;
        }

}



//Vestigial methods from collision lecture
bool checkCollision::isLinearCollision(float x1, float x2)
{
    if(fabs(x1-x2) < 0.1){
        return true;
    }else{
        return false;
    }

}

bool checkCollision::isSphereCollision(vec3 x, vec3 y)
{

}

bool checkCollision::isQuadCollision(vec2 x, vec2 y)
{

}
