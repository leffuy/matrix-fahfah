#include "Matrix.h"
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>

float* megaMatrix; 


int initMachine(int mdsz){
megaMatrix = (float*)malloc(sizeof(float)*mdsz);

//Test the machine data structure return 'OK' if structure works
megaMatrix[0] = 23.42
if(megaMatrix[0] == 23.42)
	return 0;

return 1;
}
