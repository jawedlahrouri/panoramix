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
#include <semaphore.h>

typedef struct village_s village_t;

typedef struct druid_s {
    pthread_t thread;
} druid_t;

typedef struct villager_s {
    pthread_t thread;
    int id;
    int nb_fights;
    village_t *village;
} villager_t;

struct village_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
    int pot;
    druid_t druid;
    villager_t *villagers;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};

int check_argument(int argc, char **argv);
village_t parse_arguments(char **argv);
int village_init(village_t *village);
int village_destroy(village_t *village);
int village_start(village_t *village);
int village_wait(village_t *village);
int village_run(village_t *village);

void init_villager(village_t *village, villager_t *villager, int id);
void destroy_villagers(villager_t *villager);
void refill_pot(village_t *village, villager_t *villager);
void drink_potion(village_t *village, villager_t *villager);
void fight(village_t *village, villager_t *villager);
void *villager(void *arg);

void init_druid(village_t *village);
void *druid(void *arg);

#endif /* !VILLAGE_H_ */
