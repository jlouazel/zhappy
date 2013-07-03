/*
** square.h for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jun 28 20:14:57 2013 louaze_j
** Last update Tue Jul  2 19:47:53 2013 louaze_j
*/

#ifndef	__SQUARE_H__
#define	__SQUARE_H__

#include	"list.h"
#include	"ressources.h"

typedef struct	s_square
{
  int		x;
  int		y;
  int		content[7];
} t_square;

t_square	*new_square(int, int);

#endif
