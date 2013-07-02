/*
** server_init_cmd.c for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Wed May 22 04:16:18 2013 julien fortin
** Last update Sun Jun 23 21:20:51 2013 julien fortin
*/

#include	<stdlib.h>
#include	"lib_std.h"
#include	"server.h"

const t_cmd	*init_server_cmd()
{
  t_cmd	*cmd;

  if (!(cmd = xcalloc(1, sizeof(*cmd))))
    return (NULL);
  cmd->name[0] = NULL;
  cmd->cmd[0] = NULL;
  return (cmd);
}
