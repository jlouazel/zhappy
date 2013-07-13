/*
** init_ig.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Mon Jul  8 15:59:23 2013 louaze_j
** Last update Sat Jul 13 18:31:01 2013 julien fortin
*/

#include	<stdio.h>
#include	"lib_std.h"
#include	"graphical.h"

static void	init_attr(t_graphical *new_graph)
{
  _msz(new_graph); // NOK
  _bct(new_graph); // NOK
  _mct(new_graph); // NOK
  _tna(new_graph); // NOK
  _pnw(new_graph); // NOK
  _ppo(new_graph); // NOK
  _plv(new_graph); // NOK
  _pin(new_graph); // NOK
  _pex(new_graph); // NOK
  _pbc(new_graph); // NOK
  /* _pic(new_graph); // NOK */
  /* _pie(new_graph); // NOK */
  /* _pfk(new_graph); // NOK */
  /* _pdr(new_graph); // NOK */
  /* _pgt(new_graph); // NOK */
  /* _pdi(new_graph); // NOK */
  /* _enw(new_graph); // NOK */
  /* _eht(new_graph); // NOK */
  /* _ebo(new_graph); // NOK */
  /* _edi(new_graph); // NOK */
  /* _sgt(new_graph); // NOK */
  /* _sst(new_graph); // NOK */
  /* _seg(new_graph); // NOK */
  /* _smg(new_graph); // NOK */
  /* _suc(new_graph); // NOK */
  /* _sbp(new_graph); // NOK */
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
  init_attr(new_graph);
  printf("*** New graphic client %d\n", id);
  return (new_graph);
}
