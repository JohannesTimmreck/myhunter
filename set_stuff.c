/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** file with set functions
*/

#include "header_file.h"

void set_text(sfText *text, sfFont *font, char *str, int char_size)
{
    sfText_setCharacterSize (text, char_size);
    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfText_setColor(text, sfBlack);
}

sfVector2f set_vector(sfVector2f vector, float nb1, float nb2)
{
    vector.x = nb1;
    vector.y = nb2;
    return (vector);
}

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    char *name = "DUCK HUNTING SIMULATOR";

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;

    window = sfRenderWindow_create(video_mode, name, sfDefaultStyle, NULL);
    return (window);
}

sfIntRect set_rect(sfIntRect rect)
{
    rect.top = 0;
    rect.left = 0;
    rect.width = 110;
    rect.height = 110;
    return (rect);
}

void set_frame(sfRenderWindow *window, duck_t *duck1, background_t *background)
{
    sfSprite_setTextureRect(duck1->sprite, duck1->rect);
    sfRenderWindow_drawSprite(window, background->sprite, NULL);
    sfRenderWindow_drawText(window, background->score->text, NULL);
    sfRenderWindow_drawText(window, background->time, NULL);
    sfRenderWindow_drawText(window, background->show_time, NULL);
    print_lives(window, background->lives);
    sfRenderWindow_drawSprite(window, duck1->sprite, NULL);
    sfRenderWindow_display(window);
}
