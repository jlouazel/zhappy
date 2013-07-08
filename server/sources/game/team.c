/*
** team.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Mon Jul  1 09:15:15 2013 louaze_j
** Last update Mon Jul  8 11:12:57 2013 julien fortin
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"lib_std.h"
#include	"team.h"
#include	"list.h"
#include	"player.h"

static void	add_player(t_team *team, t_player *player)
{
  if (player)
    {
      player->status = PLAYER_ALLOWED;
      player->team = team;
      if (team->members == NULL)
	team->members = new_list(player);
      else
	team->members->push_back(&team->members, player);
      team->nb_members++;
    }
}

static void	init_attr(t_team *new_team, char *name)
{
  static unsigned int	id = DEFAULT_TID;

  new_team->id = id;
  new_team->eggs = 1;
  new_team->name = name;
  new_team->members = NULL;
  new_team->nb_members = 0;
  new_team->add_player = &add_player;
  id++;
}

t_team		*create_team(char *name)
{
  t_team	*new_team;

  new_team = xcalloc(1, sizeof(*new_team));
  if (!new_team)
    return (NULL);
  init_attr(new_team, name);
  printf("Team %s : I'm awake !\n", new_team->name);
  return (new_team);
}

void		delete_team(t_team *team)
{
  if (team)
    {
      printf("Team %s is returning home...\n", team->name);
      team = xfree((void**)&team, sizeof(*team));
    }
}
