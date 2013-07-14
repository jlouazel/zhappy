/*
** incantate.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sun Jul 14 05:17:22 2013 louaze_j
** Last update Sun Jul 14 23:17:25 2013 louaze_j
*/

#include	<stdbool.h>
#include	<stdio.h>
#include	"player.h"
#include	"square.h"
#include	"incantation.h"
#include	"eressources.h"
#include	"lib_std.h"
#include	"graphical.h"

static bool	is_same_lvl(t_player *pl, const t_server *server)
{
  unsigned int		indx;
  t_list	*l;

  indx = pl->level;
  l = server->game->players;
  while (l)
    {
      if (((t_player *)l->data)->x == pl->x &&
	  ((t_player *)l->data)->y == pl->y)
	if (((t_player *)l->data)->level != indx)
	  return (false);
      l = l->next;
    }
  return (true);
}

static int	nb_players_on_square(const t_server *server, t_square *sq)
{
  int		cnt;
  t_list	*l;

  cnt = 0;
  l = server->game->players;
  while (l)
    {
      if (((t_player *)l->data)->x == sq->x &&
	  ((t_player *)l->data)->y == sq->y)
	cnt++;
      l = l->next;
    }
  return (cnt);
}

static char	*new_lvl(const t_server *server, t_square *sq, t_player *pl)
{
  char		*ret;
  t_list	*l;


  if ((ret = xcalloc(42, sizeof(*ret))))
    snprintf(ret, 42, "niveau actuel : %d\n", pl->level);
  l = server->game->players;
  notify_graph(server, pie(pl, true));
  while (l)
    {
      if (((t_player *)l->data)->x == sq->x &&
	  ((t_player *)l->data)->y == sq->y)
	{
	  ((t_player *)l->data)->level++;
	  notify_graph(server, plv(((t_player *)l->data)));
	}
      l = l->next;
    }
  notify_graph(server, bct(server, sq->x, sq->y));
  return (ret);
}


const char	*_player_incantation(t_player *player, const t_server *server,
				     void *arg)
{
  t_list	*squares;
  t_square	*sq;

  (void)arg;
  sq = NULL;
  if (!player || !server || !server->game || !server->game->world->map)
    return ("ko\n");
  squares = server->game->world->map;
  while (squares)
    {
      if (((t_square *)squares->data)->x == player->x &&
	  ((t_square *)squares->data)->y == player->y)
	sq = (t_square *)squares->data;
      squares = squares->next;
    }
  if (sq && is_same_lvl(player, server) &&
      nb_players_on_square(server, sq) == incantation_tab[player->level][0] &&
      sq->content[LINEMATE] == incantation_tab[player->level][LINEMATE] &&
      sq->content[DERAUMERE] == incantation_tab[player->level][DERAUMERE] &&
      sq->content[SIBUR] == incantation_tab[player->level][SIBUR] &&
      sq->content[MENDIANE] == incantation_tab[player->level][MENDIANE] &&
      sq->content[PHIRAS] == incantation_tab[player->level][PHIRAS] &&
      sq->content[THYSTAME] == incantation_tab[player->level][THYSTAME])
    return (new_lvl(server, sq, player));
  notify_graph(server, pie(player, false));
  return ("ko\n");
}
