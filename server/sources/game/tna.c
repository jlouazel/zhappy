/*
** tna.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Tue Jul  9 18:20:10 2013 louaze_j
** Last update Sun Jul 14 11:19:36 2013 louaze_j
*/

#include	<stdio.h>
#include	"server.h"
#include	"graphical.h"
#include	"lib_strings.h"

const char	*tna(t_graphical *graphical, const t_server *server)
{
  t_list	*list;
  char		*msg;

  msg = "";
  if (!graphical || !server)
    return ("ko\n");
  list = server->game ? server->game->teams : NULL;
  while (list)
    {
      if (list->data)
	{
	  msg = my_concat("tna ", ((t_team*)list->data)->name, "\n", NULL);
	  graphical->notify(graphical, msg);
	}
      list = list->next;
    }
  return ("ok\n");
}
