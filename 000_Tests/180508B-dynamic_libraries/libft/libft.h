#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include "ft_list.h"

void ft_putchar(char c);
void ft_putstr(char *str);
void ft_putnbr(int nbr);
void ft_putnbr_base(int nbr, char *base);
void ft_print_bits(size_t const size, void const * const ptr);
void ft_itoa(int nbr, char *str, int b);
char *ft_convert_base(char *nbr, char *base_from, char *base_to);
int ft_strlen(char *str);
int ft_atoi(char *str);
int ft_pow(int a, int b);
int ft_abs(int nbr);
void ft_swap(int *a, int *b);
int ft_strcmp(char *s1, char *s2);
char *ft_strcat(char *dest, char *src);
char *ft_strcpy(char *dest, char *src);
char **ft_split(char *str, char *charset);
void ft_sort_wordtab(char **tab);
void ft_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *));
void ft_print_words_tables(char **tab);
char **ft_split_whitespaces(char *str);
char *ft_strdup(char *src);
char *ft_join(char **tab, char *sep);
char **ft_split(char *str, char *charset);
char *ft_strstr(char *str, char *to_find);
char *ft_strcapitalize(char *str);
char *ft_strlowcase(char *str);
char *ft_strupcase(char *str);
char *ft_strrev(char *str);
int ft_str_is_alpha(char *str);
int ft_str_is_numeric(char *str);
int ft_str_is_lowercase(char *str);
int ft_str_is_uppercase(char *str);
int ft_any(char **tab, int(*f)(char *));
int ft_count_if(char **tab, int(*f)(char *));

#endif
