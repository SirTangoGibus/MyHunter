/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** none
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include "my_headerfiles.h"

int main(int argc, char *argv[])
{
    if (argc > 1) {
        if (argv[1][0] == '-' && argv[1][1] == 'h'
    && argv[1][2] == '\0') {
            h_option();
            return 0;
        } else {
            mini_printf("Unknown input. Please use '-h' for help.\n");
            return 1;
        }
    }
    display_titlescreen();
    return 0;
}
