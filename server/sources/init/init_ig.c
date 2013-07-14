/*
** init_ig.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Mon Jul  8 15:59:23 2013 louaze_j
** Last update Sun Jul 14 16:08:49 2013 louaze_j
*/

#include	<stdio.h>
#include	"lib_std.h"
#include	"graphical.h"

/* static void init_attr(t_graphical *new_graph) */
/* { */
/*   _msz(new_graph); */
/*   _bct(new_graph); */
/*   _mct(new_graph); */
/*   _tna(new_graph); */
/*   /\* _pnw(new_graph); // NOK *\/ */
/*   _ppo(new_graph); // NOK */
/*   _plv(new_graph); // NOK */
/*   _pin(new_graph); // NOK */
/*   _pex(new_graph); // NOK */
/*   _pbc(new_graph); // NOK */
/*   _sgt(new_graph); */
/*   /\* _pic(new_graph); // NOK *\/ */
/*   /\* _pie(new_graph); // NOK *\/ */
/*   /\* _pfk(new_graph); // NOK *\/ */
/*   /\* _pdr(new_graph); // NOK *\/ */
/*   /\* _pgt(new_graph); // NOK *\/ */
/*   /\* _pdi(new_graph); // NOK *\/ */
/*   /\* _enw(new_graph); // NOK *\/ */
/*   /\* _eht(new_graph); // NOK *\/ */
/*   /\* _ebo(new_graph); // NOK *\/ */
/*   /\* _edi(new_graph); // NOK *\/ */
/*   /\* _sgt(new_graph); // NOK *\/ */
/*   /\* _sst(new_graph); // NOK *\/ */
/*   /\* _seg(new_graph); // NOK *\/ */
/*   /\* _smg(new_graph); // NOK *\/ */
/*   /\* _suc(new_graph); // NOK *\/ */
/*   /\* _sbp(new_graph); // NOK *\/ */
/* } */

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
