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
    pthread_cond_init(&village->cond, NULL);
    
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
    pthread_cond_destroy(&village->cond);
    free(village->villagers);
    return 0;
}

int village_start(village_t *village)
{
    pthread_create(&village->druid.thread, NULL, druid, village);
    for (int i = 0; i < village->nb_villagers; i++)
        pthread_create(&village->villagers[i].thread, NULL, villager, &village->villagers[i]);
    return 0;
}

int village_wait(village_t *village)
{
    for (int i = 0; i < village->nb_villagers; i++)
        pthread_join(village->villagers[i].thread, NULL);
    return 0;
}

int village_run(village_t *village)
{
    if (village_init(village) == 84)
        return 84;
    village_start(village);
    village_wait(village);
    village_destroy(village);
    return 0;
}