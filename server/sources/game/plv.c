/*
** plv.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jul 12 15:00:39 2013 louaze_j
<<<<<<< HEAD
** Last update Sun Jul 14 04:49:28 2013 julien fortin
=======
** Last update Sun Jul 14 04:56:54 2013 louaze_j
>>>>>>> a24eb59b03a5d4f8eeb3e3f9c0f72c69d9a7340c
*/

#include	"graphical.h"
#include	<stdio.h>

static
const char	*plv(const t_server *server, int id)
{
<<<<<<< HEAD
  (void)server;(void)id;
  //printf("plv %d %d\n", pl->id, pl->level);
=======
  t_list	*list;
  t_player	*pl;

  (void)id;
  pl = NULL;
  list = server && server->game ? server->game->players : NULL;
  while (list)
    {
      list = list->next;
    }
  printf("plv %d %d\n", pl->id, pl->level);
>>>>>>> a24eb59b03a5d4f8eeb3e3f9c0f72c69d9a7340c
  return (NULL);
}


void		_plv(t_graphical *graphical)
{
  if (graphical)
    {
      graphical->plv = &plv;
    }
}
