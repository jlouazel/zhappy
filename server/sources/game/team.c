/*
** team.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Mon Jul  1 09:15:15 2013 louaze_j
** Last update Wed Jul 10 22:54:41 2013 julien fortin
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<strings.h>
#include	"lib_std.h"
#include	"team.h"
#include	"list.h"
#include	"player.h"

static void	team_remove_player(t_team *team, t_player *player)
{
  if (team && player && team->members && (team->members->erase(&team->members, player)) == true)
    {
      team->nb_members--;
      team->eggs++;
    }
}

static bool	team_add_player(t_team *team,
			   const t_server *serv,
			   t_player *player)
{
  char	msg[512];

  if (serv && serv->game && serv->game->world && player && team
      && team->eggs > 0)
    {
      team->eggs--;
      player->status = PLAYER_STATUS_ALLOW;
      player->team = team;
      if (team->members == NULL)
	team->members = new_list(player);
      else
	team->members->push_back(&team->members, player);
      team->nb_members++;
      bzero(msg, 512);
      snprintf(msg, 512, "%d\n%d %d\n",
	       team->eggs,
	       serv->game->world->width,
	       serv->game->world->height);
      player->notify(player, msg);
      printf("New player in team: %s\n", team->name);
      return (true);
    }
  return (false);
}

static void	init_attr(t_team *new_team, char *name)
{
  static unsigned int	id = DEFAULT_TID;

  new_team->id = id;
  new_team->eggs = 1;
  new_team->name = name;
  new_team->members = NULL;
  new_team->nb_members = 0;
  new_team->add_player = &team_add_player;
  new_team->remove_player = &team_remove_player;
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
