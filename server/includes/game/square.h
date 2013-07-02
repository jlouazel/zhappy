/*
** square.h for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jun 28 20:14:57 2013 louaze_j
** Last update Sat Jun 29 09:19:26 2013 louaze_j
*/

#ifndef	__SQUARE_H__
#define	__SQUARE_H__

#include	"list.h"

typedef struct	s_square
{
  int		x;
  int		y;
  t_list	*objects;
} t_square;

t_square	*new_square(int, int);

#endif
