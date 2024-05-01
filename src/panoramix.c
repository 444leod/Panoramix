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

villagers_t create_villagers(conf_t *conf, druid_t druid)
{
    villagers_t villagers = NULL;
    villager_t villager = NULL;

    for (__uint8_t i = 0; i < conf->nb_villagers; i++) {
        villager = create_villager(i, conf, druid);
        add_to_list((void *)villager, (node_t *)&villagers);
    }
    return villagers;
}

void wait_for_villagers(villagers_t villagers)
{
    villagers_t tmp = villagers;

    while (tmp) {
        pthread_join(((villager_t)tmp->villager)->thread, NULL);
        tmp = tmp->next;
    }
}

void panoramix(conf_t *conf)
{
    druid_t druid = create_druid(conf);
    villagers_t villagers = create_villagers(conf, druid);

    DEBUG_PRINT("nb_villagers: %d\n", conf->nb_villagers);
    DEBUG_PRINT("pot_size: %d\n", conf->pot_size);
    DEBUG_PRINT("nb_fights: %d\n", conf->nb_fights);
    DEBUG_PRINT("nb_refills: %d\n", conf->nb_refills);
    DEBUG_PRINT("Villagers created\n");
    wait_for_villagers(villagers);
    druid->villagers_ended = true;
    pthread_join(druid->thread, NULL);
}
