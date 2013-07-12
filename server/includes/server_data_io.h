/*
** server_data_io.h for zappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Fri Jun 21 16:34:55 2013 julien fortin
** Last update Fri Jul 12 12:26:55 2013 julien fortin
*/

#ifndef	__SERVER_DATA_IO_H__
#define	__SERVER_DATA_IO_H__

#include	"list.h"

#define	GET_CURRENT_TIME(div)	(time(NULL) * div)

typedef struct s_server	t_server;
typedef struct s_player	t_player;

typedef struct	s_data
{
  double	time;
  const char	*data;
  const char	*(*foo)(t_player*, const t_server*, void*);
} t_data;

typedef struct s_io
{
  t_list	*in;
  t_list	*out;
} t_io;

#endif
