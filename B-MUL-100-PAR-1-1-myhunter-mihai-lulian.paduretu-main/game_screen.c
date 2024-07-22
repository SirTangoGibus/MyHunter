/*
** EPITECH PROJECT, 2023
** game_screen.c
** File description:
** none
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include "my_headerfiles.h"

void update_game(GameData* data)
{
    animate_duck(data);
    move_reset_duck(data);
}

void render_game(GameData* data)
{
    sfRenderWindow_clear(data->gameWindow, sfBlack);
    sfRenderWindow_drawSprite(data->gameWindow, data->gameSprite, NULL);
    if (data->duckClicked == 0) {
        sfRenderWindow_drawSprite(data->gameWindow, data->duckSprite, NULL);
    }
    sfRenderWindow_display(data->gameWindow);
}

void draw_game(GameData* data)
{
    while (sfRenderWindow_isOpen(data->gameWindow)) {
        handle_eventsgame(data);
        update_game(data);
        render_game(data);
    }
}

void cleanup_game_data(GameData* data)
{
    sfSprite_destroy(data->gameSprite);
    sfTexture_destroy(sfSprite_getTexture(data->gameSprite));
    sfSprite_destroy(data->duckSprite);
    sfTexture_destroy(sfSprite_getTexture(data->duckSprite));
    sfClock_destroy(data->animationClock);
    sfClock_destroy(data->clickClock);
    sfRenderWindow_destroy(data->gameWindow);
}

void display_game_screen(void)
{
    GameData gameData;
    sfMusic* backgroundMusic = NULL;

    gameData.gameWindow = initialize_window();
    gameData.gameSprite = setup_background();
    gameData.duckSprite = setup_duck();
    gameData.duckPosition =
    (sfVector2f){0, sfRenderWindow_getSize(gameData.gameWindow).y / 2};
    gameData.offScreen = (sfVector2f){-100, -100};
    gameData.animationClock = sfClock_create();
    gameData.clickClock = sfClock_create();
    gameData.currentFrame = 0;
    gameData.duckRect = (sfIntRect){0, 0, FRAME_WIDTH,
    sfTexture_getSize(sfSprite_getTexture(gameData.duckSprite)).y};
    gameData.duckClicked = 0;
    play_background_music(&backgroundMusic);
    draw_game(&gameData);
    sfMusic_destroy(backgroundMusic);
    cleanup_game_data(&gameData);
}
