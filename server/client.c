/*
** client.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul  7 16:05:19 2013 julien fortin
** Last update Fri Jul 12 19:37:24 2013 julien fortin
*/

#include	<strings.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"lib_std.h"
#include	"lib_socket.h"

int	main(int ac, const char **av)
{
  int	r;
  char	buff[4242];
  const t_socket	*socket;

  if (ac != 2)
    return puts("Not enought arg.");
  socket = new_socket(atoi(av[1]), "localhost", SOCK_CLIENT);
  if (socket && socket->is_valid(deconst_cast(socket)))
    {
      bzero(buff, 4242);
      while ((r = read(0, buff, 4242)) > 0)
	{
	  socket->write(socket, buff);
	  bzero(buff, 4242);
	}
    }
  return 0;
}
