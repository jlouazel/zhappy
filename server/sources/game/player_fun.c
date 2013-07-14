/*
** player_fun.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 09:57:39 2013 julien fortin
** Last update Sun Jul 14 09:59:03 2013 julien fortin
*/

#include	"server.h"

t_player	*get_player_for_id(const t_server *serv, int id)
{
  t_player	*player;
  t_list	*list;

  player = NULL;
  list = serv && serv->game ? serv->game->players : NULL;
  while (list)
    {
      if (list->data && (int)((t_player*)list->data)->id == id)
        player = (t_player*)list->data;
      list = list->next;
    }
  return (player);
}
