/*
** server_init_cmd.c for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Wed May 22 04:16:18 2013 julien fortin
** Last update Sun Jul  7 14:54:54 2013 louaze_j
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"lib_std.h"
#include	"player.h"
#include	"server.h"

const t_cmd	*init_server_cmd()
{
  t_cmd	*cmd;

  printf("Init commands... ");
  if (!(cmd = xcalloc(1, sizeof(*cmd))))
    return (NULL);
  cmd->name[0] = "avance";
  cmd->name[1] = "droite";
  cmd->name[2] = "gauche";
  cmd->name[3] = "voir";
  cmd->name[4] = "inventaire";
  cmd->name[5] = "prend";
  cmd->name[6] = "pose";
  cmd->name[7] = "broadcast";
  cmd->name[8] = "connect_nbr";
  cmd->name[9] = "expluse";
  cmd->name[10] = "fork";
  cmd->name[11] = NULL;
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
  printf("Done\n");
  return (cmd);
}
