#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "myFunc.h"


//funktion fuer betrag
double betrag(komplex number1) {
	return sqrt(pow(number1.real,2)+pow(number1.imag,2));
}

//funktion fuer winkel  
double phi(komplex number1) {
	double bogen = 180.0 / PI;
	double winkel=0;
	if (number1.real>0) {
		winkel=atan2(number1.imag,number1.real)*bogen;
	}else
	if (number1.real<0 && number1.imag>=0) {
		winkel=(atan2(number1.imag,number1.real)+PI) * bogen;
	}else
	if (number1.real<0 && number1.imag<0) {
		winkel=(atan2(number1.imag,number1.real)-PI) * bogen;
	}else
	if (number1.real==0 && number1.imag>0) {
		winkel=(PI/2)*bogen;
	}else
	if (number1.real==0 && number1.imag<0) {
		winkel=((PI/2)*bogen)*(-1);
	}
	return winkel;
}

komplex addieren(komplex number1, komplex number2) {
	komplex number_temp;
	number_temp.real= number1.real + number2.real;
	number_temp.imag=number1.imag + number2.imag;
	return number_temp;
}
komplex subtrahieren(komplex number1, komplex number2) {
	komplex number_temp;
	number_temp.real= number1.real - number2.real;
	number_temp.imag=number1.imag - number2.imag;
	return number_temp;
}
komplex multiplizieren(komplex number1, komplex number2) {
	komplex number_temp;
	double r,winkel;
	double bogen = 180.0 / PI;
	r=betrag(number1)*betrag(number2);
	winkel=phi(number1) + phi(number2);
	number_temp.real= r*cos(winkel/bogen);
	number_temp.imag= r*sin(winkel/bogen);
	return number_temp;
}
komplex dividieren(komplex number1, komplex number2) {
	komplex number_temp;
	double r,winkel;
	double bogen = 180.0 / PI;
	r=betrag(number1)/betrag(number2);
	winkel=phi(number1) - phi(number2);
	number_temp.real= r*cos(winkel/bogen);
	number_temp.imag= r*sin(winkel/bogen);
	return number_temp;
}