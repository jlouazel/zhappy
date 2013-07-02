/*
** server_init_io.c for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jun 23 20:57:42 2013 julien fortin
** Last update Sun Jun 23 21:08:53 2013 julien fortin
*/

#include	<stdlib.h>
#include	"lib_std.h"
#include	"server.h"

const t_io	*init_server_io()
{
  t_io	*io;

  return (io = xcalloc(1, sizeof(*io)));
}
