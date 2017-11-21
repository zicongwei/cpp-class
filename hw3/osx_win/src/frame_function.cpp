#include "frame_function.h"

void frame_function(Context &context, vector<uint8_t> &buffer){
    //hw::invert_vector(buffer);
    
    if (context.get_use_average()==true){
        hw::average_vector(buffer);
    }
}
