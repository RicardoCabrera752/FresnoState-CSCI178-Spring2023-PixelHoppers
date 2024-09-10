#include "player.h"

player::player()
{
    //ctor
    verts[0].x = -0.5;
    verts[0].y = -0.5;
    verts[0].z = 0.0;

    verts[1].x = 0.5;
    verts[1].y = -0.5;
    verts[1].z = 0.0;


    verts[2].x = 0.5;
    verts[2].y = 0.5;
    verts[2].z = 0.0;


    verts[3].x = -0.5;
    verts[3].y = 0.5;
    verts[3].z = 0.0;


   //Default player speeds
    runSpeed = 0.1;
    jumpSpeed = 0.05;

    actionTrigger = IDLE; //default action is idle
    playerDir = 'R'; //default direction is right

    //Set default player position
    pPos.x = 0.0;
    pPos.y = -0.31;
    pPos.z = -2.5;


    //Default player jump projectile motion values
    playerTheta = 30 * PI/180.0;
    playerVelocity = 7;
    t = 0;

    startJumping = false;
    stopJumping = false;



    health = 150.0; //default current player health
    maxHealth = health; //default max player health
    score = 0.0; //default score is zero
    attackDamage = 25.5; //default attack damage


    isShooting = false;
    isJumping = false;
    isMovingLeft = false;
    isMovingRight = false;

    startTime = clock(); //start timer

}

player::~player()
{
    //dtor
}

//Draw Player in Scene
void player::drawPlayer()
{

    tLoad->binder(tex); //bind the texture

    glTranslated(pPos.x, pPos.y, pPos.z); //translate

    //Draw the player
    glBegin(GL_QUADS);

    glTexCoord2f(xMin, yMax);
    glVertex3f(verts[0].x, verts[0].y, verts[0].z);

     glTexCoord2f(xMax, yMax);
    glVertex3f(verts[1].x, verts[1].y, verts[1].z);


     glTexCoord2f(xMax, yMin);
    glVertex3f(verts[2].x, verts[2].y, verts[2].z);


     glTexCoord2f(xMin, yMin);
    glVertex3f(verts[3].x, verts[3].y, verts[3].z);

    glEnd();

}



//Player Initialization
void player::playerInit(char* fileName, int hFrm, int vFrm)
{



    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //transparency

    vFrames = vFrm; //set horizontal frames
    hFrames = hFrm; //set vertical frames




    //Set texture values
    xMax = 1.0/(float)hFrames;
    xMin = 0.0;
    yMax = 1.0/(float)vFrames;
    yMin = 0.0;

    tLoad->loadTexture(fileName, tex);



}

//Player actions
void player::actions(acts action, sounds* _snds, sceneManager* _sManager)
{

    float temp;
    float temp2;

    switch(action){
        case IDLE:


            if(clock() - startTime > 60){


            if(_sManager->gamePaused){



            }else{

                   if(playerDir == 'R'){
                xMax = 1.0/(float)hFrames;
                xMin = 0.0;
                yMax = 1.0/(float)vFrames;
                yMin = 0.0/(float)vFrames;

            }else if(playerDir == 'L'){


                xMin = 1.0/(float)hFrames;
                xMax = 0.0;
                yMax = 1.0/(float)vFrames;
                yMin = 0.0/(float)vFrames;
            }


            }


            actionTrigger = IDLE;
            }
            break;


        case WALKR:


            if(clock() - startTime > 60){




            if(_sManager->gamePaused){


                xMin = xMin;
                xMax = xMax;
            }else{

                 if(playerDir != 'R'){
                float tmp;
                tmp = xMax;
                xMax = xMin;
                xMin = tmp;
                playerDir = 'R';


                }

                xMin +=1.0/(float)hFrames;
                xMax +=1.0/(float)hFrames;

                yMin = 1.0/(float)vFrames;
                yMax = 2.0/(float)vFrames;
            }


            actionTrigger = WALKR;

            }

            if(_sManager->gamePaused){

                 pPos.x = pPos.x;
            }else{

                    if(!(pPos.x >= 10)){
                        pPos.x += runSpeed;

                    }
            }
            break;

        case WALKL:


            if(clock() - startTime > 60){





            if(_sManager->gamePaused){

                xMin = xMin;
                xMax = xMax;

            }else{

                 if(playerDir != 'L'){
                float tmp;
                tmp = xMax;
                xMax = xMin;
                xMin = tmp;
                playerDir = 'L';

                }

                xMin +=1.0/(float)hFrames;
                xMax +=1.0/(float)hFrames;

                yMin = 1.0/(float)vFrames;
                yMax = 2.0/(float)vFrames;
            }


            actionTrigger = WALKL;



            }


              if(_sManager->gamePaused){

                pPos.x = pPos.x;
            }else{

                if(!(pPos.x <= -10)){

                    pPos.x -= runSpeed;
                }

            }
            break;


        case JUMP:




                bool finishJump = false;
                startJumping = true;
                actionTrigger = JUMP;





                if(clock() - startTime > 10){


                    pPos.y += 0.1;




                 if(playerDir == 'R'){

                        if(_sManager->gamePaused){

                            pPos.y = pPos.y;
                        }else{


                            if(!(pPos.x >= 10)){
                                  pPos.x += (playerVelocity* t * cos(playerTheta)) / 1200.0;
                            }


                             pPos.y += (playerVelocity * t * sin(playerTheta) - 0.5 * GRAVITY * t * t) /700.0;
                        }



                        if(pPos.y >= -0.5){

                            t+=0.2;
                        }else{
                            pPos.y = -0.3;
                            t = 0;
                        }


                    }


                if(playerDir == 'L'){
                       if(_sManager->gamePaused){

                            pPos.y = pPos.y;
                        }else{

                            if(!(pPos.x <= -10)){
                                  pPos.x -= (playerVelocity* t * cos(playerTheta)) / 1200.0;
                            }



                             pPos.y += (playerVelocity * t * sin(playerTheta) - 0.5 * GRAVITY * t * t) /700.0;
                        }




                        if(pPos.y >= -0.5){

                            t+=0.2;
                        }else{

                            pPos.y = -0.3;
                            t = 0;
                        }



                }

                    startTime = clock();

                }











            break;

    }

}



//Hard Reset Player
//This happens then the player dies, goes back to main menu, or beats the game
void player::resetPlayer()
{
    actionTrigger = IDLE;
    playerDir = 'R';

    pPos.x = 0.0;
    pPos.y = -0.31;
    pPos.z = -2.5;


     startJumping = false;
    stopJumping = false;


    health = 200.5;
    maxHealth = 200.5;
    score = 0.0;
    attackDamage = 50.5;

    weaponType = 1;


    isShooting = false;
    isJumping = false;
    isMovingLeft = false;
    isMovingRight = false;

    startTime = clock();



}


//Soft Reset Player
//This happens when player goes to next level
void player::softResetPlayer()
{
    actionTrigger = IDLE;
    playerDir = 'R';

    pPos.x = 0.0;
    pPos.y = -0.31;
    pPos.z = -2.5;

    startJumping = false;
    stopJumping = false;

    health = maxHealth;
    score = score;


    isShooting = false;
    isJumping = false;
    isMovingLeft = false;
    isMovingRight = false;

    startTime = clock();

}


//Unused methods
string player::getHealth()
{
    stringstream strS;

    strS << health;


    string str = strS.str();
    return str;

}

string player::getScore()
{

     stringstream strS;

    strS << score;


    string str = strS.str();
    return str;

}


