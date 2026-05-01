/*
** EPITECH PROJECT, 2026
** villager
** File description:
** handle villager interactions
*/

#include "village.h"

void init_villager(villager_t *villager, int id)
{
    villager->thread = 0;
    villager->id = id;
    villager->nb_fights = 0;
    printf("Villager %d: Going into battle!\n", villager->id);
}

void drink_potion(villager_t *villager)
{
    printf("Villager %d: I need a drink... I see <nb_servings_left> servings left.\n", villager->id);
}

void refill_pot(villager_t *villager)
{
    printf("Villager %d: Hey Pano wake up! We need more potion.\n", villager->id);
}

void fight(villager_t *villager)
{
    printf("Villager %d: Take that roman scum! Only %d fights left.\n", villager->id, villager->nb_fights);
}

void destroy_villagers(villager_t *villager)
{
    printf("Villager %d: I'm going to sleep now.\n", villager->id);
}
