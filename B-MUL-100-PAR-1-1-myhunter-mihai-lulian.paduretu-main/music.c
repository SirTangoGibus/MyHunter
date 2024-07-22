/*
** EPITECH PROJECT, 2023
** music.c
** File description:
** none
*/

#include <SFML/Audio.h>
#include "my_headerfiles.h"

void play_background_music(sfMusic **music)
{
    *music = sfMusic_createFromFile("bgm.wav");
    sfMusic_setLoop(*music, sfTrue);
    sfMusic_play(*music);
}

void play_duck_sound(void)
{
    sfSoundBuffer* soundBuffer =
    sfSoundBuffer_createFromFile("duckshot.wav");
    sfSound* sound = sfSound_create();

    sfSound_setBuffer(sound, soundBuffer);
    sfSound_play(sound);
}
