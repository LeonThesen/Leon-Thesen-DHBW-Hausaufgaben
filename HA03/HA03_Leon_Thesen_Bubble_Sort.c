#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LEN 10000
#define NUM_COMMANDS 2



void stringToLower(char *string) {
	int i;
	int len = strlen(string); // 
	for(i=0; i<len; i++) {
		if(string[i] >= 'A' && string[i] <= 'Z') {
			string[i] += 32;
		}
	}
    printf("\n\n");
}







void bubbleSort(double *array, int lenOfArr){

  double temp;

  for (int n = lenOfArr; n>1; n--){
    for (int i=0; i<n-1; i++){
      if (array[i] > array[i+1]){
        temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
      } // Ende if
    } // Ende innere for-Schleife
  } // Ende äußere for-Schleife

}

int main(){

    int i = 0; // local counter
    int userFLAGG;
    FILE *fPtr;

    double *complexNumber[3]; // real, imag, length
    double *userChoice;

    for (i = 0; i < 3; i++) { // reseve storage for 
        complexNumber[i] = (double *)malloc(LEN * sizeof(double)); 
        if (complexNumber[i] == NULL) { 
            printf("can't reserve storage.\n"); 
            return -1;
            }
    }


    fPtr = fopen("re.txt", "r"); // read real part
	  if(fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to load file: %s.\n","re.txt");
        return -1;
    }else{  
        for(i = 0; i < LEN; i++){
            fscanf(fPtr,"%lf",&complexNumber[0][i]);
        }
    fclose(fPtr);
    }

    fPtr = fopen("im.txt", "r"); // read imag part and calc the magnitude
	  if(fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to load file: %s.\n","re.txt");
        return -1;
    }else{  
        for(i = 0; i < LEN; i++){
            fscanf(fPtr,"%lf",&complexNumber[1][i]);
            complexNumber[2][i] = sqrt(pow(complexNumber[0][i],2) + pow(complexNumber[1][i],2));
        }
    fclose(fPtr);
    }

    printf("sorting current complex numbers according to ...\n");
    printf(" [1] ... re-part\n [2] ... im-part\n [3] ... magnitude\n [0] ... exit\n");
    
    scanf("%d",&userFLAGG);

    switch (userFLAGG)
    {
    case 1: 
        userChoice = &complexNumber[0][0];
        break;
    case 2: 
        userChoice = &complexNumber[1][0];
        break;    
    case 3: 
        userChoice = &complexNumber[2][0];
        break;
    default:
        printf("invalid choice.\n");
        return -1;
    }

    bubbleSort(userChoice,LEN);

    printf("sorting completed\n");

    fPtr = fopen("result.txt", "w");

	if(fPtr == NULL){
        /* File not created hence exit */
        printf("Unable to open file: %s.\n","result.txt");
        return -1;
    }else{
        for(i = 0; i < LEN; i++)
        {
            fprintf(fPtr,"%lf\n",userChoice[i]);
        }
        
        fclose(fPtr);

    }
        
    char * commandsForGnuplot[] = {"set title \"Results of bubblesort\"", "plot 'result.txt'"};
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    for (i=0; i < NUM_COMMANDS; i++)
    {
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    }

    printf("process completed.\n");
    return 0;
}