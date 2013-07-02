/*
** ressources.h for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Mon Jul  1 15:52:26 2013 louaze_j
** Last update Tue Jul  2 09:59:47 2013 louaze_j
*/

#ifndef	__RESSOURCES_H__
#define	__RESSOURCES_H__

#include	"eressources.h"
#include	"square.h"

typedef struct	s_ressource
{
  e_ressource	type;

  const char	*(*get_str)(struct s_ressource *);
} t_ressource;

t_ressource	*create_ressource(e_ressource, t_square *);

#endif
