/*
** alloc.c for lib in /home/fortin_j/tek2/projects/zappy/fortin_j/core/sources/std
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Apr 29 19:20:59 2013 julien fortin
** Last update Sun Jun 30 23:53:48 2013 julien fortin
*/

#include	<strings.h>
#include	<stdio.h>
#include	<stdlib.h>

void            *xcalloc(int nmemb, int size)
{
  void  *obj;

  if ((obj = calloc(nmemb, size)) == NULL)
    perror("calloc");
  return (obj);
}

void            *xfree(void **ptr, size_t size)
{
  if (size && ptr)
    bzero(*ptr, size);
  free(ptr ? *ptr : NULL);
  if (ptr)
    *ptr = NULL;
  return (NULL);
}
