/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** tower_upgrade.c
*/

#include "defender.h"

void upgrade_attack_of_tower(defender_t *defender, float nb)
{
    defender->game.atq_bonus += nb;
}

void upgrade_life_of_tower(defender_t *defender, int nb)
{
    tower_t *tower = defender->game.towers;

    defender->game.life_bonus += nb;
    while (tower) {
        if (tower->id_tower != 0) {
            tower->life += nb;
        }
        tower = tower->next;
    }
}
