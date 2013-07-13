/*
** egg.h for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sat Jul 13 18:21:44 2013 louaze_j
** Last update Sun Jul 14 00:27:32 2013 louaze_j
*/

#ifndef	__EGG_H__
#define	__EGG_H__

#include	"team.h"

typedef struct	s_egg
{
  int		x;
  int		y;
  unsigned int	id;
} t_egg;

t_egg           *new_egg(int, int);
void            delete_egg(t_egg *, t_team *);

#endif
