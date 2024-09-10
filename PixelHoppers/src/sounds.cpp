#include "sounds.h"

sounds::sounds()
{
    //ctor
}

sounds::~sounds()
{
    //dtor
    engine->drop();
}

//Play BGM
void sounds::playMusic(char* fileName)
{
    engine->play2D(fileName, true); //true for running on loop
}


//Initialize sound engine
int sounds::initSound()
{

    if(!engine){

        cout << "The Sound Engine did not start\n";
        return 0;

    }

    return 1;

}


//Play a sound effect
void sounds::playSoundEffect(char* fileName)
{
    engine->play2D(fileName, false); //false for only playing sound once
}


//Stop all sounds
void sounds::killAllSounds()
{
    engine->stopAllSounds(); //stop all sounds
}


//Vestigial Methods from sounds lecture
void sounds::playSound(char* fileName)
{
    if(!engine->isCurrentlyPlaying(fileName)){
        engine->play2D(fileName, false, false);
    }
}

void sounds::pauseSound(char* fileName)
{
    engine->play2D(fileName, true, false);
}
