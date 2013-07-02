/*
** server_data_options.h for zappy in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Jun 24 11:52:16 2013 julien fortin
** Last update Thu Jun 27 16:10:36 2013 louaze_j
*/

#ifndef	__SERVER_DATA_OPTIONS_H__
#define	__SERVER_DATA_OPTIONS_H__

#include	"list.h"

typedef struct	s_options
{
  char		*prog_name;
  unsigned int	port;
  unsigned int	x;
  unsigned int	y;
  unsigned int	time;
  unsigned int	nb_max_clients;
  t_list	*teams_name;
} t_options;

#endif
