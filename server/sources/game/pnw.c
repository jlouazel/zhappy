/*
** pnw.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jul 12 10:20:31 2013 louaze_j
** Last update Sun Jul 14 11:13:58 2013 louaze_j
*/

#include	<stdio.h>
#include	"player.h"
#include	"lib_std.h"
#include	"graphical.h"
#include	"lib_strings.h"

const char	*pnw(t_player *pl)
{
  char		*ret;

  if (!pl || !pl->team || !pl->team->name)
    return ("ko\n");
  if ((ret = xcalloc(100 + my_strlen(pl->team->name), sizeof(*ret))))
    {
      snprintf(ret, 100 + my_strlen(pl->team->name),
	       "pnw %d %d %d %d %d %s\n", pl->id, pl->x, pl->y, pl->direction,
	       pl->level, pl->team->name);
      return (ret);
    }
  return ("ko\n");
}
