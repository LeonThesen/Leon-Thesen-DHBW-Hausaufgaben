#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "myFunc.h"

/*
Hausaufgabe zu VL02
Leon Thesen
16.05.2020
*/

//Ziel: Taschenrechner für komplexe Zahlen (Addieren,Subtrahieren,Multiplizieren,Dividieren)

//Einlesen der komplexen Zahl als string


int main() {
//init
char user_inputa[50];
char user_inputb[50];
char* char_finder;
int operation=0;
int anzeige=0;

printf("Eingabe erfolgt nach der kartesichen Darstellung in der Form a+bi (+ nicht vergessen)!\n");

printf("Komplexe Zahl 1 eingeben: ");
fgets(user_inputa,50,stdin);

printf("Komplexe Zahl 2 eingeben: ");
fgets(user_inputb,50,stdin);

printf("Waehlen sie die Operation aus:\n(1) fuer Addition\n(2) fuer Subtraktion\n(3) fuer Multiplikation\n(4) fuer Division\nEingabe: ");
scanf("%d",&operation);

printf("Waehlen sie die Art der Ergebnisanzeige aus:\n(1) fuer kartesische Form.\n(2) fuer Euler-Darstellung.\n(3) fuer fuer Polar-Koordinatenform.\nEingabe: ");
scanf("%d",&anzeige);

int laenge1=(int)strlen(user_inputa);
int laenge2=(int)strlen(user_inputb);


for (int i=0; i<laenge1;i++) {
    printf("%c",user_inputa[i]);
}
printf("\n");

for (int i=0; i<laenge2;i++) {
    printf("%c",user_inputb[i]);
}


//trennung von realteil und imaginaerteil

//neuer string der später einfach in ein double gecastet werden kann weil nur eine zahl enthalten ist

//ERSTE ZAHL

//suche das + zeichen im string und gebe den index aus
char_finder=strchr(user_inputa, '+'); //rueckgabewert null oder adresse
int index= (int) (char_finder-user_inputa); //Stelle an der das + Zeichen steht

char realteil_a[50];
int realteil_a_z=0;
char imgteil_a[50];
int imgteil_a_z=0;

//Realteil der ersten komplexen Zahl
for (int i=0; i<index;i++) {
    realteil_a[i]=user_inputa[i];
    realteil_a_z=realteil_a_z+1;
}

//Imaginaerteil der ersten komplexen Zahl
for (int i=index+1; i<laenge1-1;i++) {
    imgteil_a[i-(index+1)]=user_inputa[i];
    imgteil_a_z=imgteil_a_z+1;
}

//cast
double real_a;
double img_a;
real_a=atof(realteil_a);
img_a =atof(imgteil_a);

//ZWEITE ZAHL

char_finder=strchr(user_inputb, '+');
index= (int) (char_finder-user_inputb);

char realteil_b[50];
int realteil_b_z=0;
char imgteil_b[50];
int imgteil_b_z=0;

//Realteil der zweiten komplexen Zahl
for (int i=0; i<index;i++) {
    realteil_b[i]=user_inputb[i];
    realteil_b_z=realteil_b_z+1;
}

//Imaginaerteil der zweiten komplexen Zahl
for (int i=index+1; i<laenge1-1;i++) {
    imgteil_b[i-(index+1)]=user_inputb[i];
    imgteil_b_z=imgteil_b_z+1;
}

//cast
double real_b;
double img_b;
real_b=atof(realteil_b);
img_b =atof(imgteil_b);

komplex zahl1,zahl2,zahl_ergebnis;

zahl1.real=real_a;
zahl1.imag=img_a;

zahl2.real=real_b;
zahl2.imag=img_b;


switch (operation)
{
case 1: //add
    zahl_ergebnis=addieren(zahl1,zahl2);
    break;
case 2: //sub
    zahl_ergebnis=subtrahieren(zahl1,zahl2);
    break;
case 3: //multiply
    zahl_ergebnis=multiplizieren(zahl1,zahl2);
    break;
case 4: //divide
    zahl_ergebnis=dividieren(zahl1,zahl2);
    break;
}

//ausgabe

switch (anzeige) //kartesisch add/sub kann uebernommen werden aber mult/div muss noch umgewandelt werden
{
case 1:  
    printf("Ergebnis: %.3lf + %.3lfi",(double)zahl_ergebnis.real,(double)zahl_ergebnis.imag);
    break;

case 2:         //euler
    printf("Ergebnis: %.3lf * e^ (i * %.3lf)",betrag(zahl_ergebnis),phi(zahl_ergebnis));
    break;

case 3:
    printf("Ergebnis: %.3lf * cos(%.3lf)+ %.3lf * i * sin(%.3lf)",betrag(zahl_ergebnis),phi(zahl_ergebnis),betrag(zahl_ergebnis),phi(zahl_ergebnis));
    break;
}

getchar();
getchar();
getchar();
return 0;
}

