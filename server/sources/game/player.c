/*
** player.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jun 28 16:35:27 2013 louaze_j
** Last update Wed Jul  3 19:00:36 2013 louaze_j
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"server.h"
#include	"lib_std.h"
#include	"player.h"
#include	"list.h"
#include	"eressources.h"

static void	init_attr(t_player *new_player, const t_socket *socket)
{
  static unsigned int	id = DEFAULT_PID;

  new_player->x = 0;
  new_player->y = 0;
  new_player->id = id;
  new_player->level = DEFAULT_LVL;
  new_player->direction = DOWN;
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
}

t_player	*create_player(const t_socket *socket)
{
  t_player	*new_player;

  new_player = xcalloc(1, sizeof(*new_player));
  if (!new_player)
    return (NULL);
  init_attr(new_player, socket);
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
