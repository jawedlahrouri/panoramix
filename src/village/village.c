/*
** EPITECH PROJECT, 2026
** panoramix
** File description:
** village handler
*/

#include "village.h"

int village_init(village_t *village)
{
    village->villagers = malloc(sizeof(villager_t) * village->nb_villagers);
    if (village->villagers == NULL)
        return 84;
    pthread_mutex_init(&village->mutex, NULL);
    sem_init(&village->potion_portions, 0, village->pot_size); 
    sem_init(&village->call_druid, 0, 0); 
    init_druid(village);
    for (int i = 0; i < village->nb_villagers; i++)
        init_villager(village, &village->villagers[i], i);
    return 0;
}

int village_destroy(village_t *village)
{
    for (int i = 0; i < village->nb_villagers; i++)
        destroy_villagers(&village->villagers[i]);
    pthread_mutex_destroy(&village->mutex);
    sem_destroy(&village->potion_portions);
    sem_destroy(&village->call_druid);
    free(village->villagers);
    return 0;
}
