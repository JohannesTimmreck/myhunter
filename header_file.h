/*
** EPITECH PROJECT, 2018
** my hunter
** File description:
** header file
*/

#ifndef header
#define header

#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "lib/my_printf/headerfile_printf.h"

struct end_screen_s
{
    sfTexture *menu_button;
    sfSprite *sprite;
    sfText *game_over;
    sfText *scorel1;
    sfText *timel1;
    sfText *timel2;
    sfText *restart;
    sfText *exit;
    sfFont *font;
};
typedef struct end_screen_s end_screen_t;

struct title_screen_s
{
    int num;
    sfTexture *menu_button;
    sfSprite *sprite;
    sfText *title;
    sfText *start;
    sfText *end;
    sfFont *font;
};
typedef struct title_screen_s title_screen_t;

struct lives_s
{
    int amount;
    sfTexture *heart;
    sfSprite *sprite;
    sfVector2f pos;
};
typedef struct lives_s lives_t;

struct duck_s
{
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f speed;
    int change_rect;
};
typedef struct duck_s duck_t;

struct score_s
{
    sfText *text;
    sfFont *font;
    char *score;
    int num;
    int win;
};
typedef struct score_s score_t;

struct background_s
{
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    score_t *score;
    lives_t *lives;
    sfClock *res_clock;
    title_screen_t *title;
    sfText *time;
    sfText *show_time;
    char *end_time;
};
typedef struct background_s background_t;

char *int_to_str(int nb, char *str);

void set_background(background_t *background);

char *str_from_clock(sfClock *clock);
void load_end_screen(background_t *background, sfEvent *event);

void destroy_end_screen(end_screen_t *end);
void set_text_pos(end_screen_t *end);
void set_endscreen(end_screen_t *end, background_t *background);

void set_title(title_screen_t *title);
void load_title_screen(background_t *background, sfEvent *event,
                        title_screen_t *title);

void set_text(sfText *text, sfFont *font, char *str, int char_size);
sfVector2f set_vector(sfVector2f vector, float nb1, float nb2);
sfRenderWindow *create_window(unsigned int width, unsigned int height);
sfIntRect set_rect(sfIntRect rect);
void set_frame(sfRenderWindow *window, duck_t *duck1,
                background_t *background);

void destroy_titlescreen(title_screen_t *start_screen);
void destroy_lives(lives_t *lives);
void destroy_duck(duck_t *duck);
void destroy_background(background_t *background, sfEvent *event,
                        sfClock *clock);
void destroy_score(score_t *score);

void handle_newduck(duck_t *duck, background_t *background);
void move_duck(duck_t *duck, sfClock *clock);
void new_duck(duck_t *duck, int switch1);
sfIntRect move_rect(sfIntRect rect, int *offset, int max_value);

void fill_score(char *str);
void add_score(char *str);
void print_lives(sfRenderWindow *window, lives_t *lives);
void set_lives(lives_t *lives);
void set_score(score_t *score, unsigned int num);


void manage_preloop(duck_t *duck1, background_t *background);
void manage_mouse_click(sfMouseButtonEvent event, duck_t *duck, score_t *score);
void analize_events(sfEvent *event, duck_t *duck1, background_t *background);

void manage_mouse_click(sfMouseButtonEvent event, duck_t *duck, score_t *score);
void analize_events(sfEvent *event, duck_t *duck1, background_t *background);
void manage_endscreen_click(sfMouseButtonEvent event, background_t *background,
                            end_screen_t *end);
void manage_restart(background_t *background);

#endif
