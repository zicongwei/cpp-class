#include <iostream>
#include <vector>
#include <sstream>
#include "part3.hpp"
#include "../part1/part1.hpp"
#include "../part2/part2.hpp"

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
    
    for(;;){
        cout << "Give a command: ";
        char input;
        cin >> input;
        if (input == 'p'){
            cout << "Print Vectors:" << endl;
            print_vector(pixels, x, y);
        }
        if (input == 'i'){
            invert_vector(pixels);
            cout << "Invert Vectors:" << endl;
            print_vector(pixels,x,y);
        }
        if (input == 'a'){
            average_vector(pixels);
            cout << "Average Vectors:" << endl;
            print_vector(pixels, x, y);
        }
        if (input == 'f'){
            flip_vector(pixels,x,y);
            cout << "Flip vector:" << endl;
            print_vector(pixels, x, y);
        }
        if (input == 'r'){
            int new_x, new_y;
            cin >> new_x;
            cin >> new_y;
            char colour;
            cin >> colour;
            int value;
            cin >> value;
            cout << "Replace vector:" << endl;
            replace_in_vector(pixels, value, colour, new_x, new_y, x, y);
            print_vector(pixels, x, y);
        }
        if (input == 'q'){
            break;
        }
   
    }
    
    int *start = index_vector(1,2,pixels,x,y);
    cout << *start <<endl;
    
    replace_in_vector(pixels, 100, 'b', 1, 2, x, y);
    cout << "Replace in vector:" << endl;
    print_vector(pixels, x, y);
    
    flip_vector(pixels,x,y);
    cout << "Flip vector:" << endl;
    print_vector(pixels, x, y);

    return 0;
}
