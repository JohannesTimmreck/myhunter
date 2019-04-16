/*
** EPITECH PROJECT, 2018
** my hunter
** File description:
** set/destroy end screen
*/

#include "header_file.h"

void destroy_end_screen(end_screen_t *end)
{
    sfTexture_destroy(end->menu_button);
    sfSprite_destroy(end->sprite);
    sfFont_destroy(end->font);
    sfText_destroy(end->game_over);
    sfText_destroy(end->scorel1);
    sfText_destroy(end->timel1);
    sfText_destroy(end->timel2);
    sfText_destroy(end->restart);
    sfText_destroy(end->exit);
    free(end);
}

void set_text_pos(end_screen_t *end)
{
    sfVector2f vector1 = set_vector(vector1, 750, 40);
    sfVector2f vector2 = set_vector(vector2, 600, 150);
    sfVector2f vector3 = set_vector(vector3, 600, 260);
    sfVector2f vector4 = set_vector(vector3, 1400, 260);
    sfVector2f vector5 = set_vector(vector3, (1920/2 - 200), 510);
    sfVector2f vector6 = set_vector(vector3, (1920/2 - 160), 710);

    sfText_setPosition(end->game_over, vector1);
    sfText_setPosition(end->scorel1, vector2);
    sfText_setPosition(end->timel1, vector3);
    sfText_setPosition(end->timel2, vector4);
    sfText_setPosition(end->restart, vector5);
    sfText_setPosition(end->exit, vector6);
}

void set_endscreen(end_screen_t *end, background_t *background)
{
        end->menu_button = sfTexture_createFromFile("menu_button.png", NULL);
        end->sprite = sfSprite_create();
        end->font = sfFont_createFromFile("my_font.ttf");
        sfSprite_setTexture(end->sprite, end->menu_button, 1);
        end->game_over = sfText_create();
        set_text(end->game_over, end->font, "PLACEHOLDER", 100);
        end->scorel1 = sfText_create();
        set_text(end->scorel1, end->font, background->score->score, 80);
        end->timel1 = sfText_create();
        set_text(end->timel1, end->font, "SURVIVED SECONDS:", 80);
        end->timel2 = sfText_create();
        set_text(end->timel2, end->font, background->end_time, 80);
        end->restart = sfText_create();
        set_text(end->restart, end->font, "START", 140);
        end->exit = sfText_create();
        set_text(end->exit, end->font, "EXIT", 140);
        set_text_pos(end);
}
