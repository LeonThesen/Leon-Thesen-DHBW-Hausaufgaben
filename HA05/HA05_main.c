#include <stdlib.h>
#include <stdio.h>
#include "HA05_rhsLib.h"

#define NUMOFSTATES 2
#define NUMOFCOMMANDS 3
/*******************************************************
* NAME: HA05_main.c (main) 
*
* AUTHOR: jannik wiessler
*
* DATE: 2020-06-06
*
* DESCRIPTION:  Implementation of a simple explicit euler method. 
*               
*
* DEPENDENCIES: 
*   >> HA05_rhsLib.c
*   >> HA05_rhsLib.h
*
* INFO: For DHBW use only.
*   >> Modelling of spring damper system
*   >> Simulation with simple euler foreward method
*
**/
int main(){

    char * commandsForGnuplot[] = {"set title \"Results of simulation\"", "set xlabel \"time in s\"",
    "plot 'results.txt' using 1:2 title 'position', 'results.txt' using 1:3 title 'speed'"};

    FILE* fp;
    fp = fopen("results.txt", "w");
    if(fp == NULL) {
	    printf("Datei konnte NICHT geoeffnet werden.\n");
        return -1;
    }

    double rhs[NUMOFSTATES]; // create rhs
    double y[NUMOFSTATES]; // state vector

    double h = 2e-2; // stepsize for integrator
    double simTime = 12; // time of simulation in seconds

    // init all vecs to zero //
    for(int i = 0; i < NUMOFSTATES; i++){
        rhs[i] = 0;
        y[i] = 0;
    }

    // init x and v //  
    y[0] = 1; // location 
    y[1] = 0; // speed

    // euler forward //
    for(int i = 0; i < simTime/h; i++){   //simtime/h == max. Schrittanzahl
            fprintf(fp,"%lf %lf %lf\n",(h*i),y[0],y[1]);
            RHS_MSD(rhs,y_old);
            y[0]= y[0]+rhs[0]*h;
            y[1]= y[1]+rhs[1]*h;    
    }

    fclose(fp);
    printf("finished...\n");
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    for (int i=0; i < NUMOFCOMMANDS; i++) fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    
return 0;
}