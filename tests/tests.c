/*
** EPITECH PROJECT, 2020
** type
** File description:
** tests.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

/* 
LES FONCTIONS UTILES
cr_assert_eq
cr_assert_eq_str
cr_assert_stdout_eq_str
cr_asser_file_content
*/