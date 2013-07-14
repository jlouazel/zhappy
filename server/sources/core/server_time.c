/*
** server_time.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 19:55:51 2013 julien fortin
** Last update Sun Jul 14 21:11:04 2013 julien fortin
*/

#include	<time.h>
#include	"lib_errs.h"
#include	"server.h"

unsigned int	get_time_for_action(int action, int t)
{
  if (action < 0.1)
    return (0);
  return (((double)action / (double)t) * 1000.0);
}

unsigned int	get_current_timestamp()
{
  return ((int)time(NULL));
}

unsigned int	get_current_time()
{
  return (get_current_timestamp() * 1000);
}
