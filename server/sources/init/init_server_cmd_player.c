/*
** init_server_cmd_player.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sun Jul 14 20:50:50 2013 louaze_j
** Last update Sun Jul 14 20:54:40 2013 louaze_j
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
  cmd->name[11] = "incantation";
  cmd->name[12] = NULL;
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
  cmd->time[11] = 300.0;
  cmd->time[12] = 0.0;
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
  cmd->cmd[11] = NULL;
  cmd->cmd[12] = NULL;
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
