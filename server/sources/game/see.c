/*
** see.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Wed Jul  3 18:32:22 2013 louaze_j
** Last update Sat Jul 13 13:07:34 2013 louaze_j
*/

#include	<stdio.h>
#include	"player.h"
#include	"ressources.h"
#include	"rel_positions.h"
#include	"lib_strings.h"

static
const char	*see_player(const t_server *server, int x, int y)
{
  t_list	*tmp;
  char		*ret;

  ret = "";
  tmp = server->game->players;
  while (tmp)
    {
      if (((t_player *)tmp->data)->x == x &&
	  ((t_player *)tmp->data)->y == y)
	ret = my_concat(ret, " player", NULL);
      tmp = tmp->next;
    }
  return (ret);
}

const char	*_player_see(t_player *player, const t_server *server, void *arg)
{
  int		x;
  int		y;
  unsigned int	i;
  t_square	*sq;
  e_ressource	type;
  unsigned int	index;
  char		*ret;

  (void)arg;
  ret = "";
  if (!player->is_allowed(player))
    return (NULL);
  i = 0;
  index = 0;
  while (i <= player->level)
    index += LVL_I(i++);
  i = 0;
  ret = my_concat(ret, "{", NULL);
  while (i < index)
    {
      type = 0;
      x = player->x + vision[player->direction][i][0];
      y = player->y + vision[player->direction][i][1];
      sq = server->game->world->map->at(server->game->world->map,
					POS_LIST(ABS_X(x, server->game->world->width),
						 ABS_Y(y, server->game->world->height), server->game->world->width));
      while (type != EMPTY)
	{
	  if (sq && sq->content[type] != 0)
	    ret = my_concat(ret, " ", get_str(type), NULL);
	  type++;
	}
      ret = my_concat(ret, see_player(server, ABS_X(x, server->game->world->width), ABS_Y(y, server->game->world->height)), NULL);
      if (i != index - 1)
	ret = my_concat(ret, ",", NULL);
      i++;
    }
  ret = my_concat(ret, "}\n", NULL);
  return (ret);
}
