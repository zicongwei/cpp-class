#ifndef __CONTEXT__
#define __CONTEXT__

class Context{
    //Maintain state if needed
    bool use_average;

public:
    int height = 480; // for example
    int width = 640; // for example
    
    bool get_use_average(){
        return use_average;
    }
};

#endif
