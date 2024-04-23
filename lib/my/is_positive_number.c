/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** is_positive_number
*/

#include <stdbool.h>
#include <stddef.h>

bool is_positive_number(char *str)
{
    if (str == NULL)
        return false;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}
