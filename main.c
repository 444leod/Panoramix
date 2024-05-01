/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "debug.h"
#include "macros.h"
#include "lib.h"
#include "garbage_collector.h"
#include "panoramix.h"

void display_help(void)
{
    printf(
        "USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>"
        "\n\n"
        "DESCRIPTION\n"
        "\tnb_villagers\t\tnumber of villagers in the village\n"
        "\tpot_size\t\tmaximum number that can be contained in the pot\n"
        "\tnb_fights\t\tmaximum number of fights a villager will "
        "engage in\n"
        "\tnb_refills\t\tnumber of time the druid will refill the pot\n"
        "All arguments must be > 0\n");
}

void verify_args(int argc, char *argv[])
{
    for (u_int8_t i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 ||
            strcmp(argv[i], "--help") == 0) {
            display_help();
            my_exit(0);
        }
    }
    if (argc != 5) {
        display_help();
        my_exit(84);
    }
    for (u_int8_t i = 1; i < argc; i++) {
        if (is_positive_number(argv[i]) == false || atoi(argv[i]) == 0) {
            display_help();
            my_exit(84);
        }
    }
}

conf_t *getconf(char *argv[])
{
    conf_t *conf = my_malloc(sizeof(conf_t));

    conf->nb_villagers = atoi(argv[1]);
    conf->pot_size = atoi(argv[2]);
    conf->nb_fights = atoi(argv[3]);
    conf->nb_refills = atoi(argv[4]);
    return conf;
}

int main(UNUSED int argc, UNUSED char *argv[])
{
    verify_args(argc, argv);
    panoramix(getconf(argv));
    my_exit(0);
    return 0;
}
