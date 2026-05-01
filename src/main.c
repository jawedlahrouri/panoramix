/*
** EPITECH PROJECT, 2026
** panoramix
** File description:
** main
*/

#include "village.h"

int check_argument(int argc, char **argv)
{
    if (argc != 5) {
        printf("USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>");
        return 84;
    }
    if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0 || atoi(argv[3]) <= 0 ||
        atoi(argv[4]) <= 0) {
        printf("USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>\nValues must be >0.\n");
        return 84;
    }
    return 0;
}

village_t parse_arguments(char **argv)
{
    village_t village;

    village.nb_villagers = atoi(argv[1]);
    village.pot_size = atoi(argv[2]);
    village.nb_fights = atoi(argv[3]);
    village.nb_refills = atoi(argv[4]);
    return village;
}

int main(int argc, char **argv)
{
    village_t village = {0};

    if (check_argument(argc, argv) == 84)
        return 84;
    village = parse_arguments(argv);
    village.pot = village.pot_size;
    init_druid(&village);
    printf("The village has %d villagers, a pot size of %d, and there will be\
        %d fights and %d refills.\n", village.nb_villagers, village.pot_size,
        village.nb_fights, village.nb_refills);
    return 0;
}
