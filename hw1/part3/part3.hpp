#ifndef __part3hpp__
#define __part3hpp__

int * index_vector(int x, int y, std::vector<int> &v, int xdim, int ydim);

void replace_in_vector(std::vector<int> &v, int value, char c, int x, int y, int xdim, int ydim);

void flip_vector(std::vector<int> &v, int x, int y);

#endif
