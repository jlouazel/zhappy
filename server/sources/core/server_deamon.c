/*
** server_deamon.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 21:27:29 2013 julien fortin
** Last update Sun Jul 14 21:48:25 2013 julien fortin
*/

#include	<math.h>
#include	"server.h"

static void		_launch_deamon(const t_server *serv, int n)
{
  (void)serv;
  (void)n;
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
	  _launch_deamon(serv, 0);
	  last = get_current_timestamp();
	}
    }
}
