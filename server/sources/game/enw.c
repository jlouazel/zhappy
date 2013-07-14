/*
** enw.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sun Jul 14 15:39:08 2013 louaze_j
** Last update Sun Jul 14 15:47:43 2013 louaze_j
*/

#include	<stdio.h>
#include	"player.h"
#include	"lib_std.h"
#include	"egg.h"

const char	*enw(t_player *player, t_egg *egg)
{
  char		*ret;

  if (!player || !egg)
    return ("ko\n");
  if ((ret = xcalloc(420, sizeof(*ret))))
    {
      snprintf(ret, 420, "enw %d %d %d %d\n",
	       egg->id, player->id, player->x, player->y);
      return (ret);
    }
  return ("ko\n");
}
