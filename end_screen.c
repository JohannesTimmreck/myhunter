/*
** EPITECH PROJECT, 2018
** hunter
** File description:
** end screen
*/

#include "header_file.h"

int num_length(int num)
{
    int len = 1;

    for (;num > 0; num = num / 10)
        len++;
    return (len);
}

char *str_from_clock(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    int sec = time.microseconds / 1000000.0;
    int len = num_length(sec);
    char *str = malloc(sizeof(char *) * (len + 1));

    str = int_to_str(sec, str);
    str[len+1] = '\0';
    return (str);
}

void manage_endscreen(background_t *background, end_screen_t *end)
{
    if (background->score->win == 1) {
        sfText_setString(end->game_over, "YOU WON");
    } else if (background->score->win == 0) {
        sfText_setString(end->game_over, "YOU LOST");
    }
    sfRenderWindow_drawText(background->window, end->game_over, NULL);
    sfRenderWindow_drawText(background->window, end->scorel1, NULL);
    sfRenderWindow_drawText(background->window, end->timel1, NULL);
    sfRenderWindow_drawText(background->window, end->timel2, NULL);
    sfRenderWindow_drawText(background->window, end->restart, NULL);
    sfRenderWindow_drawText(background->window, end->exit, NULL);
}

void load_end_screen(background_t *background, sfEvent *event)
{
    end_screen_t *end = malloc(sizeof(end_screen_t));
    sfVector2f vector = set_vector(vector, (1920/2 - 250), 500);

    set_endscreen(end, background);
    sfRenderWindow_drawSprite(background->window, background->sprite, NULL);
    for (int i = 0; i < 2; i++) {
        vector.y = vector.y + i * 200;
        sfSprite_setPosition(end->sprite, vector);
        sfRenderWindow_drawSprite(background->window, end->sprite, NULL);
        }
    manage_endscreen(background, end);
    sfRenderWindow_display(background->window);
    if (sfRenderWindow_pollEvent(background->window, event) == sfTrue) {
        if (event->type  == sfEvtMouseButtonPressed)
            manage_endscreen_click(event->mouseButton, background, end);
        if (event->type  == sfEvtClosed) {
            sfRenderWindow_close(background->window);
            set_endscreen(end, background);
        }
    }
}

