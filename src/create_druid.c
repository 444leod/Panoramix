/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** create_druid
*/

#include "panoramix.h"
#include "garbage_collector.h"

druid_t create_druid(conf_t *conf)
{
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    druid_t druid = my_malloc(sizeof(struct druid_s));

    druid->pot = conf->pot_size;
    druid->max_pot_size = conf->pot_size;
    druid->nb_refills = conf->nb_refills;
    druid->mutex = &mutex;
    druid->refill_asked = false;
    druid->villagers_ended = false;
    pthread_create(&druid->thread, NULL, &druid_loop, druid);
    return druid;
}
