/*
** main.c for zhappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Apr 30 16:45:54 2013 julien fortin
** Last update Thu Jun 27 18:28:41 2013 julien fortin
*/

#include	"server.h"

int		main(int ac, const char **av)
{
  t_server	serv;

  return (run(server_init(&serv, ac, av)));
}
