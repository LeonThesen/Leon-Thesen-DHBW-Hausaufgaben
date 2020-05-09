#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Newton-Raphson-Verfahren zur Bestimmung von Nullstellen
// Funktion: f(x)=(x-3)^2
// Ableitung: f'(x)=2*(x-3)

//Funktion die neue x-Stelle berechnet nach Formel: xneu= xalt-(yalt/yableitungalt)

float input_error (float input) { //Funktion für benutzerfreundliche Eingabe
    int eingabe=0;
    while (eingabe == 0) {
		eingabe=scanf("%f", &input);
		if (eingabe == 0) {
			printf("Fehlerhafte Eingabe\n");
		}
        return input;
	}
}
float funktionswert(float x,float a, float b, float c, float d, float e, float f) {
    float grad5=a*pow(x,5);
    float grad4=b*pow(x,4);
    float grad3=c*pow(x,3);
    float grad2=d*pow(x,2);
    float grad1=e*pow(x,1);
    float grad0=f;
    
    return (grad5 + grad4 + grad3 + grad2 + grad1 + grad0);
}
float tangentensteigung(float x,float a,float b,float c, float d, float e) {
    //Ziel 2 : Ableitung bilden aus der Funktion und auch darein x-Eingaben ausrechnen lassen.
    // f'(x)= a*5*x^4 + b*4*x^3 + c*3*x^2 + d*2*x + e
    float mgrad4= a*5*pow(x,4);
    float mgrad3= b*4*pow(x,3);
    float mgrad2= c*3*pow(x,2);
    float mgrad1= d*2*x;
    float mgrad0= e;

    return (mgrad4 + mgrad3 + mgrad2 + mgrad1 + mgrad0); //f'(x)
}

int main() {
    //Initialisierung
    int num = 1;
    int i = 1;
    float x=0;
    float xneu = 0;
    float y = 1;
    float yableitung = 0;
    int running = 1;

    float a,b,c,d,e,f;
   
    printf("Geben sie eine Stelle auf der x-Achse ein um zu beginnen: ");
     x=input_error(x);

    printf("a eingeben: ");
    a=input_error(a);

    printf("b eingeben: ");
    b=input_error(b);

    printf("c eingeben: ");
    c=input_error(c);

    printf("d eingeben: ");
    d=input_error(d);

    printf("e eingeben: ");
    e=input_error(e);

    printf("f eingeben: ");
    f=input_error(f); 
    
    float hilfe = x;
    
    while (running == 1) {  //Erste While-Schleife bestimmt Größe für Arrays in denen die konvergierenden Werte abgelegt werden
        y = funktionswert(x,a,b,c,d,e,f); //f(x) //durch PolynomTry1.c ersetzen
        yableitung = tangentensteigung(x,a,b,c,d,e); //f'(x)  //durch PolynomTry1.c ersetzen
        xneu = x - (y / yableitung); //Newton-Raphson-Formel Bestimmung der verbesserten Stelle xn+1
        if (fabs(x - xneu) < 0.000001 ) {      //Abbruchkriterium mit Genauigkeit auf 5. Nachkommastelle
            running = 0;
        }
        x = xneu;
        num = num + 1; //zählt benötigten Platz für die Arrays
    }
    
    //Array-Initialisierung
    float* funktion = (float*)malloc(num * sizeof(float));
    float* stelle = (float*)malloc(num * sizeof(float));
    printf("\nNUM: %d\n", num);
    
    //Zurücksetzen der Variablen für eig. Berechnungsvorgang; Sinn: parallele Speicherung in Arrays ermöglichen bei bekannter Array-Größe in 2. while-Schleife
    xneu = 0;
    x = hilfe;
    running = 1;
    stelle[0] = x; //auch die Startwerte ins Array legen
    funktion[0] = funktionswert(x,a,b,c,d,e,f);
    
    //Zweite While-Schleife zur Speicherung der Ergebnisse
    while (running == 1) {
        y = funktionswert(x,a,b,c,d,e,f);
        funktion[i] = y;
        yableitung = tangentensteigung(x,a,b,c,d,e); //Funktion
        xneu = x - (y / yableitung);
        stelle[i] = xneu;
        if (fabs(x - xneu) < 0.000001) {
            running = 0;
        }
        x = xneu;
        i = i + 1;
    }
    for (int i = 0; i < num; i++) { //Ausgabe der Array-Inhalte
        printf("Ausgabe der Funktionswerte: %.6f\n", funktion[i]);
        printf("Ausgabe der x-Werte: %.6f\n\n", stelle[i]);
    }
    //Ausgabe
    printf("\nDie Nullstelle wurde an der Stelle %.3f berechnet.\n", xneu);

    getchar();
    getchar();

    return 0;
}
