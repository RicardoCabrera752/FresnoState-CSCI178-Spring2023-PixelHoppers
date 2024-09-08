#include "Fonts.h"
#include<commons.h>

Fonts::Fonts()
{
    //ctor
    cCnt = 0;
    rotation.x = rotation.y = rotation.z = 0;

    pos.x = 0.0;
    pos.y = 0.0;
    pos.z = 0.0;

    zoom = -2.5;

}


Fonts::Fonts(float xPos, float yPos, float zPos)
{


    cCnt = 0;
    rotation.x = rotation.y = rotation.z = 0;

    pos.x = xPos;
    pos.y = yPos;
    pos.z = zPos;

    zoom = -2.5;

}


Fonts::Fonts(float xPos, float yPos, float zPos, float xScale, float yScale, float zScale)
{

    cCnt = 0;
    rotation.x = rotation.y = rotation.z = 0;

    pos.x = xPos;
    pos.y = yPos;
    pos.z = zPos;

    scaleFactor.x = xScale;
    scaleFactor.y = yScale;
    scaleFactor.z = zScale;

    zoom = -2.5;


}



Fonts::~Fonts()
{
    //dtor
}

void Fonts::initFonts(char* fileName, int hFrm, int vFrm)
{

    hFrames = hFrm;
    vFrames = vFrm;
    tLoad->loadTexture(fileName, tex);

}


void Fonts::buildFonts2(string str)
{

     for(int i = 0; i < str.length(); i++){

        switch(str[i]){

        case ' ':

            //cout << "white space" << endl;
            C[cCnt].xMin = 0.0/hFrames;
            C[cCnt].xMax = 1.0/hFrames;

            C[cCnt].yMin = 0.0/vFrames;
            C[cCnt].yMax = 1.0/vFrames;
            break;


        case '(':

            //cout << "(" << endl;
            C[cCnt].xMin = 8.0/hFrames;
            C[cCnt].xMax = 9.0/hFrames;

            C[cCnt].yMin = 0.0/vFrames;
            C[cCnt].yMax = 1.0/vFrames;
            break;


        case ')':

            //cout << ")" << endl;
            C[cCnt].xMin = 9.0/hFrames;
            C[cCnt].xMax = 10.0/hFrames;

            C[cCnt].yMin = 0.0/vFrames;
            C[cCnt].yMax = 1.0/vFrames;
            break;

        case '0':

            //cout << "0" << endl;
            C[cCnt].xMin = 1.0/hFrames;
            C[cCnt].xMax = 2.0/hFrames;

            C[cCnt].yMin = 1.0/vFrames;
            C[cCnt].yMax = 2.0/vFrames;
            break;

        case '1':

            //cout << "1" << endl;
            C[cCnt].xMin = 2.0/hFrames;
            C[cCnt].xMax = 3.0/hFrames;

            C[cCnt].yMin = 1.0/vFrames;
            C[cCnt].yMax = 2.0/vFrames;
            break;

        case '2':

            //cout << "2" << endl;
            C[cCnt].xMin = 3.0/hFrames;
            C[cCnt].xMax = 4.0/hFrames;

            C[cCnt].yMin = 1.0/vFrames;
            C[cCnt].yMax = 2.0/vFrames;
            break;

        case '3':

            //cout << "3" << endl;
            C[cCnt].xMin = 4.0/hFrames;
            C[cCnt].xMax = 5.0/hFrames;

            C[cCnt].yMin = 1.0/vFrames;
            C[cCnt].yMax = 2.0/vFrames;
            break;

        case '4':

            //cout << "4" << endl;
            C[cCnt].xMin = 5.0/hFrames;
            C[cCnt].xMax = 6.0/hFrames;

            C[cCnt].yMin = 1.0/vFrames;
            C[cCnt].yMax = 2.0/vFrames;
            break;

        case '5':

            //cout << "5" << endl;
            C[cCnt].xMin = 6.0/hFrames;
            C[cCnt].xMax = 7.0/hFrames;

            C[cCnt].yMin = 1.0/vFrames;
            C[cCnt].yMax = 2.0/vFrames;
            break;

        case '6':

            //cout << "6" << endl;
            C[cCnt].xMin = 7.0/hFrames;
            C[cCnt].xMax = 8.0/hFrames;

            C[cCnt].yMin = 1.0/vFrames;
            C[cCnt].yMax = 2.0/vFrames;
            break;

        case '7':

            //cout << "7" << endl;
            C[cCnt].xMin = 8.0/hFrames;
            C[cCnt].xMax = 9.0/hFrames;

            C[cCnt].yMin = 1.0/vFrames;
            C[cCnt].yMax = 2.0/vFrames;
            break;

        case '8':

            //cout << "8" << endl;
            C[cCnt].xMin = 9.0/hFrames;
            C[cCnt].xMax = 10.0/hFrames;

            C[cCnt].yMin = 1.0/vFrames;
            C[cCnt].yMax = 2.0/vFrames;
            break;

        case '9':

            //cout << "9" << endl;
            C[cCnt].xMin = 10.0/hFrames;
            C[cCnt].xMax = 11.0/hFrames;

            C[cCnt].yMin = 1.0/vFrames;
            C[cCnt].yMax = 2.0/vFrames;
            break;

          case ':':

            //cout << ":" << endl;
            C[cCnt].xMin = 11.0/hFrames;
            C[cCnt].xMax = 12.0/hFrames;

            C[cCnt].yMin = 1.0/vFrames;
            C[cCnt].yMax = 2.0/vFrames;
            break;


         case 'A':
            //cout << "A" << endl;
            C[cCnt].xMin = 3.0/hFrames;
            C[cCnt].xMax = 4.0/hFrames;

            C[cCnt].yMin = 2.0/vFrames;
            C[cCnt].yMax = 3.0/vFrames;

            break;

         case 'B':
            //cout << "B" << endl;
            C[cCnt].xMin = 4.0/hFrames;
            C[cCnt].xMax = 5.0/hFrames;

            C[cCnt].yMin = 2.0/vFrames;
            C[cCnt].yMax = 3.0/vFrames;

            break;

         case 'C':
            //cout << "C" << endl;
            C[cCnt].xMin = 5.0/hFrames;
            C[cCnt].xMax = 6.0/hFrames;

            C[cCnt].yMin = 2.0/vFrames;
            C[cCnt].yMax = 3.0/vFrames;

            break;

         case 'D':
            //cout << "D" << endl;
            C[cCnt].xMin = 6.0/hFrames;
            C[cCnt].xMax = 7.0/hFrames;

            C[cCnt].yMin = 2.0/vFrames;
            C[cCnt].yMax = 3.0/vFrames;

            break;


        case 'E':
            //cout << "E" << endl;
            C[cCnt].xMin = 7.0/hFrames;
            C[cCnt].xMax = 8.0/hFrames;

            C[cCnt].yMin = 2.0/vFrames;
            C[cCnt].yMax = 3.0/vFrames;

            break;

         case 'F':
            //cout << "F" << endl;
            C[cCnt].xMin = 8.0/hFrames;
            C[cCnt].xMax = 9.0/hFrames;

            C[cCnt].yMin = 2.0/vFrames;
            C[cCnt].yMax = 3.0/vFrames;

            break;

         case 'G':
            //cout << "G" << endl;
            C[cCnt].xMin = 9.0/hFrames;
            C[cCnt].xMax = 10.0/hFrames;

            C[cCnt].yMin = 2.0/vFrames;
            C[cCnt].yMax = 3.0/vFrames;

            break;

         case 'H':
            //cout << "H" << endl;
            C[cCnt].xMin = 10.0/hFrames;
            C[cCnt].xMax = 11.0/hFrames;

            C[cCnt].yMin = 2.0/vFrames;
            C[cCnt].yMax = 3.0/vFrames;

            break;

         case 'I':
            //cout << "I" << endl;
            C[cCnt].xMin = 11.0/hFrames;
            C[cCnt].xMax = 12.0/hFrames;

            C[cCnt].yMin = 2.0/vFrames;
            C[cCnt].yMax = 3.0/vFrames;

            break;

         case 'J':
            //cout << "J" << endl;
            C[cCnt].xMin = 12.0/hFrames;
            C[cCnt].xMax = 13.0/hFrames;

            C[cCnt].yMin = 2.0/vFrames;
            C[cCnt].yMax = 3.0/vFrames;

            break;

         case 'K':
            //cout << "K" << endl;
            C[cCnt].xMin = 13.0/hFrames;
            C[cCnt].xMax = 14.0/hFrames;

            C[cCnt].yMin = 2.0/vFrames;
            C[cCnt].yMax = 3.0/vFrames;

            break;
         case 'L':
            //cout << "L" << endl;
            C[cCnt].xMin = 14.0/hFrames;
            C[cCnt].xMax = 15.0/hFrames;

            C[cCnt].yMin = 2.0/vFrames;
            C[cCnt].yMax = 3.0/vFrames;

            break;
         case 'M':
           // cout << "M" << endl;
            C[cCnt].xMin = 0.0/hFrames;
            C[cCnt].xMax = 1.0/hFrames;

            C[cCnt].yMin = 3.0/vFrames;
            C[cCnt].yMax = 4.0/vFrames;

            break;
         case 'N':
            //cout << "N" << endl;
            C[cCnt].xMin = 1.0/hFrames;
            C[cCnt].xMax = 2.0/hFrames;

            C[cCnt].yMin = 3.0/vFrames;
            C[cCnt].yMax = 4.0/vFrames;

            break;
         case 'O':
            //cout << "O" << endl;
            C[cCnt].xMin = 2.0/hFrames;
            C[cCnt].xMax = 3.0/hFrames;

            C[cCnt].yMin = 3.0/vFrames;
            C[cCnt].yMax = 4.0/vFrames;

            break;


        case 'P':
           // cout << "P" << endl;
            C[cCnt].xMin = 3.0/hFrames;
            C[cCnt].xMax = 4.0/hFrames;

            C[cCnt].yMin = 3.0/vFrames;
            C[cCnt].yMax = 4.0/vFrames;

            break;

         case 'Q':
            //cout << "Q" << endl;
            C[cCnt].xMin = 4.0/hFrames;
            C[cCnt].xMax = 5.0/hFrames;

            C[cCnt].yMin = 3.0/vFrames;
            C[cCnt].yMax = 4.0/vFrames;

            break;

         case 'R':
            //cout << "R" << endl;
            C[cCnt].xMin = 5.0/hFrames;
            C[cCnt].xMax = 6.0/hFrames;

            C[cCnt].yMin = 3.0/vFrames;
            C[cCnt].yMax = 4.0/vFrames;

            break;

         case 'S':
            //cout << "S" << endl;
            C[cCnt].xMin = 6.0/hFrames;
            C[cCnt].xMax = 7.0/hFrames;

            C[cCnt].yMin = 3.0/vFrames;
            C[cCnt].yMax = 4.0/vFrames;

            break;

         case 'T':
            //cout << "T" << endl;
            C[cCnt].xMin = 7.0/hFrames;
            C[cCnt].xMax = 8.0/hFrames;

            C[cCnt].yMin = 3.0/vFrames;
            C[cCnt].yMax = 4.0/vFrames;

            break;

         case 'U':
           // cout << "U" << endl;
            C[cCnt].xMin = 8.0/hFrames;
            C[cCnt].xMax = 9.0/hFrames;

            C[cCnt].yMin = 3.0/vFrames;
            C[cCnt].yMax = 4.0/vFrames;

            break;

         case 'V':
           // cout << "V" << endl;
            C[cCnt].xMin = 9.0/hFrames;
            C[cCnt].xMax = 10.0/hFrames;

            C[cCnt].yMin = 3.0/vFrames;
            C[cCnt].yMax = 4.0/vFrames;

            break;

         case 'W':
            //cout << "W" << endl;
            C[cCnt].xMin = 10.0/hFrames;
            C[cCnt].xMax = 11.0/hFrames;

            C[cCnt].yMin = 3.0/vFrames;
            C[cCnt].yMax = 4.0/vFrames;

            break;

         case 'X':
            //cout << "X" << endl;
            C[cCnt].xMin = 11.0/hFrames;
            C[cCnt].xMax = 12.0/hFrames;

            C[cCnt].yMin = 3.0/vFrames;
            C[cCnt].yMax = 4.0/vFrames;

            break;

         case 'Y':
            //cout << "Y" << endl;
            C[cCnt].xMin = 12.0/hFrames;
            C[cCnt].xMax = 13.0/hFrames;

            C[cCnt].yMin = 3.0/vFrames;
            C[cCnt].yMax = 4.0/vFrames;

            break;

         case 'Z':
            //cout << "Z" << endl;
            C[cCnt].xMin = 13.0/hFrames;
            C[cCnt].xMax = 14.0/hFrames;

            C[cCnt].yMin = 3.0/vFrames;
            C[cCnt].yMax = 4.0/vFrames;

            break;







            }

            cCnt++;


     }

}



void Fonts::buildFonts(char*str)
{
    for(int i = 0; i < strlen(str); i++){

        switch(str[i]){

        case 'a':
            C[cCnt].xMin = 0;
            C[cCnt].xMax = 1.0/13.0;

            C[cCnt].yMin = 3.0/10.0;
            C[cCnt].yMax = 4.0/10.0;

            break;

        case 'b':

             C[cCnt].xMin = 1.0/13.0;
            C[cCnt].xMax = 2.0/13.0;

            C[cCnt].yMin = 3.0/10.0;
            C[cCnt].yMax = 4.0/10.0;

            break;
        case 'B':
            C[cCnt].xMin = 1.0/13.0;
            C[cCnt].xMax = 2.0/13.0;

            C[cCnt].yMin = 0.0;
            C[cCnt].yMax = 1.0/10.0;
            break;

        case 'A':
            C[cCnt].xMin = 0;
            C[cCnt].xMax = 1.0/13.0;

            C[cCnt].yMin = 0;
            C[cCnt].yMax = 1.0/10.0;

            break;

        }

        cCnt++;

    }

}


void Fonts::drawFontsInScene()
{

     for(int i = 0; i < cCnt; i++){

            glPushMatrix();
            glTranslatef(pos.x+i/45.0, pos.y, pos.z);
            drawFonts(i);
            glPopMatrix();

        }

}


void Fonts::drawFonts(int i)
{

    tLoad->binder(tex);

    glPushMatrix();
    //glTranslated(pos.x,pos.y,zoom);
    glScalef(scaleFactor.x, scaleFactor.y, scaleFactor.z);
    glRotated(rotation.x,1,0,0);
    glRotated(rotation.y,0,1,0);
    glRotated(rotation.z,0,0,1);

   glBegin(GL_QUADS);
       //glTexCoord2f(C[i].xMin,1.0);
       glTexCoord2f(C[i].xMin,C[i].yMax);
       glVertex3f(0,0,0);

       //glTexCoord2f(C[i].xMax,1.0);
       glTexCoord2f(C[i].xMax,C[i].yMax);
       //glVertex3f(1.0/13.0, 0,0);
       glVertex3f(1.0/(float)hFrames, 0,0);

       //glTexCoord2f(C[i].xMax,0.0);
       glTexCoord2f(C[i].xMax,C[i].yMin);
       //glVertex3f(1.0/13.0, 1.0/10.0,0);
       glVertex3f(1.0/(float)hFrames, 1.0/(float)vFrames,0);

       //glTexCoord2f(C[i].xMin,0.0);
       glTexCoord2f(C[i].xMin,C[i].yMin);
       //glVertex3f(0,1.0/10.0,0);
      glVertex3f(0,1.0/(float)vFrames,0);

    glEnd();

    glPopMatrix();

}


void Fonts::setPosition(float xPos, float yPos, float zPos)
{

    pos.x = xPos;
    pos.y = yPos;
    pos.z = zPos;
}

