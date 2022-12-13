#define _POSIX_C_SOURCE 199309L


#include "../inc/exo2.h"    

#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <errno.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

List *new_list(void){
    return NULL;
}

Bool is_empty_list(List *li){

    if(li == NULL) return true;

    return false;
}

int list_length(List *li){

    int length = 0; 
    
    if(!is_empty_list(li)){
        while(li!=NULL){
            length++;
            li = li->next;
        }
    }

    return length;
}

void print_list(List *li){
    
    List *tmp = li;
    if(is_empty_list(tmp)){
        printf("Liste vide\n");
        return;
    }

    printf("Name\tExe_t\tPrty\n");

    while(tmp!=NULL){
        printf("%s\t", tmp->Processus.name);
        printf("%d\t", tmp->Processus.exe_time);
        printf("%d\n", tmp->Processus.priority);
        tmp = tmp->next;
    }

}

List *push_back_list(List *li, int priority, int exe_time, char *name){

    List *element =  malloc(sizeof(*element));

    if(element == NULL){
        fprintf(stderr, "Erreur: allocation mémoire 'element' in push_back_list()\n");
        exit(EXIT_FAILURE);
    }

    strcpy(element->Processus.name, name);
    element->Processus.exe_time = exe_time;
    element->Processus.priority = priority;

    element->next = NULL;

    if(is_empty_list(li)){
        return element;
    } 

    List *tmp;
    tmp = li;

    while(tmp->next != NULL){
        tmp = tmp->next;
    } 

    //il aime pas ici apparemment
    tmp->next=element;

    

    return li;
}

List *push_front_list(List *li, int priority, int exe_time, char *name){

    List *element = malloc(sizeof(*element));

    if(element == NULL){
        fprintf(stderr, "Erreur: allocation mémoire 'element' in push_back_list()\n");
        exit(EXIT_FAILURE);
    }

    strcpy(element->Processus.name, name);
    element->Processus.exe_time = exe_time;
    element->Processus.priority = priority;

    if(is_empty_list(li)){
        element->next = NULL;
    }else{
        element->next = li;
    }

    return element;
}

List *pop_back_list(List *li){
    
    if(is_empty_list(li)) return new_list();

    if(li->next == NULL){
        free(li);
        li = NULL;

        return new_list();
    }

    List *tmp = li;
    List *new_last = tmp;

    while(tmp->next != NULL){
        new_last = tmp;
        tmp = tmp->next;
    }

    new_last->next = NULL;
    free(tmp);
    tmp = NULL;

    return li;
}

List *pop_front_element(List *li){

    if(is_empty_list(li)){
        return li;
    }

    List *element;

    // if(element == NULL){
    //     fprintf(stderr, "Erreur: allocation mémoire 'element' in push_front_list()\n");
    //     exit(EXIT_FAILURE);
    // }

    element= li->next;

    free(li);
    li=NULL;

    return element;
}
//function sleep in microseconds
void sleep_us(unsigned long microseconds){
    struct timespec ts;
    ts.tv_sec = microseconds / 1000000ul;            // whole seconds
    ts.tv_nsec = (microseconds % 1000000ul) * 1000;  // remainder, in nanoseconds
    nanosleep(&ts, NULL);
}

List *step(List *li){

    if(is_empty_list(li)){
        return new_list();
    }

    system("clear");
    printf("Processus %s encours, durée estimé : %ds\nVeuillez patienter...\n",li->Processus.name,li->Processus.exe_time);

    double divise_10 = li->Processus.exe_time;
    double waiting_10 = divise_10/10 * 1000000;
    
    for(int i = 0; i<10+1; i++){
        int current_chargement = 10 * i;
        printf("%d%%\n",current_chargement);
        sleep_us(waiting_10);

    }
    printf("Processus terminé\n");

    

    return pop_front_element(li);
}

List *run(List *li){

    if(is_empty_list(li)){
        return new_list();
    }
    // List *tmp = li;

    while(li != NULL){
        li = step(li);
    }
    sleep(3);
    system("clear");

    return li;

}

void Programme_exo2(){

    List *mylist = new_list();
    int tmp = 0;
    char *p, s[100];
    char name[255];
    int exec_time;
    int priority;
    int i = 0;
    int j = 1;

    printf("------ Bonjour vous avez choisis l'exo 2 ! -------\n");

    while(tmp != 9){
        printf("(1) Ajoutez une tâche\n");
        printf("(2) Afficher la liste de tâche\n");
        printf("(3) effectuer la première tâche\n");
        printf("(4) Effectuer toutes les tâches\n");
        printf("(9) Pour quitter\n");

         while (fgets(s, sizeof(s), stdin)) {
            tmp = strtol(s, &p, 10);
            // on parcours notre entrée pour vérifier que que c'est bien un entier, qui plus est compris entre 1-3 ou 9
            if (p == s || *p != '\n') {
                printf("Veuillez rentrer un entier:\n");
            }else if(tmp>0 && tmp<5){
                break;
            }else if(tmp == 9){
                break;
            }else{
                printf("Veuillez rentrer une valeur correcte:\n");
            }
        
        }
        
        system("clear");
        switch(tmp){
            case 1 :
                system("clear");
                while(i != 2){
                    printf("le nom de la tâche voulu\n");
                    scanf("%s",name);
                    printf("Priorité\n");
                    scanf("%d",&priority);
                    printf("Temps d'execution\n");
                    scanf("%d",&exec_time);
                    mylist = push_back_list(mylist, priority, exec_time, name);
                    
                    while(j != 0){
                        printf("\n\nAjouter plus ?\n(1) oui\n(2) non\n");
                        scanf("%d",&i);
                        system("clear");
                        if(i== 1){
                            j = 0;
                        }else if(i == 2){
                            j = 0;
                            break;
                        }else{
                           printf("Veuillez rentrer une valeur correct : 1 ou 0\n");
                        }
                    }
                    j = 1;
                    
                }
                i = 0;
                j = 1;
               
                break;

            case 2:
                if(is_empty_list(mylist)){
                    
                    printf("----------------liste vide--------------------\n\n");
                    break;
                }
                print_list(mylist);
                break;

            case 3:
                if(is_empty_list(mylist)){
                    printf("liste vide\n");
                    break;
                }
                mylist=step(mylist);
                break;
            case 4:
                if(is_empty_list(mylist)){
                    printf("liste vide\n");
                    break;
                }
                mylist = run(mylist);
                //erreur de heap use after free
                break;
            default:
                break;
                


        }
        
    }
    while(mylist!=NULL){
        mylist = pop_front_element(mylist);
    }
    
    system("clear");
}