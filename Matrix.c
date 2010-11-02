#include <stdio.h>
#include <malloc.h>
#include <math.h>


//for a matrix type data size MUST == (row*col)
typedef struct Matrix{
int row;
int col;
float* data;
};



//Here are some comments to explain the beginning of this code

//a test main function wit
int main(int argc, char** argv){
//Example of how to setup the above matrix typedef.
int row = 3;
int col = 3;

//this will result in a size with some factor of nine 
float* rdta = (float*)malloc(sizeof(float)*row*col);

//setup the matrix



return 0;
}
