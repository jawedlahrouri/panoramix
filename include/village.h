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

typedef struct druid_s {
    pthread_t thread;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int nb_refills;
    int pot_size;
    int pot;
}
druid_t;

typedef struct villager_s {
    pthread_t thread;
    int id;
    int nb_fights;
} villager_t;

typedef struct village_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
    int pot;
    druid_t druid;
    villager_t *villagers;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} village_t;

#endif /* !VILLAGE_H_ */
