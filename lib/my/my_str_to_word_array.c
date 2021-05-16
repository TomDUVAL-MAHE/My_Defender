/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** a function that splits a string into words
*/

#include <stdlib.h>
#include "my.h"

char const *is_there_other_word(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_char_isalpha(str[i]) || my_char_isnum(str[i]))
            return (&str[i]);
        i += 1;
    }
    return (0);
}

char *catch_them_all(char const *str)
{
    int i = 0;
    char *word;
    int word_len = 0;

    for (i; my_char_isalpha(str[i]) || my_char_isnum(str[i]); i++) {
        word_len += 1;
    }
    word = malloc(sizeof(char) * word_len + 1);
    for (i = 0; i < word_len; i += 1)
        word[i] = str[i];
    word[i] = '\0';
    return (word);
}

int how_many_words(char const *str)
{
    int word_count = 0;
    char const *ptr = str;
    char *current_word;

    while (is_there_other_word(ptr)) {
        current_word = catch_them_all(is_there_other_word(ptr));
        ptr = ptr + my_strlen(current_word) + 1;
        word_count += 1;
    }
    return (word_count);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    char *current_word;
    char **word_array;
    char const *ptr = str;

    word_array = malloc(sizeof(char *) * (how_many_words(str) + 1));
    if (word_array == NULL)
        return (0);
    while (is_there_other_word(ptr)) {
        current_word = catch_them_all(is_there_other_word(ptr));
        ptr = is_there_other_word(ptr) + my_strlen(current_word);
        word_array[i] = current_word;
        i += 1;
    }
    word_array[i] = NULL;
    return (word_array);
}
