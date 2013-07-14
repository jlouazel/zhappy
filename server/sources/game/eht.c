/*
** eht.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sun Jul 14 15:48:53 2013 louaze_j
** Last update Sun Jul 14 16:11:13 2013 louaze_j
*/

#include	<stdio.h>
#include	"egg.h"
#include	"lib_std.h"

const char	*eht(t_egg *egg)
{
  char		*ret;

  if (!egg)
    return ("ko\n");
  if ((ret = xcalloc(42, sizeof(*ret))))
    {
      snprintf(ret, 42, "eht %d\n", egg->id);
      return (ret);
    }
  return ("ko\n");
}
