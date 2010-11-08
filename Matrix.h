//Matrix.h
//Matrix definitions for use in the C Programming language
//Please use in conjunction with MatMachine.c which includes the required
//C std libraries
//Nov 2010
//***********************

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
int (*releaseMachine)(void);
int (*allocMatrix)(Matrix m);
int (*freeMatrix)(int mNum);
Matrix (*getMatrix)(int mNum);
Matrix (*addMatrices)(int matID1, int matID2);
Matrix (*getHilbertMat) (int size);
}MatMachine;

//
extern MatMachine* createMatMach(int version); //restrict with #define VERSION



