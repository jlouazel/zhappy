/*
** ppo.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jul 12 14:52:32 2013 louaze_j
** Last update Sun Jul 14 21:48:19 2013 louaze_j
*/

#include	<stdio.h>
#include	"lib_std.h"
#include	"server.h"

const char	*ppo(t_player *pl)
{
  char		*ret;

  if (!pl)
    return ("ko\n");
  if ((ret = xcalloc(50, sizeof(*ret))))
    {
      snprintf(ret, 50, "ppo %d %d %d %d\n", pl->id, pl->x, pl->y,
	       pl->direction);
      return (ret);
    }
  return ("ko\n");
}
