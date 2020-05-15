#include <stdio.h>
#include <string.h>
/*******************************************************
* NAME: Structs (main) 
*
* AUTHOR: jannik wiessler
*
* DATE: 2020-05-14
*
* DESCRIPTION: Einführendes Vorlesungsbeispiel zu Structs
*
* DEPENDENCIES: 
*
* INFO: For DHBW use only.
*
**/
struct student
{
    // name 
    char name[50];
    // anschrift
    char stadt[50];
    char strasse[100];
    int hausnummer;
    int plz;
    // größe
    double groesse;

};

int main(){

    // create obj
    struct student person1;
    
    // fill with data
    person1.groesse = 1.80;
    strcpy(person1.strasse,"Jaegerstrasse");
    strcpy(person1.name,"Jannik");
    strcpy(person1.stadt,"Stuttgart");
    person1.hausnummer = 10;
    person1.plz = 70199;


    // print objs data
    printf("person1.name = %s\n",person1.name);
    printf("person1.stadt = %s\n",person1.stadt);
    printf("person1.strasse = %s\n",person1.strasse);

    printf("person1.hausnummer = %d\n",person1.hausnummer);
    printf("person1.plz = %d\n",person1.plz);
    printf("person1.groesse = %lf\n",person1.groesse);

    



    return 0;
}