/*
** EPITECH PROJECT, 2023
** headerfiles.h
** File description:
** Header files in one place
*/

#ifndef HEADERFILES_H
    #define HEADERFILES_H
    #define WINDOW_WIDTH 1280
    #define WINDOW_HEIGHT 720
    #define DUCK_FRAMES 2
    #define FRAME_WIDTH 110
    #define ANIMATION_SPEED 0.08f
    #include <stdarg.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
typedef enum GameState {
    TITLE_SCREEN,
    GAME_SCREEN,
} GameState;
typedef struct {
    sfRenderWindow* window;
    sfTexture* bgTexture;
    sfSprite* background;
    sfFont* font;
    sfText* startText;
    sfText* endText;
    GameState currentGameState;
} TitleScreenData;
typedef struct {
    sfRenderWindow* gameWindow;
    sfSprite* gameSprite;
    sfSprite* duckSprite;
    sfClock* animationClock;
    sfClock* clickClock;
    int duckClicked;
    int currentFrame;
    sfIntRect duckRect;
    sfVector2f duckPosition;
    sfVector2f offScreen;
} GameData;
typedef struct {
    sfRenderWindow* gameWindow;
    sfSprite* duckSprite;
    sfClock* animationClock;
    sfClock* clickClock;
    int duckClicked;
    int currentFrame;
    sfIntRect duckRect;
    sfVector2f duckPosition;
    sfVector2f offScreen;
} DuckData;
void display_titlescreen(void);
void display_game_screen(void);
void handle_start_game(TitleScreenData* titlescreenData);
void handle_end_game(sfRenderWindow* window);
void handle_events(TitleScreenData* titlescreenData);
void handle_end_game_click(TitleScreenData* titleScreenData,
    sfRenderWindow* window, sfVector2i mousePos);
void handle_start_game_click(TitleScreenData* titleScreenData,
    sfVector2i mousePos);
sfText* create_text(const char *string, sfFont *font,
    unsigned int characterSize, sfVector2f position);
void init_resources(TitleScreenData* titleScreenData);
void clear_resources(TitleScreenData* titleScreenData);
void h_option(void);
int mini_printf(const char *format, ...);
int switch_function(va_list ap, char *format);
int my_put_nbr(int nb);
int my_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
int main(int argc, char *argv[]);
sfRenderWindow* initialize_window(void);
sfSprite* setup_background(void);
sfSprite* setup_duck(void);
void animate_duck(GameData* duckData);
void move_reset_duck(GameData* duckData);
void handle_duckclick(GameData* duckData);
void handle_duck_disappearance(DuckData* duckData);
void draw_game(GameData* data);
void display_game_screen(void);
void render_game(GameData* data);
void display_game_screen(void);
void update_game(GameData* data);
void handle_eventsgame(GameData* data);
void cleanup_game_data(GameData* data);
void play_background_music(sfMusic **music);
void play_duck_sound(void);
#endif
