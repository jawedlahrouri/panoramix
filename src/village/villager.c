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

void drink_potion(village_t *village, villager_t *villager)
{   
    if (village->pot == 0)
        refill_pot(village, villager);
    else 
        printf("Villager %d: I need a drink... I see <nb_servings_left> servings left.\n", villager->id);
}

void refill_pot(village_t *village, villager_t *villager)
{
    printf("Villager %d: Hey Pano wake up! We need more potion.\n", villager->id);
    druid_refill(village);
}

void fight(village_t *village, villager_t *villager)
{
    drink_potion(village, villager);
    villager->nb_fights--;
    printf("Villager %d: Take that roman scum! Only %d fights left.\n", villager->id, villager->nb_fights);
    if (villager->nb_fights == 0)
        destroy_villagers(villager);
}

void destroy_villagers(villager_t *villager)
{
    printf("Villager %d: I'm going to sleep now.\n", villager->id);
}
