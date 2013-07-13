/*
** pnw.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jul 12 10:20:31 2013 louaze_j
** Last update Fri Jul 12 14:52:02 2013 louaze_j
*/

#include	"graphical.h"

#include <stdio.h>

static
const char	*pnw(t_graphical *graphical, const t_server *server, void *arg)
{
  t_player	*pl;

  pl = (t_player *)arg;
  printf("pnw %d %d %d %d %d %s\n", pl->id, pl->x, pl->y, pl->direction,
	 pl->level, pl->team->name);
  (void)pl;
  (void)graphical;
  (void)server;
  return (NULL);
}

void		_pnw(t_graphical *graphical)
{
  if (graphical)
    {
      graphical->pnw = &pnw;
    }
}
