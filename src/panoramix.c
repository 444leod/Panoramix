/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** panoramix
*/

#include "panoramix.h"
#include "debug.h"
#include "macros.h"
#include "linked_lists.h"

void panoramix(UNUSED conf_t *conf)
{
    villagers_t villagers = NULL;
    villagers_t villagers_tmp = NULL;

    DEBUG_PRINT("nb_villagers: %d\n", conf->nb_villagers);
    DEBUG_PRINT("pot_size: %d\n", conf->pot_size);
    DEBUG_PRINT("nb_fights: %d\n", conf->nb_fights);
    DEBUG_PRINT("nb_refills: %d\n", conf->nb_refills);
    for (__uint8_t i = 0; i < conf->nb_villagers; i++)
        add_to_list((void *)create_villager(i), (node_t *)&villagers);
    DEBUG_PRINT("Villagers created\n");
    villagers_tmp = villagers;
    while (villagers_tmp) {
        pthread_join(((villager_t)villagers_tmp->villager)->thread, NULL);
        villagers_tmp = villagers_tmp->next;
    }
}
