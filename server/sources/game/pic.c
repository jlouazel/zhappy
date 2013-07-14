/*
** pic.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sun Jul 14 13:50:15 2013 louaze_j
** Last update Sun Jul 14 21:45:03 2013 louaze_j
*/

#include	<stdio.h>
#include	"player.h"
#include	"server.h"
#include	"lib_std.h"
#include	"lib_strings.h"

const char	*pic(t_player *player, const t_server *serv)
{
  t_list	*l;
  unsigned int	id;
  char		*ret;
  char		buff[10];

  if (!player || !serv || !serv->game)
    return ("ko\n");
  l = serv->game->players;
  if (!(ret = xcalloc(6 * l->size(l) + 50, sizeof(*ret))))
    return ("ko\n");
  snprintf(ret, 6 * l->size(l) + 50, "pic %d %d %d",
	   player->x, player->y, player->level);
  while (l && l->data)
    {
      id = ((t_player *)l->data)->id;
      if (id != player->id)
	{
	  sprintf(buff, "%d", id);
	  ret = my_concat(ret, buff, NULL);
	}
      l = l->next;
    }
  return (my_concat(ret, "\n", NULL));
}
