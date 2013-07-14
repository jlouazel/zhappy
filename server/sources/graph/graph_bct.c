/*
** graph_msz.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 00:31:59 2013 julien fortin
** Last update Sun Jul 14 11:27:15 2013 louaze_j
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"graphical.h"
#include	"lib_std.h"
#include	"server.h"

const char	*_graph_bct(t_graphical *graph,
			    const t_server *serv,
			    const char *data)
{
  char	*tok;
  int	x;
  int	y;

  if (!graph || !serv || !data || !data[0])
    return ("ko\n");
  x = -1;
  y = -1;
  tok = strtok(deconst_cast(data), " \t");
  while (tok && (x < 0 || y < 0))
    {
      if (x < 0)
	x = atoi(tok);
      else if (y < 0)
	y = atoi(tok);
      tok = strtok(NULL, " \t");
    }
  if (x >= 0 && y >= 0)
    return ((bct(serv, x, y)));
  return ("ko\n");
}
