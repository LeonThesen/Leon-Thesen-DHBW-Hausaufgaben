#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "myFunction.h"
/*******************************************************
* NAME: Newton (main) 
*
* AUTHOR: jannik wiessler
*
* DATE: 2020-05-14
*
* DESCRIPTION:  Implementation of simple newton routine.
*
* DEPENDENCIES: 
*   >> myFunction.c
*   >> myFunction.h
*
* INFO: For DHBW use only.
*   >> Pointer to functions
*   >> Numerical approx auf derivative
*   >> Using GnuPlot for visualization 
*
**/
int main(){

int maxIter = 30;
double x = 1;
double y = 0;
double xOld = 5;
double xNew = 0;
double xSave[maxIter+1];
double ySave[maxIter+1];
double abort = 1e-10;
int totalLen = 0;

// fcn pointer
double (*myPolyGrad3PTR) (double);
myPolyGrad3PTR = myPolyGrad3;

// test the pointer
y = myPolyGrad3PTR(x);
printf("polyGrad3(%.3lf) = %.3lf\n",x,y);
y = numDiffGrad1(myPolyGrad3PTR,x);
printf("numDiffGrad1(%.3lf) = %.10lf\n",x,y);

// newton fcn
xSave[0] = xOld;
ySave[0] = myPolyGrad3PTR(xOld);
for(int i = 0; i < maxIter; i++){
    xNew = xOld - myPolyGrad3PTR(xOld)/numDiffGrad1(myPolyGrad3PTR,xOld);
    xOld = xNew;
    xSave[i+1] = xNew;
    ySave[i+1] = myPolyGrad3PTR(xNew);
    totalLen++;
    if(fabs(myPolyGrad3PTR(xOld))<= abort) break;
}

// ausgabe
printf("total loops performed: %d\n",totalLen);
for(int i = 0; i < maxIter+1; i++){
    printf("%d.: %.10lf\n",i,xSave[i]);
}

// save data to txt file for gnuplot
FILE* fp;
    fp = fopen("data2plot.txt", "w");
    if(fp == NULL) {
	    printf("Datei konnte NICHT geoeffnet werden.\n");
        return -1;
    }

for(int i = 0; i < totalLen; i++){
    fprintf(fp,"%d %lf %lf\n",i,xSave[i],ySave[i]);
}

fclose(fp);
//usr/local/Cellar/gnuplot/5.2.8/bin/gnuplot

char * commandsForGnuplot[] = {"set title \"Results of newton\"", 
    "set multiplot",
    "set size 0.8,0.4",
    "set origin 0.1,0.1", 
    "set xlabel \"iterations\"",
    "plot 'data2plot.txt' using 1:2 title 'xVals''",
    "set size 0.8,0.4",
    "set origin 0.1,0.6",
    "plot 'data2plot.txt' using 1:3 title 'yVals'",
    "unset multiplot"
    };

FILE * gnuplotPipe = popen("/usr/local/Cellar/gnuplot/5.2.8/bin/gnuplot -persistent", "w");
for (int i=0; i < 11; i++) fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.


}