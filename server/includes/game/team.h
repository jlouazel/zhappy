/*
** team.h for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jun 28 16:36:54 2013 louaze_j
** Last update Sun Jul 14 21:49:31 2013 louaze_j
*/

#ifndef	__TEAMS_H__
#define	__TEAMS_H__

#include "list.h"

typedef struct s_server	t_server;
typedef struct s_player	t_player;

#define	DEFAULT_TID	0

typedef struct s_team
{
  unsigned int	id;
  char		*name;
  t_list	*members;
  t_list	*eggs;
  unsigned int	nb_members;

  bool		(*add_player)(struct s_team *, const t_server *, t_player *);
  void		(*remove_player)(struct s_team *, t_player *);
} t_team;

t_team	*create_team(char *);
void	delete_team(t_team *);

#endif
