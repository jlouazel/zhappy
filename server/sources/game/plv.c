/*
** plv.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jul 12 15:00:39 2013 louaze_j
** Last update Sun Jul 14 11:34:36 2013 louaze_j
*/

#include	<stdio.h>
#include	"player.h"
#include	"lib_std.h"

const char	*plv(t_player *player)
{
  char		*ret;

  if (!player)
    return ("ko\n");
  if ((ret = xcalloc(20, sizeof(*ret))))
    {
      snprintf(ret, 20, "plv %d %d\n", player->id, player->level);
      return (ret);
    }
  return ("ko\n");
}
