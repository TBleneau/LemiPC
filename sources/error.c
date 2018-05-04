/*
** EPITECH PROJECT, 2018
** error.c<sources>
** File description:
** Created by Thomas BLENEAU
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include "lemipc.h"

static const char U_HELP[] = {'-', '-', 'h', 'e', 'l', 'p', '\0'};

STATIC int error_team(char **argv)
{
	size_t inc = 0;

	while (argv && argv[2] && argv[2][inc]) {
		if (!isdigit(argv[2][inc]))
			return (error_display(argv[0], E_NUMB));
		inc += 1;
	}
	return ((atoi(argv[2]) <= 0) ? error_display(argv[0], E_NUMB) : 0);
}

STATIC int error_path(char **argv)
{
	struct stat s_file;

	if (access(argv[1], F_OK) == -1)
		return (error_display(argv[1], E_FILE));
	if (access(argv[1], R_OK) == -1)
		return (error_display(argv[1], E_ACCESS));
	if (stat(argv[1], &s_file) == -1)
		return (error_display(argv[1], E_FD));
	return (0);
}

int error_arguments(int const argc, char **argv)
{
	if (argc < 2 || argc > 3)
		return (error_display(argv[0], E_ARGS));
	if (argc == 2 && strcmp(argv[argc - 1], U_HELP))
		return (error_display(argv[0], E_ARGS));
	if (argc == 3 && (error_path(argv) == -1 || error_team(argv) == -1))
		return (-1);
	return (0);
}
