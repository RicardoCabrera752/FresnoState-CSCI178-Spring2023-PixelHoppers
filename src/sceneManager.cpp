#include "sceneManager.h"

sceneManager::sceneManager()
{
    //ctor



    //Set default values for all boolean variables

    displayIntroScreen = false;
    displayMenuScreen = false;
    displayHelpScreen = false;
    displayCreditsScreen = false;
    displayExitConfirmationScreen = false;
    displayStartGame = false;
    displayGameOverScreen = false;
    displayWinScreen = false;

    quit = false;

    inGame = false;
    gamePaused = true;
    gameStarted = false;


    doneLoading = false;
    isLevel1 = false;
    isLevel2 = false;


    playingLevel1  = false;
    playingLevel2  = false;
    playingLevel3  = false;

    level1Complete  = false;
    level2Complete  = false;
    level3Complete  = false;


    touchLevel1Flag  = false;
    touchLevel2Flag  = false;
    touchLevel3Flag = false;


    //Default enemies left in all levels
    numLevel1EnmyLeft = 0;
    numLevel2EnmyLeft = 0;
    numLevel3EnmyLeft = 0;

    //Default max enemies in all levels
    maxNumLevel1Enmy = 5;
    maxNumLevel2Enmy = 5;
    maxNumLevel3Enmy = 5;

    //Default max player projectiles
    maxNumPlayerBullets = 50;
}

sceneManager::~sceneManager()
{
    //dtor
}


//Reset all boolean variables to default values
void sceneManager::resetAllFlags()
{
    displayIntroScreen = false;
    displayMenuScreen = false;
    displayHelpScreen = false;
    displayCreditsScreen = false;
    displayExitConfirmationScreen = false;
    displayStartGame = false;
    displayGameOverScreen = false;
    displayWinScreen = false;

    quit = false;

    inGame = false;
    gamePaused = true;
    gameStarted = false;


    doneLoading = false;
    isLevel1 = false;
    isLevel2 = false;





    playingLevel1  = false;
    playingLevel2  = false;
    playingLevel3  = false;

    level1Complete  = false;
    level2Complete  = false;
    level3Complete  = false;


    touchLevel1Flag  = false;
    touchLevel2Flag  = false;
    touchLevel3Flag = false;

}

