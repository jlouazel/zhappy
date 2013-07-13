/*
** server_init_cmd.c for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Wed May 22 04:16:18 2013 julien fortin
** Last update Sat Jul 13 23:04:41 2013 julien fortin
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"lib_std.h"
#include	"server.h"

static void	_init_server_cmd_graph_name(t_cmd_graph *cmd)
{
  /* cmd->name[0] = "msz"; */
  /* cmd->name[1] = "bct"; */
  /* cmd->name[2] = "mct"; */
  /* cmd->name[3] = "tna"; */
  /* cmd->name[4] = "pnw"; */
  /* cmd->name[5] = "ppo"; */
  /* cmd->name[6] = "plv"; */
  /* cmd->name[7] = "pin"; */
  /* cmd->name[8] = "pex"; */
  /* cmd->name[9] = "pbc"; */
  /* cmd->name[10] = */
  cmd->name[0] = NULL;
}

static void	_init_server_cmd_graph_fun(t_cmd_graph *cmd)
{
  /* cmd->cmd[0] = &_graph_msz; */
  /* cmd->cmd[1] = &_graph_bct; */
  /* cmd->cmd[2] = &_graph_mct; */
  /* cmd->cmd[3] = &_graph_tna; */
  /* cmd->cmd[4] = &_graph_pnw; */
  /* cmd->cmd[5] = &_graph_ppo; */
  /* cmd->cmd[6] = &_graph_plv; */
  /* cmd->cmd[7] = &_graph_pin; */
  /* cmd->cmd[8] = &_graph_pex; */
  /* cmd->cmd[9] = &_graph_pbc; */
  cmd->cmd[0] = NULL;
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
