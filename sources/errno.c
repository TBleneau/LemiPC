/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** Created by Thomas BLENEAU
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemipc.h"

static char const *const error_type[] = {
	[E_ARGS] = "Bad number of arguments.\nTry --help for more informations",
	[E_NUMB] = "Invalid TEAM_NUMBER. Use value more than 0",
	[E_FD] = "No such file or directory",
	[E_FILE] = "No such file",
	[E_DIR] = "is a directory",
	[E_ACCESS] = "Permission denied",
	[E_FTOK] = "ftok() function failed",
	[E_SHM] = "shmget() function failed",
	[E_SHMAT] = "shmat() function failed: map not found"
};

int error_display(char const *const name, enum error_e const value)
{
	fprintf(stderr, "%s: %s\n", name, error_type[value]);
	return (-1);
}
