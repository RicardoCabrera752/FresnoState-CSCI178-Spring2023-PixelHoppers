#include "textureLoader.h"

textureLoader::textureLoader()
{
    //ctor
}

textureLoader::~textureLoader()
{
    //dtor
}


//Load Texture image using SOIL
void textureLoader::loadTexture(char* fileName, GLuint& tId)
{
    glGenTextures(1,&tId); //generate texture

    glBindTexture(GL_TEXTURE_2D,tId); //bind the texture

    image = SOIL_load_image(fileName,&width,&height,0,SOIL_LOAD_RGBA); //load image data

    if(!image)
    cout<< "no image found"<<endl;

    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width, height,0,GL_RGBA,GL_UNSIGNED_BYTE,image); //set the texture
    SOIL_free_image_data(image); //don't need image anymore

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

//Bind Texture to texture handler
void textureLoader::binder(GLuint tId)
{
    glBindTexture(GL_TEXTURE_2D,tId);
}
