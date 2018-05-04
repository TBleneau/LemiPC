/*
** EPITECH PROJECT, 2018
** test_errno.c
** File description:
** Created by Thomas BLENEAU
*/

#include <criterion/criterion.h>
#include "lemipc.h"

Test(test01, error_display)
{
	cr_assert_eq(error_display("./lemipc", E_ARGS), -1);
	cr_assert_eq(error_display("./lemipc", E_NUMB), -1);
}

Test(test02, error_display)
{
	cr_assert_eq(error_display("./lemipc", E_FD), -1);
	cr_assert_eq(error_display("./lemipc", E_FILE), -1);
	cr_assert_eq(error_display("./lemipc", E_DIR), -1);
	cr_assert_eq(error_display("./lemipc", E_ACCESS), -1);
}

Test(test03, error_display)
{
	cr_assert_eq(error_display("./lemipc", E_FTOK), -1);
	cr_assert_eq(error_display("./lemipc", E_SHM), -1);
	cr_assert_eq(error_display("./lemipc", E_SHMAT), -1);
}
