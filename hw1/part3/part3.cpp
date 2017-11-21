#include <vector>
#include <iostream>
#include "part3.hpp"
using namespace std;

int * index_vector(int x, int y, vector<int> &v, int xdim, int ydim){
    return &v[3*xdim*y+3*x];
}

void replace_in_vector(vector<int> &v, int value, char c, int x, int y, int xdim, int ydim){
    int *start = index_vector(x, y, v, xdim, ydim);
    if (c == 'r') {
        *start = value;
    } else if (c == 'g'){
        start = start+1;
        *start = value;
        
    } else if (c == 'b'){
        start = start+2;
        *start = value;
        
    }
}

void flip_vector(vector<int> &v, int x, int y){
    for(int i=0; i < y; ++i){
        for(int j=0; j<x/2; ++j){
            int p1 = v[i*3*x+3*j];
            int p2 = v[i*3*x+3*j+1];
            int p3 = v[i*3*x+3*j+2];
            int r = x-j-1;

            replace_in_vector(v,v[i*3*x+3*r],'r',j,i,x,y);
            replace_in_vector(v,v[i*3*x+3*r+1],'g',j,i,x,y);
            replace_in_vector(v,v[i*3*x+3*r+2],'b',j,i,x,y);
            
            replace_in_vector(v,p1,'r',r,i,x,y);
            replace_in_vector(v,p2,'g',r,i,x,y);
            replace_in_vector(v,p3,'b',r,i,x,y);
         
        }
    }
}
