/*
** server_graph_actions.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sat Jul 13 01:55:19 2013 julien fortin
** Last update Sat Jul 13 02:17:38 2013 julien fortin
*/

#include	<sys/select.h>
#include	"graphical.h"

static void	_server_treat_actions_for_graph(const t_server *serv,
						t_graphical *graph)
{
  t_list	*list;

  (void)serv;
  list = graph && graph->io ? graph->io->out : NULL;
  while (list)
    {
      list = list->next;
    }
}

bool		server_graph_actions(const t_server *serv, fd_set *wfd)
{
  t_list	*list;
  t_graphical	*graph;

  if ((list = serv && serv->game ? serv->game->graphicals : NULL))
    {
      while (list)
	{
	  if (list->data)
	    {
	      graph = (t_graphical*)list->data;
	      if (graph->socket && graph->io && graph->io->out
		  && FD_ISSET(graph->socket->_socket, wfd))
		{
		  _server_treat_actions_for_graph(serv, graph);
		  ((t_io*)graph->io)->out = delete_list(graph->io->out, NULL);
		}
	    }
	  list = list->next;
	}
      return (true);
    }
  return (false);
}
