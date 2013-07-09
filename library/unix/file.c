/*
** my_file.c for libelf in /home/fortin_j/tek2/projects/nm-objdump/nmobjdump-2015s-2016-2017si-fortin_j/libmyelf
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Mar 12 17:24:35 2013 julien fortin
** Last update Wed Jun 19 15:47:25 2013 julien fortin
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<sys/mman.h>
#include	"lib_errs.h"

int		get_file_size(int fd)
{
  int		size;

  size = -1;
  if (fd > 0)
    {
      size = lseek(fd, 0, SEEK_END);
      if (size != (off_t)-1)
	return (size);
      perror("lseek");
    }
  else
    my_strerror("get_file_size: invalid file descriptor.\n");
  return (size);
}

int		my_open(const char *file, int flags)
{
  int	fd;

  if ((fd = open(file, flags)) < 0)
    perror("open");
  return (fd);
}
