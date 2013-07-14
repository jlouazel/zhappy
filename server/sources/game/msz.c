/*
** msz.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Mon Jul  8 15:09:51 2013 louaze_j
** Last update Sun Jul 14 11:25:02 2013 louaze_j
*/

#include	"server.h"
#include	"lib_std.h"

#include	<stdio.h>

const char	*msz(const t_server *server)
{
  char		*ret;

  if (!server || !server->game || !server->game->world)
    return ("ko\n");
  if ((ret = xcalloc(42, sizeof(*ret))))
    {
      snprintf(ret, 42, "msz %d %d\n",
	       server->game->world->width, server->game->world->height);
      return (ret);
    }
  return ("ko\n");
}
