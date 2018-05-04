/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** Created by Thomas BLENEAU
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include "lemipc.h"

int lemi_destroy(t_lemi *lemi, int action)
{
	if (action) {
		semctl(lemi->sem_key, 1, IPC_RMID);
		shmctl(lemi->shm_key, IPC_RMID, NULL);
		msgctl(lemi->msg_key, IPC_RMID, NULL);
	} else {
		free(lemi->path);
		free(lemi->player);
		free(lemi);
	}
	return (0);
}

t_lemi *lemi_create(char **argv)
{
	t_lemi *lemi = calloc(1, sizeof(t_lemi));
	size_t map_size = (MAP_WIDTH * MAP_LENGTH) * sizeof(t_map);

	if (lemi == NULL || argv[1] == NULL)
		return (NULL);
	lemi->player = NULL;
	lemi->path = strdup(argv[1]);
	lemi->key_ftok = ftok(lemi->path, FTOK_KEY);
	if (lemi->key_ftok == -1) {
		error_display(argv[0], E_FTOK);
		return (NULL);
	}
	lemi->shm_key = shmget(lemi->key_ftok, map_size, SHM_R | SHM_W);
	lemi->sem_key = 0;
	lemi->msg_key = 0;
	return (lemi);
}

int lemi_display(t_map *map, t_lemi *lemi)
{
	int enemy = 0;
	int is_alive = 1;

	player_position(map, lemi);
	enemy = enemies_ready(map);
	while (enemy) {
		sem_lock(lemi);
		if (is_alive)
			moves_position(map, lemi);
		is_alive = arround_player(map, lemi->player);
		enemy = enemies_find(map);
		display_map(map);
		sem_unlock(lemi);
		usleep(500000);
	}
	display_winner(map, lemi);
	return (0);
}

int lemi_game(t_map *map, t_lemi *lemi)
{
	int enemy = 0;
	int is_alive = 1;

	player_position(map, lemi);
	enemy = enemies_ready(map);
	while (is_alive && enemy) {
		sem_lock(lemi);
		moves_position(map, lemi);
		is_alive = arround_player(map, lemi->player);
		enemy = enemies_find(map);
		sem_unlock(lemi);
		usleep(500000);
	}
	return (0);
}
