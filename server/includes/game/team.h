/*
** team.h for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jun 28 16:36:54 2013 louaze_j
** Last update Mon Jul  1 10:02:16 2013 julien fortin
*/

#ifndef	__TEAMS_H__
#define	__TEAMS_H__

#include "player.h"
#include "list.h"

#define	DEFAULT_TID	0

typedef struct s_team
{
  unsigned int	id;
  char		*name;
  t_list	*members;
  unsigned int	nb_members;

  void		(*add_player)(struct s_team *, t_player *);
} t_team;

t_team	*create_team(char *);
void	delete_team(t_team *);

#endif