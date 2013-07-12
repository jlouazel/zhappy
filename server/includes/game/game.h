/*
** game.h for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Wed Jun 26 08:50:52 2013 louaze_j
** Last update Fri Jul 12 23:05:27 2013 julien fortin
*/

#ifndef	__GAME_H__
#define	__GAME_H__

#include "list.h"
#include "team.h"
#include "world.h"

typedef struct s_game
{
  t_list	*connection_queue;
  t_list	*teams;
  t_list	*players;
  t_list	*graphicals;
  t_world	*world;
  unsigned int	max_players_by_team;
} t_game;

#endif
