/*
** seg.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sun Jul 14 16:11:06 2013 louaze_j
** Last update Sun Jul 14 16:13:21 2013 louaze_j
*/

#include	<stdio.h>
#include	"lib_std.h"
#include	"lib_strings.h"

const char	*seg(const char *team)
{
  char		*ret;

  if (!team)
    return ("ko\n");
  if ((ret = xcalloc(5 + my_strlen(team), sizeof(*ret))))
    {
      snprintf(ret, 5 + my_strlen(team), "eht %s\n", team);
      return (ret);
    }
  return ("ko\n");
}
