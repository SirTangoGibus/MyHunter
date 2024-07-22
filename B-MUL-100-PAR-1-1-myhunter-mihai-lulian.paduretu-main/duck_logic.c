/*
** EPITECH PROJECT, 2023
** duck_logic.c
** File description:
** none
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include "my_headerfiles.h"

sfSprite* setup_duck(void)
{
    sfTexture* duckTexture = sfTexture_createFromFile("spritesheet.png", NULL);
    sfSprite* duckSprite = sfSprite_create();

    sfSprite_setTexture(duckSprite, duckTexture, sfTrue);
    return duckSprite;
}

void animate_duck(GameData* data)
{
    sfTime deltaTime = sfClock_getElapsedTime(data->animationClock);

    if (sfTime_asSeconds(deltaTime) > ANIMATION_SPEED) {
        sfClock_restart(data->animationClock);
        data->duckRect.left = (data->currentFrame) * FRAME_WIDTH;
        sfSprite_setTextureRect(data->duckSprite, data->duckRect);
        data->currentFrame = (data->currentFrame + 1) % DUCK_FRAMES;
    }
}

void move_reset_duck(GameData* data)
{
    sfTime elapsedTime = sfClock_getElapsedTime(data->clickClock);

    if (data->duckClicked == 0) {
        data->duckPosition.x += 0.1f;
        if (data->duckPosition.x >
        sfRenderWindow_getSize(data->gameWindow).x) {
            data->duckPosition.x =
        -sfSprite_getGlobalBounds(data->duckSprite).width;
            data->duckPosition.y =
        rand() % sfRenderWindow_getSize(data->gameWindow).y;
        }
    } else {
        if (sfTime_asMilliseconds(elapsedTime) > 1000) {
            sfSprite_setPosition(data->duckSprite, data->offScreen);
            data->duckClicked = 0;
        }
    }
    sfSprite_setPosition(data->duckSprite, data->duckPosition);
}

void handle_duckclick(GameData* data)
{
    sfVector2i mousePos =
    sfMouse_getPositionRenderWindow(data->gameWindow);
    sfFloatRect duckBounds =
    sfSprite_getGlobalBounds(data->duckSprite);

    if (sfFloatRect_contains(&duckBounds, mousePos.x, mousePos.y)) {
        data->duckClicked = 1;
        sfClock_restart(data->clickClock);
        data->duckPosition.x =
        sfRenderWindow_getSize(data->gameWindow).x + 100;
        data->duckPosition.y =
        rand() % sfRenderWindow_getSize(data->gameWindow).y;
        play_duck_sound();
    }
}

void handle_duck_disappearance(DuckData* duckData)
{
    sfTime delay = sfMilliseconds(1000);
    sfTime elapsedTime = sfClock_getElapsedTime(duckData->clickClock);

    if (sfTime_asMilliseconds(elapsedTime) > sfTime_asMilliseconds(delay)) {
        sfSprite_setPosition(duckData->duckSprite, duckData->offScreen);
        duckData->duckClicked = 0;
    }
}
