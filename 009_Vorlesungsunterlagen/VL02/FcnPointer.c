#include <stdio.h>
/*******************************************************
* NAME: Structs (main) 
*
* AUTHOR: jannik wiessler
*
* DATE: 2020-05-14
*
* DESCRIPTION: Einführendes Vorlesungsbeispiel zu Funktionspointern
*
* DEPENDENCIES: 
*
* INFO: For DHBW use only.
*
**/
double myFcn(double x){

    return x*x;
}


int main(){

    double value = 5;
    double res = 0;

    // fcn fpointer
    double (*myFcnPtr) (double);
    myFcnPtr = myFcn;

    // with fcn
    res = myFcn(value);
    printf("myFcn(%lf) = %lf\n",value,res);

    // with pointer
    res = myFcnPtr(value);
    printf("myFcnPtr(%lf) = %lf\n",value,res);


    return 0;
}