/*
** player.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jun 28 16:35:27 2013 louaze_j
** Last update Fri Jul  5 01:36:55 2013 louaze_j
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"server.h"
#include	"lib_std.h"
#include	"player.h"
#include	"list.h"
#include	"eressources.h"

static void	init_attr(t_player *new_player, const t_socket *socket,
			  const t_server *server)
{
  static unsigned int	id = DEFAULT_PID;

  new_player->x = rand() % server->game->world->width;
  new_player->y = rand() % server->game->world->height;
  new_player->id = id;
  new_player->level = DEFAULT_LVL;
  new_player->direction = rand() % 4;
  new_player->socket = socket;
  new_player->status = PLAYER_NOT_ALLOWED;
  new_player->io = init_server_io();
  new_player->inventory_tab[FOOD] = 10;
  id++;
}

static void	init_actions(t_player *new_player)
{
  _advance(new_player);
  _right(new_player);
  _left(new_player);
  _see(new_player);
  _inventory(new_player);
  _take(new_player);
  _put(new_player);
  _broadcast(new_player);
  _connect_nbr(new_player);
  _deport(new_player);
}

t_player	*create_player(const t_socket *socket, const t_server *server)
{
  t_player	*new_player;

  new_player = xcalloc(1, sizeof(*new_player));
  if (!new_player)
    return (NULL);
  init_attr(new_player, socket, server);
  init_actions(new_player);
  /**/
  printf("Player %u : I'm alive !\n", new_player->id);
  /**/
  return (new_player);
}

void		delete_player(t_player *player)
{
  if (player)
    {
      /**/
      printf("Player %u is dead..\n", player->id);
      /**/
      player->socket = delete_socket(player->socket);
      xfree((void**)&player, sizeof(*player));
    }
}
