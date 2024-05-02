/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** druid_loop
*/

#include "panoramix.h"
#include "macros.h"
#include <unistd.h>

void handle_refills(druid_t druid)
{
    if (druid->pot > 0) {
        druid->pot--;
        druid->refill_asked = false;
        return;
    }
    if (druid->nb_refills > 0) {
        druid->refill_asked = false;
        druid->pot = druid->max_pot_size;
        druid->nb_refills--;
        logger("Druid: Ah! Yes, yes, I'm awake !"
            " Working on it! Beware I can only make %d "
            "more refills after this one.\n", druid->nb_refills);
        if (druid->nb_refills == 0)
            logger("Druid: I'm out of viscum, I'm going back to... zZz\n");
    }
}

void *druid_loop(UNUSED void *param)
{
    druid_t druid = (druid_t)param;

    logger("Druid: I'm ready... but sleepy...\n");
    while (druid->villagers_ended == false) {
        if (druid->refill_asked == true) {
            handle_refills(druid);
        }
        if (druid->pot == 0 && druid->nb_refills == 0)
            break;
    }
    return NULL;
}
