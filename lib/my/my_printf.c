/*
** EPITECH PROJECT, 2020
** my_rpintf.c
** File description:
** My printf function
*/

#include "my.h"
#include <stdarg.h>
#include <unistd.h>

// A FAIRE + - 0 Digit space # p
// FAIT i d s c o % X x b u S

void flag_switch_part_one(char const *s, va_list list, int i)
{
    switch (s[i + 1]) {
    case 'c':
        my_putchar(va_arg(list, int));
        break;
    case 's':
        my_putstr(va_arg(list, char*));
        break;
    case 'i':
    case 'd':
        my_put_nbr(va_arg(list, int));
        break;
    case 'x':
        my_putnbr_base(va_arg(list, int), "0123456789abcdef");
        break;
    case 'X':
        my_putnbr_base(va_arg(list, int), "0123456789ABCDEF");
        break;
    default :
        flag_switch_part_two(s, list, i);
    }
}

void flag_switch_part_two(char const *s, va_list list, int i)
{
    switch (s[i + 1]) {
    case 'o':
        my_putnbr_base(va_arg(list, int), "01234567");
        break;
    case '%':
        my_putchar('%');
        break;
    case 'u':
        my_put_unsigned(va_arg(list, int));
        break;
    case 'b':
        my_putnbr_base(va_arg(list, int), "01");
        break;
    case 'S':
        my_putstr_unprintable(va_arg(list, char*));
        break;
    case 'p':
        my_put_ptr(va_arg(list, unsigned long));
        break;
    }
}

int is_in_str(char const *s, char c)
{
    for (int i = 0; s[i]; i++)
        if (c == s[i])
            return (1);
    return (0);
}

int check_flag(char const *s, int i)
{
    char *end_flags = "csidxXo%ubSp";
    char *possible_format = "0123456789-+# ";
    char *signs = "+ -";
    char *spaces = "0123456789";
    int x = i + 1;

    for (; s[x] && !is_in_str(end_flags, s[x]); x++){
        if (!is_in_str(possible_format, s[x]))
            return (0);
    }
    return (1);
}

void my_printf(char const *s, ...)
{
    va_list list;

    va_start(list, s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '%' && check_flag(s, i) && s[i + 1]) {
            flag_switch_part_one(s, list, i);
            i++;
        }
        else
            my_putchar(s[i]);
    }
    va_end(list);
}
