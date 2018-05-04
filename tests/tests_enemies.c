/*
** EPITECH PROJECT, 2018
** tests_enemies.c
** File description:
** Created by Thomas BLENEAU
*/

#include <criterion/criterion.h>
#include "lemipc.h"

int enemies_position(int, int *);

Test(test01, enemies_position)
{
	int nb[4] = {1, 7, 8, 9};

	cr_assert_eq(enemies_position(0, &nb[0]), 0);
	cr_assert_eq(enemies_position(7, &nb[1]), 0);
	cr_assert_eq(enemies_position(0, &nb[2]), 0);
	cr_assert_eq(enemies_position(9, &nb[3]), 0);

}

Test(test02, enemies_position)
{
	int nb[4] = {1, 7, 8, 9};

	cr_assert_eq(enemies_position(2, &nb[0]), 1);
	cr_assert_eq(enemies_position(18, &nb[1]), 1);
	cr_assert_eq(enemies_position(4, &nb[2]), 1);
	cr_assert_eq(enemies_position(3, &nb[3]), 1);
}
