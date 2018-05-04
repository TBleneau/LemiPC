/*
** EPITECH PROJECT, 2018
** tests_player.c
** File description:
** Created by Thomas BLENEAU
*/

#include <criterion/criterion.h>
#include "lemipc.h"

int init_player(char const *const, t_lemi *);

Test(test01, init_player)
{
	char *opts[] = {"./lemipc", "../sources/main.c", NULL};
	t_lemi *lemi = lemi_create(opts);

	cr_assert_eq(init_player("1", lemi), 0);
	cr_assert_eq(init_player("1", lemi), 0);
	cr_assert_eq(init_player("5", lemi), 0);
	cr_assert_eq(init_player("2", lemi), 0);
	cr_assert_eq(init_player("7", lemi), 0);
	cr_assert_eq(init_player("9", lemi), 0);
	cr_assert_eq(init_player("10", lemi), 0);
}

Test(test02, init_player)
{
	char *opts[] = {"./lemipc", "sources/main.c", NULL};
	t_lemi *lemi = lemi_create(opts);

	cr_assert_eq(init_player("1", lemi), -1);
	cr_assert_eq(init_player("1", lemi), -1);
	cr_assert_eq(init_player("5", lemi), -1);
	cr_assert_eq(init_player("2", lemi), -1);
	cr_assert_eq(init_player("7", lemi), -1);
	cr_assert_eq(init_player("9", lemi), -1);
	cr_assert_eq(init_player("10", lemi), -1);
}
