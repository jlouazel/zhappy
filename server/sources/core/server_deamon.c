/*
** server_deamon.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 21:27:29 2013 julien fortin
** Last update Sun Jul 14 23:31:29 2013 louaze_j
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>
#include	"server.h"
#include	"eressources.h"
#include	"graphical.h"

static void		_perimage_de_food(const t_server *serv, int n)
{
  t_player		*player;
  t_list		*list;
  t_list		*tmp;

  list = serv && serv->game ? serv->game->players : NULL;
  while (list)
    {
      tmp = list->next;
      if (list->data)
	{
	  player = (t_player*)list->data;
	  if (player->inventory_tab && player->is_allowed(player))
	    {
	      player->inventory_tab[FOOD] -= n;
	      if (player->inventory_tab[FOOD] <= 0)
		{
		  if (player->socket
		      && player->socket->is_valid((t_socket*)player->socket))
		    player->socket->write(player->socket, "mort\n");
		  delete_player(player, serv);
		}
	    }
	}
      list = tmp;
    }
}

static void		end_game(const t_server *serv)
{
  t_list		*t;
  t_list		*p;
  int			cnt;

  t = serv->game->teams;
  while (t)
    {
      p = ((t_team *)t->data)->members;
      cnt = 0;
      while (p)
	{
	  if (((t_player *)p->data)->level == 8)
	    cnt++;
	  if (cnt == 8)
	    {
	      notify_graph(serv, seg(((t_team *)t->data)->name));
	      exit(EXIT_SUCCESS);
	    }
	  p = p->next;
	}
      t = t->next;
    }
}

static void		_launch_deamon(const t_server *serv, int n)
{
  static int	food = 0;

  food += n;
  if (food >= 126)
    {
      _perimage_de_food(serv, 1);
      food -= 126;
    }
  end_game(serv);
}

void		server_deamon(const t_server *serv)
{
  static unsigned int	last = 0;
  int	n;

  if (!last)
    {
      _launch_deamon(serv, 1);
      last = get_current_timestamp();
    }
  else
    {
      n = abs(last - get_current_timestamp()) * serv->options->time;
      if (n > 0)
	{
	  _launch_deamon(serv, n);
	  last = get_current_timestamp();
	}
    }
}
