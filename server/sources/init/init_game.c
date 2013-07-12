/*
** init_game.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Wed Jun 26 18:35:42 2013 louaze_j
** Last update Fri Jul 12 17:54:43 2013 louaze_j
*/

#include	<stdbool.h>
#include	<stdio.h>
#include	"world.h"
#include	"lib_std.h"
#include	"server.h"
#include	"lib_strings.h"

static bool	check_if_exists(const t_options *options,
				t_list **teams, char *name)
{
  t_list	*tmp;

  tmp = *teams;
  while (tmp)
    {
      if (my_strcmp(((t_team *)tmp->data)->name, name) == 0)
	{
	  fprintf(stderr, "\033[31m%s:\
two teams can't have the same name ('%s')\n\033[0m",
		  options->prog_name, name);
	  return (true);
	}
      tmp = tmp->next;
    }
  return (false);
}

static t_list	*build_teams(const t_options *options)
{
  unsigned int	it;
  t_list	*teams;

  if (!(options->teams_name))
    {
      fprintf(stderr, "\033[31m%s: you must almost have one team\n\033[0m",
	      options->prog_name);
      return (NULL);
    }
  it = 0;
  teams =
    new_list(create_team(options->teams_name->at(options->teams_name, it)));
  while (options->teams_name->at(options->teams_name, ++it))
    {
      if (check_if_exists(options, &teams,
			  (char *)options->teams_name->at
			  (options->teams_name, it)) == true)
	return (false);
      teams->push_back(&teams,
		       create_team(options->teams_name->at
				   (options->teams_name, it)));
    }
  return (teams);
}

const t_game	*init_game(const t_options *options)
{
  t_game	*game;

  if (!(game = xcalloc(1, sizeof(*game))))
    return (NULL);
  game->max_players_by_team = options->nb_max_clients;
  if (!(game->teams = build_teams(options)))
    return (NULL);
  if (!(game->world = new_world(options)))
    return (NULL);
  return (game);
}
