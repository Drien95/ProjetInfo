
#include "../inc/logement.h"
#include "../inc/exo2.h"  
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define file "data/airbnb_donnees_propre.csv"
#define TOTAL_LENTGH 7917


int main(int argc, char const *argv[])
{

    int tmp = 0;
    char *p, s[100];

    system("clear");
    printf("--------------- Quelle exercice voulez-vous choisir ? ----------------\n\n");
    
    Logement* tlogement = initialise_array_logement(TOTAL_LENTGH);
    Logement X;

    while(tmp != 9){
        printf("(1) Exo 1\n");
        printf("(2) Exo 2\n");
        printf("(9) Pour quitter\n");

        while (fgets(s, sizeof(s), stdin)) {
            tmp = strtol(s, &p, 10);
            // on parcours notre entrée pour vérifier que que c'est bien un entier, qui plus est compris entre 1-3 ou 9
            if (p == s || *p != '\n') {
                printf("Veuillez rentrer un entier:\n");
            }else if(tmp>0 && tmp<3){
                break;
            }else if(tmp == 9){
                break;
            }else{
                printf("Veuillez rentrer une valeur correcte:\n");
            }
        
        }

        switch(tmp){

            case 1:
                // Programme_exo1(file);
                    system("clear");
                    X = take_data_X(X);
                    read_csv(file,tlogement);
                    //display_tlog(tlogement);
                    distance_similarity(X, tlogement);
                    // display_distance_similarity(tlogement);
                    which_characteristic(tlogement);
                    sleep(5);
                    system("clear");
                    
                break;
            case 2:
                 /***exo 2*/
                system("clear");
                Programme_exo2();
            default :
                break;
        }
    }
    free(tlogement);
    system("clear");

   

    return 0;
}
