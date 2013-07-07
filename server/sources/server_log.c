/*
** server_log.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jul  5 14:17:30 2013 louaze_j
** Last update Sun Jul  7 16:44:56 2013 louaze_j
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"server.h"

void		server_login()
{
  static int	i = 0;

  if (i == 0)
    {
      system("clear");
      printf("Starting server...\n");
    }
  else if (i == 1)
    printf("Server is ready...\n");
  i++;
}

void		log_map(double cnt, double tot)
{
  int		i;
  int		percent;
  static bool	done = false;

  if (done == false)
    {
      printf("\033[%d;%dH", 3, 0);
      printf("Building map: [");
      printf("\033[%d;%dH", 3, 116);
      printf("]\n");
      done = true;
    }
  percent = ((cnt / tot) * 100);
  i = percent;
  while (100 - i != 0)
    {
      printf("\033[%d;%dH", 3, 100 - (i + 16));
      printf("#");
      percent--;
    }
  printf("\033[%d;%dH", 3, 118);
  printf("%d%%\n", percent - 100);
}
