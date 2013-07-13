/*
** server_extract.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Fri Jul 12 12:30:30 2013 julien fortin
** Last update Fri Jul 12 12:37:33 2013 julien fortin
*/

#include	<stdlib.h>
#include	"lib_strings.h"
#include	"server.h"

static t_list		*_server_extract_data_packet(char *data,
						     char *new,
						     t_list *list)
{
  static char   *packet = NULL;
  int           index;

  while (data && (data = epur_begin_str(data, " \t\r"))
         && data[0] && my_strlen(data) > 0)
    {
      if ((index = find_first_of(data, '\n')) < 0)
        {
	  packet = packet ? my_concat(packet, data, NULL) : my_strdup(data);
          data = NULL;
        }
      else
        {
          new = my_strndup(data, 0, index);
          if (packet)
            {
	      new = my_concat(packet, new, NULL);
              packet = NULL;
            }
          (list ? (list->push_back(&list, (void*)new))
           : (void)(list = new_list((void*)new)));
          data = epur_begin_str(data + index, "\n");
        }
    }
  return (list);
}

t_list		*server_extract_packet(t_player *player)
{
  t_list	*list;

  if (!(list = _server_extract_data_packet
	(replace_char(player->socket->read
		      (player->socket, 424242), '\r', ' '), NULL, NULL)))
    server_disconnect_player(player);
  return (list);
}
