/*
** server_actions.c for zappy in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Jul  2 14:36:59 2013 julien fortin
** Last update Fri Jul  5 18:09:40 2013 julien fortin
*/

#include	<sys/select.h>
#include	<string.h>
#include	"lib_std.h"
#include	"lib_strings.h"
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

static void	_server_treat_actions_for_player(const t_server *serv,
						 t_player *player)
{
  const char	*data;
  int		index;

  if (player && player->socket
      && player->socket->is_valid(deconst_cast(player->socket)))
    {
      //Extraire tout le contenu de la socket et apres decouper au \n pour voir
      // si ya plusieurs commandes;
      data = player->socket->read(player->socket, 424242);
      printf("[GET:%s:%d] %s<\n", player->socket->_client->_ip, player->socket->_port, data);
      if (serv && serv->cmd &&
	  (index = _server_get_cmd_index(serv && serv->cmd ? serv->cmd : NULL, data)) >= 0)
	if (serv->cmd->cmd[index])
	  if ((data = serv->cmd->cmd[index](serv, data))) //player en param
	    {
	      if (player->io && player->io->out)
		player->io->out->push_back((t_list**)&player->io->out, (void*)data);
	      else if (player->io)
		((t_io*)player->io)->out = new_list((void*)data);
	    }
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
