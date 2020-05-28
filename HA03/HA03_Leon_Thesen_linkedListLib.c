#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HA03_Leon_Thesen_linkedListLib.h" // JW 2020-05-27: dont forget to rename the includes as well !

void addListElem(listElement *start){
    
    listElement * new;
    new = (listElement *)malloc(sizeof(listElement));
    if (new == NULL) {
        printf("can't reserve storage.\n"); 
        return;
        }

    listElement * currElem = start;
    while (currElem->nextElem != NULL) currElem = currElem->nextElem;// get last elem in list
    currElem->nextElem = new; // add new to the end of list
    new->nextElem = NULL;
    
    /* fill data in new element */
    printf("Please enter last name: \n");
    scanf("%s",new->lastName);
    printf("Please enter first name: \n");
    scanf("%s",new->firstName);
    printf("Please enter age: \n");
    scanf("%d",&(new->age));
    printf("end of function\n");
}


void printList(listElement *start){
    if (start->nextElem == NULL) printf ("\n>> list is empty\n\n");
    else{
        int i = 0;
        listElement *currElem = start;
        printf("\n>> current list:\n\n");
            do {
                currElem = currElem->nextElem;
                printf("%d.",i); i++;
                printf("\tlast Name: %s\n",currElem->lastName);
                printf("\tfirst Name: %s\n",currElem->firstName);
                printf("\tage : %d\n",currElem->age);
                
            } while (currElem->nextElem != NULL);
    printf("\n");
    }
}

void delListElem(listElement *start){

    printf("\n>> delListElem fcn is tbd.\n\n");

}

void delList(listElement *start){

    printf("\n>> getLenOfList fcn is tbd.\n\n");

}

int getLenOfList(listElement *start){ // we use this for save list fcn

    int counter = 0;
    listElement * currElem = start;
    while (currElem->nextElem != NULL) {// get last elem in list
        currElem = currElem->nextElem; counter++;
        }
    return counter;
}

int saveList(listElement *start){
    listElement * currElem = start;
	char filename[50];
	printf("\n >> saving data...\n\n");
	printf("filename without extension: ");
	scanf("%s",filename);
	strcat(filename, ".txt"); // adding .txt to file name
	

	FILE * fPtr;
    fPtr = fopen(filename, "w");

    /* YOUR CODE HERE */
        
        if (fPtr == NULL) {
        printf("error:file cannot be opened!");
        return 1;
        }
        
        fprintf(fPtr,"%d\n",getLenOfList(start));

        do
        { 
        currElem = currElem->nextElem;
        fprintf(fPtr,"%s\n",currElem->lastName);
        fprintf(fPtr,"%s\n",currElem->firstName);
        fprintf(fPtr,"%d\n",currElem->age);
            
        } while (currElem->nextElem != NULL);

        printf("list was successfully saved!\n");
        fclose(fPtr);	
        return 0;
}


        

int loadList(listElement *start){
	listElement * currElem = start;
	char filename[50];
    int length_list=0;
    int j=0;

	printf("\nloading data...\n\n");
	printf("availible data: \n----------------\n");
	system("ls /b *.txt"); // dir /b *.txt for windows | print availible *.txt files in current location
	printf("\nfilename without extension: ");
	scanf("%s",filename);
	strcat(filename, ".txt"); // adding .txt to file name
	
	FILE * fPtr;
	fPtr = fopen(filename, "r");
	
    /* YOUR CODE HERE */
    
    if (fPtr == NULL) {
        printf("error:file cannot be opened!");
        return 1;
        }

        fscanf(fPtr,"%d",&length_list);
        
    do{
        listElement * new;
        new = (listElement *)malloc(sizeof(listElement));
        if (new == NULL) {
        printf("can't reserve storage.\n"); 
        return 1;
        }
        while (currElem->nextElem != NULL) currElem = currElem->nextElem;// get last elem in list
        currElem->nextElem = new; // add new to the end of list
        new->nextElem = NULL;      
    
        fscanf(fPtr,"%s",new->lastName);
        fscanf(fPtr,"%s",new->firstName);
        fscanf(fPtr,"%d",&(new->age));
        j++;
    }while (j<(length_list));   

	fclose(fPtr);
	printf("loading data will be append to current list...\n");
	printList(start); // show loaded list
    return 0;
}

void exitFcn(listElement *start){

  int saveFlagg = 0;

  printf("do you want to save the current list?\n");
  printf("[1] ... yes\n");
  printf("[0] ... no\n");
  scanf("%d",&saveFlagg);

  if (saveFlagg == 1) saveList(start);
  system("cls");


}


void sortList(listElement *start){
	
	printf("\n>>sortList fcn is tbd.\n\n");
    
}

void stringToLower(char *string) {
	
    printf("\n>>stringToLower fcn is tbd.\n\n");

}
/*
JW-2020-05-27:
--------------
> well done (9/10) 
> missing return statement in int function: -1Pkt
*/






