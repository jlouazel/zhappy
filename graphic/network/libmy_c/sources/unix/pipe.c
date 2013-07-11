/*
** pipe.c for lib in /home/fortin_j/libmy/libmy_c/sources/unix
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Apr  9 15:35:44 2013 julien fortin
** Last update Tue Apr  9 16:05:54 2013 julien fortin
*/

#include	<stdio.h>
#include	<unistd.h>

int		xpipe(int fd[2])
{
  int	res;

  if ((res = pipe(fd)) < 0)
    perror("pipe");
  return (-1);
}
