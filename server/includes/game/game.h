/*
** game.h for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Wed Jun 26 08:50:52 2013 louaze_j
** Last update Fri Jun 28 16:38:35 2013 louaze_j
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
  t_world	*world;
  unsigned int	max_players_by_team;
} t_game;

#endif