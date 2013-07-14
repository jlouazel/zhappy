/*
** mct.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Mon Jul  8 16:30:37 2013 louaze_j
** Last update Sun Jul 14 06:52:02 2013 louaze_j
*/

#include	"server.h"
#include	"graphical.h"

static
const char	*mct(t_graphical *graphical, const t_server *server)
{
  unsigned int	x;
  unsigned int	y;

  y = 0;
  while (y != server->game->world->height)
    {
      x = 0;
      while (x != server->game->world->width)
	{
	  graphical->notify(graphical, graphical->bct(server, x, y));
	  x++;
	}
      y++;
    }
  return (NULL);
}

void		_mct(t_graphical *graphical)
{
  if (graphical)
    {
      graphical->mct = &mct;
    }
}
