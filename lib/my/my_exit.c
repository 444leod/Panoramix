/*
** EPITECH PROJECT, 2024
** Panoramix-Bootstrap
** File description:
** my_exit
*/

#include <stdlib.h>
#include "debug.h"
#include "garbage_collector.h"

void my_exit(int status)
{
    my_free_all();
    exit(status);
}
