/*
** server_actions.c for zappy in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
[1;5B]**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Jul  2 14:36:59 2013 julien fortin
** Last update Sun Jul 14 10:33:55 2013 julien fortin
*/

#include	<sys/select.h>
#include	<string.h>
#include	<time.h>
#include	"lib_strings.h"
#include	"lib_std.h"
#include	"server.h"
#include	"player.h"

#include	<stdio.h>

static int	_server_get_cmd_index(const t_cmd_player *this, const char *cmd)
{
  int           cmd_len;
  int           real_len;
  int           beg_len;
  unsigned int  i;

  i = 0;
  while (cmd && this && this->name && this->name[i]
         && this->cmd && this->cmd[i])
    {
      cmd_len = my_strlen(cmd);
      real_len = my_strlen(this->name[i]);
      beg_len = find_first_of(cmd, ' ');
      if (!strncmp(this->name[i], cmd, real_len)
          && (cmd_len == real_len || beg_len == real_len))
        return (i);
      i++;
    }
  return (-1);
}

static void	_server_treat_cmd_for_player(const t_server *serv,
					     t_player *player,
					     char *cmd,
					     fd_set *rfd)
{
  t_data	*data;
  int		index;
  int		i;

  cmd = epur_end_str(epur_begin_str(cmd, " \t\n\r"), " \t\n\r");
  if (player && !player->is_allowed(player))
    {
      puts("TRYAUTH");
      server_get_auth_from_player(serv, player, cmd, rfd);
    }
  else if (((index = _server_get_cmd_index(serv->cmd_player, cmd)) >= 0)
      && serv->cmd_player->cmd[index])
    {
      if (!(data = xcalloc(1, sizeof(*data))))
	{
	  player->notify(player, "ko\n");
	  return ;
	}
      data->time = (GET_CURRENT_TIME(serv->options->time))
	+ (serv->cmd_player->time[index] / serv->options->time);
      data->data = cmd + ((i = find_first_of(cmd, ' ')) > 0 ? i : 0);
      data->foo = serv->cmd_player->cmd[index];
      if (player->io && player->io->in)
	player->io->in->push_back(&((t_io*)player->io)->in, (void*)data);
      else
	((t_io*)player->io)->in = new_list((void*)data);
      // if (elevation etc..)
    }
  else
    player->notify(player, "ko\n");
}

static void	_server_treat_actions_for_player(const t_server *serv,
						 t_player *player,
						 fd_set *rfd)
{
  t_list	*list;
  unsigned int	i;

  if (player && player->socket
      && player->socket->is_valid(deconst_cast(player->socket)))
    {
      list = server_extract_player_packet(player);
      i = 0;
      while (list)
	{
	  if (list->data)
	    {
	      if (i < 10)
		i = player->io->out ? player->io->out->size(player->io->out) : 0;
	      if (i >= 10)
		player->notify(player, "ko\n");
	      else
		_server_treat_cmd_for_player(serv, player, (char*)list->data, rfd);
	      i++;
	    }
	  list = list->next;
	}
    }
}

bool		server_players_actions(const t_server *serv, fd_set *rfd)
{
  t_list	*list;
  t_list	*tmp;
  t_player	*player;

  list = serv && serv->game && serv->game->players ? serv->game->players : NULL;
  while (list)
    {
      tmp = list->next;
      if (list->data)
	{
	  player = (t_player*)list->data;
	  if (player && player->socket && FD_ISSET(player->socket->_socket, rfd))
	    _server_treat_actions_for_player(serv, player, rfd);
	}
      list = tmp;
    }
  return (true);
}
