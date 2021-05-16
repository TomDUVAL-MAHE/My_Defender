/*
** EPITECH PROJECT, 2020
** My_Lib
** File description:
** my_close_file.c
*/

#include "my.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

int my_close_file(my_file_t *file)
{
    close(file->fd);
    free(file->buffer);
    return (0);
}