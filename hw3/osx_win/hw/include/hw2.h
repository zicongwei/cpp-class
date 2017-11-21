#ifndef __HW2__
#define __HW2__

#include "hw1.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


template <typename T> class Image{
protected:
    int height;
    int width;
    vector<T> local_buffer; //

public:
    Image(){}
    Image(int x, int y): height(y), width(x){}
    Image(vector<T> &copy_from, int x, int y) //
     : height(y), width(x)
    {
        local_buffer.resize(x*y*3);
        for(uint i=0; i<copy_from.size(); ++i){
            local_buffer[i] = copy_from[i];
        }

    }
    virtual ~Image(){}

    virtual void populate_image() = 0;
    virtual void print_image() = 0;
    virtual void average_image() = 0;
    virtual void invert_image() = 0;
    virtual T *index_image(int x_val, int y_val) = 0;
    virtual void replace_in_image(T *start, char color, int value) = 0; //
    virtual void flip_image() = 0;
    virtual void copy_from(vector<T> &copy_from) = 0; //

};


template <typename T> class CameraImage: public Image<T>{
public:
    CameraImage() : Image<T>(){}
    CameraImage(int x, int y) : Image<T>(x,y){}
    CameraImage(vector<T> &copy_from, int x, int y) : Image<T>(copy_from, x,y){} //
    virtual ~CameraImage(){}

    virtual void populate_image(){
        hw::populate_vector(this->local_buffer);
    }

    virtual void print_image(){
        hw::print_vector(this->local_buffer, this->width, this->height);
    }

    virtual void average_image(){
        hw::average_vector(this->local_buffer);
    }

    virtual void invert_image(){
        hw::invert_vector(this->local_buffer);
    }

    virtual T *index_image(int x_val, int y_val){
        return hw::index_vector(this->local_buffer, this->width, this->height, x_val, y_val);
    }

    virtual void replace_in_image(T *start, char color, int value){
        hw::replace_in_vector(this->local_buffer, this->width, this->height, start, color, value);
    }

    virtual void flip_image(){
        hw::flip_vector(this->local_buffer, this->width, this->height);
    }

    //TODO copy from!
    virtual void copy_from(vector<T> &copy_from){ // x? y?
        this->local_buffer.resize(copy_from.size());
        for(uint i=0; i<copy_from.size(); ++i){
            this->local_buffer[i] = copy_from[i];
        }
    }
    
    friend ostream& operator<<(ostream& os, CameraImage<T> &v){
        int x_index = 0;
        for(T i: v.local_buffer){
            if(x_index == v.width*3){
                x_index = 0;
                os << endl;
            }
            
            os << i << " ";
            x_index++;
            
            if(x_index%3 ==0){
                os << "\t";
            }
        }
        os << endl;
        return os;
    }
    
    
    template <typename U> friend bool operator>(CameraImage<T>& one, CameraImage<U>& two){ // Add typename U?
        one.average_image();
        two.average_image();
        T average_one = one.getBuffer()[0];
        T average_two = two.getBuffer()[0];
        if (average_one > average_two){
            return true;
        } else {
            return false;
        }
    }
    
    template <typename U> friend bool operator!=(CameraImage<T>& one, CameraImage<U>& other){ // Add typename U?
        if(one.getBuffer().size()!=other.getBuffer().size()){
            return true;
        }
        for (int i=0; i<one.local_buffer.size(); i++){
            if (one.getBuffer()[i] == other.getBuffer()[i]){
                return false;
            }
        }
        return true;
    }
    
    vector<T> getBuffer(){
        return this->local_buffer;
    }
    
    template <typename U> friend bool operator==(CameraImage<T>& one, CameraImage<U>& other){
        if(one.getBuffer().size()!=other.getBuffer().size()){
            return false;
        }
        for (int i=0; i<one.local_buffer.size(); i++){ // How About Differnt Type??
            if ( one.getBuffer()[i]!=other.getBuffer()[i]){
                return false;
            }
        }
        return true;
    }
};


#endif
