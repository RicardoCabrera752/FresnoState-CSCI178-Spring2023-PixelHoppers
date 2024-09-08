#ifndef GLSCENE_H
#define GLSCENE_H

#include <windows.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<iostream>


#include <Model.h>
#include <GLLight.h>
#include <Inputs.h>
#include <parallax.h>
#include <player.h>
#include <enms.h>
#include <checkCollision.h>
#include <sounds.h>
#include <Fonts.h>
#include <button.h>
#include <sceneManager.h>
#include <projectile.h>
#include <scenery.h>
#include <memory>
#include <levelManager.h>
#include <collisionManager.h>

using namespace std;

//Global variables
const int maxNumPlayerProjectiles = 50; //max number projectiles the player can have

const int level1NumEnemies = 5; //max number of enemies that can spawn in level 1

const int level2NumEnemies = 5; //max number of enemies that can spawn in level 2

const int level3NumEnemies = 5; //max number of enemies that can spawn in level 3


//Scene class
class GLScene
{
    public:
        GLScene(); //default constructor
        virtual ~GLScene(); //destructor
        int drawScene();   // main renderer
        int GLinit();       // initialization of the scene
        void GLReSize(GLsizei, GLsizei);// callback function for resize

        int winMsg(HWND,UINT,WPARAM,LPARAM); //handle mouse or keyboard inputs

        float screenWidth,screenHeight; //screen resolution, height and width


        //Utility Methods
            void cleanUp(); //method used to delete all objects when player quits the game

            void handlePlayerProjectiles(); //method used to handle drawing player projectiles in the scene
            //will draw projectiles and also check if they are out of bounds


            void buildAllFonts(); //method used to build all fonts that will be used

            void initAllFonts(); //method used to initialize all fonts that will be used


        bool initOnce; //boolean that helps us know if the player pressed F1
        //this will prevent is from building the fonts more than once

        //Game Objects

            //collision manager
            collisionManager* cManager;

            //level manager
            levelManager* lvlManager;

            //player
            player *ply;


            //player projectiles
            int playerBulletIndex;

            projectile playerBullet[maxNumPlayerProjectiles];


            //Level 1 enemies
            enms level1Enemies[level1NumEnemies];

            //Level 2 enemies
            enms level2Enemies[level1NumEnemies];

            //Level 3 enemies
            enms level3Enemies[level1NumEnemies];


            //collisions
            checkCollision *hit;

            checkCollision *bulletEnm;

            //inputs
            //unique_ptr<Inputs> KbMs = unique_ptr<Inputs>(new Inputs());
            Inputs* KbMs;

            //sounds
            sounds* snds;

            //sceneManager
            sceneManager *sManager;

            //Parallax
            parallax *introScreen;
            parallax *creditsScreen;
            parallax *helpScreen;
            parallax *startMenuScreen;
            parallax *exitConfirmationScreen;
            parallax *gameOverScreen;
            parallax *winScreen;

            //pause menu
            parallax *helpScreenFromGame;


            //level 1 parallax
            parallax *level1BG;


            //level 2 parallax
            parallax *level2BG;


            //level 3 parallax
            parallax *level3BG;

            //Fonts
                //intro screen fonts
                Fonts *exitIntroText;

                //main menu screen fonts
                Fonts *startGameText;
                Fonts *helpControlsText;
                Fonts *creditsText;
                Fonts *quitGameText;

                //return to menu screen fonts
                Fonts *helpReturnToMainText;
                Fonts *creditsReturnToMainText;

                //exit game confirmation fonts
                Fonts *exitConfirmationYesText;
                Fonts *exitConfirmationNoText;
                Fonts *exitConfirmationQuestion;

                //pause menu text fonts
                Fonts *resumeGameText;
                Fonts *helpFromGameText;
                Fonts *backToMainText;

                Fonts *helpReturnToGameText;
                Fonts* gamePausedText;

                //game over and win fonts
                Fonts* returnToMainText;


                //player health and score
                Fonts* playerHealth;
                Fonts* playerScore;

                string pHealth;
                string pScore;

                //credits fonts
                Fonts* creditsTitleText;
                Fonts* creditsRicardoText;
                Fonts* creditsTienText;
                Fonts* creditsJonahText;

            //Buttons
                //intro screen buttons
                button *exitIntro;

                //main menu screen buttons
                button *startGame;
                button *helpControls;
                button *credits;
                button *quitGame;

                //return to menu screen buttons
                button *helpReturnToMain;
                button *creditsReturnToMain;

                //exit game confirmation buttons
                button *exitConfirmationYes;
                button *exitConfirmationNo;

                //pause menu buttons
                button *resumeGame;
                button *helpFromGame;
                button *backToMain;

                button *helpReturnToGame;

                //game over and win buttons
                button* returnToMain;

            //Scenery
            scenery* flagLevel1;
            scenery* flagLevel2;
            scenery* flagLevel3;

            scenery* victoryFlag1;
            scenery* victoryFlag2;

            scenery* introFlag1;
            scenery* introFlag2;

                //Health Bars

                scenery* healthBar1;
                scenery* healthBar2;
                scenery* healthBar3;
                scenery* healthBar4;


        //Unused Properties
        bool doneLoading;
        bool isLevel1;
        bool isLevel2;

        clock_t cameraSync;


    protected:

    private:
};

#endif // GLSCENE_H
