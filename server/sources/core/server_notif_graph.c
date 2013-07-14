/*
** server_notif_graph.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Fri Jul 12 23:21:09 2013 julien fortin
** Last update Sun Jul 14 20:09:47 2013 julien fortin
*/

#include	<time.h>
#include	<stdio.h>
#include	"lib_strings.h"
#include	"lib_std.h"
#include	"server.h"
#include	"graphical.h"

bool                    server_will_notify_graph(const t_server *serv,
                                                  fd_set *wfd, int *max_fd)
{
  t_list        *list;
  t_graphical	*graph;

  list = serv && serv->game ? serv->game->graphicals : NULL;
  while (list)
    {
      if (list->data)
        {
	  graph = (t_graphical*)list->data;
          if (graph->io && graph->io->out && graph->socket)
            {
	      FD_SET(graph->socket->_socket, wfd);
              if (*max_fd < graph->socket->_socket)
                *max_fd = graph->socket->_socket;
            }
        }
      list = list->next;
    }
  if (list)
    return (true);
  return false;
}

static void             _notify_foreach_graph(t_graphical *graph)
{
  t_list        *list;
  const char    *data;
  char		*disp;
  unsigned int	i;

  list = graph->io ? graph->io->out : NULL;
  while (list)
    {
      if (list->data)
        {
	  data = (const char*)list->data;
          graph->socket->write(graph->socket, data);
	  i = my_strlen(data);
	  if (i > 0)
	    {
	      disp = my_strndup(data, 0, i - 1);
	      printf("%d:\tSending message \"%s\" to %u\n",
		     get_current_timestamp(),
		     disp,
		     graph->id);
	      xfree((void**)&disp, 0);
	    }
	}
      list = list->next;
    }
}

bool            server_notify_graph(const t_server *serv, fd_set *wfd)
{
  t_list        *list;
  t_graphical	*graph;

  if ((list = serv && serv->game ? serv->game->graphicals : NULL))
    {
      while (list)
        {
          if (list->data)
            {
	      graph = (t_graphical*)list->data;
              if (graph->socket && FD_ISSET(graph->socket->_socket, wfd))
                {
		  _notify_foreach_graph(graph);
                  if (graph->io->out)
                    ((t_io*)graph->io)->out = delete_list(graph->io->out, NULL);
                }
            }
          list = list->next;
        }
    }
  return (true);
}

void		_notify_each_graph(void *data, void *arg)
{
  t_graphical	*graph;
  const char	*msg;

  if (data && arg)
    {
      graph = (t_graphical*)data;
      msg = (const char*)arg;
      if (graph->io)
	{
	  if (graph->io->out)
	    ((t_io*)graph->io)->out->push_back((t_list**)&graph->io->out, (void*)msg);
	  else
	    ((t_io*)graph->io)->out = new_list((void*)msg);
	}
    }
}

bool		notify_graph(const t_server *serv, const char *msg)
{
  t_list	*list;

  if ((list = serv && serv->game ? serv->game->graphicals : NULL))
    {
      list->foreach(list, &_notify_each_graph, (void*)msg);
      return (true);
    }
  return (false);
}
