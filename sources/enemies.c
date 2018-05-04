/*
** EPITECH PROJECT, 2018
** ennemy.c
** File description:
** Created by Thomas BLENEAU
*/

#include "lemipc.h"

STATIC int enemies_position(int position, int *nb)
{
	if (position != *nb && position != 0) {
		*nb = position;
		return (1);
	}
	return (0);
}

int enemies_find(t_map *map)
{
	int nb = -1;
	int count = 0;
	int inc[2] = {0, 0};

	for (inc[0] = 0; inc[0] < MAP_LENGTH; inc[0]++) {
		for (inc[1] = 0; inc[1] < MAP_WIDTH && count <= 1; inc[1]++)
			count += enemies_position(map->core[inc[0]][inc[1]],
							&nb);
		if (count > 1)
			return (1);
	}
	return (0);
}

int enemies_ready(t_map *map)
{
	int enemy = 0;

	while (!enemy)
		enemy = enemies_find(map);
	return (enemy);
}
