//this would make a good header file rearrange
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>

//for a matrix type data size MUST == (row*col)
typedef struct{
int row;
int col;
float* data;
}Matrix;

/*typedef struct{
int (*allocMatrix)(Matrix m) = 0;
int (*freeMatrix)(int mNum) = 0;
float (*MatrixSum)(int mNum) = 0;
}MatFace;
*/
/*
The above was an experiment for polymorphism. Unnecessary for a traditional 
interface. In following elements are stats of the "machine" operation
as a whole.

int mats;
int* rs;
int* cs;
int* sid;
float* matData;
*/
//Interface for basic matrix operations
//This is a matrix machine posed as an interface.
typedef struct{
int (*initMachine)(int mdsz);
int (*allocMatrix)(Matrix m);
int (*freeMatrix)(int mNum);
Matrix (*getMatrix)(int mNum);
}MatMachine;

//
extern MatMachine* createMatMach(int version); //restrict with #define VERSION



//
//End Useful Code
//Below is just a test comment out or manipulate to sandbox
//Here are some comments to explain the beginning of this code
//a test main function wit
int main(int argc, char** argv){
//Begin Matrix Build
//Example of how to setup the above matrix typedef.
srand(1342);
//Establish the matrix
Matrix bigM;
//test variable; set to arbritary but static values
int i = 0;
int row = 3;
int col = 3;
//this will result in a size with some factor of nine 
float* rdta = (float*)malloc(sizeof(float)*row*col);
//setup the matrix
bigM.row = row;
bigM.col = col;
for(i=0; i<row*col; i++){
*(rdta + i) = (float)rand()/(float)RAND_MAX;
}
bigM.data = rdta;
//After this you have a bigM that is "operational"
//Ene Matrix Build


//Test sandbox code
//Here:

printf("Element 4: %f \n", *((bigM.data)+3));
printf("Free memory\n");
free(bigM.data);
printf("Memory freed\n");
printf("End program\n");
return 0;
}
