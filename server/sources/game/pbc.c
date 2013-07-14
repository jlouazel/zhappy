/*
** pbc.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jul 12 17:23:21 2013 louaze_j
** Last update Sun Jul 14 17:20:30 2013 louaze_j
*/

#include	<stdio.h>
#include	"player.h"
#include	"lib_std.h"
#include	"lib_strings.h"

const char	*pbc(t_player *player, const char *msg)
{
  char		*ret;

  if (!player || !msg)
    return ("ko\n");
  if ((ret = xcalloc(20 + my_strlen(msg), sizeof(*ret))))
    {
      snprintf(ret, 20 + my_strlen(msg), "pbc %d %s\n",
	       player->id, msg);
      return (ret);
    }
  return ("ko\n");
}
