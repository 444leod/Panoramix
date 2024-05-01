/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** villager_loop
*/

#include "panoramix.h"
#include <unistd.h>

void ask_for_refill(villager_t villager)
{
    logger("Villager %d: I need a drink... I see %d servings left.\n",
        villager->id, villager->druid->pot);
    pthread_mutex_lock(villager->druid->mutex);
    if (villager->druid->pot == 0) {
        logger("Villager %d: Hey Pano wake up! We need more potion.\n",
            villager->id);
        villager->druid->refill_asked = true;
        while (villager->druid->refill_asked);
    }
    villager->druid->pot--;
    pthread_mutex_unlock(villager->druid->mutex);
    villager->can_fight = true;
}

void *villager_loop(void *villager)
{
    villager_t villager_struct = (villager_t)villager;

    logger("Villager %d: Going into battle!\n", villager_struct->id);
    while (villager_struct->fights_left > 0) {
        if (villager_struct->can_fight == false) {
            ask_for_refill(villager_struct);
        } else {
            villager_struct->fights_left--;
            villager_struct->can_fight = false;
            logger("Villager %d: Take that roman scum! Only %d left.\n",
                villager_struct->id, villager_struct->fights_left);
        }
    }
    logger("Villager %d: I'm going to sleep now.\n", villager_struct->id);
    return NULL;
}
