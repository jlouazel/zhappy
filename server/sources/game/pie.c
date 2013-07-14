/*
** pie.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jul 12 20:31:25 2013 louaze_j
** Last update Sun Jul 14 14:39:41 2013 louaze_j
*/

#include	<stdbool.h>
#include	<stdio.h>
#include	"player.h"
#include	"lib_std.h"

const char	*pie(t_player *player, bool success)
{
  char		*ret;

  if (!player)
    return ("ko\n");
  if ((ret = xcalloc(42, sizeof(*ret))))
    {
      snprintf(ret, 42, "pie %d %d %d\n", player->x, player->y, success);
      return (ret);
    }
  return ("ko\n");
}
