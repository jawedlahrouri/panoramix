/*
** EPITECH PROJECT, 2026
** villager
** File description:
** handle villager interactions
*/

#include "village.h"

void init_villager(village_t *village, villager_t *villager, int id)
{
    villager->thread = 0;
    villager->id = id;
    villager->nb_fights = village->nb_fights;
    villager->village = village;
}

void destroy_villagers(villager_t *villager)
{
    (void)villager;
}

void drink_potion(village_t *village, villager_t *villager)
{
    pthread_mutex_lock(&village->mutex);
    printf("Villager %d: I need a drink... I see %d servings left.\n",
        villager->id, village->pot);
    if (village->pot == 0) {
        printf("Villager %d: Hey Pano wake up! We need more potion.\n",
            villager->id);
        sem_post(&village->call_druid);
        sem_wait(&village->potion_portions);
        village->pot--;
        pthread_mutex_unlock(&village->mutex);
    } else {
        village->pot--;
        pthread_mutex_unlock(&village->mutex);
        sem_wait(&village->potion_portions);
    }
}

void fight(village_t *village, villager_t *villager)
{
    drink_potion(village, villager);
    villager->nb_fights--;
    printf("Villager %d: Take that roman scum! Only %d left.\n",
        villager->id, villager->nb_fights);
}

void *villager(void *arg)
{
    villager_t *my_data = (villager_t *)arg;
    village_t *village = my_data->village;

    printf("Villager %d: Going into battle!\n", my_data->id);
    while (my_data->nb_fights > 0)
        fight(village, my_data);
    printf("Villager %d: I'm going to sleep now.\n", my_data->id);
    return NULL;
}
