/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** villager_loop
*/

#include "panoramix.h"
#include <unistd.h>

void *villager_loop(void *villager)
{
    villager_t villager_struct = (villager_t)villager;

    logger("Villager %d: Going into battle!\n", villager_struct->id);
    sleep(1);
    logger("Villager %d: I'm back!\n", villager_struct->id);
    return NULL;
}
