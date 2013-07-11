/*
** server_log.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jul  5 14:17:30 2013 louaze_j
** Last update Thu Jul 11 19:20:31 2013 louaze_j
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
  int		percent2;

  printf("\033[32m\rGenerating world : [\033[32m");
  percent = ((cnt / tot) * 100);
  percent2 = percent;
  i = 100 - percent;
  while (percent >= 0)
    {
      printf("\033[32m#\033[0m");
      percent--;
      fflush(NULL);
    }
  while (i > 0)
    {
      printf("\033[31m#\033[0m");
      /* printf(" "); */
      fflush(NULL);
      i--;
    }
  printf("\033[32m] %d%%\033[0m", percent2);
}
