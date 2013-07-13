/*
** msz.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Mon Jul  8 15:09:51 2013 louaze_j
** Last update Sat Jul 13 22:37:32 2013 julien fortin
*/

#include	"server.h"
#include	"graphical.h"

#include	<stdio.h>

const char	*_graph_msz(t_graphical *graphical, const t_server *server)
{
  (void)graphical;
  printf("msz %d %d\n", server->game->world->width, server->game->world->height);
  return (NULL);
}
