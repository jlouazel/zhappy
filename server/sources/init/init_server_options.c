/*
** server_init_options.c for zappy in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Jun 24 18:24:47 2013 julien fortin
** Last update Wed Jul 10 10:41:55 2013 julien fortin
*/

#include	<stdlib.h>
#include	<stdbool.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	"lib_std.h"
#include	"server.h"
#include	"lib_errs.h"

/*

fprintf(stderr, "usage: %s [[[-p port] -p port] ...] [-x world_x] [-y world_y] [-c max_clients] [-t speed] -n team_name_1 team_name_2 ...\n", av[0]);

*/

static bool	is_empty(char *str, const char **av, int flag)
{
  if (!str || str[0] == '\0')
    {
      fprintf(stderr,
	      "%s: option cannot be empty -- '%c'\n", av[0], flag);
      return (true);
    }
  return (false);
}

static bool	is_an_integer(const char *str, const char **av, int flag)
{
  int	i;

  i = -1;
  if (!str)
    return (false);
  while (str[++i])
    if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
      {
	fprintf(stderr,
		"%s: option must be an integer -- '%c'\n", av[0], flag);
	return (false);
      }
  return (true);
}

static bool	switch_on_cases_othrs(t_options *opts,
				      const char **av, int flag)
{
  if (flag != 'n' && flag != '?')
    {
      if (is_an_integer(optarg, av, flag) == false)
	return (false);
      if (flag == 'p')
	opts->port = atoi(optarg);
      else if (flag == 'x')
	opts->x = atoi(optarg);
      else if (flag == 'y')
	opts->y = atoi(optarg);
      else if (flag == 'c')
	opts->nb_max_clients = atoi(optarg);
      else if (flag == 't')
	opts->time = atoi(optarg);
    }
  return (true);
}

static bool	switch_on_cases(t_options *opts, int flag, const char **av)
{
  int		it;

  if (switch_on_cases_othrs(opts, av, flag) == false)
    return (false);
  if (flag == 'n')
    {
      if (!(opts->teams_name))
	if (!(opts->teams_name = new_list(optarg)))
	  return (false);
      it = 0;
      while (av[optind + it] && av[optind + it][0] != '-')
	{
	  if (is_empty(deconst_cast(av[optind + it]), av, flag) == true)
	    return (false);
	  opts->teams_name->push_back(&opts->teams_name,
				      deconst_cast(av[optind + it]));
	  it++;
	}
    }
  else if (flag == '?')
    return (false);
  if (is_empty(optarg, av, flag) == true)
    return (false);
  return (true);
}

const t_options	*init_server_options(int ac, const char **av)
{
  int		flag;
  t_options	*opts;

  if (!(opts = xcalloc(1, sizeof(*opts))))
    return (NULL);
  if (!(opts->prog_name = xcalloc(strlen(av[0]) + 1,
				  sizeof(*(opts->prog_name)))))
    return (NULL);
  opts->port = ENTRY_PORT;
  opts->x = DEFAULT_X;
  opts->y = DEFAULT_Y;
  opts->prog_name = deconst_cast(av[0]);
  opts->time = DEFAULT_TIME;
  while ((flag = getopt(ac, deconst_cast(av), "p:x:y:n:c:t:")) > 0)
    if (switch_on_cases(opts, flag, av) == false)
      return (NULL);
  return (opts);
}
