/*
** my_errors.c for myscript in /home/fortin_j/tek2/projects/my_script/myscript-2015s-2016-2017si-fortin_j/include
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Feb 26 18:29:38 2013 julien fortin
** Last update Wed May  1 20:17:27 2013 julien fortin
*/

#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<errno.h>

const char	*get_error()
{
  return (strerror(errno));
}

int		my_perror(const char *s)
{
  if (s)
    perror(s);
  else
    perror("Error");
  return (EXIT_FAILURE);
}

int		my_strerror(const char *s)
{
  if (s)
    write(2, s, strlen(s));
  return (EXIT_FAILURE);
}

void		xexit(const char *s)
{
  if (s)
    write(2, s, strlen(s));
  exit(EXIT_FAILURE);
}
