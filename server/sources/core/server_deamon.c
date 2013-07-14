/*
** server_deamon.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 21:27:29 2013 julien fortin
** Last update Sun Jul 14 22:28:59 2013 louaze_j
*/

#include	<math.h>
#include	"server.h"
#include	"eressources.h"
#include	"graphical.h"
#include <stdio.h>
static void		_launch_deamon(const t_server *serv, int n)
{
  t_list		*l;

  if (serv && serv->game)
    {
      l = serv->game->players;
      while (l && l->data)
	{
	  if (n < (int)((t_player *)l->data)->inventory_tab[FOOD])
	    ((t_player *)l->data)->inventory_tab[FOOD] -= n;
	  else
	    {
	      ((t_player *)l->data)->inventory_tab[FOOD] = 0;
	      notify_graph(serv, pdi(((t_player *)l->data)));
	      /* delete_player(((t_player *)l->data), serv); */
	      /* l->erase(&l, ((t_player *)l->data)); */
	    }
	  l = l->next;
	}
    }
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
