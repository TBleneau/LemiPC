/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Created by Thomas BLENEAU
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lemipc.h"

static int help_usage(void)
{
	printf("USAGE\n");
	printf("\t./lemipc PATH TEAM_NUMBER\n");
	printf("DESCRIPTION\n");
	printf("\tPATH\t        path you'll give to ftok\n");
	printf("\tTEAM_NUMBER\tteam number of the current");
	printf(" champion (greater than 0)\n");
	return (0);
}

int main(int argc, char **argv)
{
	int ret = 0;
	t_lemi *lemi = NULL;

	srand(time(NULL));
	if (error_arguments(argc, argv) == -1)
		return (84);
	if (argc == 2)
		return (help_usage());
	lemi = lemi_create(argv);
	if (lemi == NULL)
		return (84);
	if (lemi->shm_key == -1)
		ret = first_player(argv, lemi);
	else
		ret = other_player(argv, lemi);
	lemi_destroy(lemi, 0);
	return ((ret == -1) ? 84 : 0);
}
