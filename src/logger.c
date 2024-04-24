/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** logger
*/

#include <stdio.h>
#include <stdarg.h>
#include <pthread.h>

void logger(char *format, ...)
{
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    va_list args;

    pthread_mutex_lock(&mutex);
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    pthread_mutex_unlock(&mutex);
}
