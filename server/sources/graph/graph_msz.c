/*
** graph_msz.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 00:31:59 2013 julien fortin
** Last update Sun Jul 14 01:10:47 2013 julien fortin
*/

#include	<stdio.h>
#include	"server.h"
#include	"lib_std.h"

const char	*_graph_msz(t_graphical *graph,
			    const t_server *serv,
			    const char *data)
{
  char	*msg;

  (void)data;
  if (!graph || !serv || !serv->game || !serv->game->world)
    return ("ko\n");
  if ((msg = xcalloc(42, sizeof(*msg))))
    {
      snprintf(msg, 42, "msz %d %d\n",
	       serv->game->world->width,
	       serv->game->world->height);
      return (msg);
    }
  return ("ko\n");
}
