/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** function that displays a number given as a parameter
*/

#include "my_headerfiles.h"

int my_nbr(int nb)
{
    int nbr = nb % 10;

    nb = nb / 10;
    if (nb != 0) {
        my_nbr(nb);
    }
    my_putchar(nbr + 48);
}

int my_put_nbr(int nb)

{
    if (nb < 0){
    my_putchar('-');
    nb = -1 * nb;
    my_nbr(nb);
    } else {
    my_nbr(nb);
    }
    return 0;
}
