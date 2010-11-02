all: MatMachine.o Matrix.o
	gcc MatMachine.o Matrix.o -o MatterTester

MatMachine.o:
	gcc -c MatMachine.c

Matrix.o:
	gcc -c Matrix.c

clean:
	@rm *.o
	@rm MatterTester
