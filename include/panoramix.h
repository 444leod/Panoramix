/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** panoramix
*/

#pragma once

typedef struct conf_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
} conf_t;

void panoramix(conf_t *conf);
