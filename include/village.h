/*
** EPITECH PROJECT, 2026
** village.h
** File description:
** village struct and function
*/

#ifndef VILLAGE_H_
#define VILLAGE_H_

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct village_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
    int pot;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} village_t;

#endif /* !VILLAGE_H_ */
