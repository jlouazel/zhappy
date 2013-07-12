/*
** plv.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jul 12 15:00:39 2013 louaze_j
** Last update Fri Jul 12 15:03:46 2013 louaze_j
*/

#include	"graphical.h"

#include <stdio.h>
static
const char	*plv(t_graphical *graphical, const t_server *server, void *arg)
{
  t_player	*pl;

  (void)graphical;
  (void)server;
  pl = (t_player *)arg;
  printf("plv %d %d\n", pl->id, pl->level);
  return (NULL);
}


void		_plv(t_graphical *graphical)
{
  if (graphical)
    {
      graphical->plv = &plv;
    }
}
