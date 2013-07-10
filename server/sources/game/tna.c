/*
** tna.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Tue Jul  9 18:20:10 2013 louaze_j
** Last update Tue Jul  9 18:23:06 2013 louaze_j
*/

#include	"server.h"
#include	"graphical.h"

#include	<stdio.h>

static
const char	*tna(t_graphical *graphical, const t_server *server, void *arg)
{
  (void)graphical;
  (void)server;
  (void)arg;
  return (NULL);
}

void		_tna(t_graphical *graphical)
{
  if (graphical)
    {
      graphical->tna = &tna;
    }
}
