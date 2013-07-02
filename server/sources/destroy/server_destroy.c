/*
** server_destroy.c for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jun 23 21:29:57 2013 julien fortin
** Last update Mon Jul  1 12:18:30 2013 julien fortin
*/

#include	<strings.h>
#include	<stdlib.h>
#include	"lib_socket.h"
#include	"server.h"

const t_server	*destroy_server(t_server *serv)
{
  if (serv)
    {
      serv->cmd = destroy_server_cmd(serv->cmd);
      serv->socket = delete_socket(serv->socket);
      //serv->game = destroy_game(serv->game);
      bzero(serv, sizeof(*serv));
    }
  return (NULL);
}
