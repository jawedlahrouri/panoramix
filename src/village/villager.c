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
    printf("Villager %d: Going into battle!\n", villager->id);
}

void refill_pot(village_t *village, villager_t *villager)
{
    printf("Villager %d: Hey Pano wake up! We need more potion.\n", villager->id);
    druid_refill(village);
}

void drink_potion(village_t *village, villager_t *villager)
{   
    if (village->pot == 0)
        refill_pot(village, villager);
    else 
        printf("Villager %d: I need a drink... I see %d servings left.\n", villager->id, village->pot);
}

void fight(village_t *village, villager_t *villager)
{
    drink_potion(village, villager);
    villager->nb_fights--;
    printf("Villager %d: Take that roman scum! Only %d fights left.\n", villager->id, villager->nb_fights);
}

void *villager(village_t *village, void *arg)
{
    villager_t *villager = (villager_t *)arg;

    while (villager->nb_fights > 0)
        fight(village, villager);
    printf("Villager %d: I'm going to sleep now.\n", villager->id);
    pthread_mutex_destroy(&villager->thread);
    return NULL;
}
