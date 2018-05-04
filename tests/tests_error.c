/*
** EPITECH PROJECT, 2018
** tests_error.c
** File description:
** Created by Thomas BLENEAU
*/

#include <criterion/criterion.h>
#include "lemipc.h"

int error_path(char **);
int error_team(char **);

Test(test01, error_arguments)
{
	char *argv_1[] = {"./lemipc", "../sources/main.c", "3", NULL};
	char *argv_2[] = {"./lemipc", "../sources/main.c", "0", NULL};
	char *argv_3[] = {"./lemipc", "sources/main.c", "1", NULL};
	int argc[4] = {1, 3, 4, 2};

	cr_assert_eq(error_arguments(argc[0], argv_1), -1);
	cr_assert_eq(error_arguments(argc[1], argv_1), 0);
	cr_assert_eq(error_arguments(argc[2], argv_2), -1);
	cr_assert_eq(error_arguments(argc[1], argv_2), -1);
	cr_assert_eq(error_arguments(argc[3], argv_3), -1);
}

Test(test01, error_team)
{
	char *argv_1[] = {"./lemipc", "../sources/main.c", "3", NULL};
	char *argv_2[] = {"./lemipc", "sources/main.c", "0", NULL};
	char *argv_3[] = {"./lemipc", "main.c", "1", NULL};
	char *argv_4[] = {"./lemipc", "Makefile", "-1", NULL};

	cr_assert_eq(error_team(argv_1), 0);
	cr_assert_eq(error_team(argv_2), -1);
	cr_assert_eq(error_team(argv_3), 0);
	cr_assert_eq(error_team(argv_4), -1);
}

Test(test01, error_path)
{
	char *argv_1[] = {"./lemipc", "../sources/main.c", "3", NULL};
	char *argv_2[] = {"./lemipc", "sources/main.c", "0", NULL};
	char *argv_3[] = {"./lemipc", "main.c", "1", NULL};
	char *argv_4[] = {"./lemipc", "Makefile", "1", NULL};

	cr_assert_eq(error_path(argv_1), 0);
	cr_assert_eq(error_path(argv_2), -1);
	cr_assert_eq(error_path(argv_3), -1);
	cr_assert_eq(error_path(argv_4), 0);
}
