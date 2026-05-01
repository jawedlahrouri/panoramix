/*
** EPITECH PROJECT, 2026
** panoramix
** File description:
** druid handler
*/

#include "village.h"

void *druid(void *arg)
{
    village_t *village = (village_t *)arg;

    while (1) {
        pthread_mutex_lock(&village->mutex);
        while (village->pot > 0) {
            pthread_cond_wait(&village->cond, &village->mutex);
        }
    }
}

void init_druid(village_t *village)
{
    druid_t druid = {0};

    druid.nb_refills = village->nb_refills;
    druid.pot_size = village->pot_size;
    druid.pot = village->pot;
    printf("Druid: I'm ready... but sleepy...\n");
    druid.thread = pthread_self();
    pthread_mutex_init(&druid.mutex, NULL);
    pthread_cond_init(&druid.cond, NULL);
}

void destroy_druid(village_t *village)
{
    pthread_mutex_destroy(&village->mutex);
    pthread_cond_destroy(&village->cond);
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
}

void refill(village_t *village)
{
    village->pot = village->pot_size;
    village->nb_refills--;
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only make %d more refills after this one.", village->nb_refills);
    pthread_cond_broadcast(&village->cond);
    if (village->nb_refills == 0)
        destroy_druid(village);
}
