#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H


#include<commons.h>
#include<enms.h>
#include<projectile.h>

//Level Manager Class that handles reseting player projectiles and enemies
class levelManager
{
    public:
        levelManager(); //default constuctor
        virtual ~levelManager(); //destrcutor


        //A and B enemy groups
        //A Group will spawn to the right of the player
        //B Group will spawn to the left of the player

            //Level 1 A and B groups
            int level1AGroup;
            int level1BGroup;

            //Level 2 A and B groups
            int level2AGroup;
            int level2BGroup;

            //Level 2 A and B groups
            int level3AGroup;
            int level3BGroup;


        float randomVal(float , float ); //method to get a random x value for enemy spawn points
        //inputs are a max range and min range

        void resetEnemies(enms [], int); //method to reset all enemies of a level, ie set them to alive and spawn them again

        void resetProjectile(projectile [], int); //method to reset all player projectiles
        //this will make sure all projectiles are destroyed when changing levels


    protected:

    private:
};

#endif // LEVELMANAGER_H
