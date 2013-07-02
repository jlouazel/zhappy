/*
** ressources.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Mon Jul  1 16:00:00 2013 louaze_j
** Last update Tue Jul  2 10:02:03 2013 louaze_j
*/

#include		"list.h"
#include		"square.h"
#include		"lib_std.h"
#include		"ressources.h"
#include		"str_ressources.h"

static const char	*get_str(t_ressource *ressource)
{
  return (string_ressources[ressource->type]);
}

t_ressource		*create_ressource(e_ressource type, t_square *square)
{
  t_ressource		*new_ressource;

  if (!square)
    return (NULL);
  if (!(new_ressource = xcalloc(1, sizeof(*new_ressource))))
    return (NULL);
  new_ressource->get_str = &get_str;
  new_ressource->type = type;
  if (square->objects)
    square->objects->push_back(&square->objects, new_ressource);
  else
    square->objects = new_list(new_ressource);
  return (new_ressource);
}

void			delete_ressource(t_ressource *ressource)
{
  if (ressource)
    {
      free(ressource);
    }
}
