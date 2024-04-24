/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** create_villager
*/

#include "panoramix.h"
#include "garbage_collector.h"

villager_t create_villager(int id)
{
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    villager_t villager = my_malloc(sizeof(struct villager_s));

    villager->id = id;
    villager->can_fight = false;
    villager->mutex = &mutex;
    pthread_create(&villager->thread, NULL, &villager_loop, villager);
    return villager;
}
