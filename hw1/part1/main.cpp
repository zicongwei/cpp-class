#include <iostream>
#include <vector>
#include "part1.hpp"
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
    for (int val: pixels){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
