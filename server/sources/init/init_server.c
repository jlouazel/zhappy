/*
** server_init.c for zhappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Wed May 22 03:59:56 2013 julien fortin
** Last update Mon Jul  1 14:54:57 2013 julien fortin
*/

#include	<string.h>
#include	<stdlib.h>
#include	"server.h"
#include	"lib_socket.h"

const t_server	*server_init(t_server *serv, int ac, const char **av)
{
  bzero(serv, sizeof(*serv));
  if (!(serv->io = init_server_io())
      || !(serv->cmd = init_server_cmd())
      || !(serv->options = init_server_options(ac, av))
      || !(serv->socket = new_socket(serv->options->port, NULL, SOCK_SERV))
      || !(serv->game = init_game(serv->options)))
    return (destroy_server(serv));
  return (serv);
}
