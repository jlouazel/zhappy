/*
** ebo.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sun Jul 14 15:55:18 2013 louaze_j
** Last update Sun Jul 14 15:55:49 2013 louaze_j
*/

#include	<stdio.h>
#include	"egg.h"
#include	"lib_std.h"

const char	*ebo(t_egg *egg)
{
  char		*ret;

  if (!egg)
    return ("ko\n");
  if ((ret = xcalloc(42, sizeof(*ret))))
    {
      snprintf(ret, 42, "ebo %d\n", egg->id);
      return (ret);
    }
  return ("ko\n");
}
