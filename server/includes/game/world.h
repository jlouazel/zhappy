/*
** world.h for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Wed Jun 26 18:37:38 2013 louaze_j
** Last update Tue Jul  2 07:22:56 2013 louaze_j
*/

#ifndef	__WORLD_H__
#define	__WORLD_H__

#define		POS_LIST(x, y, w)	(x + w * y)

#include	"server_data_options.h"

#define		DEFAULT_QTE	10
#define		MIN_RESSOURCE	4

typedef struct	s_world
{
  unsigned int	qte_rs[7];
  unsigned int	width;
  unsigned int	height;
  t_list	*map;
} t_world;

t_world		*new_world(const t_options *);

#endif
