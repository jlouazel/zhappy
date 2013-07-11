/*
** dup.c for lib in /home/fortin_j/libmy/libmy_c/sources/unix
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Apr  9 15:51:56 2013 julien fortin
** Last update Tue Apr  9 16:06:57 2013 julien fortin
*/

#include	<stdio.h>
#include	<unistd.h>

int	xdup2(int old, int new)
{
  int	res;

  if ((res = dup2(old, new)) < 0)
    perror("dup2");
  return (res);
}
