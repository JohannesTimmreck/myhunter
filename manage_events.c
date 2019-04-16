/*
** EPITECH PROJECT, 2018
** my hunter
** File description:
** handle events
*/

#include "header_file.h"

void manage_mouse_click(sfMouseButtonEvent event, duck_t *duck, score_t *score)
{
    if (((event.x >= duck->pos.x  - 30) && event.x <= duck->pos.x + 110) &&
        (event.y >= duck->pos.y && event.y <= duck->pos.y + 110)) {
        duck->speed.y = duck->speed.y + 10;
        duck->speed.x = 0;
        duck->change_rect = 1;
        set_score(score, 1);
        }
}

void analize_events(sfEvent *event, duck_t *duck1, background_t *background)
{
    if (event->type  == sfEvtMouseButtonPressed) {
        manage_mouse_click(event->mouseButton, duck1, background->score);
        if (background->score->num >= 20) {
            background->score->win = 1;
        }
    }
    if (event->type  == sfEvtClosed)
        sfRenderWindow_close(background->window);
}

void manage_restart(background_t *background)
{
    sfClock_restart(background->res_clock);
    background->lives->amount = 3;
    background->score->win = 0;
    background->score->num = 0;
    fill_score(background->score->score);
    sfText_setString(background->score->text, background->score->score);
}

void manage_endscreen_click(sfMouseButtonEvent event, background_t *background,
                            end_screen_t *end)
{
    if ((event.x >= 700 && event.x < 1200 &&
            (event.y >=  500) && event.y <= 670)) {
        background->title->num = 1;
        manage_restart(background);
    } else if ((event.x >= 700 && event.x < 1200 &&
                (event.y >= 700) && event.y <= 900)) {
        sfRenderWindow_close(background->window);
        set_endscreen(end, background);
    }
}
