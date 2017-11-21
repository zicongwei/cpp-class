#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


#include "hw2.h"

Image::Image(){
    
}
    
Image::Image(int x, int y) {
        this->x = x;
        this->y = y;
    v.reserve(3*x*y);
    for (int i = 0; i < 3*x*y; i++)
    {
        v.push_back(0);
    }
    }
Image::Image(std::vector<int> &copy_from, int x_dim, int y_dim) {
        x = x_dim;
        y = y_dim;
        v = copy_from;
    }


CameraImage::CameraImage(){
    
}

CameraImage::CameraImage(int x, int y) {
        this->x = x;
        this->y = y;
	v.reserve(3*x*y);
	for (int i = 0; i < 3*x*y; i++)
	{
		v.push_back(0);
	}
}

CameraImage::CameraImage(std::vector<int> &copy_from, int x_dim, int y_dim){
        x = x_dim;
        y = y_dim;
        v = copy_from;
    }


void CameraImage::populate_image() {
	    std::cout<<v.size()<<","<<3*x*y;
        populate_vector(v);
    }

void CameraImage:: print_image(){
    print_vector(v, x, y);
    }

void CameraImage:: average_image() {
        average_vector(v);
    }
    
void CameraImage:: invert_image() {
        invert_vector(v);
    }
    
int *CameraImage:: index_image(int x_val, int y_val) {
        return index_vector(v, x, y, x_val, y_val);
    }
    
void CameraImage:: replace_in_image(int *start, char color, int value){
        replace_in_vector(v, x, y, start, color, value);
    }
    
void CameraImage:: flip_image() {
        flip_vector(v, x, y);
    }




    
PersistentCameraImage::PersistentCameraImage(std::string infilename, std::string outfilename){
        this->outfilename = outfilename;

        std::ifstream inFile(infilename);
        int numRows = 0;
        std::string line;
        
        while (std::getline(inFile, line))
        ++ numRows;
        inFile.clear();
    
    inFile.seekg(0, std::ios::beg);
        std::getline(inFile, line);
        std::stringstream linestream(line);
        std::string value;
        int numCol = 0;
        while(getline(linestream,value,',')){
            ++ numCol;
        }
        inFile.clear();
        inFile.seekg(0, std::ios::beg);

    x = numCol/3;
    y = numRows;
    
        v.reserve(numRows*numCol);
        while (std::getline(inFile, line)) {
            std::stringstream linestream(line);
            std::string value;
            while(getline(linestream,value,',')) {
                v.push_back(std::stoi(value));
            }
        }

    }


void PersistentCameraImage:: print_image(){
    if (outfilename.empty()){
        CameraImage::print_image();
    } else {
    
    std::ofstream outfile;
    outfile.open(outfilename);
    int x_index = 0;
    for(int i: v){
        if(x_index == x*3){
            x_index = 0;
            outfile << "\n";
        }
        outfile << i << " ";
        x_index++;
        
        if(x_index%3 ==0){
            outfile << "\t";
        }
    }
    outfile << "\n";
    outfile << "\n";
    outfile.close();
    }

    }





























