/*
** plv.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jul 12 15:00:39 2013 louaze_j
** Last update Sun Jul 14 04:49:28 2013 julien fortin
*/

#include	"graphical.h"
#include	<stdio.h>

static
const char	*plv(const t_server *server, int id)
{
  (void)server;(void)id;
  //printf("plv %d %d\n", pl->id, pl->level);
  return (NULL);
}


void		_plv(t_graphical *graphical)
{
  if (graphical)
    {
      graphical->plv = &plv;
    }
}
