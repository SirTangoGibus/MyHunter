/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** none
*/

#include "my_headerfiles.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
    i = i + 1;
            }
    return i;
}
