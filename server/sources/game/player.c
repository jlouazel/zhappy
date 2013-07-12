/*
** player.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jun 28 16:35:27 2013 louaze_j
<<<<<<< HEAD
** Last update Thu Jul 11 22:41:59 2013 julien fortin
=======
<<<<<<< HEAD
** Last update Mon Jul  8 15:59:01 2013 louaze_j
=======
** Last update Mon Jul  8 12:27:28 2013 julien fortin
>>>>>>> 3066dd62253e7cd3866725ad525c4fc4b08c62ac
>>>>>>> 75dd803e3b04e8e902a6acce42f16617637dddb3
*/

#include	<stdlib.h>
#include	"server.h"
#include	"lib_std.h"
#include	"player.h"
#include	"list.h"
#include	"eressources.h"
#include	<time.h>
#include	<stdio.h>

static bool	_player_is_allowed(const t_player *player)
{
  return (player->status != PLAYER_STATUS_NOT_ALLOW && player->team);
}

static void	_player_notify(t_player *player,
			       const t_server *serv,
			       const char *msg,
			       int t)
{
  t_data	*data;
  unsigned int	div;

  if (!player)
    return ;
  data = xcalloc(1, sizeof(*data));
  data->time = 0.0;
  div = serv && serv->options ? serv->options->time : DEFAULT_TIME;
  if (t > 0 && div > 0)
    data->time = (GET_CURRENT_TIME(div)) + (t / div);
  data->data = msg;
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
  new_player->status = PLAYER_STATUS_NOT_ALLOW;
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
  t_list	*list;

  (void)server;
  if (player)
    {
      /**/
      list = server->game->players;
      if (list)
      	list->erase(&list, player);
      ((t_game*)server->game)->players = list;
      // erase de la liste des joueurs de l'equipe. et rajoute un oeuf au compteur.
      // player->team = player->team->remove_player(player->team, player); renvoi NULL;
      /* list = player->team && player->team->members ? player->team->members : NULL; */
      /* if (list) */
      /* 	list->erase(&list, player); */
      printf("Player %u is dead..\n", player->id);
      /**/
      player->socket = delete_socket(player->socket);
      xfree((void**)&player, sizeof(*player));
    }
}
