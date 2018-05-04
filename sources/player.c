/*
** EPITECH PROJECT, 2018
** player.c
** File description:
** Created by Thomas BLENEAU
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include "lemipc.h"

STATIC int init_player(const char *const team, t_lemi *lemi)
{
	if (lemi == NULL)
		return (-1);
	lemi->player = calloc(1, sizeof(t_player));
	if (lemi->player == NULL)
		return (-1);
	lemi->player->pos_x = 0;
	lemi->player->pos_y = 0;
	lemi->player->create = 0;
	lemi->player->nb_team = atoi(team);
	return (0);
}

int player_position(t_map *map, t_lemi *lemi)
{
	sem_lock(lemi);
	map->core[lemi->player->pos_y][lemi->player->pos_x] = 0;
	lemi->player->pos_x = (rand() % (MAP_WIDTH - 1));
	lemi->player->pos_y = (rand() % (MAP_LENGTH - 1));
	while (map->core[lemi->player->pos_y][lemi->player->pos_x] != 0) {
		lemi->player->pos_x = (rand() % (MAP_WIDTH - 1));
		lemi->player->pos_y = (rand() % (MAP_LENGTH - 1));
	}
	map->core[lemi->player->pos_y][lemi->player->pos_x] =
		lemi->player->nb_team;
	sem_unlock(lemi);
	return (0);
}

int first_player(char **argv, t_lemi *lemi)
{
	void *location = NULL;
	size_t map_size = (MAP_WIDTH * MAP_LENGTH) * sizeof(t_map);

	lemi->shm_key = shmget(lemi->key_ftok, map_size,
				IPC_CREAT | SHM_R | SHM_W);
	if (lemi->shm_key == -1 || init_player(argv[2], lemi) == -1)
		return (error_display(argv[0], E_SHM));
	location = shmat(lemi->shm_key, 0, 0);
	if (location != (void *) -1) {
		location = create_map(lemi, (t_map *) location);
		lemi_display((t_map *) location, lemi);
		shmdt(location);
	}
	return (0);
}

int other_player(char **argv, t_lemi *lemi)
{
	void *location = NULL;

	lemi->sem_key = semget(lemi->key_ftok, 1, SHM_R | SHM_W);
	lemi->msg_key = msgget(lemi->key_ftok, SHM_R | SHM_W);
	location = shmat(lemi->shm_key, NULL, SHM_R | SHM_W);
	if (location != (void *) -1 && init_player(argv[2], lemi) != -1) {
		map_location((t_map *) location) ?
			lemi_game((t_map *) location, lemi) : exit(0);
		shmdt(location);
	} else
		return (error_display(argv[0], E_SHMAT));
	return (0);
}
