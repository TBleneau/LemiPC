/*
** EPITECH PROJECT, 2018
** lemipc.h
** File description:
** Created by Thomas BLENEAU
*/

#ifndef LEMIPC_H_
	#define LEMIPC_H_

	#ifndef DUNIT_TEST
		#define STATIC
	#else
		#define STATIC static
	#endif /* !DUNIT_TEST */

	#include <sys/types.h>
	#include <sys/ipc.h>
	#include <sys/shm.h>
	#include <sys/sem.h>
	#include <sys/msg.h>

	enum error_e {
		E_ARGS,
		E_NUMB,
		E_FD,
		E_FILE,
		E_DIR,
		E_ACCESS,
		E_FTOK,
		E_SHM,
		E_SHMAT
	};

	enum color_e {
		KRED = 0,
		KGRN = 1,
		KYEL = 2,
		KBLU = 3,
		KMAG = 4,
		KCYN = 5,
		KWHT = 6
	};

	static const int MAP_LENGTH = 50;
	static const int MAP_WIDTH = 50;
	static const size_t FTOK_KEY = 1;
	static const int NEIGHBOURS = 8;
	static const int NB_COLORS = 6;

	typedef struct s_lemi {
		key_t key_ftok;
		int sem_key;
		int msg_key;
		int shm_key;
		char *path;
		struct s_player *player;
	} t_lemi;

	typedef struct s_map {
		int core[50][50];
	} t_map;

	typedef struct s_player {
		int pos_x;
		int pos_y;
		int create;
		int nb_team;
	} t_player;

	int arround_player(t_map *, t_player *);
	int enemies_find(t_map *);
	int enemies_ready(t_map *);
	int error_arguments(int const, char **);
	int error_display(char const *const, enum error_e const);
	int first_player(char **, t_lemi *);
	int display_map(t_map *);
	int display_winner(t_map *, t_lemi *);
	int lemi_destroy(t_lemi *, int);
	int lemi_display(t_map *, t_lemi *);
	int lemi_game(t_map *, t_lemi *);
	int lemi_is_alive(t_map *, t_player *, int *);
	int map_location(t_map *);
	int moves_position(t_map *, t_lemi *);
	int other_player(char **, t_lemi *);
	int player_position(t_map *, t_lemi *);
	int sem_lock(t_lemi *);
	int sem_unlock(t_lemi *);
	t_lemi *lemi_create(char **);
	t_map *create_map(t_lemi *, t_map *);

#endif /* !LEMIPC_H_ */
