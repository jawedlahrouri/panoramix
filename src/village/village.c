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
    for (int i = 0; i < village->nb_villagers; i++)
        init_villager(&village->villagers[i], i);
    return 0;
}

int village_destroy(village_t *village)
{
    for (int i = 0; i < village->nb_villagers; i++)
        destroy_villagers(&village->villagers[i]);
    free(village->villagers);
    return 0;
}

int village_start(village_t *village)
{
    for (int i = 0; i < village->nb_villagers; i++)
        pthread_create(&village->villagers[i].thread, NULL, villager, &village->villagers[i]);
    pthread_create(&village->druid.thread, NULL, druid, village);
    return 0;
}

int village_wait(village_t *village)
{
    for (int i = 0; i < village->nb_villagers; i++)
        pthread_join(village->villagers[i].thread, NULL);
    pthread_join(village->druid.thread, NULL);
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
