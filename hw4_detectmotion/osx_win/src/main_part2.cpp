#include "ps3eye.h"
#include "context.h"
#include "frame_function.h"

enum colors{
    RED,
    GREEN,
    BLUE,
    WHITE,
    BLACK
};

int main(int argc, char **argv){
    if (argc <2){
        cout << "USAGE: ./part2 COLOR"<< endl;
        exit(1);
    }
    
    colors color1 = RED;
    string str_in = argv[1];
    
    vector<Scalar> all_colour;
    all_colour.push_back(Scalar(0,0,255));
    all_colour.push_back(Scalar(0,255,0));
    all_colour.push_back(Scalar(255,0,0));
    all_colour.push_back(Scalar(255,255,255));
    all_colour.push_back(Scalar(0,0,0));
    
    if (str_in=="RED"){
        color1 = RED;
    } else if (str_in == "GREEN"){
        color1 = GREEN;
    }else if (str_in == "BLUE"){
        color1 = BLUE;
    }else if (str_in == "WHITE"){
        color1 = WHITE;
    }else if (str_in == "BLACK"){
        color1 = BLACK;
    }
    
    Scalar colour = all_colour[color1];
    
    vector<Scalar>().swap(all_colour);
    
    Context ctx;
    run_camera(ctx, colour);
    
}
