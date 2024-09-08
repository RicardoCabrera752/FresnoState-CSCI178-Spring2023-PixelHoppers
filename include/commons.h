#ifndef COMMONS_H
#define COMMONS_H

#include <SNDS/irrKlang.h>
using namespace irrklang;


#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;



#include<math.h>
#include<time.h>
#define GRAVITY 9.81
#define PI 3.14159


//vec3 structure used to hold 3 data values
typedef struct{


    float x;
    float y;
    float z;



}vec3;


//vec2 structure used to hold 2 data values
typedef struct{


    float x;
    float y;



}vec2;


//Vestigial commons class, in reality it's not needed
class commons
{
    public:
        commons();
        virtual ~commons();

    protected:

    private:
};

#endif // COMMONS_H
