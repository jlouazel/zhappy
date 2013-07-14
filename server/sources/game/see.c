/*
** see.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Wed Jul  3 18:32:22 2013 louaze_j
** Last update Sun Jul 14 21:32:46 2013 louaze_j
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
      if (((t_player *)tmp->data)->team &&
	  ((t_player *)tmp->data)->x == x &&
	  ((t_player *)tmp->data)->y == y)
	ret = my_concat(ret, " joueur", NULL);
      tmp = tmp->next;
    }
  return (ret);
}

static char	*treat(t_square *sq, const t_server *server, int x, int y)
{
  char		*ret;
  e_ressource	type;

  type = 0;
  ret = "";
  while (type != EMPTY)
    {
      if (sq && sq->content[type] != 0)
	ret = my_concat(ret, " ", get_str(type), NULL);
      type++;
    }
  ret = my_concat(ret,
		  see_player(server,
			     ABS_X(x, server->game->world->width),
			     ABS_Y(y, server->game->world->height)), NULL);
  return (ret);
}

static char	*egalize(t_player *player, const t_server *server, int i)
{
  t_square	*sq;
  char		*ret;
  int		x;
  int		y;

  ret = "";
  x = player->x + vision[player->direction][i][0];
  y = player->y + vision[player->direction][i][1];
  sq =
    server->game->world->map->
    at(server->game->
       world->map, POS_LIST(ABS_X(x, server->game->
				  world->width),
			    ABS_Y(y, server->
				  game->world->
				  height),
			    server->game->world->width));
  ret = my_concat(ret, treat(sq, server, x, y), NULL);
  return (ret);
}

const char	*_player_see(t_player *player, const t_server *server,
			     void *arg)
{
  unsigned int	i;
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
      ret = my_concat(ret, egalize(player, server, i), NULL);
      if (i != index - 1)
	ret = my_concat(ret, ",", NULL);
      i++;
    }
  ret = my_concat(ret, "}\n", NULL);
  return (ret);
}
