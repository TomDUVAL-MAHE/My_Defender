/*
** EPITECH PROJECT, 2020
** Defender
** File description:
** defender.h
*/

#ifndef _MY_DEFENDER_
#define _MY_DEFENDER_
//-----NEEDED-INCLUDE------

#include <SFML/Window.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "my.h"
#include "tower.h"
#include "enemies.h"

//-----MACRO---------------

#define TEXT_COLOR sfColor_fromRGB(227, 245, 244)
#define EXIT_ID -1
#define MAIN_MENU_ID 0
#define GAME_ID 1

//-----STRUCTURES----------
struct defender_s;

typedef struct music_s
{
    sfMusic *sound_background;
    sfMusic *sound_posing;
    sfMusic *sound_selling;
}music_t;

typedef struct my_background_s
{
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
}my_background_t;

typedef struct my_window{
    sfClock *clock;
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    my_background_t *background;
}my_window_t;

typedef struct round_s{
    int nb_round;
    int cooldown;
    int spawn_time;
}round_t;

typedef struct enemy_s
{
    int type;
    int life;
    int anim_speed;
    int anim_cooldown;
    int attack_speed;
    int attack_cooldown;
    int attack_damage;
    int malus_cooldown;
    float speed_multiplier;
    float speed_malus;
    bool malus;
    sfVector2f move;
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect anim_rect;
    sfFloatRect hitbox;
    tower_t *nearest_tower;
    struct enemy_s *next_enemy;
}enemy_t;

typedef struct tower_s
{
    int id_tower;
    int life;
    int cost;
    int animation_count;
    int attack_speed;
    int attack_cooldown;
    float range;
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect_anim;
    sfFloatRect hitbox;
    sfVector2f pos;
    sfCircleShape *area_range;
    struct enemy_s *nearest_enemy;
    struct tower_s *next;
}tower_t;

typedef struct projectile_s {
    int type;
    int damage;
    int anim_speed;
    int anim_cooldown;
    float range;
    float speed_multiplier;
    bool pierce;
    sfIntRect anim_rect;
    sfFloatRect hitbox;
    sfVector2f departure;
    sfVector2f destination;
    sfVector2f move;
    sfVector2u texture_size;
    sfSprite *sprite;
    sfTexture *texture;
    struct projectile_s *next;
    void (*call_back)(enemy_t *enemy);
}projectile_t;

typedef struct button_s
{
    bool hover;
    bool pressed;
    sfTexture *texture_basic;
    sfTexture *texture_pressed;
    sfSprite *sprite;
    sfIntRect rect;
    sfTime time;
    void (*call_back)(struct defender_s *defender);
}button_t;

typedef struct my_mini_menu
{
    bool displayed;
    sfIntRect area;
    sfTexture *texture;
    sfSprite *sprite;
    button_t *btns;
}my_mini_menu_t;


typedef struct main_menu_s
{
    bool displayed;
    button_t start_btn;
    button_t exit_btn;
    button_t score_btn;
    button_t settings_btn;
    button_t tutorial_btn;
    sfText *title;
}main_menu_t;

typedef struct game_s
{
    int coin;
    int score;
    int life_bonus;
    float atq_bonus;
    bool sell_mode;
    sfText *text_score;
    sfText *text_coin;
    sfSprite *sprite_energy;
    sfTexture *text_energy;
    round_t round;
    button_t pause_btn;
    button_t skills_btn;
    my_mini_menu_t skills_menu;
    my_mini_menu_t tower_menu;
    my_mini_menu_t pause_menu;
    enemy_t *enemies;
    tower_t *temp;
    tower_t *towers;
    projectile_t *projectiles;
}game_t;

typedef struct defender_s
{
    bool sound;
    bool music;
    bool loose;
    int scene_id;
    int elapsed_microsecond;
    int last_score;
    sfClock *clock;
    sfText *text_score;
    sfTime actual_time;
    sfTime last_time;
    my_window_t window;
    my_mini_menu_t score;
    my_mini_menu_t settings;
    my_mini_menu_t help;
    main_menu_t main_menu;
    game_t game;
    music_t sounds;
}defender_t;

//-----PROTOTYPES--------
//main.c
void end_game(defender_t *defender);

//defender_struct.c
int init_defender_struct(defender_t *defender);

//window.c
void window_init(my_window_t *window, sfVector2f window_size);
void make_close_window(defender_t *defender);

//event.c
void detect_key(defender_t *defender, sfEvent event);
void event_management(defender_t *defender, sfRenderWindow *window, \
sfEvent event);
void check_click(defender_t *defender, sfEvent event);

//background.c
my_background_t *background_create(void);
void background_drawing(sfRenderWindow *window, my_background_t *background);

//main_menu.c
int init_main_menu(main_menu_t *menu);
void main_menu_button_manager(defender_t *defender, main_menu_t *menu, \
sfClock *clock);
void menu_event_management(sfRenderWindow *window, sfEvent event, \
defender_t *defender);
void draw_main_menu(sfRenderWindow *window, main_menu_t *menu, \
defender_t *defender);
void set_sprite(main_menu_t *menu);

//tuto
void help_appears(defender_t *defender);
int init_help_menu(my_mini_menu_t *help);
void draw_help(defender_t *defender);

//sound.c
void make_sound_on(defender_t *defender);
void make_sound_off(defender_t *defender);

//music.c
void make_music_on(defender_t *defender);
void make_music_off(defender_t *defender);

//button.c
button_t init_button(sfVector2f vectors[2], char *path_basic, \
char *path_pressed, void (*call_back)(defender_t *menu));
bool button_is_hover(button_t *button, int mouse_x, int mouse_y);
bool button_is_clicked(button_t *button, defender_t *defender);
void one_button_manager(button_t *button, sfTime time);
void draw_button(sfRenderWindow *window, button_t *button);

//settings_menu.c
int init_settings_menu(my_mini_menu_t *settings);
void draw_settings_menu(defender_t *defender);
void make_settings_appears(defender_t *defender);
void make_settings_disappears(defender_t *defender);

//go_to_scene.c
void make_game_start(defender_t *defender);
void return_to_main_menu(defender_t *defender);

//scene_manager.c
void scene_manager(defender_t *defender);

//text.c
sfText *init_text(sfVector2f pos, unsigned int size, char *str, sfColor color);
void change_text(sfText *text, char *new_str);
char *change_int_into_str(int nb);
void draw_coin(sfRenderWindow *window, sfText *text);

//game.c
int init_game_part(defender_t *defender, game_t *game);
void game_event_management(sfRenderWindow *window, sfEvent event, \
defender_t *defender);
void make_changment_for_game(game_t *game);

//game_menu.c
void draw_game_menu(sfRenderWindow *window, game_t *game_scene, \
defender_t *defender);
void check_game_menu_button_hover(defender_t *defender, int mouse_x, \
int mouse_y);
void check_game_menu_button_pressed(defender_t *defender);

//tool_functions.c
void draw_sprite_outline(sfRenderWindow *window, sfSprite *sprite);
void show_enemy_hitbox(sfRenderWindow *window, enemy_t *enemy);
void show_tower_hitbox(sfRenderWindow *window, tower_t *tower);
void show_projectile_hitbox(sfRenderWindow *window, projectile_t *projectile);
bool is_in_area_range_two(tower_t *tower, enemy_t *enemy, float tower_x, \
float tower_y);

//time_management.c
void get_time(defender_t *defender);

//music_manag.c
void create_music(music_t *sounds);
void destroy_music(music_t *sounds);

//pause.c
void make_pause(defender_t *defender);
int set_pause_menu(my_mini_menu_t *pause_menu);
void draw_pause_menu(defender_t *defender);
void select_sprite_for_pause(my_mini_menu_t *pause_menu);


//projectiles_creation.c
projectile_t *add_projectile(projectile_t **projectile, int type, \
sfVector2f pos, sfVector2f destination);
void create_projectile_sprite(projectile_t *projectile, char *path);

//projectiles_type.c
void init_projectile_type(projectile_t *projectile, int type);

//projectiles_destruction.c
void destroy_all_projectiles(projectile_t **projectile);
void destroy_only_one_projectile(game_t *game, projectile_t *projectile);

//projectiles_moves.c
void calcul_move(projectile_t *projectile);
void move_projectiles(defender_t *defender, projectile_t *projectile);
void rotate_projectile(projectile_t *projectile);

//projectiles_display.c
void draw_projectiles(sfRenderWindow *window, defender_t *defender, \
projectile_t *projectile);

//projectiles_check.c
projectile_t *check_for_projectile_action(defender_t *defender, \
projectile_t *projectile);

//projectiles_attack.c
void projectile_explode(defender_t *defender, \
projectile_t *projectile, enemy_t *enemies);
void arrived_at_destination(defender_t *defender, projectile_t *projectile);
void projectile_attack(defender_t *defender, \
projectile_t *projectile, enemy_t *enemy);

//energy_manager.c
void set_new_text(game_t *game);
void get_energy_for_tower(defender_t *defender, tower_t *tower);
void get_energy_for_enemy_destroy(game_t *game, enemy_t *enemy);

//sell_towers.c
void active_sell_mode(defender_t *defender);
void desactive_sell_mode(defender_t *defender);
void sell_tower(defender_t *defender, sfEvent event);

//tower_upgrade.c
void upgrade_attack_of_tower(defender_t *defender, float nb);
void upgrade_life_of_tower(defender_t *defender, int nb);

//skill_tree_init.c
void make_skills_appears(defender_t *defender);
int init_skill_tree(my_mini_menu_t *skills_tree);

//skill_tree_tools.c
void do_a_damage_upgrade(defender_t *defender);
void do_a_life_upgrade(defender_t *defender);
void check_skill_tree_button_hover(button_t *button, int mouse_x, int mouse_y);
void check_skill_tree_buton_pressed(defender_t *defender);

//skill_tree_draw.c
void draw_skill_tree(defender_t *defender);

//score.c
void score_appears(defender_t *defender);
int init_score_menu(my_mini_menu_t *score);
void draw_score(defender_t *defender);

//end_of_a_game.c
bool does_continue(defender_t *defender);

//detroy.c
void destroy_game(game_t game);
void destroy_button(button_t button);
void destroy_mini_menu(my_mini_menu_t settings, int nb);
void destroy_main_menu(main_menu_t main_menu);
void destroy_sounds(music_t sounds);
void destroy_defender(defender_t *defender);
void destroy_background(my_background_t *background);

#endif
