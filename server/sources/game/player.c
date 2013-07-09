/*
** player.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jun 28 16:35:27 2013 louaze_j
** Last update Mon Jul  8 12:39:19 2013 julien fortin
*/

#include	<stdlib.h>
#include	"server.h"
#include	"lib_std.h"
#include	"player.h"
#include	"list.h"
#include	"eressources.h"

#include	<stdio.h>

static bool	_player_is_allowed(const t_player *player)
{
  return (player->status != PLAYER_NOT_ALLOWED && player->team);
}

static void	_player_notify(t_player *player, const char *data)
{
  if (!player)
    return ;
  if (player->io && player->io->out)
    player->io->out->push_back((t_list**)&player->io->out, (void*)data);
  else if (player->io)
    ((t_io*)player->io)->out = new_list((void*)data);
}

static void	init_attr(t_player *new_player, const t_socket *socket)
{
  static unsigned int	id = DEFAULT_PID;

  new_player->egg = true;
  new_player->x = 0;
  new_player->y = 0;
  new_player->id = id;
  new_player->level = DEFAULT_LVL;
  new_player->direction = rand() % 4;
  new_player->socket = socket;
  new_player->status = PLAYER_NOT_ALLOWED;
  new_player->io = init_server_io();
  new_player->inventory_tab[FOOD] = 10;
  new_player->is_allowed = &_player_is_allowed;
  new_player->notify = &_player_notify;
  id++;
}

t_player	*create_player(const t_socket *socket)
{
  t_player	*new_player;

  if (!(new_player = xcalloc(1, sizeof(*new_player))))
    return (NULL);
  init_attr(new_player, socket);
  /**/
  printf("Player %u : I'm alive !\n", new_player->id);
  /**/
  return (new_player);
}

void		delete_player(t_player *player, const t_server *server)
{
  (void)server;
  if (player)
    {
      /**/
      printf("Player %u is dead..\n", player->id);
      /**/
      player->socket = delete_socket(player->socket);
      xfree((void**)&player, sizeof(*player));
    }
}
