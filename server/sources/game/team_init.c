/*
** team_init.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 22:31:34 2013 julien fortin
** Last update Sun Jul 14 22:34:34 2013 julien fortin
*/

#include	"team.h"
#include	"egg.h"
#include	"server.h"

static t_egg    *getFirstEgg(t_team *team)
{
  t_list        *tmp;
  t_egg         *egg;

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

void	_init_player_in_team(t_team *team, t_player *player)
{
  if (team->eggs)
    team->eggs->erase(&team->eggs, getFirstEgg(team));
  player->status = PLAYER_STATUS_ALLOW;
  player->team = team;
  team->nb_members++;
}
