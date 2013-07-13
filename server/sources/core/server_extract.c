/*
** server_extract.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Fri Jul 12 12:30:30 2013 julien fortin
** Last update Sat Jul 13 16:49:01 2013 julien fortin
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#include	"lib_strings.h"
#include	"server.h"
#include	"graphical.h"

static void		_server_log_input(char *from, int id, t_list *list)
{
  while (list)
    {
      if (list->data)
	printf("%d:\tReceived message from %s(%d) \"%s\"\n",
	       (int)GET_CURRENT_TIME(1),
	       from,
	       id,
	       (char*)list->data);
      list = list->next;
    }
}

static t_list		*_server_extract_data_packet(char *data,
						     char *new,
						     t_list *list,
						     char **packet)
{
  int           index;

  while (data && (data = epur_begin_str(data, " \t\r"))
         && data[0] && my_strlen(data) > 0)
    {
      if ((index = find_first_of(data, '\n')) < 0)
        {
	  *packet = *packet ? my_concat(*packet, data, NULL) : my_strdup(data);
          data = NULL;
        }
      else
        {
          new = my_strndup(data, 0, index);
          if (*packet)
            {
	      new = my_concat(*packet, new, NULL);
              *packet = NULL;
            }
          (list ? (list->push_back(&list, (void*)new))
           : (void)(list = new_list((void*)new)));
          data = epur_begin_str(data + index, "\n");
        }
    }
  return (list);
}

t_list		*server_extract_player_packet(t_player *player)
{
  t_list	*list;

  if (!player)
    return (NULL);
  if (!(list = _server_extract_data_packet
	(replace_char(player->socket->read
		      (player->socket, 424242), '\r', ' '),
	 NULL,
	 NULL,
	 &player->packet)))
    server_disconnect_player(player);
  _server_log_input("player", player->id, list);
  return (list);
}

t_list		*server_extract_graph_packet(t_graphical *graph)
{
  t_list	*list;

  if (!graph)
    return (NULL);
  if (!(list = _server_extract_data_packet
	(replace_char(graph->socket->read
		      (graph->socket, 424242), '\r', ' '),
	 NULL,
	 NULL,
	 &graph->packet)))
    server_disconnect_graph(graph);
  _server_log_input("graph", graph->id, list);
  return (list);
}
