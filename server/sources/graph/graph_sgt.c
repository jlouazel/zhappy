/*
** graph_msz.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 00:31:59 2013 julien fortin
** Last update Sun Jul 14 10:17:52 2013 julien fortin
*/

#include	<stdio.h>
#include	"lib_std.h"
#include	"server.h"

const char	*_graph_sgt(t_graphical *graph,
			    const t_server *server,
			    const char *data)
{
  char	*res;

  (void)graph;
  (void)data;
  if (!server)
    return ("ko\n");
  if ((res = xcalloc(42, sizeof(*res))))
    {
      if (server->options)
	snprintf(res, 42, "sgt %d\n", server->options->time);
      else
	res = "ko\n";
      return (res);
    }
  return ("ko\n");
}
