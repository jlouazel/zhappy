/*
** server_data_io.h for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Fri Jun 21 16:34:55 2013 julien fortin
** Last update Fri Jun 21 16:46:22 2013 julien fortin
*/

#ifndef	__SERVER_DATA_IO_H__
#define	__SERVER_DATA_IO_H__

#include	"list.h"

typedef struct s_player	t_player;

typedef struct	s_data
{
  const t_player	*player;
  const char		*data;
} t_data;

typedef struct s_io
{
  t_list	*in;
  t_list	*out;
} t_io;

#endif
