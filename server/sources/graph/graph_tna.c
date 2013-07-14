/*
** graph_msz.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 00:31:59 2013 julien fortin
** Last update Sun Jul 14 07:09:58 2013 louaze_j
*/

#include	"graphical.h"
#include	"server.h"
#include	"lib_strings.h"

static
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
	  msg = my_concat("tna ",
			  ((t_team*)list->data)->name,
			  "\n",
			  NULL);
	  graphical->notify(graphical, msg);
	}
      list = list->next;
    }
  return (msg);
}

const char	*_graph_tna(t_graphical *graph,
			    const t_server *serv,
			    const char *data)
{
  (void)data;
  if (!serv || !graph)
    return ("ko\n");
  return (tna(graph, serv));
}
