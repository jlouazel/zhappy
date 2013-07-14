/*
** init_ig.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Mon Jul  8 15:59:23 2013 louaze_j
** Last update Sun Jul 14 20:49:43 2013 louaze_j
*/

#include	<stdio.h>
#include	"lib_std.h"
#include	"graphical.h"

void	_welcome(t_graphical *graph, const t_server *server)
{
  graph->notify(graph, msz(server));
  graph->notify(graph, sgt(server));
  mct(graph, server);
  tna(graph, server);
}

static void	_graph_notify(t_graphical *graph, const char *data)
{
  if (!graph || !data)
    return ;
  if (graph->io && graph->io->out)
    graph->io->out->push_back((t_list**)&graph->io->out, (void*)data);
  else if (graph->io)
    ((t_io*)graph->io)->out = new_list((void*)data);
}

t_graphical	*new_graphical_client(const t_socket *socket, unsigned int id)
{
  t_graphical	*new_graph;

  if (!(new_graph = xcalloc(1, sizeof(*new_graph))))
    return (NULL);
  new_graph->id = id;
  new_graph->io = init_server_io();
  new_graph->packet = NULL;
  new_graph->socket = socket;
  new_graph->notify = &_graph_notify;
  printf("*** New graphic client %d\n", id);
  return (new_graph);
}
