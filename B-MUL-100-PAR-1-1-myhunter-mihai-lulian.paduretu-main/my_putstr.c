/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** none
*/

#include "my_headerfiles.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
    my_putchar(str[i]);
    i = i + 1;
    }
}
