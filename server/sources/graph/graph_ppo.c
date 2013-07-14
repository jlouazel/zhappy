/*
** graph_msz.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 00:31:59 2013 julien fortin
** Last update Sun Jul 14 03:14:36 2013 julien fortin
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"graphical.h"
#include	"server.h"

const char	*_graph_ppo(t_graphical *graph,
			    const t_server *server,
			    const char *data)
{
  if (!server || !data || !data[0])
    return ("ko\n");
  return (graph->ppo(server, atoi(data)));
}
