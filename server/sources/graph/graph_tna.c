/*
** graph_msz.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 00:31:59 2013 julien fortin
** Last update Sun Jul 14 10:12:21 2013 louaze_j
*/

#include	"graphical.h"
#include	"server.h"
#include	"lib_strings.h"

const char	*_graph_tna(t_graphical *graph,
			    const t_server *serv,
			    const char *data)
{
  (void)data;
  if (!serv || !graph)
    return ("ko\n");
  return (graph->tna(graph, serv));
}
