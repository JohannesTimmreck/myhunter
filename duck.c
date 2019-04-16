/*
** EPITECH PROJECT, 2018
** my hunter
** File description:
** duck functions
*/

#include "header_file.h"

void handle_newduck(duck_t *duck, background_t *background)
{
    sfTime time = sfClock_getElapsedTime(background->res_clock);
    int sec = time.microseconds / 1000000.0;

    if (duck->pos.x >= 1920) {
        background->lives->amount--;
    }
    if (background->lives->amount == 0) {
        background->title->num = 2;
    }
    new_duck(duck, 0);
}

sfIntRect move_rect(sfIntRect rect, int *offset, int max_value)
{
    rect.left = rect.left + *offset;
    if (rect.left >= max_value || rect.left < 0) {
        rect.left = 0;
    }
    return (rect);
}

void new_duck(duck_t *duck, int switch1)
{
    sfVector2f duck_pos = set_vector(duck_pos, 0, (rand() % 720));
    sfVector2f duck_speed = set_vector(duck_speed, ((rand() % 10) + 1), 0);

    if (switch1 == 1) {
        duck->texture = sfTexture_createFromFile("spritesheed.png", NULL);
    } else {
        sfSprite_destroy(duck->sprite);
    }
    duck->change_rect = 0;
    duck->sprite = sfSprite_create();
    sfSprite_setPosition(duck->sprite, duck_pos);
    duck->rect = set_rect(duck->rect);
    duck->pos = set_vector(duck->pos, duck_pos.x, duck_pos.y);
    duck->speed = set_vector(duck->speed, duck_speed.x, duck_speed.y);
    sfSprite_setTexture(duck->sprite, duck->texture, 1);
}

void move_duck(duck_t *duck, sfClock *clock)
{
    int offset = 110;
    sfTime time = sfClock_getElapsedTime(clock);
    float sec = time.microseconds / 1000000.0;

    if (sec > 0.01)
        sfSprite_move(duck->sprite, duck->speed);
    if (sec > 0.25 && duck->change_rect == 0) {
        duck->rect = move_rect(duck->rect, &offset, 330);
        sfClock_restart(clock);
    }
}
