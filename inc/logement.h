#ifndef __LOGEMENT_H__
#define __LOGEMENT_H__

#include <math.h>
#include <time.h>

typedef struct{
    int id;
    int acommodates;
    int bedrooms;
    int bathrooms;
    int beds;
    int price;
    int minimum_nights;
    int maximum_nights;
    int number_of_reviews;
    int tcaracteristic[8];

}Logement, *loge;


   /*-----------------------------------------------------------------*/
  /*                   INITIALISATION_PART                           */
 /*-----------------------------------------------------------------*/

Logement *initialise_array_logement(int size_length);

Logement take_data_X(Logement logement);

   /*-----------------------------------------------------------------*/
  /*                           DATA_PART                             */
 /*-----------------------------------------------------------------*/

void read_csv(char file[], Logement *tlog);

int display_tlog(Logement *tlog);

void distance_similarity(Logement X, Logement *tlog);

void display_distance_similarity(Logement *tlog);

void which_characteristic(Logement *tlog);

   /*-----------------------------------------------------------------*/
  /*                        SORTING_PART                             */
 /*-----------------------------------------------------------------*/
int partition(Logement *tlog, int low, int high, int characteristic);

int partition_r(Logement *tlog, int low, int high, int characteristic);

void quickSort(Logement *tlog, int low, int high, int characteristic);

   /*-----------------------------------------------------------------*/
  /*                     ESTIMATION_PART                             */
 /*-----------------------------------------------------------------*/
void k_mean(Logement *tlog);
int price_estimation_from_k(Logement *tlog, int k);

   /*-----------------------------------------------------------------*/
  /*                        PROGRAMME_PART                           */
 /*-----------------------------------------------------------------*/
void Programme_exo1(char file[]);

#endif