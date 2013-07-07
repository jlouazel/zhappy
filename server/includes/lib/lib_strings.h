/*
** libmy_c_string.h for lib in /home/fortin_j/libmy/libmy_c
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Fri Apr  5 11:27:50 2013 julien fortin
** Last update Sun Jul  7 18:23:32 2013 julien fortin
*/

#ifndef	__LIBMY_C_STRING_H__
#define	__LIBMY_C_STRING_H__

#include	<stdarg.h>

unsigned int	my_strlen(const char *);
unsigned int	char_match_with(char, const char *);

int     my_strcmp(const char *, const char *);
int     my_strncmp(const char *, const char *, int);
int     count_match(const char *, char);
int	find_first_of(const char *, char);

char	*replace_char(char *, char, char);
char	*epur_begin_str(char *, const char *);
char    *my_strdup(const char *);
char    *my_strndup(const char *, int, int);
char	*my_strcat(const char *, const char *);
char	*my_concat(const char *, ...);

#endif
