/*
** server_graph_actions.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sat Jul 13 01:55:19 2013 julien fortin
** Last update Sat Jul 13 14:37:59 2013 julien fortin
*/

#include	<sys/select.h>
#include	"lib_std.h"
#include	"graphical.h"

static void	_server_treat_actions_for_graph(const t_server *serv,
						t_graphical *graph)
{
  t_list	*list;

  if (!serv || !graph || !graph->socket
      || !graph->socket->is_valid(deconst_cast(graph->socket)))
    return ;
  list = server_extract_graph_packet(graph);
  while (list)
    {
      list = list->next;
    }
}

bool            server_graph_actions(const t_server *serv, fd_set *rfd)
{
  t_list        *list;
  t_list        *tmp;
  t_graphical      *graph;

  list = serv && serv->game ? serv->game->graphicals : NULL;
  while (list)
    {
      tmp = list->next;
      if (list->data)
        {
	  graph = (t_graphical*)list->data;
          if (graph && graph->socket && FD_ISSET(graph->socket->_socket, rfd))
            _server_treat_actions_for_graph(serv, graph);
        }
      list = tmp;
    }
  return (true);
}
