/*
** bct.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Mon Jul  8 16:23:31 2013 louaze_j
** Last update Mon Jul  8 16:32:27 2013 louaze_j
*/

#include	"server.h"
#include	"graphical.h"

#include	<stdio.h>

static
const char	*bct(t_graphical *graphical, const t_server *server,
		     void *arg1, void *arg2)
{
  int		x;
  int		y;

  (void)graphical;
  (void)server;
  x = *(int *)arg1;
  y = *(int *)arg2;
  printf("bct %d %d\n", x, y);
  return (NULL);
}

void		_bct(t_graphical *graphical)
{
  if (graphical)
    {
      graphical->bct = &bct;
    }
}
