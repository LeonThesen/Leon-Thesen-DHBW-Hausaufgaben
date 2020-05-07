#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int num = 0; //Benutzerfreundliche Eingabe des Wertebereichs
	while (num == 0) {
		printf("Geben sie das Maximum des Wertebereichs an von dem sie alle Primzahlen wissen wollen: \n");
		scanf_s("%d", &num);
		if (num < 0) {
			printf("Geben sie eine positive Zahl ein!\n");
			num = 0;
		}
	}
	//Array der Größe N(num) erzeugen
	int* matrix;
	matrix = (int*)malloc((num-2) * sizeof(int)); //void in int casten((int))
	if (matrix == NULL) {                          //ist der Speicher noch vorhanden
		printf("no storage reserved\n");
	}
	else {
		printf("storage reserved\n");
	}
	for (int i = 0; i < num-1; i++) {   //Array mit Zahlen von 2 bis N auffüllen
		matrix[i] = i + 2;
	}
	for (int i = 0; i < num-1; i++) {      //Alle Zahlen des Wertebereichs anzeigen lassen
		printf("Zahl: %d\n", matrix[i]);
	}
	int teiler;
	int endwert = sqrt(num);
	printf("Endwert: %d\n", endwert);
	for (teiler = 2; teiler < endwert+1; teiler++) {
		for (int i = 1; i < num - 1; i++) {  //Idee: Array durchlaufen.  Vielfache von Teiler identifizieren mit modulo und gleich null setzen
			if (matrix[i] != 0 && matrix[i]/teiler != 1) {
				int rest = matrix[i] % teiler;
				if (rest == 0) {               //Rest=0 also Vielfache von 2(Teiler) 
					matrix[i] = 0;
				}
			}
		//	printf("Primzahl: %d\n", matrix[i-1]);

		}
	}
		int counter = 0;

		for (int i = 0; i < num - 1; i++) {         //Zählen der Anzahl übrig gebliebenen Elemente
			if (matrix[i] != 0) {
				counter = counter + 1;
			}
		}
		int* newmatrix;
		newmatrix = (int*)malloc((counter) * sizeof(int)); //void in int casten((int))
		if (matrix == NULL) {                          //ist der Speicher noch vorhanden
			printf("no storage reserved\n");
		}
		else {
			printf("storage reserved\n");
		}
		for (int i = 0; i < num - 1; i++) { 
			for (int z = 0; z < 1; z++) {                   //PROBLEM UNGLEICHE ARRAY GROESSE  //Speichern der übrig gebliebenen Elemente in neuer Matrix angepasster Größe
				if (matrix[i] != 0) {
					newmatrix[z] = matrix[i];
				}
			}
		}
		for (int i = 0; i < num-1; i++) {
			for (int z = 0; z < 1; z++) {
				if (matrix[i] != 0) {
					newmatrix[z] = matrix[i];
					printf("Primzahl: %d\n", newmatrix[z]);
				}
					z = z + 1;
				}
			}
		}
		
	

	