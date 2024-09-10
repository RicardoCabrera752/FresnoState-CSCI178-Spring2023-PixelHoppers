#ifndef SOUNDS_H
#define SOUNDS_H
#include<commons.h>

//Sound engine class
class sounds
{
    public:
        sounds(); //default contructor
        virtual ~sounds(); //destructor

        //ISoundEngine* engine = createIrrKlangDevice();
        ISoundEngine* engine = createIrrKlangDevice(); //sound engine object

        void playMusic(char* ); //method used to play BGM
        void playSoundEffect(char*); //play a sound effect from sound file
        int initSound(); //initialize sound engine

        void killAllSounds(); //method used to stop all sounds


        //Vestigial methods from sounds lecture
        void playSound(char* );
        void pauseSound(char* );

    protected:

    private:
};

#endif // SOUNDS_H
