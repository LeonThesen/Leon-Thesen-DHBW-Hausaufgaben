#ifndef myFunc_H
#define myFunc_H

#define PI (3.1416) //JW-2020-05-19: nice use of define macro. u might consider M_PI ?

typedef struct {
	double real;
    double imag;
	}komplex;

double betrag(komplex );
double phi(komplex );
komplex addieren(komplex , komplex );
komplex subtrahieren(komplex , komplex );	
komplex multiplizieren(komplex , komplex );
komplex dividieren(komplex , komplex );


#endif 