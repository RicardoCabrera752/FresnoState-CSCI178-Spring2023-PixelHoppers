//#include<commons.h>
#include "GLScene.h"





GLScene::GLScene()
{
    //ctor

    //Get Screen Resolution
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth  = GetSystemMetrics(SM_CXSCREEN);

     doneLoading = false;
     isLevel1 = false;
     isLevel2 = false;

     initOnce = false;


    KbMs = new Inputs();
    ply = new player();
    hit = new checkCollision();
    snds = new sounds();

    sManager = new sceneManager();

    cManager = new collisionManager();

    lvlManager = new levelManager();


    //Screens
    introScreen = new parallax();
    creditsScreen = new parallax();
    helpScreen = new parallax();
    startMenuScreen = new parallax();
    exitConfirmationScreen = new parallax();
    gameOverScreen = new parallax();
    winScreen = new parallax();

    //intro screen buttons
    exitIntro = new button(0.0,-0.5,-2.0, 0.1, 0.05, 1.0, "exitIntro");
    exitIntroText = new Fonts(-0.12,-0.53,-2.0, 0.5, 0.5, 1.0);

    //main menu screen buttons and text
    startGame = new button(0.0,0.0, -2.0, 0.1, 0.05, 1.0, "startGame");
    helpControls = new button(0.0, -0.15, -2.0, 0.1, 0.05, 1.0, "helpControls");
    credits = new button(0.0, -0.30, -2.0, 0.1, 0.05, 1.0, "credits");
    quitGame = new button(0.0, -0.45, -2.0, 0.1, 0.05, 1.0, "quitGame");

    startGameText = new Fonts(-0.12,-0.03,-2.0, 0.5, 0.5, 1.0);
    helpControlsText = new Fonts(-0.12,-0.18,-2.0, 0.5, 0.5, 1.0);
    creditsText = new Fonts(-0.12,-0.33,-2.0, 0.5, 0.5, 1.0);
    quitGameText = new Fonts(-0.12,-0.48,-2.0, 0.5, 0.5, 1.0);

    //return to menu screen buttons
    helpReturnToMain = new button(0.0, 0.0, -2.0, 0.1, 0.05, 1.0, "helpReturnToMain");
    creditsReturnToMain = new button(0.0, 0.0, -2.0, 0.1, 0.05, 1.0, "creditsReturnToMain");

    helpReturnToMainText = new Fonts(-0.12,-0.03,-2.0, 0.5, 0.5, 1.0);
    creditsReturnToMainText = new Fonts(-0.12,-0.03,-2.0, 0.5, 0.5, 1.0);


    //exit game confirmation buttons
    exitConfirmationYes = new button(0.0, 0.0, -2.0, 0.1, 0.05, 1.0, "exitYes");
    exitConfirmationNo = new button(0.0, -0.15, -2.0, 0.1, 0.05, 1.0, "exitNo");

    exitConfirmationYesText = new Fonts(-0.1,-0.03,-2.0, 0.5, 0.5, 1.0);
    exitConfirmationNoText = new Fonts(-0.1,-0.18,-2.0, 0.5, 0.5, 1.0);

    exitConfirmationQuestion = new Fonts(-0.1,0.1,-2.0, 0.5, 0.5, 1.0);


    //pause menu buttons and text
    resumeGame = new button(0.0, 0.0, -2.0, 0.1, 0.05, 1.0, "resumeGame");
    helpFromGame = new button(0.0, -0.15, -2.0, 0.1, 0.05, 1.0, "helpFromGame");
    backToMain = new button(0.0, -0.30, -2.0, 0.1, 0.05, 1.0, "backToMain");

    helpReturnToGame = new button(0.0, 0.0, -2.0, 0.1, 0.05, 1.0, "helpReturnToGame");
    helpScreenFromGame = new parallax();

    resumeGameText = new Fonts(-0.12,-0.03,-2.0, 0.5, 0.5, 1.0);
    helpFromGameText = new Fonts(-0.12,-0.18,-2.0, 0.5, 0.5, 1.0);
    backToMainText  = new Fonts(-0.12,-0.33,-2.0, 0.5, 0.5, 1.0);

    helpReturnToGameText = new Fonts(0.0,0.0,-2.0, 0.5, 0.5, 1.0);

    gamePausedText = new Fonts(-0.1,0.1,-2.0, 0.5, 0.5, 1.0);


    //game over and win buttons
    returnToMain = new button(0.0,0.0, -2.0, 0.1, 0.05, 1.0, "returnToMain");
    returnToMainText = new Fonts(-0.12,-0.03,-2.0, 0.5, 0.5, 1.0);



    //player health and score
    playerHealth = new Fonts(0.0,0.0,-2.0, 0.5, 0.5, 1.0);
    playerScore = new Fonts(0.0,0.0,-2.0, 0.5, 0.5, 1.0);


    //level 1 parallax
    level1BG = new parallax();


    //level 2 parallax
    level2BG = new parallax();


    //level 3 parallax
    level3BG = new parallax();


    //credits text
    creditsTitleText = new Fonts(-1.2 + 0.0,0.3 + 0.0,-2.0, 0.5, 0.5, 1.0);
    creditsRicardoText = new Fonts(-1.2 +0.0,0.3 + -0.15,-2.0, 0.5, 0.5, 1.0);
    creditsTienText = new Fonts(-1.2 +0.0,0.3 + -0.30,-2.0, 0.5, 0.5, 1.0);
    creditsJonahText = new Fonts(-1.2 +0.0,0.3 + -0.45,-2.0, 0.5, 0.5, 1.0);





    playerBulletIndex = 0; //set index for player projectile array

    bulletEnm = new checkCollision();


    //Scenery
    flagLevel1 = new scenery(9.5, -0.31, -2.5, 0.1, 0.1, 0.1, "level1Flag");
    flagLevel2 = new scenery(9.5, -0.31, -2.5, 0.1, 0.1, 0.1, "level2Flag");
    flagLevel3 = new scenery(9.5, -0.31, -2.5, 0.1, 0.1, 0.1, "level3Flag");

    victoryFlag1 = new scenery(-0.5, 0.35, -2.5, 0.1, 0.1, 0.1, "victoryFlag1");
    victoryFlag2 = new scenery(0.5, 0.35, -2.5, 0.1, 0.1, 0.1, "victoryFlag2");

    introFlag1 = new scenery(-1.2, 0.35, -2.5, 0.1, 0.1, 0.1, "introFlag1");
    introFlag2 = new scenery(1.2, 0.35, -2.5, 0.1, 0.1, 0.1, "introFlag2");



    healthBar1 = new scenery(0, 50, -2.5, 0.05, 0.05, 0.05, "hp1");
    healthBar2 = new scenery(0, 50, -2.5, 0.05, 0.05, 0.05, "hp2");
    healthBar3 = new scenery(0, 50, -2.5, 0.05, 0.05, 0.05, "hp3");
    healthBar4 = new scenery(0, 50, -2.5, 0.05, 0.05, 0.05, "hp4");


    cameraSync = clock();
}

GLScene::~GLScene()
{
    //dtor


}


void GLScene::cleanUp()
{

    //Delete all objects

    cout << "I was here" << endl;
    delete KbMs;
    delete ply;
    delete hit;
    delete snds;

    delete sManager;

    delete cManager;

    delete lvlManager;



    delete introScreen ;
    delete creditsScreen;
    delete helpScreen;
    delete startMenuScreen;
    delete exitConfirmationScreen;
    delete gameOverScreen;
    delete winScreen;

    //intro screen buttons
    delete exitIntro;
    delete exitIntroText;

    //main menu screen buttons
    delete startGame;
    delete helpControls;
    delete credits;
    delete quitGame;

    delete startGameText;
    delete helpControlsText;
    delete creditsText;
    delete quitGameText;

    //return to menu screen buttons
    delete helpReturnToMain;
    delete creditsReturnToMain;

    delete helpReturnToMainText;
    delete creditsReturnToMainText;


    //exit game confirmation buttons
    delete exitConfirmationYes;
    delete exitConfirmationNo;

    delete exitConfirmationYesText;
    delete exitConfirmationNoText;

    delete exitConfirmationQuestion;


    //pause menu buttons
    delete resumeGame;
    delete helpFromGame;
    delete backToMain;

    delete helpReturnToGame;
    delete helpScreenFromGame;

    delete resumeGameText;
    delete helpFromGameText;
    delete backToMainText;

    delete helpReturnToGameText;

    delete gamePausedText;


    //game over and win buttons
    delete returnToMain;
    delete returnToMainText;



    //player health and score
    delete playerHealth;
    delete playerScore;


    //level 1 parallax
    delete level1BG;


    //level 2 parallax
    delete level2BG;


    //level 3 parallax
    delete level3BG;


    //credits text
    delete creditsTitleText;
    delete creditsRicardoText;
    delete creditsTienText;


    delete bulletEnm;


    delete flagLevel1;
    delete flagLevel2;
    delete flagLevel3;

    delete victoryFlag1;
    delete victoryFlag2;

    delete introFlag1;
    delete introFlag2;

    delete healthBar1;
    delete healthBar2;
    delete healthBar3;
    delete healthBar4;

    cout << "I was here" << endl;

}



//Draw the Scene
int GLScene::drawScene()
{
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();

   glColor3f(1.0,0.0,0.0);   // R, G,B




   //Draw the Intro Screen
   if(sManager->displayIntroScreen){


        gluLookAt(0.0,0,0.0000000000000001,0.0,0,0.0,0,1,0);

        glPushMatrix();
        glScaled(3.33,3.33,1.0);
        introScreen->drawSquare(screenWidth, screenHeight);
        glPopMatrix();

        glPushMatrix();
        introFlag1->drawScenery();
        glPopMatrix();

        glPushMatrix();
        introFlag2->drawScenery();
        glPopMatrix();

        glPushMatrix();
        exitIntro->drawSquare();
        glPopMatrix();

        glPushMatrix();
        exitIntroText->drawFontsInScene();
        glPopMatrix();


    //Draw the Main Menu Screen
   }else if(sManager->displayMenuScreen && !sManager->gameStarted){

        gluLookAt(0.0,0,0.0000000000000001,0.0,0,0.0,0,1,0);

        glPushMatrix();
        glScaled(3.33,3.33,1.0);
        startMenuScreen->drawSquare(screenWidth, screenHeight);
        glPopMatrix();


        glPushMatrix();
        startGame->drawSquare();
        glPopMatrix();

        glPushMatrix();
        startGameText->drawFontsInScene();
        glPopMatrix();


        glPushMatrix();
        helpControls->drawSquare();
        glPopMatrix();

        glPushMatrix();
        helpControlsText->drawFontsInScene();
        glPopMatrix();

        glPushMatrix();
        credits->drawSquare();
        glPopMatrix();

        glPushMatrix();
        creditsText->drawFontsInScene();
        glPopMatrix();


        glPushMatrix();
        quitGame->drawSquare();
        glPopMatrix();


        glPushMatrix();
        quitGameText->drawFontsInScene();
        glPopMatrix();



    //Draw the Help Screen
   } else if(sManager->displayHelpScreen){


        gluLookAt(0.0,0,0.0000000000000001,0.0,0,0.0,0,1,0);

        glPushMatrix();
        glScaled(3.33,3.33,1.0);
        helpScreen->drawSquare(screenWidth, screenHeight);
        glPopMatrix();


        glPushMatrix();
        helpReturnToMain->drawSquare();
        glPopMatrix();


        glPushMatrix();
        helpReturnToMainText->drawFontsInScene();
        glPopMatrix();





    //Draw the Credits Screen
   } else if(sManager->displayCreditsScreen){



        gluLookAt(0.0,0,0.0000000000000001,0.0,0,0.0,0,1,0);

        glPushMatrix();
        glScaled(3.33,3.33,1.0);
        creditsScreen->drawSquare(screenWidth, screenHeight);
        glPopMatrix();


        glPushMatrix();
        creditsReturnToMain->drawSquare();
        glPopMatrix();

        glPushMatrix();
        creditsReturnToMainText->drawFontsInScene();
        glPopMatrix();


        glPushMatrix();
        creditsTitleText->drawFontsInScene();
        glPopMatrix();


        glPushMatrix();
        creditsTienText->drawFontsInScene();
        glPopMatrix();




        glPushMatrix();
        creditsRicardoText->drawFontsInScene();
        glPopMatrix();



        glPushMatrix();
        creditsJonahText->drawFontsInScene();
        glPopMatrix();





    //Draw the Quit Screen
   } else if(sManager->displayExitConfirmationScreen){



        gluLookAt(0.0,0,0.0000000000000001,0.0,0,0.0,0,1,0);

        glPushMatrix();
        glScaled(3.33,3.33,1.0);
        exitConfirmationScreen->drawSquare(screenWidth, screenHeight);
        glPopMatrix();




        glPushMatrix();
        exitConfirmationNo->drawSquare();
        glPopMatrix();



        glPushMatrix();
        exitConfirmationQuestion->drawFontsInScene();
        glPopMatrix();



        glPushMatrix();
        exitConfirmationYes->drawSquare();
        glPopMatrix();

        glPushMatrix();
        exitConfirmationYesText->drawFontsInScene();
        glPopMatrix();

        glPushMatrix();
        exitConfirmationNoText->drawFontsInScene();
        glPopMatrix();



    //Draw the Game Screens ie Level 1, Level 2, Level 3
   }else if(sManager->inGame && !sManager->displayGameOverScreen && !sManager->displayWinScreen){




        gluLookAt(ply->pPos.x,0,0.000000000000001,ply->pPos.x,0,0.0,0,1,0); //set camera to follow player
        //still have artifact bug with projectiles and enemies when moving

        //gluLookAt(0.0,0,0.000000000000001,0.0,0,0.0,0,1,0);




        //Draw Level 1
        if(sManager->inGame && sManager->playingLevel1 && !sManager->level1Complete){



            glPushMatrix();
            glScaled(9.99,3.33,1.0);
            level1BG->drawSquare(screenWidth, screenHeight);
            glPopMatrix();


            //Level 1 enemies
            glPushMatrix();

                //Handle player damage enemies
                cManager->handlePlayerHitEnemy(maxNumPlayerProjectiles, playerBullet, sManager->maxNumLevel1Enmy, level1Enemies, hit, sManager, ply, snds, 1);


            glPopMatrix();



            glPushMatrix();

                //Handle enemies damage player
                cManager->handleLevelEnemyCollision(sManager->maxNumLevel1Enmy, level1Enemies, ply, hit, sManager, snds);

            glPopMatrix();


            //Level 1 flag
            //Only appears when all level 1 enemies are dead
            if(sManager->numLevel1EnmyLeft <= 0){



            glPushMatrix();
            flagLevel1->drawScenery();

            //if player touches level 1 flag then go to level 2
            if(hit->isRadialCollision(ply->pPos.x, flagLevel1->position.x, ply->pPos.y, flagLevel1->position.y, 0.1, 0.11)){
                sManager->level1Complete = true;
                sManager->touchLevel1Flag = true;
                sManager->playingLevel1 = false;
                sManager->playingLevel2 = true;
                ply->softResetPlayer();
                lvlManager->resetEnemies(level1Enemies, sManager->maxNumLevel1Enmy);
                lvlManager->resetEnemies(level2Enemies, sManager->maxNumLevel2Enmy);
                lvlManager->resetEnemies(level3Enemies, sManager->maxNumLevel3Enmy);

                lvlManager->resetProjectile(playerBullet, maxNumPlayerProjectiles);
                snds->killAllSounds();
                snds->playMusic("sounds/62.mp3");


            }
            glPopMatrix();

            }

        }



        //Draw Level 2
        if(sManager->inGame && sManager->playingLevel2 && !sManager->level2Complete){

            glPushMatrix();
            glScaled(9.99,3.33,1.0);
            level2BG->drawSquare(screenWidth, screenHeight);
            glPopMatrix();

            //Level 2 enemies
             glPushMatrix();


                //Handle player damage enemies
                cManager->handlePlayerHitEnemy(maxNumPlayerProjectiles, playerBullet, sManager->maxNumLevel2Enmy, level2Enemies, hit, sManager, ply, snds, 2);


            glPopMatrix();



            glPushMatrix();


                //Handle enemies damage player
                cManager->handleLevelEnemyCollision(sManager->maxNumLevel2Enmy, level2Enemies, ply, hit, sManager, snds);

            glPopMatrix();


            //Level 2 flag
            //Only appears when all level 2 enemies are dead
            if(sManager->numLevel2EnmyLeft <= 0){



            glPushMatrix();
            flagLevel2->drawScenery();

            //if player touches level 2 flag then go to level 3
            if(hit->isRadialCollision(ply->pPos.x, flagLevel2->position.x, ply->pPos.y, flagLevel2->position.y, 0.1, 0.11)){

                sManager->level2Complete = true;
                sManager->touchLevel2Flag = true;
                sManager->playingLevel1 = false;
                sManager->playingLevel2 = false;
                sManager->playingLevel3 = true;
                ply->softResetPlayer();
                lvlManager->resetEnemies(level1Enemies, sManager->maxNumLevel1Enmy);
                lvlManager->resetEnemies(level2Enemies, sManager->maxNumLevel2Enmy);
                lvlManager->resetEnemies(level3Enemies, sManager->maxNumLevel3Enmy);

                lvlManager->resetProjectile(playerBullet, maxNumPlayerProjectiles);
                snds->killAllSounds();
                snds->playMusic("sounds/87.mp3");


            }
            glPopMatrix();

            }

        }


        //Draw Level 3
        if(sManager->inGame && sManager->playingLevel3 && !sManager->level3Complete){

            glPushMatrix();
            glScaled(9.99,3.33,1.0);
            level3BG->drawSquare(screenWidth, screenHeight);
            glPopMatrix();



             //Level 3 enemies
             glPushMatrix();

                //Handle player damage enemies
                cManager->handlePlayerHitEnemy(maxNumPlayerProjectiles, playerBullet, sManager->maxNumLevel3Enmy, level3Enemies, hit, sManager, ply, snds, 3);


            glPopMatrix();



            glPushMatrix();

                 //Handle enemies damage player
                cManager->handleLevelEnemyCollision(sManager->maxNumLevel3Enmy, level3Enemies, ply, hit, sManager, snds);

            glPopMatrix();


            //Level 3 flag
            //Only appears when all level 3 enemies are dead
              if(sManager->numLevel3EnmyLeft <= 0){



            glPushMatrix();
            flagLevel3->drawScenery();

             //if player touches level 3 flag then go to Win Screen
            if(hit->isRadialCollision(ply->pPos.x, flagLevel3->position.x, ply->pPos.y, flagLevel3->position.y, 0.1, 0.11)){

                sManager->level3Complete = true;
                sManager->touchLevel3Flag = true;
                sManager->playingLevel1 = false;
                sManager->playingLevel2 = false;
                sManager->playingLevel3 = false;
                ply->softResetPlayer();
                lvlManager->resetEnemies(level1Enemies, sManager->maxNumLevel1Enmy);
                lvlManager->resetEnemies(level2Enemies, sManager->maxNumLevel2Enmy);
                lvlManager->resetEnemies(level3Enemies, sManager->maxNumLevel3Enmy);


                lvlManager->resetProjectile(playerBullet, maxNumPlayerProjectiles);
                snds->killAllSounds();
                snds->playMusic("sounds/26.mp3");

                sManager->inGame = false;
                sManager->gamePaused = true;
                ShowCursor(true);
                ply->resetPlayer();
                sManager->displayWinScreen = true;


            }
            glPopMatrix();

            }


        }



        //Draw Player Health Status in top left of screen
        playerHealth->setPosition(ply->pPos.x +-1.7,0.9,-2.5);
        glPushMatrix();
        playerHealth->drawFontsInScene();
        glPopMatrix();


        //Set Health Bars relative to player position
        healthBar1->setPosition(ply->pPos.x +-1.4,0.9,-2.5);
        healthBar2->setPosition(ply->pPos.x +-1.3,0.9,-2.5);
        healthBar3->setPosition(ply->pPos.x +-1.2,0.9,-2.5);
        healthBar4->setPosition(ply->pPos.x +-1.1,0.9,-2.5);


        //Draw Health Bars
        if(ply->health >= ply->maxHealth /1.0){
            glPushMatrix();

            healthBar4->drawScenery();

            glPopMatrix();
        }


        if(ply->health >= ply->maxHealth /2.0){
            glPushMatrix();

            healthBar3->drawScenery();

            glPopMatrix();
        }


          if(ply->health >= ply->maxHealth /3.0){
            glPushMatrix();

            healthBar2->drawScenery();

            glPopMatrix();
        }



          if(ply->health >= ply->maxHealth /4.0){
            glPushMatrix();

            healthBar1->drawScenery();

            glPopMatrix();
        }


        //Draw the Player
        glPushMatrix();
        ply->drawPlayer();
        glPopMatrix();


        //player projectiles
        glPushMatrix();

            //Handle drawing player projectiles
            handlePlayerProjectiles();

        glPopMatrix();



            //Draw Pause Menu
           if(sManager->gamePaused){



                //Set Pause Menu Button positions relative to player
                resumeGame->setPosition(ply->pPos.x, 0.0, -2.0);
                helpFromGame->setPosition(ply->pPos.x, -0.15, -2.0);
                backToMain->setPosition(ply->pPos.x, -0.30, -2.0);


                //Set Pause Menu Fonts positions relative to player
                resumeGameText->setPosition(ply->pPos.x + -0.12, -0.03,-2.0);
                helpFromGameText->setPosition(ply->pPos.x +-0.12,-0.18,-2.0);
                backToMainText->setPosition(ply->pPos.x +-0.12,-0.33,-2.0);

                gamePausedText->setPosition(ply->pPos.x +-0.1,0.1,-2.0);



                glPushMatrix();
                resumeGame->drawSquare();
                glPopMatrix();

                glPushMatrix();
                helpFromGame->drawSquare();
                glPopMatrix();

                glPushMatrix();
                backToMain->drawSquare();
                glPopMatrix();

                glPushMatrix();
                gamePausedText->drawFontsInScene();
                glPopMatrix();


                glPushMatrix();
                resumeGameText->drawFontsInScene();
                glPopMatrix();


                glPushMatrix();
                helpFromGameText->drawFontsInScene();
                glPopMatrix();

                glPushMatrix();
                backToMainText->drawFontsInScene();
                glPopMatrix();


           }


           //Handle Player Jumping
           if(!sManager->gamePaused){
                        if(ply->startJumping){
        ply->actions(ply->JUMP, snds, sManager);


       }


        if(ply->pPos.y <= -0.31){
                ply->startJumping = false;
                ply->pPos.y = -0.3;
                //ply->actionTrigger = ply->IDLE;
                ply->actions(ply->IDLE, snds, sManager);

            }
           }


        //Check if player has died
        //If so then go to Game Over Screen
        if(ply->health <= 0){

            sManager->displayGameOverScreen = true;
            sManager->inGame = false;
            snds->killAllSounds();
            snds->playSoundEffect("sounds/player_death.mp3");
            snds->playMusic("sounds/96.mp3");
            ShowCursor(true);


        }

    //Draw Game Over Screen
   }else if(sManager->displayGameOverScreen){



        gluLookAt(0.0,0,0.0000000000000001,0.0,0,0.0,0,1,0);

        glPushMatrix();
        glScaled(3.33,3.33,1.0);
        gameOverScreen->drawSquare(screenWidth, screenHeight);
        glPopMatrix();



        glPushMatrix();
        returnToMain->drawSquare();
        glPopMatrix();

        glPushMatrix();
        returnToMainText->drawFontsInScene();
        glPopMatrix();

    //Draw Win Screen
   }else if(sManager->displayWinScreen){

        gluLookAt(0.0,0,0.0000000000000001,0.0,0,0.0,0,1,0);

        glPushMatrix();
        glScaled(3.33,3.33,1.0);
        winScreen->drawSquare(screenWidth, screenHeight);
        glPopMatrix();


        glPushMatrix();
        victoryFlag1->drawScenery();
        glPopMatrix();

        glPushMatrix();
        victoryFlag2->drawScenery();
        glPopMatrix();

        glPushMatrix();
        returnToMain->drawSquare();
        glPopMatrix();

        glPushMatrix();
        returnToMainText->drawFontsInScene();
        glPopMatrix();


   }










   //Precaution Check
   //Hard Reset Player
   if(sManager->gameStarted == false || sManager->displayGameOverScreen){

        ply->resetPlayer();
        //cout << "player reset" << endl;
   }


   //Check if player has quit the game
   if(sManager->quit){
        return false;
   }else{
        return true;
   }


}

//Initialize the Scene
int GLScene::GLinit()
{
    srand(time(0)); //seed random number generator

    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glClearColor(0.0f,0.0f,0.0f,0.0f);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLLight Light(GL_LIGHT0);
    Light.setLight(GL_LIGHT0);

    glEnable(GL_TEXTURE_2D); //enable textures

    //Precaution check, kill all sounds
    snds->killAllSounds();


    //Precaution check, reset all flags
    sManager->resetAllFlags();



    //Player Initialization
    ply->playerInit("images/complete_knight.png", 10, 5);


    //Load level 1 enemies texture
    level1Enemies[0].enemyTexture("images/Skeleton_enemy.png"); //to avoid loading same image for all enemies

    //Load level 2 enemies texture
    level2Enemies[0].enemyTexture("images/cultist.png");

    //Load level 3 enemies texture
    level3Enemies[0].enemyTexture("images/fiend.png");

    //Load Player Projectiles texture
    playerBullet[0].projectileTexture("images/mega_shot.png"); //to avoid loading same image for all player projectiles



    //Initialize Menu Backgrounds
        introScreen->initParallax("images/ph_splash.png");
        startMenuScreen->initParallax("images/menu_splash_main.png");
        helpScreen->initParallax("images/help_splash_2.png");
        creditsScreen->initParallax("images/credits_splash_2.png");
        exitConfirmationScreen->initParallax("images/menu_splash.png");


        gameOverScreen->initParallax("images/intro_splash_died.png");
        winScreen->initParallax("images/win_splash.png");


    //Initialize All Buttons
        exitIntro->initButton("images/placeholder_text.png");
        startGame->initButton("images/placeholder_text.png");
        helpControls->initButton("images/placeholder_text.png");
        credits->initButton("images/placeholder_text.png");
        quitGame->initButton("images/placeholder_text.png");

        exitConfirmationNo->initButton("images/placeholder_text.png");
        exitConfirmationYes->initButton("images/placeholder_text.png");

        helpReturnToMain->initButton("images/placeholder_text.png");
        creditsReturnToMain->initButton("images/placeholder_text.png");



        resumeGame->initButton("images/placeholder_text.png");
        helpFromGame->initButton("images/placeholder_text.png");
        backToMain->initButton("images/placeholder_text.png");
        returnToMain->initButton("images/placeholder_text.png");



    //Level 1 enemy initialization
    for(int i = 0; i < level1NumEnemies; i++){
        level1Enemies[i].enemyName = "Skel";
        level1Enemies[i].initEnemy(level1Enemies[0].tex, 13, 5); //load enemies
        level1Enemies[i].alive = true; //spawn enemies
        //level1Enemies[i].placeEnemy(vec3{(float)rand()/(float)(RAND_MAX) * 5 - 3.5, -0.59, -2.5}); //random placement
    }


    //Level 2 enemy initialization
    for(int i = 0; i < level2NumEnemies; i++){
        level2Enemies[i].enemyName = "Cultist";
        level2Enemies[i].initEnemy(level2Enemies[0].tex, 10, 6); //load enemies
        level2Enemies[i].alive = true; //spawn enemies
        //level2Enemies[i].placeEnemy(vec3{(float)rand()/(float)(RAND_MAX) * 5 - 3.5, -0.59, -2.5}); //random placement
    }


    //Level 3 enemy initialization
    for(int i = 0; i < level3NumEnemies; i++){
        level3Enemies[i].enemyName = "Fiend";
        level3Enemies[i].initEnemy(level3Enemies[0].tex, 10, 7); //load enemies
        level3Enemies[i].alive = true; //spawn enemies
        //level3Enemies[i].placeEnemy(vec3{(float)rand()/(float)(RAND_MAX) * 5 - 3.5, -0.59, -2.5}); //random placement
    }


    //Player Projectile Init
    for(int i = 0; i < maxNumPlayerProjectiles; i++){

        playerBullet[i].alive = false;
        playerBullet[i].actionTrigger = playerBullet[i].IDLE;
        playerBullet[i].projectileType = "P";
        playerBullet[i].initProjectile(playerBullet[0].tex,4, 1);
        playerBullet[i].placeProjectile(0, 50, -2.5);

    }


    //Initialize sound engine
    snds->initSound();



    //Initialize all fonts
    initAllFonts();



    //Precaution check for building fonts
    //Only want to build fonts once
     if(initOnce != true){
        //snds->playMusic("sounds/85.mp3");
        //snds->playMusic("sounds/01.mp3");
        buildAllFonts();
     }


     //Play Main Menu BGM
     snds->playMusic("sounds/01.mp3");




    //Levels Background Initialization
        level1BG->initParallax("images/menu_splash.png");
        level2BG->initParallax("images/level2.png");
        level3BG->initParallax("images/level3.png");


    //Scenery Initialization
        flagLevel1->initScenery("images/exit_flag.png");
        flagLevel2->initScenery("images/exit_flag.png");
        flagLevel3->initScenery("images/exit_flag.png");

        introFlag1->initScenery("images/flag_blue.png");
        introFlag2->initScenery("images/flag_blue.png");

        victoryFlag1->initScenery("images/flag_red.png");
        victoryFlag2->initScenery("images/flag_red.png");


        healthBar1->initScenery("images/hp.png");
        healthBar2->initScenery("images/hp.png");
        healthBar3->initScenery("images/hp.png");
        healthBar4->initScenery("images/hp.png");


    //Precaution check so that intro screen shows
    sManager->displayIntroScreen = true;
    sManager->gameStarted = false;
    sManager->inGame = false;

    ShowCursor(true); //show mouse cursor


    return true;
}

//Resize Method
void GLScene::GLReSize(GLsizei width, GLsizei height)
{
    screenWidth= width;
    screenHeight = height;
    float ratio = (float)width/(float)height;
    glViewport(0,0, width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,ratio,0.1,1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



//Handle mouse and keyboard inputs
int GLScene::winMsg(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    KbMs->wParam = wParam;

    switch(uMsg)
    {
    case WM_KEYDOWN:


        KbMs->keyPlayer(ply, snds, sManager, playerBullet, playerBulletIndex, maxNumPlayerProjectiles);

        KbMs->sceneChangeUsingKey(LOWORD(wParam), HIWORD(lParam), sManager, snds, lvlManager, playerBullet, level1Enemies);

        break;

    case WM_KEYUP:
        KbMs ->keyUp();

        ply->actions(ply->IDLE, snds, sManager);

        break;

    case WM_LBUTTONDOWN:



        if(sManager->displayIntroScreen){

            KbMs->sceneChangeUsingMouse(LOWORD(wParam), HIWORD(lParam), sManager, exitIntro, -0.1, 0.1, -0.55, -0.45, snds, lvlManager, playerBullet, level1Enemies);

        } else if(sManager->displayMenuScreen){

            //cout << "in menu" << endl;
            KbMs->sceneChangeUsingMouse(LOWORD(wParam), HIWORD(lParam), sManager, startGame, -0.1, 0.1, -0.05, 0.05,  snds, lvlManager, playerBullet, level1Enemies);
            KbMs->sceneChangeUsingMouse(LOWORD(wParam), HIWORD(lParam), sManager, helpControls, -0.1, 0.1, -0.2, -0.1,  snds, lvlManager, playerBullet, level1Enemies);
            KbMs->sceneChangeUsingMouse(LOWORD(wParam), HIWORD(lParam), sManager, credits, -0.1, 0.1, -0.35, -0.25,  snds, lvlManager, playerBullet, level1Enemies);
            KbMs->sceneChangeUsingMouse(LOWORD(wParam), HIWORD(lParam), sManager, quitGame, -0.1, 0.1, -0.5, 0.4,  snds, lvlManager, playerBullet, level1Enemies);

        }else if(sManager->displayExitConfirmationScreen){

            KbMs->sceneChangeUsingMouse(LOWORD(wParam), HIWORD(lParam), sManager, exitConfirmationYes, -0.1, 0.1, -0.05, 0.05,  snds, lvlManager,  playerBullet, level1Enemies);
            KbMs->sceneChangeUsingMouse(LOWORD(wParam), HIWORD(lParam), sManager, exitConfirmationNo, -0.1, 0.1, -0.2, -0.1,  snds, lvlManager, playerBullet, level1Enemies);

        }else if(sManager->displayHelpScreen && !sManager->gameStarted){

             KbMs->sceneChangeUsingMouse(LOWORD(wParam), HIWORD(lParam), sManager, helpReturnToMain, -0.1, 0.1, -0.05, 0.05,  snds, lvlManager, playerBullet, level1Enemies);

        }else if(sManager->displayCreditsScreen){

            KbMs->sceneChangeUsingMouse(LOWORD(wParam), HIWORD(lParam), sManager, creditsReturnToMain, -0.1, 0.1, -0.05, 0.05,  snds, lvlManager, playerBullet, level1Enemies);
        }else if(sManager->gameStarted && sManager->inGame && sManager->gamePaused){

             //KbMs->sceneChangeUsingMouse(LOWORD(wParam), HIWORD(lParam), sManager, resumeGame, ply->pPos.x + -0.1, 0.1, -0.05, 0.05,  snds);
             //KbMs->sceneChangeUsingMouse(LOWORD(wParam), HIWORD(lParam), sManager, helpFromGame, ply->pPos.x +-0.1, 0.1, -0.2, -0.1,  snds);
             //KbMs->sceneChangeUsingMouse(LOWORD(wParam), HIWORD(lParam), sManager, backToMain, ply->pPos.x +-0.1, 0.1, -0.35, -0.25,  snds);

        }else if(sManager->displayHelpScreen && sManager->gameStarted){
            KbMs->sceneChangeUsingMouse(LOWORD(wParam), HIWORD(lParam), sManager, helpReturnToMain, -0.1, 0.1, -0.05, 0.05,  snds, lvlManager, playerBullet, level1Enemies);
        }else if(sManager->displayGameOverScreen ){

             KbMs->sceneChangeUsingMouse(LOWORD(wParam), HIWORD(lParam), sManager, returnToMain, -0.1, 0.1, -0.05, 0.05,  snds, lvlManager, playerBullet, level1Enemies);

        }else if(sManager->displayWinScreen){

             KbMs->sceneChangeUsingMouse(LOWORD(wParam), HIWORD(lParam), sManager, returnToMain, -0.1, 0.1, -0.05, 0.05,  snds, lvlManager, playerBullet, level1Enemies);
        }




        break;

    case WM_RBUTTONDOWN:

        break;

    case WM_MBUTTONDOWN:

        break;

    case    WM_LBUTTONUP:
    case    WM_RBUTTONUP:
    case    WM_MBUTTONUP:

             KbMs ->mouseBtnUp();
             if(sManager->displayIntroScreen){
             }
            break;

    case WM_MOUSEMOVE:

        break;

    case WM_MOUSEWHEEL:

        break;

    }

}


//Handle drawing player projectiles in the scene
void GLScene::handlePlayerProjectiles(){



           for(int i = 0; i < maxNumPlayerProjectiles; i++){


                if(playerBullet[i].alive == true){

                    if(playerBullet[i].position.x >= 20.0 || playerBullet[i].position.x <= -20.0 || playerBullet[i].alive == false){ //check if the fireball's y position is off the screen
                        //if the fireball is off the screen then we don't need it anymore


                        playerBullet[i].alive = false;
                        playerBullet[i].placeProjectile(0, 50, -2.5);
                    }


                }


                //Fireball projectile drawing
                if(playerBullet[i].alive == true){ //check if myBullets[i] is nullptr, we only want to draw fireballs that are "alive"


                    playerBullet[i].drawProjectile(sManager); //draw the fireball



                }



           }

}





//Build all fonts
void GLScene::buildAllFonts(){


    exitIntroText->buildFonts2("PRESS ENTER");



    startGameText->buildFonts2("START GAME(N)");
    helpControlsText->buildFonts2("HELP(H)");
    creditsText->buildFonts2("CREDITS(C)");
    quitGameText->buildFonts2("QUIT GAME(Q)");



    helpReturnToMainText->buildFonts2("RETURN(BACKSPACE)");
    creditsReturnToMainText->buildFonts2("RETURN(BACKSPACE)");



    exitConfirmationYesText->buildFonts2("YES(Y)");
    exitConfirmationNoText->buildFonts2("NO(N)");





    resumeGameText->buildFonts2("RESUME GAME(P)");
    helpFromGameText->buildFonts2("HELP(H)");
    backToMainText->buildFonts2("MAIN MENU(M)");

    helpReturnToGameText->buildFonts2("RETURN(BACKSPACE)");



    returnToMainText->buildFonts2("MAIN MENU(M)");


    //player score

    playerScore->initFonts("images/font_3.png", 15, 8);


    //credits



    creditsTitleText->buildFonts2("CODEBREAKERS DEV TEAM:");
    creditsRicardoText->buildFonts2("RICARDO CABRERA");
    creditsTienText->buildFonts2("TIEN TRAN");
    creditsJonahText->buildFonts2("JONAH LOZANO");



    exitConfirmationQuestion->buildFonts2("QUIT GAME:");



    gamePausedText->buildFonts2("GAME PAUSED:");

    playerHealth->buildFonts2("HEALTH: ");

}


//Initialize All fonts using texture image
void GLScene::initAllFonts(){

    exitIntroText->initFonts("images/font_3.png", 15, 8);




    startGameText->initFonts("images/font_3.png", 15, 8);
    helpControlsText->initFonts("images/font_3.png", 15, 8);
    creditsText->initFonts("images/font_3.png", 15, 8);
    quitGameText->initFonts("images/font_3.png", 15, 8);





    helpReturnToMainText->initFonts("images/font_3.png", 15, 8);
    creditsReturnToMainText->initFonts("images/font_3.png", 15, 8);




    exitConfirmationYesText->initFonts("images/font_3.png", 15, 8);
    exitConfirmationNoText->initFonts("images/font_3.png", 15, 8);



    resumeGameText->initFonts("images/font_3.png", 15, 8);
    helpFromGameText->initFonts("images/font_3.png", 15, 8);
    backToMainText->initFonts("images/font_3.png", 15, 8);

    helpReturnToGameText->initFonts("images/font_3.png", 15, 8);







    returnToMainText->initFonts("images/font_3.png", 15, 8);



    //player score
    playerHealth->initFonts("images/font_3.png", 15, 8);
    playerScore->initFonts("images/font_3.png", 15, 8);


    //credits
    creditsTitleText->initFonts("images/font_3.png", 15, 8);
    creditsRicardoText->initFonts("images/font_3.png", 15, 8);
    creditsTienText->initFonts("images/font_3.png", 15, 8);
    creditsJonahText->initFonts("images/font_3.png", 15, 8);




    exitConfirmationQuestion->initFonts("images/font_3.png", 15, 8);


    gamePausedText->initFonts("images/font_3.png", 15, 8);
}





