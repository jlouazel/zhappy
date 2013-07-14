/*
** server_destroy_io.c for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server/sources/destroy
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jun 23 21:12:27 2013 julien fortin
** Last update Sun Jul 14 22:12:57 2013 julien fortin
*/

#include	<stdlib.h>
#include	"server.h"

const t_io	*destroy_server_io(const t_io *io)
{
  if (io)
    {
      delete_list(io->in, NULL);
      delete_list(io->out, NULL);
    }
  return (NULL);
}
