/*
** pbc.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jul 12 17:23:21 2013 louaze_j
** Last update Fri Jul 12 17:34:19 2013 louaze_j
*/

#include	"graphical.h"

#include <stdio.h>

static
const char	*pbc(t_graphical *graphical, const t_server *server,
		     void *arg, void *msg)
{
  t_player	*pl;

  (void)graphical;
  (void)server;
  pl = (t_player *)arg;
  printf("pbc %d %s\n", pl->id, (char *)msg);
  return (NULL);
}

void		_pbc(t_graphical *graphical)
{
  if (graphical)
    {
      graphical->pbc = &pbc;
    }
}
