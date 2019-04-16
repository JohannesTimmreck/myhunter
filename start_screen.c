/*
** EPITECH PROJECT, 2018
** my hunter
** File description:
** title screen
*/

#include "header_file.h"

void draw_texts(sfRenderWindow *window, title_screen_t *title)
{
    sfVector2f vector1 = set_vector(vector1, 25, 200);
    sfVector2f vector2 = set_vector(vector2, (1920/2 - 200), 510);
    sfVector2f vector3 = set_vector(vector3, (1920/2 - 160), 710);

    sfText_setPosition(title->title, vector1);
    sfText_setPosition(title->start, vector2);
    sfText_setPosition(title->end, vector3);
    sfRenderWindow_drawText(window, title->title, NULL);
    sfRenderWindow_drawText(window, title->start, NULL);
    sfRenderWindow_drawText(window, title->end, NULL);
}

void set_title(title_screen_t *title)
{
    title->num = 0;
    title->menu_button = sfTexture_createFromFile("menu_button.png", NULL);
    title->sprite = sfSprite_create();
    sfSprite_setTexture(title->sprite, title->menu_button, 1);
    title->font = sfFont_createFromFile("my_font.ttf");
    title->title = sfText_create();
    set_text(title->title, title->font, "DUCK HUNTING SIMULATOR", 145);
    title->start = sfText_create();
    set_text(title->start, title->font, "START", 140);
    title->end = sfText_create();
    set_text(title->end, title->font, "EXIT", 140);
}

void manage_titlescreen(sfMouseButtonEvent event, title_screen_t *title,
                        sfRenderWindow *window)
{
    if ((event.x >= 700 && event.x < 1200 &&
        (event.y >=  500) && event.y <= 670)) {
        title->num = 1;
    } else if ((event.x >= 700 && event.x < 1200 &&
                (event.y >= 700) && event.y <= 900)) {
        sfRenderWindow_close(window);
    }
}

void load_title_screen(background_t *background, sfEvent *event,
                        title_screen_t *title)
{
    sfVector2f vector = set_vector(vector, (1920/2 - 250), 500);

    sfRenderWindow_drawSprite(background->window, background->sprite, NULL);
    for (int i = 0; i < 2; i++) {
        vector.y = vector.y + i * 200;
        sfSprite_setPosition(title->sprite, vector);
        sfRenderWindow_drawSprite(background->window, title->sprite, NULL);
    }
    draw_texts(background->window, title);
    sfRenderWindow_display(background->window);
    if (sfRenderWindow_pollEvent(background->window, event) == sfTrue) {
        if (event->type  == sfEvtMouseButtonPressed)
            manage_titlescreen(event->mouseButton, title, background->window);
        if (event->type  == sfEvtClosed) {
            sfRenderWindow_close(background->window);
        }
    }
}
