/*
** eggs.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sat Jul 13 18:59:56 2013 louaze_j
** Last update Sun Jul 14 21:06:14 2013 louaze_j
*/

#include	"egg.h"
#include	"team.h"
#include	"lib_std.h"

t_egg		*new_egg(int x, int y)
{
  static int	id = 0;
  t_egg		*egg;

  if (!(egg = xcalloc(1, sizeof(*egg))))
    return (NULL);
  egg->id = id;
  egg->x = x;
  egg->y = y;
  id++;
  return (egg);
}

void		delete_egg(t_egg *egg, t_team *team)
{
  if (team && team->eggs)
    {
      team->eggs->erase(&team->eggs, egg);
    }
}
