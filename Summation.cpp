#include <iostream>

using namespace std;

int s = 0;

float summation(float* numbers, int size){
     float sum = 0;
     for (int i; i <= size; i++){
         sum += *(numbers + i);
     }
     
     return sum;
}
