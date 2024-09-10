#include "projectile.h"

projectile::projectile()
{
    //ctor

    //Default projectile positions
    position.x =  0.0;
    position.y = 0.0;
    position.z = -2.5;


    //Default projectile scale factors
    scaleSize.x = 0.05;
    scaleSize.y = 0.05;
    scaleSize.z = 1.0;

    //Default rotation angles for projectiles
    rotation.x = rotation.y = rotation.z = 0.0;


    speed.x = 0.25; //default speed of x direction movement
    speed.y = 0.03; //default speed of y direction movement

    action = MOVER; //default action for projectiles is to move right

    t = 0; //set t time variable
    //theta = 30 * PI/180.0;
    theta = 0.0;
    velocity = 23.0; //initial velocity

    projectileType = "N";

    direction = 'R'; //default direction is right

    alive = true; //projectile is alive by default

    startTime = clock(); //start the timer

}

projectile::~projectile()
{
    //dtor
}


//Handle Projectile Actions
void projectile::actions(sceneManager* _sManager)
{

    switch(actionTrigger){


    case MOVER:


        if(clock() - startTime > 60){




            if(_sManager->gamePaused){
                xMin = xMin; //increment xMin to next frame
                xMax = xMax; //increment xMax to next frame






            }else{


                if(direction != 'R'){
                float tmp;
                tmp = xMax;
                xMax = xMin;
                xMin = tmp;
                direction = 'R';


                }

                //Projectile animation using horizontal and vertical frames
                xMin += 1.0/(float)hFrames; //increment xMin to next frame
                xMax += 1.0/(float)hFrames; //increment xMax to next frame




            }


            if(_sManager->gamePaused){

                 position.x  = position.x; //make the projectile move upward
            }else{
                  position.x  = position.x +  speed.x; //make the projectile move upward
            }


            startTime = clock(); //reset the timer




        }


        break;


    case MOVEL:


         if(clock() - startTime > 60){




            if(_sManager->gamePaused){
                xMin = xMin; //increment xMin to next frame
                xMax = xMax; //increment xMax to next frame






            }else{


                if(direction != 'L'){
                float tmp;
                tmp = xMax;
                xMax = xMin;
                xMin = tmp;
                direction = 'L';


                }

                //Projectile animation using horizontal and vertical frames
                xMin += 1.0/(float)hFrames; //increment xMin to next frame
                xMax += 1.0/(float)hFrames; //increment xMax to next frame





            }



              if(_sManager->gamePaused){

                 position.x  = position.x; //make the projectile move upward
            }else{
                  position.x  = position.x -  speed.x; //make the projectile move upward
            }

            startTime = clock(); //reset the timer




        }

        break;


    case IDLE:

        position.x = position.x;
        position.y = position.y;

        xMin = xMin; //increment xMin to next frame
        xMax = xMax; //increment xMax to next frame
        break;


    }

}


//Draw Projectile in scene
void projectile::drawProjectile(sceneManager* _sManager)
{

    tLoad->binder(tex); //bind the projectile's texture
    glPushMatrix(); //push the projectile onto the stack


        glTranslatef(position.x, position.y, position.z); //translate the projectile
        glRotatef(rotation.x, 1.0, 0.0, 0.0);  //rotation about x-axis
        glRotatef(rotation.y, 0.0, 1.0, 0.0);  //rotation about y-axis
        glRotatef(rotation.z, 0.0, 0.0, 1.0);  //rotation about z-axis
        glScalef(scaleSize.x, scaleSize.y, scaleSize.z); //apply scale factors

        glBegin(GL_QUADS); //start drawing the projectile
            glTexCoord2f(xMin, yMin);
            glVertex3f(1.0, 1.0, 0.0);

            glTexCoord2f(xMax, yMin);
            glVertex3f(-1.0, 1.0, 0.0);

            glTexCoord2f(xMax, yMax);
            glVertex3f(-1.0, -1.0, 0.0);

            glTexCoord2f(xMin, yMax);
            glVertex3f(1.0, -1.0, 0.0);


        glEnd(); //we finished drawing the projectile

    actions(_sManager); //perform any operations tied to specific actions
    glPopMatrix(); //pop the projectile from the stack

}



void projectile::projectileTexture(char* fileName)
{
     tLoad->loadTexture(fileName, tex); //load the projectile texture



}


void projectile::initProjectile(GLuint tex, int hFrm, int vFrm)
{

    //Enable GL_BLEND to preserve transparency of png
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    vFrames = vFrm; //get the number of vertical frames for projectile sprite sheet
    hFrames = hFrm; //get the number of horizontal frames for projectile sprite sheet

    //Get the first frame
    xMax = 1.0/(float)hFrames;
    xMin = 0.0;
    yMax = 1.0/(float)vFrames;
    yMin = 0.0;

    this->tex = tex; //set texture handler

}


//Set projectile position
void projectile::placeProjectile(float xPos, float yPos, float zPos)
{

    //Set position using input position
    position.x = xPos;
    position.y = yPos;
    position.z = zPos;

}


//Unused methods
void projectile::updateProjectile()
{

}
