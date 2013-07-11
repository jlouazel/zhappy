/*
** select.c for lib in /home/fortin_j/libmy/libmy_c
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Fri Apr 12 10:01:06 2013 julien fortin
** Last update Sat Apr 13 20:26:32 2013 julien fortin
*/

#include	<stdlib.h>
#include	<stdarg.h>
#include	<strings.h>
#include	<sys/select.h>
#include	"libmy_c_errs.h"

struct timeval	*select_timeout(struct timeval *t, int sec, int usec)
{
  if (t)
    {
      bzero(t, sizeof(*t));
      t->tv_sec = sec;
      t->tv_usec = usec;
    }
  return (t);
}

fd_set		*select_fd_set(fd_set *set, ...)
{
  va_list	ap;
  int		fd;

  if (set)
    {
      va_start(ap, set);
      FD_ZERO(set);
      while ((fd = va_arg(ap, int)) >= 0)
	FD_SET(fd, set);
    }
  return (set);
}

int		xselect(int mfd, fd_set *rfd, fd_set *wfd, struct timeval *t)
{
  int	res;

  if ((res = select(mfd, rfd, wfd, NULL, t)) < 0)
    return (my_perror("select") ? -1 : -1);
  return (res);
}
