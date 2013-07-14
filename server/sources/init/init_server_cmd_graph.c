/*
** server_init_cmd.c for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Wed May 22 04:16:18 2013 julien fortin
** Last update Sun Jul 14 00:37:15 2013 julien fortin
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"lib_std.h"
#include	"server.h"
#include	"graphical.h"

static void	_init_server_cmd_graph_name(t_cmd_graph *cmd)
{
  cmd->name[0] = "msz";
  cmd->name[1] = "bct";
  cmd->name[2] = "mct";
  cmd->name[3] = "tna";
  cmd->name[4] = "ppo";
  cmd->name[5] = "plv";
  cmd->name[6] = "pin";
  cmd->name[7] = "sgt";
  cmd->name[8] = "sst";
  cmd->name[9] = NULL;
}

static void	_init_server_cmd_graph_fun(t_cmd_graph *cmd)
{
  cmd->cmd[0] = &_graph_msz;
  cmd->cmd[1] = &_graph_bct;
  cmd->cmd[2] = &_graph_mct;
  cmd->cmd[3] = &_graph_tna;
  cmd->cmd[4] = &_graph_ppo;
  cmd->cmd[5] = &_graph_plv;
  cmd->cmd[6] = &_graph_pin;
  cmd->cmd[7] = &_graph_sgt;
  cmd->cmd[8] = &_graph_sst;
  cmd->cmd[9] = NULL;
}

const t_cmd_graph	*init_server_cmd_graph()
{
  t_cmd_graph	*cmd;

  if (!(cmd = xcalloc(1, sizeof(*cmd))))
    return (NULL);
  _init_server_cmd_graph_name(cmd);
  _init_server_cmd_graph_fun(cmd);
  return (cmd);
}
