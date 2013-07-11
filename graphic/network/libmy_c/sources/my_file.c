/*
** my_file.c for libelf in /home/fortin_j/tek2/projects/nm-objdump/nmobjdump-2015s-2016-2017si-fortin_j/libmyelf
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Mar 12 17:24:35 2013 julien fortin
** Last update Wed Apr  3 22:32:46 2013 julien fortin
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<sys/mman.h>
#include	"libmy_c_errs.h"

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

int		my_open(const char *file)
{
  int	fd;

  if ((fd = open(file, O_RDONLY)) < 0)
    {
      perror("open");
      return (-1);
    }
  return (fd);
}

void		*my_map_file(char *file)
{
  void	*data;
  int	fd;

  if ((fd = my_open(file)) < 0)
    return (NULL);
  data = mmap(NULL, get_file_size(fd), PROT_READ, MAP_SHARED, fd, 0);
  if (data == (void*)-1 || !data || data == MAP_FAILED)
    {
      perror("mmap");
      return (NULL);
    }
  return (data);
}
