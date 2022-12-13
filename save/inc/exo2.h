#ifndef __EXO2_H__
#define __EXO2_H__

typedef enum bool {
  false, true
}Bool;

typedef struct Processus{

    char name[255];
    int exe_time;
    int priority;
    
}Processus;

typedef struct ListElement{

    Processus Processus;
    struct ListElement *next;

}List;

   /*-----------------------------------------------------------------*/
  /*                            LIST_PART                            */
 /*-----------------------------------------------------------------*/

List *new_list(void);

Bool is_empty_list(List *li);

int list_length(List *li);

void print_list(List *li);

List *push_back_list(List *li, int priority, int exe_time, char *name);

List *push_front_list(List *li, int priority, int exe_time, char *name);

List *pop_back_list(List *li);

List *pop_front_element(List *li);

   /*-----------------------------------------------------------------*/
  /*                         RUNNING_PART                            */
 /*-----------------------------------------------------------------*/

List *step(List *li);

List *run(List *li);

void sleep_us(unsigned long microseconds);

  /*-----------------------------------------------------------------*/
 /*                        PROGRAMME_PART                           */
/*-----------------------------------------------------------------*/

void Programme_exo2();






#endif