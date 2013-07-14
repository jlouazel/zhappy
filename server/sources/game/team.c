/*
** team.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sun Jul 14 21:40:41 2013 louaze_j
** Last update Sun Jul 14 21:40:42 2013 louaze_j
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<strings.h>
#include	"lib_std.h"
#include	"team.h"
#include	"list.h"
#include	"player.h"
#include	"graphical.h"
#include	"egg.h"

static void	team_remove_player(t_team *team, t_player *player)
{
  if (team && player && team->members &&
      (team->members->erase(&team->members, player)) == true)
    {
      team->nb_members--;
    }
}

static t_egg	*getFirstEgg(t_team *team)
{
  t_list	*tmp;
  t_egg		*egg;

  tmp = team->eggs;
  if (!tmp)
    return (NULL);
  egg = tmp->data;
  while (tmp)
    {
      if (egg->id > ((t_egg *)tmp->data)->id)
	egg = tmp->data;
      tmp = tmp->next;
    }
  return (egg);
}

static bool	team_add_player(t_team *team,
			   const t_server *serv,
			   t_player *player)
{
  char	*msg;

  if (serv && serv->game && serv->game->world && player && team
      && (!team->members || (team->members && team->eggs))
      && _player_connect_nbr_int(serv, team) > 0)
    {
      if (team->eggs)
	team->eggs->erase(&team->eggs, getFirstEgg(team));
      player->status = PLAYER_STATUS_ALLOW;
      player->team = team;
      if (team->members == NULL)
	team->members = new_list(player);
      else
	team->members->push_back(&team->members, player);
      team->nb_members++;
      //msg = xcalloc(12, sizeof(*msg));
      /* snprintf(msg, 12, "%d\n", team->eggs); */
      //player->notify(player, msg);
      if (!(msg = xcalloc(400, sizeof(*msg))))
	{
	  printf("*** [ERR] player %u cannot join team %s\n", player->id, team->name);
	  return (false);
	}
      snprintf(msg, 20, "%d %d\n", serv->game->world->width, serv->game->world->height);
      player->notify(player, msg);
      notify_graph(serv, pnw(player));
      printf("*** [JOIN] player %u join team %s\n", player->id, team->name);
      return (true);
    }
  player->notify(player, "ko\n");
  printf("*** [ERR] player %u cannot join team %s\n", player->id, team->name);
  return (false);
}

static void	init_attr(t_team *new_team, char *name)
{
  static unsigned int	id = DEFAULT_TID;

  new_team->id = id;
  new_team->eggs = NULL;
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

  if (!(new_team = xcalloc(1, sizeof(*new_team))))
    return (NULL);
  init_attr(new_team, name);
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
