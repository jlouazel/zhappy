/*
** pie.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jul 12 20:31:25 2013 louaze_j
** Last update Fri Jul 12 20:36:16 2013 louaze_j
*/

#include	"graphical.h"

#include <stdio.h>

static
const char	*pie(t_graphical *graphical, const t_server *server, void *arg,
		     void *res)
{
  printf("pie % Y R\n");
  return (NULL):
}

void		_pie(t_graphical *graphical)
{
  if (graphical)
    {
      graphical->pie = &pie;
    }
}
