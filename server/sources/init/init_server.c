/*
** server_init.c for zhappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Wed May 22 03:59:56 2013 julien fortin
** Last update Thu Jul 11 17:46:00 2013 louaze_j
*/

#include	<stdio.h>
#include	<time.h>
#include	<string.h>
#include	<stdlib.h>
#include	"server.h"
#include	"lib_socket.h"
#include	"log.h"

static bool	log_conf(t_server *server)
{
  t_list	*tmp;

  printf("Configuration : Max(%d) WorldX(%d) WorldY(%d) T(%d)\n",
	 server->options->nb_max_clients,
	 server->options->x,
	 server->options->y,
	 server->options->time);
  printf("Team :\n");
  tmp = server->options->teams_name;
  while (tmp)
    {
      printf("\tName(%s)\n", (char *)tmp->data);
      tmp = tmp->next;
    }
  return (true);
}

const t_server	*server_init(t_server *serv, int ac, const char **av)
{
  srand(time(NULL));
  bzero(serv, sizeof(*serv));
  if (!(serv->io = init_server_io())
      || !(serv->cmd = init_server_cmd())
      || !(serv->options = init_server_options(ac, av))
      || !(log_conf(serv))
      || !(serv->socket = new_socket(serv->options->port, NULL, SOCK_SERV))
      || !(serv->game = init_game(serv->options)))
    return (destroy_server(serv));
  return (serv);
}
