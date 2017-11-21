#include <iostream>
#include <vector>
#include "part2.hpp"
#include "../part1/part1.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    int x;
    cout << "Please enter an interger for X value: ";
    cin >> x;
    int y;
    cout << "Please enter an integer for Y value: ";
    cin >> y;
    vector<int> pixels = populate_vector(x, y);
    
    cout << "Print Vectors:" << endl;
    print_vector(pixels, x, y);
    
    average_vector(pixels);
    cout << "Average Vectors:" << endl;
    print_vector(pixels, x, y);
    
    invert_vector(pixels);
    cout << "Invert Vectors:" << endl;
    print_vector(pixels,x,y);
    
    return 0;
}
