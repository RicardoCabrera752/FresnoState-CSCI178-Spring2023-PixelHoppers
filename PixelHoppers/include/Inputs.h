#ifndef INPUTS_H
#define INPUTS_H
#include<windows.h>
#include <Model.h>
#include <parallax.h>
#include <player.h>
#include <sounds.h>
#include <sceneManager.h>
#include <button.h>
#include <projectile.h>
#include <levelManager.h>
#include <enms.h>

//Mouse and Keyboard inputs class
class Inputs
{
    public:
        Inputs(); //default constructor
        virtual ~Inputs(); //destructor

        void keyPlayer(player *, sounds*, sceneManager*, projectile [], int &, int ); //perform a player action based on key input
        //void keyPlayer(player *, sounds*, sceneManager*, projectile* [], int &, int );
        void keyUp(); //perform an action if a key is released

        void fixedKeyPlayer(player *, sounds *, sceneManager *, projectile [], int &, int); //new version of keyPlayer()


        void keyProjectile(projectile* [], int &, float, float, int, sceneManager*, char); //perform action for projectile object when key is pressed


        void sceneChangeUsingKey(double, double, sceneManager*, sounds*, levelManager*, projectile [], enms []); //method used to change scenes using keyboard key

        void sceneChangeUsingMouse(double , double, sceneManager*, button*, float, float, float, float, sounds*, levelManager*, projectile [], enms[]); //method used to change scenes using mouse click and a button

        WPARAM wParam; //determine which key was pressed


        POINT mouseCursorPos; //POINT variable to determine the position of a mouse click

        //variable to help get x, y, and z screen coordinates of mouse cursor
        double realMX;
        double realMY;
        double realMZ;

        clock_t cooldown; //timer variable used to implement player attack cooldown
        //this will prevent player from spamming attacks

      //Vestigial methods from inputs lecture
      void mouseBtnDwn(Model *, double, double);
      void mouseBtnUp();
      void mouseWheel(Model *,double);
      void mouseMove(Model *,double, double);

      void keyEnv(parallax*, float);
      void keyPressed(Model *);

      //Vestigial properties from inputs lecture
      double prev_Mx;
      double prev_My;

      bool Mouse_translate =false;
      bool Mouse_Rotate =false;

    protected:

    private:
};

#endif // INPUTS_H
