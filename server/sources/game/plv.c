/*
** plv.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jul 12 15:00:39 2013 louaze_j
<<<<<<< HEAD
** Last update Sun Jul 14 08:08:59 2013 julien fortin
=======
** Last update Sun Jul 14 04:56:54 2013 louaze_j
>>>>>>> a24eb59b03a5d4f8eeb3e3f9c0f72c69d9a7340c
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
