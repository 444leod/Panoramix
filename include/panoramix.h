/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** panoramix
*/

#pragma once

#include <pthread.h>
#include <stdbool.h>

typedef struct conf_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
} conf_t;

typedef struct druid_s {
    pthread_t thread;
    pthread_mutex_t *mutex;
    int pot;
    int nb_refills;
} *druid_t;

typedef struct villager_s {
    pthread_t thread;
    pthread_mutex_t *mutex;
    int id;
    bool can_fight;
} *villager_t;

typedef struct villagers_s {
    struct villagers_s *next;
    villager_t villager;
} *villagers_t;

void panoramix(conf_t *conf);
villager_t create_villager(int id);
void *villager_loop(void *villager);
void logger(char *format, ...);
