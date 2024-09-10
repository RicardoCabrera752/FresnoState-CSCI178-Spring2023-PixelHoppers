#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include<commons.h>


//Scene manger class used to change which scene is displayed on the screen
class sceneManager
{
    public:
        sceneManager(); //default constructor
        virtual ~sceneManager(); //destructor



        //Main Menu Screen Management
        bool displayIntroScreen; //determine if the intro screen should be displayed
        bool displayMenuScreen; //determine if the main menu should be displayed
        bool displayHelpScreen; //determine if the help screen should be displayed
        bool displayCreditsScreen; //determine if the credits screen should be displayed
        bool displayExitConfirmationScreen; //determine if the exit screen should be displayed
        bool displayGameOverScreen; //determine if the game over screen should be displayed
        bool displayWinScreen; //determine if the win screen should be displayed



        bool quit; //boolean used to determine if the player has quit the game

        bool inGame; //boolean that determines if the player is currently in a game session
        //mainly used as precaution check to make sure the level is being displayed not the main menu

        bool gamePaused; //boolean used to determine if the game is paused
        //used to show/hide pause menu

        bool gameStarted; //boolean used to determine if a new game was started
        //this means that the player has pressed the new game button



        //Level Status management
            //Check which level the player is currently in
            bool playingLevel1;
            bool playingLevel2;
            bool playingLevel3;

            //Check which levels the player has completed
            bool level1Complete;
            bool level2Complete;
            bool level3Complete;

            //Check which flags the player has touched
            bool touchLevel1Flag;
            bool touchLevel2Flag;
            bool touchLevel3Flag;

            int maxNumPlayerBullets; //max number of projectiles player can shoot

            //Max number of enemies a level can have
            int maxNumLevel1Enmy;
            int maxNumLevel2Enmy;
            int maxNumLevel3Enmy;

            //How many enemies in a level are left
            int numLevel1EnmyLeft;
            int numLevel2EnmyLeft;
            int numLevel3EnmyLeft;


        void resetAllFlags(); //method used to reset all boolean variables to default values


        //Unused variables
        bool doneLoading;
        bool isLevel1;
        bool isLevel2;

        bool displayStartGame;



    protected:

    private:
};

#endif // SCENEMANAGER_H
