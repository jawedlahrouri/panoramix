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

    printf("Druid: I'm ready... but sleepy...\n");
    while (village->nb_refills > 0) {
        sem_wait(&village->call_druid);
        pthread_mutex_lock(&village->mutex);
        if (village->pot == 0) {
            village->pot = village->pot_size;
            village->nb_refills--;
            printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware ");
            printf("I can only make %d more refills after this one.\n",
                village->nb_refills);
            for (int i = 0; i < village->pot_size; i++)
                sem_post(&village->potion_portions);
        }
        pthread_mutex_unlock(&village->mutex);
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return NULL;
}

void init_druid(village_t *village)
{
    village->druid.thread = 0;
}
