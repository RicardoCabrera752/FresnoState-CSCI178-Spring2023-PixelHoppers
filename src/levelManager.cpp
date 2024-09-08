#include "levelManager.h"

levelManager::levelManager()
{
    //ctor

    //Set default A and B group sizes
    level1AGroup = 3; //3 enemies will spawn to the right of player
    level1BGroup = 2; //2 enemies will spawn to the left of player
}

levelManager::~levelManager()
{
    //dtor
}



//Get a random value for enemy x position for spawn point
float levelManager::randomVal(float maxVal, float minVal)
{
    float result; //the result we will return

    //result = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/range)); //calculate the random float
    result = (static_cast <float> (rand()) / (static_cast <float> (RAND_MAX))) * (maxVal - minVal) + minVal ; //calculate the random float
    //value using rand(), RAND_MAX, and a specified range value


    return result; //return the random float value
}



//Reset the enemies in a level
void levelManager::resetEnemies(enms levelEnemies[], int maxNumEnmy)
{


    //B Group ie left enemies
    for(int i = 0; i < maxNumEnmy - level1BGroup; i++){

        levelEnemies[i].alive = true; //set alive
        levelEnemies[i].enemyHealth = levelEnemies[i].defaultHealth; //reset health
        levelEnemies[i].setSpawnPositon(randomVal(4.0, 6.0) , -0.59, -2.5); //set spawn point



    }


    //A Group ie right enemies
    for(int i = level1AGroup; i < maxNumEnmy; i++){

        levelEnemies[i].alive = true; //set alive
        levelEnemies[i].enemyHealth = levelEnemies[i].defaultHealth; //reset health
        levelEnemies[i].setSpawnPositon(randomVal(-6.0, -4.0) , -0.59, -2.5); //set spawn point

    }



}

//Reset all of the player's projectiles
void levelManager::resetProjectile(projectile myBullets[], int maxNum)
{

    for(int i = 0; i < maxNum; i++){

        myBullets[i].alive = false; //kill the projectile
        myBullets[i].actionTrigger = myBullets[i].IDLE; //set projectile to idle is do nothing
        myBullets[i].placeProjectile(0, 50, -2.5); //set projectile position off screen


    }

    cout << "reset all" << endl;


}

