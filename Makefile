SRC     =	src/main.c \
			src/window.c \
			src/defender_struct.c \
			src/tool_fonctions.c \
			src/menus/pause.c \
			src/menus/main_menu.c	\
			src/menus/main_menu_draw.c	\
			src/menus/menu_background.c \
			src/menus/event.c \
			src/menus/button.c \
			src/menus/main_menu_init.c	\
			src/menus/settings_menu.c \
			src/menus/game_menu.c \
			src/menus/tuto.c \
			src/menus/score.c \
			src/scenes/game.c \
			src/scenes/scene_manager.c \
			src/scenes/go_to_scene.c \
			src/enemies/enemies_creation.c \
			src/enemies/enemies_management.c \
			src/enemies/enemies_moves.c \
			src/enemies/enemies_spawning.c	\
			src/enemies/enemies_spawning_two.c	\
			src/enemies/enemies_tool_function.c	\
			src/towers/tower_creation.c \
			src/towers/tower_types.c \
			src/towers/tower_destruction.c \
			src/towers/tower_managment.c \
			src/towers/tower_display.c \
			src/towers/tower_button_functions.c \
			src/towers/temp_tower.c \
			src/towers/tower_types_two.c \
			src/towers/sell_tower.c \
			src/towers/tower_upgrade.c \
			src/projectiles/projectiles_creation.c \
			src/projectiles/projectiles_type.c \
			src/projectiles/projectiles_destruction.c \
			src/projectiles/projectiles_moves.c \
			src/projectiles/projectiles_display.c \
			src/projectiles/projectiles_attack.c \
			src/projectiles/projectiles_check.c \
			src/options/music_manag.c \
			src/options/texts.c \
			src/options/sound.c \
			src/options/music.c \
			src/options/time_management.c	\
			src/energy/energy_manager.c	\
			src/skill_tree/skill_tree_tools.c \
			src/skill_tree/skill_tree_init.c \
			src/skill_tree/skill_tree_draw.c \
			src/destroy/destroy.c \
			src/end/end_of_a_game.c 

NAME    =       my_defender

OBJ     =       $(SRC:.c=.o)

CFLAGS  =       -L lib/my/ -lmy -I include -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -Wall -Wextra -Wshadow

CC      =       gcc

SRC_T 	=

TEST_N	=	unit_tests

T_FLAGS	=	-lcriterion --coverage

all:    $(NAME)

$(NAME):        $(OBJ)
		make -C ./lib/my/
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		make fclean -C ./lib/my/

re:		fclean all

tests_run:
		$(MAKE) -C ./lib/my
		gcc -o $(TEST_N) $(SRC_T) $(CFLAGS) $(T_FLAGS)
		./unit_tests
		gcovr --exclude tests/
		gcovr --exclude tests/ --branches
