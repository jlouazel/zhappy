/*
** server_actions.c for zappy in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Jul  2 14:36:59 2013 julien fortin
** Last update Sun Jul  7 17:18:00 2013 julien fortin
*/

#include	<sys/select.h>
#include	<string.h>
#include	"lib_strings.h"
#include	"lib_std.h"
#include	"server.h"
#include	"player.h"

#include	<stdio.h>

static int	_server_get_cmd_index(const t_cmd *this, const char *cmd)
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

static void	_server_treat_cmd_for_player(const t_server *serv, t_player *player,
					     const char *cmd)
{
  int		index;

  printf("[GET:%s:%d] %s<\n", player->socket->_client->_ip, player->socket->_port, cmd);
  fflush(NULL);
  if (serv && serv->cmd &&
      (index = _server_get_cmd_index(serv && serv->cmd ? serv->cmd : NULL, cmd)) >= 0)
    if (serv->cmd->cmd[index])
      if ((cmd = serv->cmd->cmd[index](player, serv, (void*)cmd))) //player en param
	{
	  if (player->io && player->io->out)
	    player->io->out->push_back((t_list**)&player->io->out, (void*)cmd);
	  else if (player->io)
	    ((t_io*)player->io)->out = new_list((void*)cmd);
	}
}

static t_list	*_server_extract_data_packet(const char *data)
{
  t_list	*list;
  char		*tmp;
  char		*new;
  int		index;

  list = NULL;
  tmp = deconst_cast(data);
  while (tmp && (tmp = epur_begin_str(tmp, " \t")) && tmp[0] && my_strlen(tmp) > 0)
    {
      if ((index = find_first_of(tmp, '\n')) < 0)
	(list ? (list->push_back(&list, (void*)tmp))
	 : (void)(list = new_list((void*)tmp)));
      else
	{
	  new = my_strndup(tmp, 0, index);
	  (list ? (list->push_back(&list, (void*)new))
	   : (void)(list = new_list((void*)new)));
	  tmp = epur_begin_str(tmp + index, "\n");
	}
    }
  // Gerer le cas ou un packet est incomplet (non terminee par un \n,
  // du coup mettre tmp dans une static et attendre le prochain coup pour
  // concatener jusqu'au prochain \n envoye)
  return (list);
}


static void	_server_treat_actions_for_player(const t_server *serv,
						 t_player *player)
{
  t_list	*list;

  if (player && player->socket
      && player->socket->is_valid(deconst_cast(player->socket)))
    {
      list = _server_extract_data_packet(player->socket->read(player->socket, 424242));
      puts("##################+");
      while (list)
	{
	  if (list->data)
	    _server_treat_cmd_for_player(serv, player, (const char*)list->data);
	  list = list->next;
	}
      puts("##################-");
    }
}

bool		server_players_actions(const t_server *serv, fd_set *rfd)
{
  t_list	*list;
  t_player	*player;

  list = serv && serv->game && serv->game->players ? serv->game->players : NULL;
  while (list)
    {
      if (list->data)
	{
	  player = (t_player*)list->data;
	  if (player && player->socket && FD_ISSET(player->socket->_socket, rfd))
	    _server_treat_actions_for_player(serv, player);
	}
      list = list->next;
    }
  return (true);
}
