/*
** pex.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jul 12 17:23:21 2013 louaze_j
** Last update Fri Jul 12 17:33:07 2013 louaze_j
*/

#include	"graphical.h"

#include <stdio.h>

static
const char	*pex(t_graphical *graphical, const t_server *server, void *arg)
{
  t_player	*pl;

  (void)graphical;
  (void)server;
  pl = (t_player *)arg;
  printf("pex %d\n", pl->id);
  return (NULL);
}

void		_pex(t_graphical *graphical)
{
  if (graphical)
    {
      graphical->pex = &pex;
    }
}
