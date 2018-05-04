/*
** EPITECH PROJECT, 2018
** map.c
** File description:
** Created by Thomas BLENEAU
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include "lemipc.h"

static const char *const colors[] = {
	[KRED] = "\x1B[31m",
	[KGRN] = "\x1B[32m",
	[KYEL] = "\x1B[33m",
	[KBLU] = "\x1B[34m",
	[KMAG] = "\x1B[35m",
	[KCYN] = "\x1B[36m",
	[KWHT] = "\x1B[37m"
};

t_map *create_map(t_lemi *lemi, t_map *map)
{
	int coord[2] = {0, 0};

	lemi->msg_key = msgget(lemi->key_ftok,
				IPC_CREAT | SHM_R | SHM_W);
	lemi->sem_key = semget(lemi->key_ftok, 1, IPC_CREAT | SHM_R | SHM_W);
	lemi->player->create = 1;
	semctl(lemi->sem_key, 0, SETVAL, 1);
	while (coord[0] < MAP_LENGTH) {
		coord[1] = 0;
		while (coord[1] < MAP_WIDTH) {
			map->core[coord[0]][coord[1]] = 0;
			coord[1] += 1;
		}
		coord[0] += 1;
	}
	return (map);
}

int display_line(void)
{
	int inc = 0;

	printf(" ");
	while (inc < MAP_WIDTH * 2) {
		printf("\033[22;31m#");
		inc += 1;
	}
	printf("\n");
	return (0);
}

int display_map(t_map *map)
{
	int position = 0;
	int coord[2] = {0, 0};

	system("clear");
	display_line();
	for (coord[0] = 0; coord[0] < MAP_LENGTH; coord[0]++) {
		printf("\033[22;31m# ");
		for (coord[1] = 0; coord[1] < MAP_WIDTH; coord[1]++) {
			position = map->core[coord[0]][coord[1]];
			(position == 0) ? printf("\033[01;37m%c ", ' ') :
				printf("%s%d ", colors[position % NB_COLORS],
					position);
		}
		printf("\033[22;31m#\n");
	}
	display_line();
	return (0);
}

int display_winner(t_map *map, t_lemi *lemi)
{
	int ret = 0;
	int coord[2] = {0, 0};

	display_map(map);
	for (coord[0] = 0; coord[0] < MAP_LENGTH; coord[0]++) {
		coord[1] = 0;
		for (coord[1] = 0; coord[1] < MAP_WIDTH &&
				ret == 0; coord[1]++) {
			ret = (map->core[coord[0]][coord[1]] != 0) ?
				map->core[coord[0]][coord[1]] : 0;
		}
		if (ret != 0)
			break;
	}
	printf("\033[01;37m\nCONGRATULATIONS : WINNER'S TEAM IS %d !\n", ret);
	lemi_destroy(lemi, 1);
	return (0);
}

int map_location(t_map *map)
{
	int ret = 0;
	int coord[2] = {0, 0};

	for (coord[0] = 0; coord[0] < MAP_LENGTH; coord[0]++) {
		for (coord[1] = 0; coord[1] < MAP_WIDTH &&
				ret == 0; coord[1]++) {
			ret = (map->core[coord[0]][coord[1]] == 0) ? 1 : 0;
		}
		if (ret == 1)
			return (1);
	}
	return (0);
}
