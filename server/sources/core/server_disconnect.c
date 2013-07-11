/*
** server_disconnect.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Jul  8 10:53:15 2013 julien fortin
** Last update Thu Jul 11 16:00:27 2013 julien fortin
*/

#include	"server.h"

#include	<stdio.h>

bool		server_disconnect_player(t_player *player)
{
  if (player)
    player->socket = delete_socket(player->socket);
  return (true);
}

bool		server_kick_player(const t_server *serv, t_player *p)
{
  delete_player(p, serv);
  return (true);
}
