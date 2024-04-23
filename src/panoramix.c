/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** panoramix
*/

#include "panoramix.h"
#include "debug.h"
#include "macros.h"

void panoramix(UNUSED conf_t *conf)
{
    DEBUG_PRINT("nb_villagers: %d\n", conf->nb_villagers);
    DEBUG_PRINT("pot_size: %d\n", conf->pot_size);
    DEBUG_PRINT("nb_fights: %d\n", conf->nb_fights);
    DEBUG_PRINT("nb_refills: %d\n", conf->nb_refills);
}
