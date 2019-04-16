/*
** EPITECH PROJECT, 2018
** my hunter
** File description:
** destroy functions
*/

#include "header_file.h"

void destroy_titlescreen(title_screen_t *start_screen)
{
    sfTexture_destroy(start_screen->menu_button);
    sfSprite_destroy(start_screen->sprite);
    sfFont_destroy(start_screen->font);
    sfText_destroy(start_screen->title);
    sfText_destroy(start_screen->start);
    sfText_destroy(start_screen->end);
    free(start_screen);
}

void destroy_lives(lives_t *lives)
{
    sfTexture_destroy(lives->heart);
    sfSprite_destroy(lives->sprite);
    free(lives);
}

void destroy_duck(duck_t *duck)
{
    sfTexture_destroy(duck->texture);
    sfSprite_destroy(duck->sprite);
    free(duck);
}

void destroy_score(score_t *score)
{
    sfText_destroy(score->text);
    sfFont_destroy(score->font);
    free(score->score);
    free(score);
}

void destroy_background(background_t *background, sfEvent *event,
                        sfClock *clock)
{
    sfSprite_destroy(background->sprite);
    sfTexture_destroy(background->texture);
    sfClock_destroy(clock);
    sfClock_destroy(background->res_clock);
    destroy_score(background->score);
    sfText_destroy(background->time);
    sfText_destroy(background->show_time);
    sfRenderWindow_destroy(background->window);
    free(event);
    free(background);
}
