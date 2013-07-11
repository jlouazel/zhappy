/*
** server_log.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jul  5 14:17:30 2013 louaze_j
** Last update Thu Jul 11 19:00:53 2013 louaze_j
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"server.h"

void		server_conf(t_server *server)
{
  printf("Configuration : Max(%d) WorldX(%d) WorldY(%d) T(%d)\n",
	 server->options->nb_max_clients,
	 server->options->x,
	 server->options->y,
	 server->options->time);
}

void		log_map(double cnt, double tot)
{
  int		i;
  int		percent;
  static bool	done = false;

  if (done == false)
    {
      printf("Building map: [");
      done = true;
    }
  percent = ((cnt / tot) * 100);
  i = percent;
  while (100 - i != 0)
    {
      printf("#");
      percent--;
    }
}
