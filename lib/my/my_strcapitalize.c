/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** A function that puts every letter of every word in it in uppercase.
*/
#include "my.h"

char *my_strcapitalize(char *str)
{
    int i;
    int alphabet = 0;
    int special = 0;

    my_strlowcase(str);
    for (i = 0; i < my_strlen(str); i += 1) {
        if (str[i] >= 'a' && str[i] <= 'z' && (str[i-1] == ' ' || i == 0))
            alphabet = 1;
        if (str[i-1] == '+' || str[i-1] == '-')
            special = 1;
        if (alphabet == 1 || special == 1)
            str[i] = str[i]-32;
        alphabet = 0;
        special = 0;
    }
    return (str);
}
