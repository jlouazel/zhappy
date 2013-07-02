/*
** server_destroy_cmd.c for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jun 23 21:22:23 2013 julien fortin
** Last update Sun Jun 30 23:58:24 2013 julien fortin
*/

#include	<stdlib.h>
#include	"lib_std.h"
#include	"server.h"

const t_cmd	*destroy_server_cmd(const t_cmd *cmd)
{
  cmd = xfree((void **)&cmd, sizeof(*cmd));
  return (NULL);
}
