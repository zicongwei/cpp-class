/*
 * hw2.h
 */
#ifndef __HW2__
#define __HW2__

#include "hw1.h"
#include <fstream>

class Image {
    public:
    std::vector<int> v;
    int x;
    int y;
    
    
    Image();
    Image(int x, int y);
    Image(std::vector<int> &copy_from, int x_dim, int y_dim);

    virtual void populate_image() = 0;
    
    virtual void print_image() =0;
    
    virtual void average_image() =0;
    
    virtual void invert_image() =0;
    
    virtual int *index_image(int x_val, int y_val) =0;
    
    virtual void replace_in_image(int *start, char color, int value) =0;
    
    virtual void flip_image() =0;

};

class CameraImage: virtual public Image {
    public:

    CameraImage();
    CameraImage(int x, int y);
    CameraImage(std::vector<int> &copy_from, int x_dim, int y_dim);
    
    virtual void populate_image();
    
    virtual void print_image();
    
    virtual void average_image();
    
    virtual void invert_image();
    
    virtual int *index_image(int x_val, int y_val);
    
    virtual void replace_in_image(int *start, char color, int value);
    
    virtual void flip_image();
   
};


class PersistentCameraImage: public CameraImage{
    
public:
    
    PersistentCameraImage():CameraImage(){};
    PersistentCameraImage(int x, int y):CameraImage(x,y){};
    PersistentCameraImage(std::vector<int> &copy_from, int x_dim, int y_dim):CameraImage(copy_from, x_dim, y_dim){};
    PersistentCameraImage(std::string infilename, std::string outfilename);
    
    virtual void print_image();

    std::string outfilename;
    
    

};

#endif

