#include <vector>
#include <stdlib.h>
#include "part1.hpp"
using namespace std;

vector<int> populate_vector(int x, int y) {
    vector<int> v;
    for(int i = 0; i < 3*x*y; ++i){
        v.push_back(rand() % 256);
    }
    return v;
}
