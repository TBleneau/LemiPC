/*
** EPITECH PROJECT, 2018
** arround.c
** File description:
** Created by Thomas BLENEAU
*/

#include <stdlib.h>
#include "lemipc.h"

static int arround_corner(t_player *player, t_map *map, int state)
{
	int pos_y = player->pos_y;
	int pos_x = player->pos_x;

	switch (state) {
	case 1:
		return ((pos_y - 1 >= 0 && pos_x + 1 < MAP_WIDTH) ?
			map->core[pos_y - 1][pos_x + 1] : 0);
	case 2:
		return ((pos_y - 1 >= 0 && pos_x - 1 >= 0) ?
			map->core[pos_y - 1][pos_x - 1] : 0);
	case 3:
		return ((pos_y + 1 < MAP_LENGTH && pos_x + 1 < MAP_WIDTH) ?
			map->core[pos_y + 1][pos_x + 1] : 0);
	case 4:
		return ((pos_y + 1 < MAP_LENGTH && pos_x - 1 >= 0) ?
			map->core[pos_y + 1][pos_x - 1] : 0);
	}
	return (0);
}

static int arround_sides(t_player *player, t_map *map, int state)
{
	int pos_y = player->pos_y;
	int pos_x = player->pos_x;

	switch (state) {
	case 1:
		return ((pos_y - 1 >= 0) ?
			map->core[pos_y - 1][pos_x] : 0);
	case 2:
		return ((pos_x - 1 >= 0) ?
			map->core[pos_y][pos_x - 1] : 0);
	case 3:
		return ((pos_y + 1 < MAP_LENGTH) ?
			map->core[pos_y + 1][pos_x] : 0);
	case 4:
		return ((pos_x + 1 < MAP_WIDTH) ?
			map->core[pos_y][pos_x + 1] : 0);
	}
	return (0);
}

static int *get_neighbours(t_map *map, t_player *player)
{
	int *neighbours = calloc(NEIGHBOURS, sizeof(int));

	neighbours[0] = arround_sides(player, map, 1);
	neighbours[1] = arround_sides(player, map, 2);
	neighbours[2] = arround_sides(player, map, 3);
	neighbours[3] = arround_sides(player, map, 4);
	neighbours[4] = arround_corner(player, map, 1);
	neighbours[5] = arround_corner(player, map, 2);
	neighbours[6] = arround_corner(player, map, 3);
	neighbours[7] = arround_corner(player, map, 4);
	return (neighbours);
}

static int arround_another(int *neighbours, int ref)
{
	int inc = 0;

	while (inc < NEIGHBOURS) {
		if (inc != ref && neighbours[inc] == neighbours[ref])
			return (1);
		inc += 1;
	}
	return (0);
}

int arround_player(t_map *map, t_player *player)
{
	int inc = 0;
	int *neighbours = get_neighbours(map, player);

	while (inc < NEIGHBOURS) {
		if (neighbours[inc] != 0 && neighbours[inc] != player->nb_team
			&& arround_another(neighbours, inc)) {
			free(neighbours);
			map->core[player->pos_y][player->pos_x] = 0;
			return ((player->create == 1) ? 1 : 0);
		}
		inc += 1;
	}
	return (1);
}
