#include "../inc/logement.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <errno.h>

#define MAX_LENGTH 255
#define TOTAL_LENGTH 7917


// Our characteristic
Logement take_data_X(Logement X){
    printf("Nombres de personnes :\n");
    scanf("%d",&X.acommodates);
    printf("Nombres de chambres :\n");
    scanf("%d",&X.bedrooms);
    printf("Nombre de douche :\n");
    scanf("%d",&X.bathrooms);
    printf("Nombre de lits :\n");
    scanf("%d",&X.beds);
    printf("Prix :\n");
    scanf("%d",&X.price);
    printf("Nombre de nuits mini :\n");
    scanf("%d",&X.minimum_nights);
    printf("Nombre de nuits maxi :\n");
    scanf("%d",&X.maximum_nights);
    printf("Nombre de reviews :\n");
    scanf("%d",&X.number_of_reviews);

    return X;
}

// Initialize my arrayStructure
Logement *initialise_array_logement(int size_length){

    Logement *array = (Logement*)malloc((size_length+1) * sizeof(Logement));

    return array;    
}

// Read file then creation of the structure part
void read_csv(char file[], Logement *tlog){

    //variable
    int i = 0;
    int tmp = 1;
    double value_tmp = 0;
    FILE *inputFile = fopen(file,"r");

    //test if my file is fine and not empty
    if(inputFile == NULL){
        fprintf(stderr, "Cannot read file %s, errno =%d\n", file, errno);
        exit(EXIT_FAILURE);
    }

    //skip the 1st line of my file
    char * buffer = (char *) malloc( MAX_LENGTH );
    fgets(buffer, MAX_LENGTH, inputFile);

    //take every line one by one of my file
    while (fgets( buffer, MAX_LENGTH, inputFile )) {

        //skip the '\n'
        buffer[strlen(buffer)-1] = '\0';

        //if error
        if ( ferror( inputFile ) ) {
            fprintf( stderr, "Reading error with code %d\n", errno);
            break;
        }
        
        //cut buffer into different part separate by ','
        char *c = strtok(buffer, ",");
        while(c != NULL){
            // printf("%s\n",c);
            switch(tmp){
                case 1 :
                    value_tmp = strtod(c, NULL);
                    tlog[i].id=(int)value_tmp;
                    break;
                case 2 :
                    value_tmp = strtod(c, NULL);
                    tlog[i].acommodates=(int)value_tmp;
                    break;
                case 3 :
                    value_tmp = strtod(c, NULL);
                    tlog[i].bedrooms=(int)value_tmp;
                    break;
                case 4:
                    value_tmp = strtod(c, NULL);
                    tlog[i].bathrooms=(int)value_tmp;
                    break;
                case 5:
                    value_tmp = strtod(c, NULL);
                    tlog[i].beds=(int)value_tmp;
                    break;
                case 6:
                    value_tmp = strtod(c, NULL);
                    tlog[i].price=(int)value_tmp;
                    break;
                case 7:
                    value_tmp = strtod(c, NULL);
                    tlog[i].minimum_nights=(int)value_tmp;
                    break;
                case 8:
                    value_tmp = strtod(c, NULL);
                    tlog[i].maximum_nights=(int)value_tmp;                    
                    break;
                case 9:
                    value_tmp = strtod(c, NULL);
                    tlog[i].number_of_reviews=(int)value_tmp;
                    break;
                default :
                    EXIT_FAILURE;
                    break;
                
                
            }
            tmp++;
            c = strtok(NULL, ",");
        }       
        
        tmp = 1;
        i++;
    }
    free( buffer );
    fclose(inputFile);
    
}

// Display of my structure
int display_tlog(Logement *tlog){

    
    for(int i=0;i<TOTAL_LENGTH;i++){
         printf("%d %d %d %d %d %d %d %d %d\n",tlog[i].id, tlog[i].acommodates,tlog[i].bedrooms,tlog[i].bathrooms,tlog[i].beds,tlog[i].price,tlog[i].minimum_nights,tlog[i].maximum_nights,tlog[i].number_of_reviews);
    }
    
    return 0;
}

// Calcul of every distance similarity
void distance_similarity(Logement X, Logement *tlog){

    if(tlog == NULL) EXIT_FAILURE;

    for(int size_tlog= 0; size_tlog<TOTAL_LENGTH; size_tlog++){
        for(int caracteristic = 0; caracteristic<8; caracteristic++){

            switch(caracteristic){
                case 0:
                    tlog[size_tlog].tcaracteristic[caracteristic] = sqrt(pow(X.acommodates - tlog[size_tlog].acommodates, 2));
                    break;
                case 1:
                    tlog[size_tlog].tcaracteristic[caracteristic] = sqrt(pow(X.bedrooms - tlog[size_tlog].bedrooms,2));
                    break;
                case 2:
                    tlog[size_tlog].tcaracteristic[caracteristic] = sqrt(pow(X.bathrooms - tlog[size_tlog].bathrooms,2));
                    break;
                case 3:
                    tlog[size_tlog].tcaracteristic[caracteristic] = sqrt(pow(X.beds - tlog[size_tlog].beds,2));
                    break;
                case 4:
                    tlog[size_tlog].tcaracteristic[caracteristic] = sqrt(pow(X.price - tlog[size_tlog].price,2));
                    break;
                case 5:
                    tlog[size_tlog].tcaracteristic[caracteristic] = sqrt(pow(X.minimum_nights - tlog[size_tlog].minimum_nights,2));
                    break;
                case 6:
                    tlog[size_tlog].tcaracteristic[caracteristic] = sqrt(pow(X.maximum_nights - tlog[size_tlog].maximum_nights,2));
                    break;
                case 7:
                    tlog[size_tlog].tcaracteristic[caracteristic] = sqrt(pow(X.number_of_reviews - tlog[size_tlog].number_of_reviews,2));
                    break;
                default:
                    EXIT_FAILURE;
                    break;
            }
            
        }
    }
}

// Display of every distance similarity
void display_distance_similarity(Logement *tlog){

    for(int size_tlog = 0; size_tlog<TOTAL_LENGTH; size_tlog++){
        for(int caracteristic = 0; caracteristic<8; caracteristic++){
            printf("%d ",tlog[size_tlog].tcaracteristic[caracteristic]);
        }
        printf("\n");
    }
}

// choice from which characteristic should i compare then sort
void which_characteristic(Logement *tlog){

    int characteristic;
    int true = 0;

    printf("En fonction de quelle caracteristique voulait estimer le prix de X ?\n");
    printf("1. acommodates\n");
    printf("2. bedrooms\n");
    printf("3. bathrooms\n");
    printf("4. beds\n");
    printf("5. price\n");
    printf("6. minimum_nights\n");
    printf("7. maximum_nights\n");
    printf("8. number_of_reviews\n");

    while(true != 1){
        scanf("%d",&characteristic);
        if(characteristic > 0 && characteristic < 9){
            true = 1;
        }else{
            printf("\n\nVeuillez rentrer une valeur comprise entre 1-8\n");
        }
    }

    quickSort(tlog, 0, TOTAL_LENGTH, characteristic);
    // display_tlog(tlog); 
    k_mean(tlog);

}

void k_mean(Logement *tlog){

    int k = 0;
    char *p, s[100];

    printf("Combien de bien voulez vous comparer ?\n");
    
    while (fgets(s, sizeof(s), stdin)) {
            k = strtol(s, &p, 10);
            if (p == s || *p != '\n') {
                printf("Veuillez rentrer un entier:\n");
            }else if(k<TOTAL_LENGTH && k>1){
                break;
            }else{
                printf("Veuillez rentrer une valeur correcte:\n");
            }
        
        }
    int price_estimation = price_estimation_from_k(tlog,k);
    system("clear");
    printf("Le prix estimée de votre bien est de %d€\n\n", price_estimation);

}

int price_estimation_from_k(Logement *tlog, int k_value){

    int total = 0;

    for(int i = 0; i<k_value; i++){
        total += tlog[i].price;
    }

    total = total / k_value;
    return total;
}

// sorting part
int partition(Logement *tlog, int low, int high, int characteristic){

    int pivot = tlog[high].tcaracteristic[characteristic-1]; 
    Logement tmp;
    int i = low-1; 
  
    for (int j = low; j <= high - 1; j++) 
    {
        if (tlog[j].tcaracteristic[characteristic-1] <= pivot) {
            i++; 
            tmp = tlog[i];
            tlog[i]=tlog[j];
            tlog[j]=tmp;
        }
    }
    tmp = tlog[i+1];
    tlog[i+1]=tlog[high];
    tlog[high]=tmp;
    return(i + 1);
}

int partition_r(Logement *tlog, int low, int high, int characteristic){

    srand(time(NULL));
    int random = low + rand() % (high - low);
    Logement tmp;

    tmp=tlog[random];
    tlog[random]=tlog[high];
    tlog[high]=tmp;
  
    return partition(tlog, low, high, characteristic);
}

void quickSort(Logement *tlog, int low, int high, int characteristic){
    if (low < high) {

        int pi = partition_r(tlog, low, high, characteristic);
  
        quickSort(tlog, low, pi - 1, characteristic);
        quickSort(tlog, pi + 1, high, characteristic);
    }
}

void Programme_exo1(char file[]){

}






