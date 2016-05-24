#include <stdio.h>
#include <time.h>
#include <math.h>

float mutuo (float capitale, int mese, double tasso){
    return (capitale*(tasso/(1-(1/pow((tasso+1), mese)))));
}
