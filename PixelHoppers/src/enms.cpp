#include "enms.h"

enms::enms()
{
    //ctor

    //Set default position
    ePos.x =  0.7;
    ePos.y = -0.6;
    ePos.z = -2.6;

    //Set default scale factor
    eSize.x = 0.4;
    eSize.y = 0.4;

    //Set default rotaion angles
    eRot.x = eRot.y = eRot.z = 0.0;

    //eSpeed.x = -0.08;
    //Set default speeds
    eSpeed.x = -0.07;
    eSpeed.y = 0.0;

    action = WALKL; //default action is walk left

    //Set projectile motion values
    theta = 30 * PI/180.0;
    velocity = 35;
    t = 0;

    enemyDir = 'L'; //default direction is left

    enemyDamage = 2.5; //default damage
    enemyHealth = 100.0; //current health

    defaultHealth = enemyHealth; //default max health

    alive = false; //enemy is not alive

    startTime = clock(); //start animation timer
    finishRoll = clock(); //start knockback timer

}

enms::~enms()
{
    //dtor
}

//Draw Enemy in the Scene
void enms::drawEnemy(sceneManager* _sManager)
{

    tLoad->binder(tex); //bind the texture
    glPushMatrix();


        glTranslated(ePos.x, ePos.y, ePos.z); //translate
        glRotatef(eRot.x, 1.0, 0.0, 0.0);  //rotate about x-axis
        glRotatef(eRot.y, 0.0, 1.0, 0.0);  //rotate about y-axis
        glRotatef(eRot.z, 0.0, 0.0, 1.0);  //rotate about z-axis
        glScalef(eSize.x, eSize.y, 1.0); //apply scale factor

        //Draw the enemy
        glBegin(GL_POLYGON);
            glTexCoord2f(xMin, yMin);
            glVertex3f(1.0, 1.0, 0.0);

            glTexCoord2f(xMax, yMin);
            glVertex3f(-1.0, 1.0, 0.0);

            glTexCoord2f(xMax, yMax);
            glVertex3f(-1.0, -1.0, 0.0);

            glTexCoord2f(xMin, yMax);
            glVertex3f(1.0, -1.0, 0.0);


        glEnd();

    actions(_sManager); //set actions
    glPopMatrix();

}


//Set Spawn point
void enms::setSpawnPositon(float xPos, float yPos, float zPos)
{


    //Set position using input position
    ePos.x = xPos;
    ePos.y = yPos;
    ePos.z = zPos;

}


//Load Texture
void enms::enemyTexture(char* fileName)
{
    tLoad->loadTexture(fileName, tex); //load texture from image

}


//Enemy Initialization
void enms::initEnemy(GLuint tex, int hFrm, int vFrm)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //transparency

    vFrames = vFrm; //set vertical frames
    hFrames = hFrm; //set horizontal frames

    //Set Texture values
    xMax = 1.0/(float)hFrames;
    xMin = 0.0;
    yMax = 1.0/(float)vFrames;
    yMin = 0.0;

    this->tex = tex;

}

//Handle Enemy Actions
void enms::actions(sceneManager* _sManager)
{

    switch(action){


    case IDLE:

        //Idle Animation
        if(clock() - startTime > 60){
            xMin += 1.0/(float)hFrames;
            xMax += 1.0/(float)hFrames;
        }


        break;

    case WALKR:

        if(clock() - startTime > 60){


            //Check enemy direction, set it to right
             if(enemyDir != 'R'){
                float tmp;
                tmp = xMax;
                xMax = xMin;
                xMin = tmp;
                enemyDir = 'R';


            }







            //If game is pause then don't play animation
            if(_sManager->gamePaused){

                xMin = xMin;
                xMax = xMax;

            }else{

                //Walk right animation
                xMin += 1.0/(float)hFrames;
                xMax += 1.0/(float)hFrames;
            }




            //Check what type the enemy is
            //Need to do this because enemy sprite sheets can be different

            //If enemy is a skeleton
            if(enemyName == "Skel"){


                yMax = 3.0/(float)vFrames;
                yMin = 2.0/(float)vFrames;
            }

            if(enemyName == "Cultist"){


                  if(xMin >= 8.0/(float)hFrames){

                   xMin = 1.0/(float)hFrames;
                   xMax = 0.0;
                }

                yMax = 2.0/(float)vFrames;
                yMin = 1.0/(float)vFrames;

            }


             if(enemyName == "Fiend"){


                  if(xMin >= 8.0/(float)hFrames){

                   xMin = 1.0/(float)hFrames;
                   xMax = 0.0;
                }


                yMax = 2.0/(float)vFrames;
                yMin = 1.0/(float)vFrames;
            }


            //Rest y and z position
            ePos.y = ePos.y;
            eRot.z = 0.0;


            //If game is pause then don't move enemy to the right
              if(_sManager->gamePaused){
                ePos.x = ePos.x;

            }else{

                //Move enemy to the right
                ePos.x -=eSpeed.x;
            }


            startTime = clock(); //reset timer

        }

        break;

    case WALKL:

         if(clock() - startTime > 60){


           //Check enemy direction, set it to left
             if(enemyDir != 'L'){
                float tmp;
                tmp = xMax;
                xMax = xMin;
                xMin = tmp;
                enemyDir = 'L';


            }



            //If game is pause then don't play animation
            if(_sManager->gamePaused){

                xMin = xMin;
                xMax = xMax;

            }else{
                //Walk left animation
                xMin += 1.0/(float)hFrames;
                xMax += 1.0/(float)hFrames;
            }




              //If enemy is a skeleton
            if(enemyName == "Skel"){

                if(xMin >= 12.0/(float)hFrames){
                   xMin = 0.0;
                   xMax = 1.0/(float)hFrames;
                }

                //yMax = 1.0/(float)vFrames;
                //yMin = 0.0;


                yMax = 3.0/(float)vFrames;
                yMin = 2.0/(float)vFrames;


            }


            if(enemyName == "Cultist"){

                if(xMin >= 8.0/(float)hFrames){
                   xMin = 0.0;
                   xMax = 1.0/(float)hFrames;
                }

                //yMax = 1.0/(float)vFrames;
                //yMin = 0.0;


                yMax = 2.0/(float)vFrames;
                yMin = 1.0/(float)vFrames;


            }



             if(enemyName == "Fiend"){


                  if(xMin >= 8.0/(float)hFrames){

                   xMax = 1.0/(float)hFrames;
                   xMin = 0.0;
                }


                yMax = 2.0/(float)vFrames;
                yMin = 1.0/(float)vFrames;
            }







            //Rest y and z position
            ePos.y = ePos.y;
            eRot.z = 0.0;


             //If game is pause then don't move enemy to the left
            if(_sManager->gamePaused){
                ePos.x = ePos.x;

            }else{

                 //Move enemy to the left
                ePos.x +=eSpeed.x;
            }




            startTime = clock(); //reset timer

        }

        break;


    case ROLLR:

        if(clock() - startTime > 60){


             //If game is pause then don't play animation
            if(_sManager->gamePaused){
                xMin = xMin;
                xMax = xMax;

            }else{

                //push enemy right
                xMin += 1.0/(float)hFrames;
                xMax += 1.0/(float)hFrames;
            }


            //If enemy is a skeleton
            if(enemyName == "Skel"){

                yMax = 2.0/(float)vFrames;
                yMin = 1.0/(float)vFrames;
            }



            if(enemyName == "Cultist"){

                yMax = 6.0/(float)vFrames;
                yMin = 5.0/(float)vFrames;
            }



              if(enemyName == "Fiend"){

                yMax = 7.0/(float)vFrames;
                yMin = 6.0/(float)vFrames;
            }





             //If game is pause then don't move enemy to the right
            if(_sManager->gamePaused){
                ePos.x = ePos.x;

            }else{


                 //Move enemy to the right
                if(clock() - finishRoll > 400){


                    action = WALKL;
                    finishRoll = clock();
                    break;
                }else{

                  ePos.x += 0.25;
                }

            }



            startTime = clock(); //start timer

        }


        break;

    case ROLLL:


        if(clock() - startTime > 60){



             //If game is pause then don't play animation
            if(_sManager->gamePaused){
                xMin = xMin;
                xMax = xMax;

            }else{

                //push enemy left
                xMin += 1.0/(float)hFrames;
                xMax += 1.0/(float)hFrames;
            }


            //If enemy is a skeleton
            if(enemyName == "Skel"){
                 yMax = 2.0/(float)vFrames;
                yMin = 1.0/(float)vFrames;
            }

            if(enemyName == "Cultist"){

                yMax = 6.0/(float)vFrames;
                yMin = 5.0/(float)vFrames;
            }


              if(enemyName == "Fiend"){

                yMax = 7.0/(float)vFrames;
                yMin = 6.0/(float)vFrames;
            }



             //If game is pause then don't move enemy to the left
            if(_sManager->gamePaused){
                ePos.x = ePos.x;

            }else{


                //Move enemy to the left
                if(clock() - finishRoll > 400){

                    action = WALKR;
                    finishRoll = clock();
                    break;
                }else{
                  ePos.x -= 0.25;
                }
            }



            startTime = clock(); //start timer

        }


        break;

    }

}


//Vestigial methods from enemies lecture
void enms::placeEnemy(vec3 p)
{

    ePos.x = p.x;
    ePos.y = p.y;
    ePos.z = p.z;

}
