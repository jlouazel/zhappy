/*
** server_init_cmd.c for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Wed May 22 04:16:18 2013 julien fortin
** Last update Sat Jul 13 01:43:21 2013 julien fortin
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"lib_std.h"
#include	"server.h"

static void	_init_server_cmd_graph_name(t_cmd_graph *cmd)
{
  cmd->name[0] = NULL;
}

static void	_init_server_cmd_graph_fun(t_cmd_graph *cmd)
{
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
