/*
** sgt.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sun Jul 14 10:39:37 2013 louaze_j
** Last update Sun Jul 14 16:02:25 2013 louaze_j
*/

#include	<stdio.h>
#include	"server.h"
#include	"lib_std.h"

const char	*sgt(const t_server *serv)
{
  char		*ret;

  if (!serv || !serv->options)
    return ("ko\n");
  if ((ret = xcalloc(20, sizeof(*ret))))
    {
      snprintf(ret, 20, "sgt %d\n", serv->options->time);
      return (ret);
    }
  return ("ko\n");
}
