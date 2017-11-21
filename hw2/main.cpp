#include <iostream>
#include <vector>
#include <sstream>
#include "hw2.h"


using namespace std;

int main(int argc, const char * argv[]) {

    std::string in;
    cout << "CameraImage or PersistentCameraImage? ";
    cin >> in;
    
    PersistentCameraImage img;
    if (in== "PersistentCameraImage") {
        img = PersistentCameraImage("test", "outfile");
    } else if (in == "CameraImage") {
        int x;
        cout << "Please enter an interger for X value: ";
        cin >> x;
        int y;
        cout << "Please enter an integer for Y value: ";
        cin >> y;
        img = PersistentCameraImage(x,y);
        img.populate_image();
    } else {
        cout << "Wrong Input" << std::endl;
        return 0;
    }

    cout << "Print Vectors:" << endl;
    img.print_image();
    
    for(;;){
        cout << "Give a command: ";
        char input;
        cin >> input;
        if (input == 'p'){
            cout << "Print Image:" << endl;
            img.print_image();
        }
        if (input == 'i'){
            img.invert_image();
            cout << "Invert Image:" << endl;
            img.print_image();
        }
        if (input == 'a'){
            img.average_image();
            cout << "Average Image:" << endl;
            img.print_image();
        }
        if (input == 'f'){
            img.flip_image();
            cout << "Flip Image:" << endl;
            img.print_image();
        }
        if (input == 'r'){
            int new_x, new_y;
            cin >> new_x;
            cin >> new_y;
            char colour;
            cin >> colour;
            int value;
            cin >> value;
            cout << "Replace Image:" << endl;
            img.replace_in_image(img.index_image(new_x, new_y), colour, value);
            img.print_image();
        }
        if (input == 'q'){
            break;
        }
        
    }
    
    return 0;
}
