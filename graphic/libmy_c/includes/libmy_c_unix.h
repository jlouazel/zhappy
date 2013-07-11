/*
** libmy_c_unix.h for lib in /home/fortin_j/libmy/libmy_c
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Apr  9 15:32:03 2013 julien fortin
** Last update Fri Apr 12 11:40:52 2013 julien fortin
*/

#ifndef	__LIBMY_C_UNIX_H__
#define	__LIBMY_C_UNIX_H__

#include	<sys/select.h>
#include	<unistd.h>

int		xpipe(int *);
int		xdup2(int, int);
pid_t		xfork();

struct timeval  *select_timeout(struct timeval *, int, int);
fd_set		*select_fd_set(fd_set *, ...);
int		xselect(int, fd_set *, fd_set *, struct timeval *);

#endif
