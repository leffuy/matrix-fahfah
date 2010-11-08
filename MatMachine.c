//Implements a MatMachine.c for the CPU see MatMachine.cu for device code

#define MAXMAT 4

#include "Matrix.h"
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

<<<<<<< HEAD
//Global handle to the machine interface after implementation use for self
//reference
=======

>>>>>>> 28e0dc49d45d9714b8df174e53e8353eea31ef68
MatMachine* g_mach;

//This could be bundled into member variables but left as static and scoped
//Into a static library like device when turned into MatMachine.o object code
static float* megaMatrix; 
static int* rs;
static int* cs;
static int mcnt;
static int memspt;


//Init the machine resources
int initMachine(int mdsz){
megaMatrix = (float*)malloc(sizeof(float)*mdsz);
rs = (int*)malloc(sizeof(int)*MAXMAT);
cs = (int*)malloc(sizeof(int)*MAXMAT);
mcnt = 0;
memspt = 0;
//Test the machine data structure return 'OK' if structure works
megaMatrix[0] = 23.0;

if(megaMatrix[0] == 23.0)
	return 0;

return 1;
}

//Releases the machine resources. Call before using free()
int releaseMachine(void){
free(megaMatrix);
free(rs);
free(cs);
return 0;
}

//allocates a matrix to the machine's database returns an SID
int allocMatrix(Matrix m){
int theSZ = m.row * m.col;

rs[mcnt] = m.row;
cs[mcnt] = m.col;

memcpy((megaMatrix + memspt), m.data, sizeof(float)*theSZ);

memspt += theSZ;
mcnt++;

return (mcnt - 1);
}

Matrix getMatrix(int mNum){
int i;
int mspt = 0;
Matrix retr;

retr.row = rs[mNum];
retr.col = rs[mNum];
retr.data = (float*)malloc(sizeof(float)*retr.row*retr.col);
<<<<<<< HEAD

=======
>>>>>>> 28e0dc49d45d9714b8df174e53e8353eea31ef68
for(i = 0; i < mNum; i++)
mspt += rs[i]*cs[i];

memcpy((retr.data), (megaMatrix + mspt), sizeof(float)*(retr.row*retr.col));

return retr;
}

Matrix addMatrices(int matID1, int matID2){
int i;
Matrix A;
Matrix B;
Matrix C;
if(rs[matID1]*cs[matID1] != rs[matID2]*cs[matID2])
	return C; //matrices aren't aligned correctly. addition not possible
A = getMatrix(matID1);
B = getMatrix(matID2);
C.row = B.row;
C.col = A.col;
C.data = (float*)malloc(sizeof(float)*C.row*C.col);

for(i = 0; i < A.row*B.col; i++){
C.data[i] = A.data[i] + B.data[i];
}

free(A.data);
free(B.data);

return C; //be sure to return
}


//Creates an instance of the machine to use and returns a handle
MatMachine* createMatMach(int version){
g_mach = (MatMachine*)malloc(sizeof(MatMachine));
g_mach->initMachine = &initMachine;
g_mach->releaseMachine = &releaseMachine;
g_mach->allocMatrix = &allocMatrix;
g_mach->getMatrix = &getMatrix;
g_mach->addMatrices = &addMatrices;
return g_mach;
}


