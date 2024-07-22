/*
** EPITECH PROJECT, 2023
** my_huntertitlestart.c
** File description:
** none
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include "my_headerfiles.h"

void handle_start_game(TitleScreenData* titleScreenData)
{
    titleScreenData->currentGameState = GAME_SCREEN;
}

void handle_end_game(sfRenderWindow* window)
{
    sfRenderWindow_close(window);
}

void handle_start_game_click(TitleScreenData* titleScreenData,
    sfVector2i mousePos)
{
    sfFloatRect startBounds =
    sfText_getGlobalBounds(titleScreenData->startText);

    if (sfFloatRect_contains(&startBounds, mousePos.x, mousePos.y)) {
        handle_start_game(titleScreenData);
    }
}

void handle_end_game_click(TitleScreenData* titleScreenData,
    sfRenderWindow* window, sfVector2i mousePos)
{
    sfFloatRect endBounds = sfText_getGlobalBounds(titleScreenData->endText);

    if (sfFloatRect_contains(&endBounds, mousePos.x, mousePos.y)) {
        handle_end_game(window);
    }
}

void handle_events(TitleScreenData* titleScreenData)
{
    sfEvent event;
    sfVector2i mousePos;

    while (sfRenderWindow_pollEvent(titleScreenData->window, &event)) {
        switch (event.type) {
            case sfEvtClosed:
                sfRenderWindow_close(titleScreenData->window);
                break;
            case sfEvtMouseButtonPressed:
                mousePos =
                sfMouse_getPositionRenderWindow(titleScreenData->window);
                handle_start_game_click(titleScreenData, mousePos);
                handle_end_game_click(titleScreenData,
                titleScreenData->window, mousePos);
                break;
            default:
                break;
        }
    }
}
