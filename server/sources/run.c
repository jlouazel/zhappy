/*
** run.c for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server/sources
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Thu May  2 15:47:52 2013 julien fortin
** Last update Tue Jun 25 17:34:03 2013 julien fortin
*/

#include	<stdlib.h>
#include	"lib_std.h"
#include	"server.h"

static int	staying_alive(int res)
{
  if (res == EXIT_SUCCESS)
    return (1);
  return (0);
}

int	run(const t_server *server)
{
  int	res;

  if (server && server->socket
      && server->socket->is_valid(deconst_cast(server->socket)))
    {
      res = EXIT_SUCCESS;
      while (staying_alive(res))
	res = server_loop(server);
    }
  return (server ? EXIT_SUCCESS : EXIT_FAILURE);
}
