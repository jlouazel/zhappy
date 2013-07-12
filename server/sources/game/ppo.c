/*
** ppo.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jul 12 14:52:32 2013 louaze_j
** Last update Fri Jul 12 14:59:05 2013 louaze_j
*/

#include	"graphical.h"

#include <stdio.h>

static
const char	*ppo(t_graphical *graphical, const t_server *server, void *arg)
{
  t_player	*pl;

  (void)server;
  (void)graphical;
  pl = (t_player *)arg;
  printf("ppo %d %d %d %d\n", pl->id, pl->x, pl->y, pl->direction);
  return (NULL);
}

void		_ppo(t_graphical *graphical)
{
  if (graphical)
    {
      graphical->ppo = &ppo;
    }
}
