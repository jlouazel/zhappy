/*
** ressources.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Mon Jul  1 16:00:00 2013 louaze_j
** Last update Mon Jul  8 11:13:17 2013 julien fortin
*/

#include	"eressources.h"
#include	"str_ressources.h"

const char	*get_str(e_ressource type)
{
  return (string_ressources[type]);
}
