/*
** graph_msz.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 00:31:59 2013 julien fortin
** Last update Sun Jul 14 14:14:13 2013 julien fortin
*/

#include	"graphical.h"
#include	"server.h"

const char	*_graph_pin(t_graphical *graph,
			    const t_server *server,
			    const char *data)
{
  if (!graph || !server || !data || !data[0])
    return ("suc\n");
  return (graph->pin(graph, server, get_player_for_id(server, atoi(data))));
}
