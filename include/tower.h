/*
** EPITECH PROJECT, 2021
** include for tower
** File description:
** for my_defender
*/


#ifndef _MY_TOWERS_
#define _MY_TOWERS_
//------NEEDED-INCLUDES-----

#include "defender.h"

//-----MACROS---------------

//-----STRUCTURES-----------
typedef struct defender_s defender_t;
typedef struct game_s game_t;
typedef struct tower_s tower_t;
typedef struct enemy_s enemy_t;
//-----PROTOTYPES-----------
//tower_creation.c
int tower_create(defender_t *defender, tower_t **tower, int type, \
sfVector2f pos);

//tower_types.c
void tower_type_base(tower_t *new_tower);
void tower_type_one(tower_t *new_tower);
void tower_type_two(tower_t *new_tower);
void tower_type_three(tower_t *new_tower);
void tower_type_four(tower_t *new_tower);

//tower_type_two
void tower_type_base_two(tower_t *new_tower);
void tower_type_one_two(tower_t *new_tower);
void tower_type_two_two(tower_t *new_tower);
void tower_type_three_two(tower_t *new_tower);
void tower_type_four_two(tower_t *new_tower);

//tower_destrcution.c
void destroy_only_one_tower(game_t *game, tower_t *tower);
void destroy_all_towers(tower_t **tower);

//tower_managment.c
void tower_managment(defender_t *defender, tower_t *tower, enemy_t *enemy);

//tower_display.c
void tower_display(sfRenderWindow *window, defender_t *defender, \
tower_t *tower);

//tower_button_functions.c
void add_tower_one(defender_t *defender);
void add_tower_two(defender_t *defender);
void add_tower_three(defender_t *defender);
void add_tower_four(defender_t *defender);

//temp_display.c
void temp_display(sfRenderWindow *window, game_t *game);

#endif
