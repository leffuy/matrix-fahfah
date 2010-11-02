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



//Here are some comments to explain the beginning of this code

//a test main function wit
int main(int argc, char** argv){
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

printf("Element 4: %f \n", *((bigM.data)+3));
printf("Free memory\n");
free(bigM.data);
printf("Memory freed\n");
printf("End program\n");
return 0;
}
