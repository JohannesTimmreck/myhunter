/*
** EPITECH PROJECT, 2018
** main
** File description:
** my_hunter_main
*/

#include "header_file.h"

void manage_preloop(duck_t *duck1, background_t *background)
{
    sfVector2f pos1 = set_vector(pos1, 1600, 800);
    sfVector2f pos2 = set_vector(pos2, 1750, 800);

    set_background(background);
    background->title = malloc(sizeof(title_screen_t));
    set_title(background->title);
    set_score(background->score, 0);
    sfText_setFont(background->time, background->score->font);
    sfText_setPosition(background->time, pos1);
    sfText_setString(background->time, "Seconds:");
    sfText_setFont(background->show_time, background->score->font);
    sfText_setPosition(background->show_time, pos2);
    new_duck(duck1, 1);
    background->lives = malloc(sizeof(lives_t));
    set_lives(background->lives);
    background->res_clock = sfClock_create();
    sfSprite_setTexture(background->sprite, background->texture, 1);
    sfRenderWindow_setFramerateLimit(background->window, 60);
}

void handle_help(void)
{
    my_printf("\nUSAGE:\t./my_hunter\n\n");
    my_printf("HOW TO PLAY\n\n");
    my_printf("1.\tpress \"START\" to start a game or \"EXIT\" to quit ");
    my_printf("and close the game\n");
    my_printf("2.\tpress the left mouse button to shoot the ducks\n");
    my_printf("3.\tget a score of at least 20 to win\n");
    my_printf("4.\tthe game will continue until you lose all your lifes\n\n");
}

void game_loop(background_t *background, duck_t *duck1, sfEvent *event,
                sfClock *clock)
{
    background->end_time = str_from_clock(background->res_clock);
    sfText_setString(background->show_time, background->end_time);
    set_frame(background->window, duck1, background);
    duck1->pos = sfSprite_getPosition(duck1->sprite);
    if (duck1->pos.x >= 1920 || duck1->pos.y >= 720) {
        handle_newduck(duck1, background);
    }
    move_duck(duck1, clock);
    if (sfRenderWindow_pollEvent(background->window, event) == sfTrue)
        analize_events(event, duck1, background);
}

void main_loop(background_t *background, duck_t *duck1, sfEvent *event,
                sfClock *clock)
{
    manage_preloop(duck1, background);
    while (sfRenderWindow_isOpen(background->window)) {
        if (background->title->num == 0) {
            load_title_screen(background, event, background->title);
            sfClock_restart(background->res_clock);
        } else if (background->title->num == 1) {
            game_loop(background, duck1, event, clock);
            ;
        } else if (background->title->num == 2) {
            load_end_screen(background, event);
        }
    }
    destroy_titlescreen(background->title);
    destroy_lives(background->lives);
}

int main(int ac, char **av)
{
    background_t *background = malloc(sizeof(background_t));
    duck_t *duck1 = malloc(sizeof(duck_t));
    sfEvent *event = malloc(sizeof(sfEvent));
    sfClock *clock = sfClock_create();

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        handle_help();
        return (0);
    }
    main_loop(background, duck1, event, clock);
    destroy_duck(duck1);
    destroy_background(background, event, clock);
}
