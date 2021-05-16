/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_open_and_read.c
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int my_open_and_read(my_file_t *file, char *filepath)
{
    struct stat files_stats;

    file->fd = open(filepath, O_RDONLY);
    if (file->fd < 0)
        return (my_error("The file can not be read\n", -1));
    stat(filepath, &files_stats);
    file->size = files_stats.st_size;
    file->buffer = my_calloc_char(sizeof(char), file->size + 1, '\0');
    if (file->buffer == NULL)
        return (my_error("An error has occurred with the memory\n", -1));
    if (read(file->fd, file->buffer, file->size) == -1) {
        free(file->buffer);
        return (my_error("An error has occurred during the reading\n", -1));
    }
    return (0);
}