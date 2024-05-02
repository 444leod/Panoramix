/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** panoramix
*/

#pragma once

#include <pthread.h>
#include <stdbool.h>
#include <semaphore.h>

typedef struct conf_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
} conf_t;

typedef struct druid_s {
    pthread_t thread;
    pthread_mutex_t *mutex;
    int max_pot_size;
    int pot;
    int nb_refills;
    bool villagers_ended;
    bool refill_asked;
} *druid_t;

typedef struct villager_s {
    pthread_t thread;
    pthread_mutex_t *mutex;
    int id;
    bool can_fight;
    int fights_left;
    druid_t druid;
} *villager_t;

typedef struct villagers_s {
    struct villagers_s *next;
    villager_t villager;
} *villagers_t;

void do_panoramix(conf_t *conf);
villager_t create_villager(int id, conf_t *conf, druid_t druid);
void *villager_loop(void *villager);
void logger(char *format, ...);
druid_t create_druid(conf_t *conf);
void *druid_loop(void *param);
