/*
** EPITECH PROJECT, 2023
** my_huntertitle.c
** File description:
** Title screen to the game
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include "my_headerfiles.h"

sfText* create_text(const char *string, sfFont *font,
    unsigned int characterSize, sfVector2f position)
{
    sfText* text = sfText_create();

    sfText_setString(text, string);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, characterSize);
    sfText_setPosition(text, position);
    sfText_setFillColor(text, sfWhite);
    return text;
}

void init_resources(TitleScreenData* titleScreenData)
{
    titleScreenData->window =
    sfRenderWindow_create((sfVideoMode){1280, 720, 32},
    "Title Screen", sfDefaultStyle, NULL);
    titleScreenData->bgTexture =
    sfTexture_createFromFile("Duck-Hunt-Title.jpg", NULL);
    titleScreenData->background = sfSprite_create();
    sfSprite_setTexture(titleScreenData
    ->background, titleScreenData->bgTexture, sfTrue);
    titleScreenData->font = sfFont_createFromFile("slkscr.ttf");
    titleScreenData->startText = create_text("Start Game",
    titleScreenData->font, 40, (sfVector2f){500, 500});
    titleScreenData->endText = create_text("End Game",
    titleScreenData->font, 40, (sfVector2f){500, 600});
    titleScreenData->currentGameState = TITLE_SCREEN;
}

void clear_resources(TitleScreenData* titleScreenData)
{
    sfText_destroy(titleScreenData->startText);
    sfText_destroy(titleScreenData->endText);
    sfFont_destroy(titleScreenData->font);
    sfSprite_destroy(titleScreenData->background);
    sfTexture_destroy(titleScreenData->bgTexture);
    sfRenderWindow_destroy(titleScreenData->window);
}

void display_titlescreen(void)
{
    TitleScreenData titleScreenData;

    init_resources(&titleScreenData);
    while (sfRenderWindow_isOpen(titleScreenData.window)) {
        handle_events(&titleScreenData);
        sfRenderWindow_clear(titleScreenData.window, sfBlack);
        sfRenderWindow_drawSprite(titleScreenData.window,
        titleScreenData.background, NULL);
        sfRenderWindow_drawText(titleScreenData.window,
        titleScreenData.startText, NULL);
        sfRenderWindow_drawText(titleScreenData.window,
        titleScreenData.endText, NULL);
        sfRenderWindow_display(titleScreenData.window);
        if (titleScreenData.currentGameState == GAME_SCREEN) {
            sfRenderWindow_close(titleScreenData.window);
        display_game_screen();
            break;
        }
    }
    clear_resources(&titleScreenData);
}
