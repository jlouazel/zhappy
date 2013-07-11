/*
** fork.c for lib in /home/fortin_j/libmy/libmy_c/sources/unix
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Apr  9 16:04:14 2013 julien fortin
** Last update Tue Apr  9 18:00:05 2013 julien fortin
*/

#include	<stdio.h>
#include	<unistd.h>

pid_t	xfork()
{
  pid_t	pid;

  if ((pid = fork()) < 0)
    perror("fork");
  return (pid);
}
