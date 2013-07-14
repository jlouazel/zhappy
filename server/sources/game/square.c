/*
** square.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jun 28 20:21:32 2013 louaze_j
** Last update Sun Jul 14 21:40:55 2013 louaze_j
*/

#include	<strings.h>
#include	"lib_std.h"
#include	"square.h"

t_square	*new_square(int x, int y)
{
  t_square	*square;

  if (!(square = xcalloc(1, sizeof(*square))))
    return (NULL);
  square->x = x;
  square->y = y;
  bzero(square->content, sizeof(square->content));
  return (square);
}
