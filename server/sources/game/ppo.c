/*
** ppo.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jul 12 14:52:32 2013 louaze_j
** Last update Sun Jul 14 03:12:11 2013 julien fortin
*/

#include	"graphical.h"

#include <stdio.h>

static
const char	*ppo(const t_server *server, int id)
{
  t_list	*list;
  t_player	*pl;

  if (!server || id < 0)
    return ("ko\n");
  list = server->game ? server->game->players : NULL;
  pl = NULL;
  while (list)
    {
      if (list->data && ((int)((t_player*)list->data)->id) == id)
	{
	  pl = (t_player*)list->data;
	  break;
	}
      list = list->next;
    }
  if (pl)
    {
      printf("ppo %d %d %d %d\n", pl->id, pl->x, pl->y, pl->direction);
      return (NULL);
    }
  else
    return ("ko\n");
}

void		_ppo(t_graphical *graphical)
{
  if (graphical)
    {
      graphical->ppo = &ppo;
    }
}
