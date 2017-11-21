#include <vector>
#include <iostream>
#include "part2.hpp"
using namespace std;

void print_vector(vector<int> v, int x, int y) {
    for (int i = 0; i<y; ++i) {
        for (int j = 0; j<x; ++j) {
            cout << v[i*3*x+j*3] << " ";
            cout << v[i*3*x+j*3+1] << " ";
            cout << v[i*3*x+j*3+2] << " ";
            cout << "   ";
            
        }
        cout << endl;
    }
}

void average_vector(vector<int> &v){
    int n = v.size()/3;
    for (int i=0; i<n; ++i){
        int average = (v[i*3]+v[i*3+1]+v[i*3+2])/3;
        v[i*3] = average;
        v[i*3+1] = average;
        v[i*3+2] = average;
    }
}

void invert_vector(vector<int> &v){
    for (int &val: v){
        val = 255;
    }
}
