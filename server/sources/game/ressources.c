/*
** ressources.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Mon Jul  1 16:00:00 2013 louaze_j
** Last update Tue Jul  2 19:44:50 2013 louaze_j
*/

#include	"eressources.h"
#include	"str_ressources.h"

const char	*get_str(e_ressource type)
{
  return (string_ressources[type]);
}
