/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** enemies.h
*/

#ifndef _MY_ENEMIES_
#define _MY_ENEMIES_
//------NEEDED-INCLUDES-----

#include "defender.h"

//-----MACROS---------------

//-----STRUCTURES-----------
typedef struct round_s round_t;
typedef struct defender_s defender_t;
typedef struct game_s game_t;
typedef struct tower_s tower_t;
typedef struct enemy_s enemy_t;
//-----PROTOTYPES-----------

//enemies_creation.c
int add_enemy(enemy_t **enemy, int type, sfVector2f pos);

//enemies_management.c
void draw_enemies(sfRenderWindow *window, defender_t *defender, enemy_t *enemy);
void destroy_all_enemies(enemy_t **enemy);
void destroy_only_one_enemy(game_t *game, enemy_t *enemy);

//enemies_spawning.c
void init_round(round_t *round);
void enemy_spawn_manager(defender_t *defender);
void spawn_enemy(game_t *game, sfVector2f limite_one, sfVector2f limite_two);

//enemies_spawning_two.c
void spawn_round_two(defender_t *defender, int random);

//enemies_moves.c
void move_ennemies(defender_t *defender, enemy_t *enemy);

//enemies_spawning.c
void init_round(round_t *round);
void enemy_spawn_manager(defender_t *defender);
void spawn_round_two(defender_t *defender, int random);
void spawn_enemy(game_t *game, sfVector2f limite_one, sfVector2f limite_two);

//enemies_tool_function.c
void set_goot_rotation(enemy_t *enemy, tower_t *tower);
void get_new_time(defender_t *defender, enemy_t *enemy, float x, float y);

#endif
