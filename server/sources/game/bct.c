/*
** bct.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Mon Jul  8 16:23:31 2013 louaze_j
** Last update Sun Jul 14 21:38:36 2013 louaze_j
*/

#include	<stdio.h>
#include	"square.h"
#include	"server.h"
#include	"eressources.h"
#include	"lib_std.h"

const char	*bct(const t_server *server, int x, int y)
{
  char		*buff;
  t_square	*square;

  if (!server || !server->game || !server->game->world ||
      !server->game->world->map)
    return ("ko\n");
  square =
    server->game->world->map->at(server->game->world->map,
				 POS_LIST(x, y, server->game->world->width));
  if (!square)
    return ("ko\n");
  if ((buff = xcalloc(60, sizeof(*buff))))
    {
      snprintf(buff, 60, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
	       square->content[FOOD],
	       square->content[LINEMATE], square->content[DERAUMERE],
	       square->content[SIBUR], square->content[MENDIANE],
	       square->content[PHIRAS], square->content[THYSTAME]);
      return (buff);
    }
  return ("ko\n");
}
