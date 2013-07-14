/*
** graph_msz.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 00:31:59 2013 julien fortin
** Last update Sun Jul 14 10:23:19 2013 julien fortin
*/

#include	"graphical.h"
#include	"server.h"

const char	*_graph_sst(t_graphical *graph,
			    const t_server *server,
			    const char *data)
{
  int	new;

  if (!server || !data || !data[0])
    return ("ko\n");
  new = atoi(data);
  if (new > 0 && new < 10000)
    {
      if (server && server->options)
	{
	  ((t_options*)server->options)->time = new;
	  return (_graph_sgt(graph, server, NULL));
	}
    }
  return ("ko\n");
}
