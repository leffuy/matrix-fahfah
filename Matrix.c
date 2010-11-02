//this would make a good header file rearrange
#include "Matrix.h"
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, char** argv){
MatMachine* a_mach = createMatMach(0);
int kino = a_mach->initMachine(800);
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
printf("Matrix Machine status K-var: %d \n", kino);
printf("Element 4: %f \n", *((bigM.data)+3));
printf("Free memory\n");
free(bigM.data);
a_mach->releaseMachine();
free(a_mach);
printf("Memory freed\n");
printf("End program\n");
return 0;
}
