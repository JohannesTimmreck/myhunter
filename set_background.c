/*
** EPITECH PROJECT, 2018
** my hunter
** File description:
** set background
*/

#include "header_file.h"

void set_background(background_t *background)
{
    background->window = create_window(1920, 1080);
    background->texture = sfTexture_createFromFile("hunter_bg.jpg", NULL);
    background->sprite = sfSprite_create();
    background->score = malloc(sizeof(score_t));
    background->score->num = - 1;
    background->time = sfText_create();
    background->show_time = sfText_create();
}
