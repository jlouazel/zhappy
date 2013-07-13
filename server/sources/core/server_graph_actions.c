/*
** server_graph_actions.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sat Jul 13 01:55:19 2013 julien fortin
** Last update Sat Jul 13 22:28:20 2013 julien fortin
*/

#include	<sys/select.h>
#include	<string.h>
#include	"lib_std.h"
#include	"lib_strings.h"
#include	"graphical.h"

static int      _server_get_cmd_graph_index(const t_cmd_graph *this, const char *cmd)
{
  int           cmd_len;
  int           real_len;
  int           beg_len;
  unsigned int  i;

  i = 0;
  while (cmd && this && this->name && this->name[i]
         && this->cmd && this->cmd[i])
    {
      cmd_len = my_strlen(cmd);
      real_len = my_strlen(this->name[i]);
      beg_len = find_first_of(cmd, ' ');
      if (!strncmp(this->name[i], cmd, real_len)
          && (cmd_len == real_len || beg_len == real_len))
        return (i);
      i++;
    }
  return (-1);
}

static void	_server_treat_actions_for_graph(const t_server *serv,
						t_graphical *graph)
{
  const char	*res;
  t_list	*list;
  int		index;
  int		i;

  if (!serv || !graph || !graph->socket
      || !graph->socket->is_valid(deconst_cast(graph->socket)))
    return ;
  list = server_extract_graph_packet(serv, graph);
    while (list)
      {
	if (list->data)
	  {
	    if ((index = _server_get_cmd_graph_index
		 (serv ? serv->cmd_graph : NULL, (const char*)list->data)) >= 0)
	      {
		i = (i = find_first_of((const char*)list->data, ' ')) >= 0 ? i : 0;
		res = serv->cmd_graph->cmd[index](graph, serv, ((char*)list->data) + i);
		if (res)
		  graph->notify(graph, res);
	      }
	    else
	      graph->notify(graph, "ko\n");
	  }
	list = list->next;
      }
}

bool            server_graph_actions(const t_server *serv, fd_set *rfd)
{
  t_list        *list;
  t_list        *tmp;
  t_graphical      *graph;

  list = serv && serv->game ? serv->game->graphicals : NULL;
  while (list)
    {
      tmp = list->next;
      if (list->data)
        {
	  graph = (t_graphical*)list->data;
          if (graph && graph->socket && FD_ISSET(graph->socket->_socket, rfd))
            _server_treat_actions_for_graph(serv, graph);
        }
      list = tmp;
    }
  return (true);
}
