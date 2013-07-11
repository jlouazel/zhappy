/*
** my_free.c for lib in /home/fortin_j/libmy/libmy_c
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Apr 23 01:13:48 2013 julien fortin
** Last update Tue Apr 23 01:14:53 2013 julien fortin
*/

#include	<stdlib.h>

void		*xfree(void **ptr)
{
  free(*ptr);
  *ptr = NULL;
  return (NULL);
}
