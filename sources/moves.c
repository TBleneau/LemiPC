/*
** EPITECH PROJECT, 2018
** moves.c
** File description:
** Created by Thomas BLENEAU
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include "lemipc.h"

static int calc_abscisse(int x, t_player *player, t_map *map)
{
	int pos_x = player->pos_x;
	int pos_y = player->pos_y;

	if (x > pos_x && pos_x + 1 < MAP_WIDTH
			&& map->core[pos_y][pos_x + 1] == 0)
		return (pos_x + 1);
	else if (x < pos_x && pos_x - 1 > 0
			&& map->core[pos_y][pos_x - 1] == 0)
		return (pos_x - 1);
	return (pos_x);
}

static int calc_ordonnate(int y, t_player *player, t_map *map)
{
	int pos_x = player->pos_x;
	int pos_y = player->pos_y;

	if (y > pos_y && pos_y + 1 < MAP_LENGTH
			&& map->core[pos_y + 1][pos_x] == 0)
		return (pos_y + 1);
	else if (y < pos_y && pos_y - 1 > 0
			&& map->core[pos_y - 1][pos_x] == 0)
		return (pos_y - 1);
	return (pos_y);
}

static int vector_position(t_map *map, int coord[2], t_player *player)
{
	int position = map->core[coord[0]][coord[1]];

	if (position != 0 && position != player->nb_team) {
		player->pos_x = calc_abscisse(coord[1], player, map);
		player->pos_y = calc_ordonnate(coord[0], player, map);
		return (1);
	}
	return (0);
}

static int ennemy_position(t_map *map, t_player *player)
{
	int ret = 0;
	int coord[2] = {0, 0};

	for (coord[0] = 0; coord[0] < MAP_LENGTH && ret != 1; coord[0]++) {
		for (coord[1] = 0; coord[1] < MAP_WIDTH
				&& ret != 1; coord[1]++) {
			ret = vector_position(map, coord, player);
		}
	}
	return (0);
}

int moves_position(t_map *map, t_lemi *lemi)
{
	int pos_x = lemi->player->pos_x;
	int pos_y = lemi->player->pos_y;
	int new_x = pos_x + (rand() % 3 - 1);
	int new_y = pos_y + (rand() % 3 - 1);

	map->core[lemi->player->pos_y][lemi->player->pos_x] = 0;
	ennemy_position(map, lemi->player);
	if (pos_x == lemi->player->pos_x && pos_y == lemi->player->pos_y) {
		if (new_x >= 0 && new_x < MAP_WIDTH &&
			new_y >= 0 && new_y < MAP_LENGTH) {
			lemi->player->pos_x = (map->core[new_y][new_x] == 0) ?
				new_x : pos_x;
			lemi->player->pos_y = (map->core[new_y][new_x] == 0) ?
				new_y : pos_y;
		}
	}
	map->core[lemi->player->pos_y][lemi->player->pos_x] =
		lemi->player->nb_team;
	return (0);
}
