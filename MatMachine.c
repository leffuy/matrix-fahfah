#include "Matrix.h"
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>

MatMachine* g_mach;
float* megaMatrix; 

//Init the machine resources
int initMachine(int mdsz){
megaMatrix = (float*)malloc(sizeof(float)*mdsz);

//Test the machine data structure return 'OK' if structure works
megaMatrix[0] = 23.0;

if(megaMatrix[0] == 23.0)
	return 0;

return 1;
}

//Releases the machine resources. Call before using free()
int releaseMachine(void){
free(megaMatrix);
return 0;
}

MatMachine* createMatMach(int version){
g_mach = (MatMachine*)malloc(sizeof(MatMachine));
g_mach->initMachine = &initMachine;
g_mach->releaseMachine = &releaseMachine;
return g_mach;
}


