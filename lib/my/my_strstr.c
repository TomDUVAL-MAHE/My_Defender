/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** Reproduce the behavior of the strstr function.
*/
#include "my.h"
#include "unistd.h"

char *my_strstr(char *str, const char *to_find)
{
    int f = 0;
    int y = 0;
    int i = 0;
    if (to_find[0] == '\0')
        return (str);
    while (str[i] != '\0') {
        while (to_find[f] == str[y] && to_find[f] != '\0') {
            f++;
            y++;
        }
        if (to_find[f] == '\0' && str[y] == ' ' && (i <= 2 \
            || str[i - 2] == ' '))
            return (&str[i - 1]);
        f = 0;
        y = i;
        i++;
    }
    return (NULL);
}
