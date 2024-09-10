#include "collisionManager.h"

collisionManager::collisionManager()
{
    //ctor

    iFrames = clock();
}

collisionManager::~collisionManager()
{
    //dtor
}



//Handle checking collisions of groups of enemies with the player
void collisionManager::handleLevelEnemyCollision(int numEnemies, enms levelEnemies[] , player* ply, checkCollision* hits, sceneManager* _sManager, sounds* _snds)
{
    for(int i = 0; i < numEnemies; i++){ //for every enemy in the levelEnemies array check for a collision



            //Determine if the enemy is alive
            if(levelEnemies[i].alive == true){ //only check collision if the enemy is alive










            if(hits->isRadialCollision(ply->pPos.x, levelEnemies[i].ePos.x, ply->pPos.y, levelEnemies[i].ePos.y,0.1, 0.195 )){ //check for radial collision between enemy and player



                    //If collision occurred then:
                    ply->health -= levelEnemies[i].enemyDamage; //damage the player
                    //_snds->playSoundEffect("sounds/player_hurt.mp3");

                    //Check what direction player is facing to perform enemy knockback
                    if(ply->playerDir == 'R'){
                        levelEnemies[i].action = levelEnemies[i].ROLLR; //if player if facing right push enemy to the right
                    }else{
                         levelEnemies[i].action = levelEnemies[i].ROLLL; //if player if facing left push enemy to the left
                    }

                    //ply->pPos.x += 0.5;
                    //en[i].enemyHealth -= 2.5; 0.195

                    /*
                    if(levelEnemies[i].enemyHealth <= 0){
                        levelEnemies[i].alive = false;
                        _sManager->numLevel1EnmyLeft --;
                        //cout << sManager->numLevel1EnmyLeft << endl;
                    }
                    */

                    cout << ply->health << endl;
                    //cout << en[i].enemyName << endl;




            }

            //Else if there was no collision then perform an enemy action

            //Note: this part should be moved to its own class specifically for handling enemy AI



            //perform WALKR or WALKL action based on "contact" with boundary
            if(levelEnemies[i].ePos.x < -10.0){ //if the enemy has reached left boundary
                //en[i].actions(en[i].WALKL);
                //en[i].ePos.x += en[i].eSpeed.x;
                levelEnemies[i].action = levelEnemies[i].WALKR; //change the enemy to walk right
                //en[i].eSpeed.x = 0.1;
            }else if(levelEnemies[i].ePos.x > 10.0){ //if the enemy has reached right boundary
                //en[i].actions(en[i].WALKR);
                //en[i].ePos.x -= en[i].eSpeed.x;
               levelEnemies[i].action = levelEnemies[i].WALKL; //change the enemy to walk left
                //en[i].eSpeed.x = -0.1;
            }



            levelEnemies[i].drawEnemy(_sManager); //draw the enemy in the scene

            }



           }


}


//Handle checking player projectile collisions with enemies
void collisionManager::handlePlayerHitEnemy(int numProjectiles, projectile myBullets[], int numEnemies, enms levelEnemies[], checkCollision* hits, sceneManager* _sManager, player* ply, sounds* _snds, int levelNumber)
{


 for(int i = 0; i < numProjectiles; i++){ //for every player projectile

        if(myBullets[i].alive == true){ //check if it's alive, only want to check collision with projectiles that are alive

            for(int j = 0; j < numEnemies; j++){ //for every enemy in the level

                if(levelEnemies[j].alive == true && myBullets[i].alive == true){ //only check hits against enemies that are alive

                    if(hits->isPlayerHitEnemy(myBullets[i].position.x, levelEnemies[j].ePos.x, myBullets[i].position.y, levelEnemies[j].ePos.y, 0.1, 0.11)){ //check for a collision


                        //If collision occurred then:

                        myBullets[i].alive = false; //kill the projectile
                        myBullets[i].placeProjectile(0, 50, 2.5); //set the projectile off screen

                        levelEnemies[j].enemyHealth -= ply->attackDamage; //damage the enemy
                        //cout << "bonked em" << endl;

                        if(levelEnemies[j].enemyHealth <= 0){ //if the enemy health is less than or equal to zero
                            levelEnemies[j].alive = false; //kill the enemy

                            //Check what level the player is in
                            //Need to decrease number of enemies from the correct level
                            if(levelNumber == 1){ //if level 1
                                _sManager->numLevel1EnmyLeft --; //decrease number of level 1 enemies alive
                                cout << _sManager->numLevel1EnmyLeft << endl;
                            }else if(levelNumber == 2){ //if level 2
                                 _sManager->numLevel2EnmyLeft --; //decrease number of level 2 enemies alive
                                 cout << _sManager->numLevel2EnmyLeft << endl;
                            }else if(levelNumber == 3){ //if level 3
                             _sManager->numLevel3EnmyLeft --; //decrease number of level 3 enemies alive
                             cout << _sManager->numLevel3EnmyLeft << endl;
                            }

                            //_sManager->numLevel1EnmyLeft --;


                            _snds->playSoundEffect("sounds/enemy_death.mp3"); //if enemy died then play enemy death sound
                        }
                    }


                }

            }


        }

    }

}
