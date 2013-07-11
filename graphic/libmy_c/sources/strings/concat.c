/*
** concat.c for lib in /home/fortin_j/libmy/libmy_c
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Wed Apr 10 10:37:38 2013 julien fortin
** Last update Wed Apr 10 10:50:00 2013 julien fortin
*/

#include	<stdarg.h>
#include	<stdlib.h>
#include	"libmy_c_strings.h"

char		*my_concat(const char *first, ...)
{
  char		*new;
  char		*res;
  char		*tmp;
  va_list	ap;

  res = NULL;
  new = my_strdup(first);
  va_start(ap, first);
  while ((res = va_arg(ap, char *)))
    {
      tmp = my_strcat(new, res);
      free(new);
      new = tmp;
    }
  return (new);
}
