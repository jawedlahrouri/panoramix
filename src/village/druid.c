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
        while (village->pot > 0)
            pthread_cond_wait(&village->cond, &village->mutex);
        pthread_mutex_unlock(&village->mutex);
    }
    return NULL;
}

void init_druid(village_t *village)
{
    village->druid.thread = 0;
    printf("Druid: I'm ready... but sleepy...\n");
}

void destroy_druid(village_t *village)
{
    (void)village;
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
}

void druid_refill(village_t *village)
{
    village->pot = village->pot_size;
    village->nb_refills--;
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only make %d more refills after this one.\n", village->nb_refills);
    pthread_cond_broadcast(&village->cond);
    if (village->nb_refills == 0)
        destroy_druid(village);
}