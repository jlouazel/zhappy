/*
** server_init_cmd.c for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Wed May 22 04:16:18 2013 julien fortin
<<<<<<< HEAD:server/sources/init/init_server_cmd_player.c
** Last update Sun Jul 14 13:54:53 2013 julien fortin
=======
** Last update Sat Jul 13 16:29:12 2013 louaze_j
>>>>>>> fa0803fdbc5d2dfe3a1bdfa2f0d8230b855f1b46:server/sources/init/init_server_cmd.c
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"lib_std.h"
#include	"player.h"
#include	"server.h"

static void	_init_server_cmd_player_name(t_cmd_player *cmd)
{
  cmd->name[0] = "avance";
  cmd->name[1] = "droite";
  cmd->name[2] = "gauche";
  cmd->name[3] = "voir";
  cmd->name[4] = "inventaire";
  cmd->name[5] = "prend";
  cmd->name[6] = "pose";
  cmd->name[7] = "broadcast";
  cmd->name[8] = "connect_nbr";
  cmd->name[9] = "expulse";
  cmd->name[10] = "fork";
  //cmd->name[11] = "incntation"
  cmd->name[11] = NULL;
}

static void	_init_server_cmd_player_time(t_cmd_player *cmd)
{
  cmd->time[0] = 7.0;
  cmd->time[1] = 7.0;
  cmd->time[2] = 7.0;
  cmd->time[3] = 7.0;
  cmd->time[4] = 1.0;
  cmd->time[5] = 7.0;
  cmd->time[6] = 7.0;
  cmd->time[7] = 7.0;
  cmd->time[8] = 0.0;
  cmd->time[9] = 7.0;
  cmd->time[10] = 42.0;
  cmd->time[11] = 0.0;
  //cmd->name[11] = "incntation"
}

static void	_init_server_cmd_player_fun(t_cmd_player *cmd)
{
  cmd->cmd[0] = &_player_advance;
  cmd->cmd[1] = &_player_right;
  cmd->cmd[2] = &_player_left;
  cmd->cmd[3] = &_player_see;
  cmd->cmd[4] = &_player_inventory;
  cmd->cmd[5] = &_player_take;
  cmd->cmd[6] = &_player_put;
  cmd->cmd[7] = &_player_broadcast;
  cmd->cmd[8] = &_player_connect_nbr;
  cmd->cmd[9] = &_player_deport;
  cmd->cmd[10] = &_player_fork;
  //cmd->name[11] = "incntation"
  cmd->cmd[11] = NULL;
}

const t_cmd_player	*init_server_cmd_player()
{
  t_cmd_player	*cmd;

  if (!(cmd = xcalloc(1, sizeof(*cmd))))
    return (NULL);
  _init_server_cmd_player_name(cmd);
  _init_server_cmd_player_time(cmd);
  _init_server_cmd_player_fun(cmd);
  return (cmd);
}
