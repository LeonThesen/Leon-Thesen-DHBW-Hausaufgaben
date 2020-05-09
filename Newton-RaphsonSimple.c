#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Newton-Raphson-Verfahren zur Bestimmung von Nullstellen
// Funktion: f(x)=(x-3)^2
// Ableitung: f'(x)=2*(x-3)

//Funktion die neue x-Stelle berechnet nach Formel: xneu= xalt-(yalt/yableitungalt)


/* TO-DO:
-Werte von x und von y in Array ablegen done
-Benutzer soll Startstelle festlegen  done
- evtl. verallgemeinern(!) Idee: erstmal Polynomfunktion konstruieren 
*/


int main() {
//Initialisierung
    int num = 1;
    int i = 1;
    float x = 0;
    float xneu = 0;
    float y = 1;
    float yableitung = 0;
    int running = 1;
    
    
    printf("Geben sie eine Stelle auf der x-Achse ein um zu beginnen: "); 
    scanf("%f", &x); //Startwert für x vom Benutzer eingeben lassen
    float hilfe = x;
    
    while (running == 1) {  //Erste While-Schleife bestimmt Größe für Arrays in denen die konvergierenden Werte abgelegt werden
        y = pow((x - 3), 2); //f(x)
        yableitung = 2 * (x - 3); //f'(x)  
        xneu = x - (y / yableitung); //Newton-Raphson-Formel Bestimmung der verbesserten Stelle xn+1
        if (fabs(x - xneu) < 0.00001 ) {      //Abbruchkriterium mit Genauigkeit auf 5. Nachkommastelle
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
    funktion[0] = pow((x - 3), 2);
    
    //Zweite While-Schleife zur Speicherung der Ergebnisse
    while (running == 1) {
        y = pow((x - 3), 2);
        funktion[i] = y;
        yableitung = 2 * (x - 3); //Funktion
        xneu = x - (y / yableitung);
        stelle[i] = xneu;
        if (fabs(x - xneu) < 0.00001) {
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