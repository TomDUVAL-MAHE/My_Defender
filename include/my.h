/*
** EPITECH PROJECT, 2020
** mylib
** File description:
** My library
*/
#ifndef _MY_H_
#define _MY_H_
//-----NEEDED-INCLUDES--
#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

//-----MY-STRUCTURES----
typedef struct my_file {
    int fd;
    char *buffer;
    int size;
}my_file_t;

//-----PROTOTYPES-------
char *my_calloc_char(size_t nmemb, size_t size, char default_char);
char *my_memset_char(char *s, char c, size_t n);
int *my_calloc_int(size_t nmemb, size_t size, int default_int);
int *my_memset_int(int *tab, int c, size_t n);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_int_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int smalest_int(int *array, int size, int idx_int, int cycle);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
bool my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int n);
int my_char_isalpha(char charc);
int my_char_isnum(char charc);
char const *is_there_other_word(char const *str);
char *catch_them_all(char const *str);
int how_many_words(char const *str);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *src);
int my_open_and_read(my_file_t *file, char *filepath);
int my_close_file(my_file_t *file);
int my_nbr_size(int nb);
char *my_strndup(char const *src, int n);
int my_error(char *message, int return_value);
void my_putstr_error(char *message);
char **my_calloc_two_d_array(int nb_rows, int nb_cols, char initial_char);
int my_print_char_two_d_array(char **array);
char **my_char_array_dup(char **initial_array);

//-----------PRINTF-------
void my_printf(char const *s, ...);
int check_flag(char const *s, int i);
void verif_flags(char const *s, va_list list, int i);
int my_putnbr_base(int n, char const *base);
unsigned int my_int_to_unsigned(int i);
int my_put_unsigned(int i);
int my_putstr_unprintable(char const *s);
int my_putchar_unprintable(char const c);
int my_put_ptr(unsigned long ptr);
void flag_switch_part_one(char const *s, va_list list, int i);
void flag_switch_part_two(char const *s, va_list list, int i);
#endif
