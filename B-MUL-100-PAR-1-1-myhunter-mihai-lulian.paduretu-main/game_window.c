/*
** EPITECH PROJECT, 2023
** game_window.c
** File description:
** none
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include "my_headerfiles.h"

sfRenderWindow* initialize_window(void)
{
    sfVideoMode mode = {1280, 720, 32};

    return sfRenderWindow_create(mode, "Game Window", sfClose, NULL);
}

sfSprite* setup_background(void)
{
    sfTexture* gameTexture =
    sfTexture_createFromFile("hills-game-background-vector.jpg", NULL);
    sfSprite* gameSprite = sfSprite_create();

    sfSprite_setTexture(gameSprite, gameTexture, sfTrue);
    return gameSprite;
}

void handle_eventsgame(GameData* data)
{
    sfEvent event;

    if (!sfRenderWindow_pollEvent(data->gameWindow, &event)) {
    return;
    }
    switch (event.type) {
    case sfEvtClosed:
    sfRenderWindow_close(data->gameWindow);
    break;
    case sfEvtMouseButtonPressed:
    if (data->duckClicked == 0) {
    handle_duckclick(data);
    }
    break;
    default:
    break;
    }
}
