/*
** EPITECH PROJECT, 2018
** my hunter
** File description:
** lifes and score
*/

#include "header_file.h"

void set_score(score_t *score, unsigned int num)
{
    sfVector2f pos = set_vector(pos, 1600, 850);
    int len = 10;

    score->text = sfText_create();
    if (num == 0) {
        score->score = malloc(sizeof(char) * len);
        fill_score(score->score);
        score->font = sfFont_createFromFile("my_font.ttf");
    }
    if (num == 1) {
        add_score(score->score);
    }
    sfText_setFont(score->text, score->font);
    sfText_setPosition(score->text, pos);
    sfText_setString(score->text, score->score);
    score->num++;
    score->win = 0;
}

void set_lives(lives_t *lives)
{
    lives->amount = 3;
    lives->heart = sfTexture_createFromFile("life_heart.png", NULL);
    lives->sprite = sfSprite_create();
    lives->pos = set_vector(lives->pos, 1750, 875);
    sfSprite_setPosition(lives->sprite, lives->pos);
    sfSprite_setTexture(lives->sprite, lives->heart, 1);
}

void print_lives(sfRenderWindow *window, lives_t *lives)
{
    int amount = lives->amount;
    sfVector2f vect = set_vector(vect, lives->pos.x, lives->pos.y);

    while (amount > 0) {
        sfSprite_setPosition(lives->sprite, vect);
        sfRenderWindow_drawSprite(window, lives->sprite, NULL);
        vect = set_vector(vect, (vect.x - 100), vect.y);
        amount--;
    }
}

void fill_score(char *str)
{
        str[0] = 'S';
        str[1] = 'c';
        str[2] = 'o';
        str[3] = 'r';
        str[4] = 'e';
        str[5] = ':';
        str[6] = '0';
        str[7] = '0';
        str[8] = '0';
        str[9] = '\0';
}

void add_score(char *str)
{
    int a = str[6] - 48;
    int b = str[7] - 48;
    int c = str[8] - 48;

    c++;
    if (c == 10) {
        c = 0;
        b++;
    }
    if (b == 10) {
        b = 0;
        a++;
    }
    str[6] = a + 48;
    str[7] = b + 48;
    str[8] = c + 48;
}
