#include "Inputs.h"


Inputs::Inputs()
{
    //ctor


    //gameStarted = false;
    //gamePaused = false;

    cooldown = clock(); //start cooldown timer
}

Inputs::~Inputs()
{
    //dtor
}


//Change Scenes using keyboard
void Inputs::sceneChangeUsingKey(double x, double y, sceneManager* _sManager,sounds* _snds, levelManager* _lvlManager, projectile myBullets[], enms levelEnemies[])
{
    switch(wParam){


    case VK_RETURN: //pressed ENTER

        //Change from Into Screen to Main Menu
        if(_sManager->displayIntroScreen){

            if(!_sManager->inGame){
            _snds->playSoundEffect("sounds/button_click.mp3");
            _sManager->displayIntroScreen = false;
            _sManager->displayMenuScreen = true;
            cout << "intro screen ended" << endl;
        }
        }

        break;


    case 72: //pressed 'H'

        //Go to Help Screen from Main Menu
        if(_sManager->displayMenuScreen){

                if(!_sManager->inGame){
            _snds->playSoundEffect("sounds/button_click.mp3");
            _sManager->displayIntroScreen = false;
            _sManager->displayMenuScreen = false;
            _sManager->displayHelpScreen = true;
             cout << "display help screen" << endl;
        }

        }

        //Go to Help Screen from Main Menu
        if(_sManager->inGame && _sManager->gamePaused){


            _snds->playSoundEffect("sounds/button_click.mp3");
            _sManager->inGame = false;
            _sManager->displayHelpScreen = true;
            cout << "display help screen from pause menu" << endl;

        }




        break;

    case 67: //pressed 'C'


        //Go to Credits Screen from Main Menu
        if(_sManager->displayMenuScreen){

                    if(!_sManager->inGame){
            _snds->playSoundEffect("sounds/button_click.mp3");
            _sManager->displayIntroScreen = false;
            _sManager->displayMenuScreen = false;
            _sManager->displayHelpScreen = false;
            _sManager->displayCreditsScreen = true;
             cout << "display credits screen" << endl;
        }


        }



        break;


    case 79: //pressed 'Q'

        //Go to Quit Screen from Main Menu
        if(_sManager->displayMenuScreen){

                         if(!_sManager->inGame){
            _snds->playSoundEffect("sounds/button_click.mp3");
            _sManager->displayIntroScreen = false;
            _sManager->displayMenuScreen = false;
            _sManager->displayHelpScreen = false;
            _sManager->displayCreditsScreen = false;
            _sManager->displayExitConfirmationScreen =true;
             cout << "display exit game screen" << endl;
        }




        }

        break;

    case VK_BACK: //backspace


        //Return to Main Menu from Help Screen
        if(_sManager->displayHelpScreen){


                             if(!_sManager->gameStarted){
            _snds->playSoundEffect("sounds/button_click.mp3");
            _sManager->displayIntroScreen = false;
            _sManager->displayMenuScreen = true;
            _sManager->displayHelpScreen = false;
            _sManager->displayCreditsScreen = false;
            _sManager->displayExitConfirmationScreen = false;
            cout << "return to main from help" << endl;

            }

            //Return to Game Screen from Help Screen
            if(_sManager->gameStarted && _sManager->gamePaused){


                _snds->playSoundEffect("sounds/button_click.mp3");
                _sManager->displayHelpScreen = false;
                _sManager->inGame = true;

                cout << "return to game from help" << endl;
            }

        //Return to Main Menu from Credits Screen
        }else if(_sManager->displayCreditsScreen){



                             if(!_sManager->inGame){
            _snds->playSoundEffect("sounds/button_click.mp3");
            _sManager->displayIntroScreen = false;
            _sManager->displayMenuScreen = true;
            _sManager->displayHelpScreen = false;
            _sManager->displayCreditsScreen = false;
            _sManager->displayExitConfirmationScreen = false;
            cout << "return to main from credits" << endl;
        }


        }




        break;


    case 81: //pressed 'Q'


            //Got to Quit Screen from Main Menu
          if(_sManager->displayMenuScreen){

                         if(!_sManager->inGame){
            _snds->playSoundEffect("sounds/button_click.mp3");
            _sManager->displayIntroScreen = false;
            _sManager->displayMenuScreen = false;
            _sManager->displayHelpScreen = false;
            _sManager->displayCreditsScreen = false;
            _sManager->displayExitConfirmationScreen =true;
             cout << "display exit game screen" << endl;
        }




        }
        break;


    case 78: //pressed 'N'


        //Go back to Main Menu from Quit Screen
        if(_sManager->displayExitConfirmationScreen){


                                         if(!_sManager->inGame){
            _snds->playSoundEffect("sounds/button_click.mp3");
            _sManager->displayIntroScreen = false;
            _sManager->displayMenuScreen = true;
            _sManager->displayHelpScreen = false;
            _sManager->displayCreditsScreen = false;
            _sManager->displayExitConfirmationScreen = false;
            _sManager->displayGameOverScreen = false;

             cout << "clicked no" << endl;
        }


        //Start a New Game
        }else if(_sManager->displayMenuScreen){


                                         if(!_sManager->inGame){

            _sManager->displayIntroScreen = false;
            _sManager->displayMenuScreen = false;
            _sManager->displayHelpScreen = false;
            _sManager->displayCreditsScreen = false;
            _sManager->displayExitConfirmationScreen = false;
            _sManager->inGame = true;
            _sManager->gamePaused = false;
            _sManager->gameStarted = true;
            _sManager->displayGameOverScreen = false;

            _sManager->playingLevel1 = true;
            _sManager->playingLevel2 = false;
            _sManager->playingLevel3 = false;

            _sManager->level1Complete = false;
            _sManager->level2Complete = false;
            _sManager->level3Complete = false;

            _sManager->touchLevel1Flag = false;
            _sManager->touchLevel2Flag = false;
            _sManager->touchLevel3Flag = false;

            _sManager->numLevel1EnmyLeft = 5;
            _sManager->numLevel2EnmyLeft = 5;
            _sManager->numLevel3EnmyLeft = 5;

            _lvlManager->resetProjectile(myBullets, _sManager->maxNumPlayerBullets);
            _lvlManager->resetEnemies(levelEnemies, _sManager->maxNumLevel1Enmy);


            _snds->killAllSounds();
            _snds->playSoundEffect("sounds/button_click.mp3");
                    _snds->playMusic("sounds/85.mp3");

             ShowCursor(false);
             cout << "new game was started" << endl;
        }


        }

        break;


    case 89: //pressed 'Y'

        //Exit the Game
        if(_sManager->displayExitConfirmationScreen){

            _sManager->quit = true;
             cout << "clicked yes" << endl;

        }

        break;

    case 80: //pressed 'P'



        //Pause the Game
        if(_sManager->inGame && !_sManager->gamePaused){

                _snds->playSoundEffect("sounds/button_click.mp3");

            _sManager->gamePaused = true;
            ShowCursor(false);
            ShowCursor(true);
            cout << "game was paused" << endl;

        //Unpause the Game
        }else if(_sManager->inGame && _sManager->gamePaused){

            _snds->playSoundEffect("sounds/button_click.mp3");
            _sManager->gamePaused = false;
            ShowCursor(false);
            cout << "game was unpaused" << endl;
        }

        break;


    case 77: //pressed 'M'

        //Go back to Main Menu from the Game Screen
        if(_sManager->inGame && _sManager->gamePaused){
                _snds->playSoundEffect("sounds/button_click.mp3");
                 ShowCursor(true);


                    _sManager->inGame = false;
                    _sManager->displayMenuScreen = true;
                    _sManager->gamePaused = true;
                    _sManager->gameStarted = false;
                    _snds->killAllSounds();
                    _snds->playMusic("sounds/01.mp3");
                    cout <<"main menu screen from game" << endl;

        //Go back to Main Menu from Game Over Screen
        }else if(_sManager->displayGameOverScreen){
            _snds->playSoundEffect("sounds/button_click.mp3");
             ShowCursor(true);

                 _sManager->inGame = false;
                    _sManager->displayMenuScreen = true;
                    _sManager->gamePaused = true;
                    _sManager->gameStarted = false;


                     _sManager->playingLevel1  = false;
                     _sManager->playingLevel2  = false;
                    _sManager->playingLevel3  = false;

                     _sManager->level1Complete  = false;
                    _sManager->level2Complete  = false;
                     _sManager->level3Complete  = false;


                    _sManager->touchLevel1Flag  = false;
                     _sManager->touchLevel2Flag  = false;
                    _sManager->touchLevel3Flag = false;

                    _snds->killAllSounds();
                    _snds->playMusic("sounds/01.mp3");
                cout << "return to main from game over" << endl;

        //Go Back to Main Menu from Win Screen
        }else if(_sManager->displayWinScreen){


                    ShowCursor(true);

                _sManager->displayWinScreen = false;
                 _sManager->inGame = false;
                    _sManager->displayMenuScreen = true;
                    _sManager->gamePaused = true;
                    _sManager->gameStarted = false;

                    _sManager->playingLevel1  = false;
                     _sManager->playingLevel2  = false;
                    _sManager->playingLevel3  = false;

                     _sManager->level1Complete  = false;
                    _sManager->level2Complete  = false;
                     _sManager->level3Complete  = false;


                    _sManager->touchLevel1Flag  = false;
                     _sManager->touchLevel2Flag  = false;
                    _sManager->touchLevel3Flag = false;

                    _snds->killAllSounds();
                    _snds->playSoundEffect("sounds/button_click.mp3");
                    _snds->playMusic("sounds/01.mp3");

                    cout <<"main menu screen from win screen" << endl;
        }



        break;



    }
}



//Change Scene using Mouse
void Inputs::sceneChangeUsingMouse(double x, double y, sceneManager* _sManager, button* btn, float xMinVal, float xMaxVal, float yMinVal, float yMaxVal, sounds* _snds, levelManager* _lvlManager, projectile myBullets[], enms levelEnemies[])
{


        GetCursorPos(&mouseCursorPos); //get the mouse pixel coordinates


        int viewPort[4]; //viewport
        GLdouble modelView[16]; //matrix that holds model transforms and camera postion
        GLdouble projectionMat[16]; //matrix that tells how you are looking at
        GLfloat winX, winY, winZ; //window x, y, and z values

        glGetDoublev(GL_PROJECTION_MATRIX, projectionMat);
        glGetDoublev(GL_MODELVIEW_MATRIX, modelView);
        glGetIntegerv(GL_VIEWPORT, viewPort);


        winX = (GLfloat)mouseCursorPos.x; //convert width of screen
        //winX is the window x value

        winY = (GLfloat)viewPort[3] - (GLfloat)mouseCursorPos.y; //viewPort[3] is the height of the screen, need to subtract y because window
        //origin is top left of screen
        //winY is the window y value

        glReadPixels(mouseCursorPos.x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ); //get the depth value
        //winZ is the window depth value


        gluUnProject(winX, winY, winZ, modelView, projectionMat, viewPort, &realMX, &realMY, &realMZ);
        //the last three inputs are the real mouse postions that are updated by this function

        //get the world coordinates for the mouse cursor
        double sX = realMX; //x world coordinate
        double sY = realMY; //y wold coordinate


        //cout << "x: " << sX << endl;
        //cout << "y: " << sY << endl;


        //Check if we click on a button
        if((sX >= xMinVal && sX <= xMaxVal) && (sY >= yMinVal && sY <= yMaxVal)){

            cout << "mouse click was in range " << endl;

             //Change from Into Screen to Main Menu
            if(btn->name == "exitIntro" && _sManager->displayIntroScreen){



                 if(!_sManager->inGame){
                     _snds->playSoundEffect("sounds/button_click.mp3");
                    _sManager->displayIntroScreen = false;
                    _sManager->displayMenuScreen = true;
                    cout << "intro screen ended" << endl;

                }

            }


            //Change from Main Menu to Help Screen
            if(btn->name == "helpControls" && _sManager->displayMenuScreen){

                 if(!_sManager->inGame){
                    _snds->playSoundEffect("sounds/button_click.mp3");
                    _sManager->displayIntroScreen = false;
                    _sManager->displayMenuScreen = false;

                    _sManager->displayHelpScreen = true;
                    cout << "display help screen" << endl;
                }

            }


            //Change from Main Menu to Credits Screen
             if(btn->name == "credits" && _sManager->displayMenuScreen){

                 if(!_sManager->inGame){
                    _snds->playSoundEffect("sounds/button_click.mp3");
                    _sManager->displayIntroScreen = false;
                    _sManager->displayMenuScreen = false;

                    _sManager->displayHelpScreen = false;
                    _sManager->displayCreditsScreen = true;
                    cout << "display credits screen" << endl;
                }

            }


            //Change from Main Menu to Quit Screen
             if(btn->name == "quitGame" && _sManager->displayMenuScreen){

                 if(!_sManager->inGame){
                    _snds->playSoundEffect("sounds/button_click.mp3");
                    _sManager->displayIntroScreen = false;
                    _sManager->displayMenuScreen = false;

                    _sManager->displayHelpScreen = false;
                    _sManager->displayCreditsScreen = false;
                    _sManager->displayExitConfirmationScreen = true;
                    cout << "display exit game screen" << endl;
                }

            }


            //Start a New Game
             if(btn->name == "startGame" && _sManager->displayMenuScreen){

                 if(!_sManager->inGame){
                    _sManager->displayIntroScreen = false;
                    _sManager->displayMenuScreen = false;

                    _sManager->displayHelpScreen = false;
                    _sManager->displayCreditsScreen = false;
                    _sManager->displayExitConfirmationScreen = false;
                     _sManager->displayGameOverScreen = false;

                    _sManager->inGame = true;
                    _sManager->gamePaused = false;
                    _sManager->gameStarted = true;


                    _sManager->playingLevel1 = true;
                    _sManager->playingLevel2 = false;
                    _sManager->playingLevel3 = false;

                    _sManager->level1Complete = false;
                    _sManager->level2Complete = false;
                    _sManager->level3Complete = false;

                    _sManager->touchLevel1Flag = false;
                    _sManager->touchLevel2Flag = false;
                    _sManager->touchLevel3Flag = false;

                    _sManager->numLevel1EnmyLeft = 5;
                    _sManager->numLevel2EnmyLeft = 5;
                    _sManager->numLevel3EnmyLeft = 5;

                    _lvlManager->resetProjectile(myBullets, _sManager->maxNumPlayerBullets);
                    _lvlManager->resetEnemies(levelEnemies, _sManager->maxNumLevel1Enmy);

                    _snds->killAllSounds();
                     _snds->playSoundEffect("sounds/button_click.mp3");
                    _snds->playMusic("sounds/85.mp3");


                    ShowCursor(false);
                     //_snds->playMusic("sounds/85.mp3");
                    cout << "new game was started" << endl;
                }

            }



            //Quit the Game
             if(btn->name == "exitYes" && _sManager->displayExitConfirmationScreen){

                    _sManager->quit = true;
                    cout << "clicked yes" << endl;



            }




            //Go back to Main Menu from Quit Game Screen
             if(btn->name == "exitNo" && _sManager->displayExitConfirmationScreen){



                if(!_sManager->inGame){
                    _snds->playSoundEffect("sounds/button_click.mp3");
                    _sManager->displayIntroScreen = false;
                    _sManager->displayMenuScreen = true;
                    _sManager->displayHelpScreen = false;
                    _sManager->displayCreditsScreen = false;
                    _sManager->displayExitConfirmationScreen = false;
                    cout << "clicked no" << endl;
                }


            }



              if(btn->name == "helpReturnToMain" && _sManager->displayHelpScreen && !_sManager->gameStarted){

                //Go back to Main Menu from Help Screen
                 if(!_sManager->inGame && !_sManager->gameStarted){
                    _snds->playSoundEffect("sounds/button_click.mp3");
                    _sManager->displayIntroScreen = false;
                    _sManager->displayMenuScreen = true;

                    _sManager->displayHelpScreen = false;
                    _sManager->displayCreditsScreen = false;
                    _sManager->displayExitConfirmationScreen = false;
                     cout << "return to main from help" << endl;

                }

                //Go back to Main Menu from Game Screen
                if(_sManager->gameStarted && _sManager->gamePaused){

                    _sManager->displayHelpScreen = false;
                    _sManager->inGame = true;

                    cout << "return to game from help" << endl;
                }

            }



            //Go back to Main Menu from Credits Screen
               if(btn->name == "creditsReturnToMain" && _sManager->displayCreditsScreen){

                 if(!_sManager->inGame){
                    _snds->playSoundEffect("sounds/button_click.mp3");
                    _sManager->displayIntroScreen = false;
                    _sManager->displayMenuScreen = true;

                    _sManager->displayHelpScreen = false;
                    _sManager->displayCreditsScreen = false;
                    _sManager->displayExitConfirmationScreen = false;
                     cout << "return to main from credits" << endl;

                }

            }


            //Unpause the game
            if(btn->name == "resumeGame" && _sManager->inGame && _sManager->gamePaused){
                    _sManager->gamePaused = false;
                    cout <<"resume game" << endl;
            }


            //Go to help screen from Game Screen
            if(btn->name == "helpFromGame" && _sManager->gameStarted && _sManager->gamePaused){
                    _sManager->inGame = false;
                    _sManager->displayHelpScreen = true;
                    cout <<"help screen from game" << endl;
            }



            //Go to main menu from Game Screen
             if(btn->name == "backToMain" && _sManager->gameStarted && _sManager->gamePaused){
                    _sManager->inGame = false;
                    _sManager->displayMenuScreen = true;
                    _sManager->gamePaused = true;
                    _sManager->gameStarted = false;
                    _snds->killAllSounds();
                    _snds->playMusic("sounds/01.mp3");
                    cout <<"main menu screen from game" << endl;
            }




            //Go back to Main Menu from Game Over Screen
            if(btn->name == "returnToMain" && _sManager->displayGameOverScreen){
                _snds->playSoundEffect("sounds/button_click.mp3");
                     ShowCursor(true);

                 _sManager->inGame = false;
                    _sManager->displayMenuScreen = true;
                    _sManager->gamePaused = true;
                    _sManager->gameStarted = false;
                    _sManager->playingLevel1  = false;
                     _sManager->playingLevel2  = false;
                    _sManager->playingLevel3  = false;

                     _sManager->level1Complete  = false;
                    _sManager->level2Complete  = false;
                     _sManager->level3Complete  = false;


                    _sManager->touchLevel1Flag  = false;
                     _sManager->touchLevel2Flag  = false;
                    _sManager->touchLevel3Flag = false;

                    _snds->killAllSounds();
                    _snds->playMusic("sounds/01.mp3");
                    cout <<"main menu screen from game over" << endl;
            }





            //Go back to Main Menu from Win Screen
            if(btn->name == "returnToMain" && _sManager->displayWinScreen){
                _snds->playSoundEffect("sounds/button_click.mp3");
                     ShowCursor(true);

                _sManager->displayWinScreen = false;
                 _sManager->inGame = false;
                    _sManager->displayMenuScreen = true;
                    _sManager->gamePaused = true;
                    _sManager->gameStarted = false;

                                 _sManager->playingLevel1  = false;
                     _sManager->playingLevel2  = false;
                    _sManager->playingLevel3  = false;

                     _sManager->level1Complete  = false;
                    _sManager->level2Complete  = false;
                     _sManager->level3Complete  = false;


                    _sManager->touchLevel1Flag  = false;
                     _sManager->touchLevel2Flag  = false;
                    _sManager->touchLevel3Flag = false;

                     _snds->killAllSounds();
                    _snds->playMusic("sounds/01.mp3");

                    cout <<"main menu screen from win screen" << endl;
            }






        }




}



//Handle Player inputs
void Inputs::keyPlayer(player* ply, sounds* _snds, sceneManager* _sManager ,projectile myBullets[], int &i, int maxDrops)
{


    BYTE keyBoardState[256];
    GetKeyboardState(keyBoardState);

    //Right Arrow key
    if(keyBoardState[VK_RIGHT] & 0x80){

        ply->isMovingRight = true;
        //cout << "Right" << endl;
    }else{

        ply->isMovingRight = false;
    }


    //Left Arrow Key
     if(keyBoardState[VK_LEFT] & 0x80){

        ply->isMovingLeft = true;
        //cout << "Left" << endl;
    }else{

        ply->isMovingLeft = false;
    }

    if(keyBoardState[VK_LEFT] & keyBoardState[VK_RIGHT] & 0x80){
        //cout << "RightLeft" << endl;
    }


    //Up Arrow Key
     if(keyBoardState[VK_UP] & 0x80){

        ply->isJumping = true;
        //cout << "Up" << endl;
    }else{

        ply->isJumping = false;
    }


    //Space
     if(keyBoardState[VK_SPACE] & 0x80){



        ply->isShooting = true;
    }else{

        ply->isShooting = false;
    }


    //check for action to perform
    if(ply->isMovingRight){

        ply->actions(ply->WALKR, _snds, _sManager);

    }

    if(ply->isMovingLeft){

         ply->actions(ply->WALKL, _snds, _sManager);

    }

    if(ply->isJumping){
        ply->actions(ply->JUMP, _snds, _sManager);

    }


    if(ply->isShooting){


         if(clock() - cooldown > 170){



        //note: I'm not sure if I can move the texture loading step outside of the keyProjectile() method
        //Right now I'm just loading the texture each time a fireball object is instantiated, but I;m not sure if this is incurring massive overhead

        //Set starting positions of fireball projectile movement
        myBullets[i].alive = true;
        myBullets[i].position.x = ply->pPos.x;
        myBullets[i].position.y = ply->pPos.y - 0.15;



        if(ply->playerDir == 'R'){

             myBullets[i].direction = ply->playerDir;
             myBullets[i].actionTrigger = myBullets[i].MOVER;
        }


        if(ply->playerDir == 'L'){
            myBullets[i].direction = ply->playerDir;
            myBullets[i].actionTrigger = myBullets[i].MOVEL;

        }



        i++; //increment the index
        //This will make it so the next time the player presses space, we will be creating a new fireball

        //Precaution check
        //This handles the case when the player manages to press the space key more than the maximum number of fireball allowed
        if(i >= maxDrops){ //if the current index is greater than or equal to maxDrops then we will have an array access violation

            i = 0; //set the index back to 0, ie the first fireball that was created
        }






        //_snds->playSoundEffect("sounds/laserRocket.mp3");
        _snds->playSoundEffect("sounds/player_attack.mp3");
        cooldown = clock();



        //start here//



        }





    }


}


//Handle key released
void Inputs::keyUp()
{
   switch(wParam)
  {



  }
}




//Unused Methods
void Inputs::keyProjectile(projectile* myBullets[], int &i, float playerX, float playerY, int maxDrops, sceneManager* _sManager, char dir)
{


    if(clock() - cooldown > 200){



    if(wParam == VK_SPACE){

     //if player presses space create a fireball projectile

       myBullets[i] = new projectile(); //instantiate new projectile object, ie create fireball

        myBullets[i]->projectileTexture("images/mega_shot.png"); //load fireball texture
        myBullets[i]->initProjectile(myBullets[i]->tex, 4, 1); //initialize the fireball projectile
        myBullets[i]->projectileType = "P";

        //note: I'm not sure if I can move the texture loading step outside of the keyProjectile() method
        //Right now I'm just loading the texture each time a fireball object is instantiated, but I;m not sure if this is incurring massive overhead

        //Set starting positions of fireball projectile movement
        myBullets[i]->position.x = playerX; //fireball x position is the players current x position when they pressed space
        myBullets[i]->position.y = playerY - 0.15; //fireball y position is the players current y position when they pressed space


        if(dir == 'R'){

             myBullets[i]->direction = dir;
             myBullets[i]->actionTrigger = myBullets[i]->MOVER;
        }


        if(dir == 'L'){
             myBullets[i]->direction = dir;
            myBullets[i]->actionTrigger = myBullets[i]->MOVEL;

        }

        //myBullets[i]->direction = ply->playerDir;


        i++; //increment the index
        //This will make it so the next time the player presses space, we will be creating a new fireball

        //Precaution check
        //This handles the case when the player manages to press the space key more than the maximum number of fireball allowed
        if(i >= maxDrops){ //if the current index is greater than or equal to maxDrops then we will have an array access violation

            i = 0; //set the index back to 0, ie the first fireball that was created
        }



    }

    cooldown = clock();
    }


}



//Vestigial Methods from inputs lecture
void Inputs::mouseBtnDwn(Model * mdl,double x, double y)
{
     prev_Mx = x;
     prev_My = y;

     switch(wParam)
     {
         case MK_LBUTTON: Mouse_Rotate = true; break;
         case MK_RBUTTON: Mouse_translate = true; break;
         case MK_MBUTTON: break;
     }
}

void Inputs::mouseBtnUp()
{
    Mouse_Rotate = false;
    Mouse_translate = false;
}

void Inputs::mouseWheel(Model * mdl,double delta)
{
    mdl->zoom +=delta/100.0;
}

void Inputs::mouseMove(Model * mdl,double x, double y)
{
    if(Mouse_translate)
    {
        mdl->posX += (x - prev_Mx)/100.0;
        mdl->posY -= (y - prev_My)/100.0;

        prev_Mx =x;
        prev_My =y;
    }

    if(Mouse_Rotate)
    {
        mdl->rotateX += (x - prev_Mx)/3.0;
        mdl->rotateY += (y - prev_My)/3.0;

        prev_Mx =x;
        prev_My =y;
    }

}


void Inputs::keyEnv(parallax* plx, float speed)
{
    switch(wParam)
  {
  case VK_LEFT:
    plx->xMax -= speed;
    plx->xMin -= speed;
    break;

  case VK_RIGHT:
    plx->xMax += speed;
    plx->xMin += speed;
    break;

  case VK_DOWN:
    plx->yMax += speed;
    plx->yMin += speed;
    break;

  case VK_UP:
    plx->yMax -= speed;
    plx->yMin -= speed;
    break;
  }
}


void Inputs::keyPressed(Model * mdl)
{
  switch(wParam)
  {
  case VK_LEFT:
    mdl->rotateY -=1.0;
    break;

  case VK_RIGHT:
    mdl->rotateY +=1.0;
    break;

  case VK_DOWN:
    mdl->rotateX +=1.0;
    break;

  case VK_UP:
    mdl->rotateX -=1.0;
    break;

  case VK_SUBTRACT:
    mdl->zoom -=1.0;
    break;

    case VK_ADD:
    mdl->zoom +=1.0;
    break;
  }
}


