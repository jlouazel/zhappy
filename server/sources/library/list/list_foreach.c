/*
** list_foreach.c for list in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Thu Jun 27 14:59:27 2013 julien fortin
** Last update Thu Jun 27 17:23:20 2013 julien fortin
*/

#include	"list.h"

static void	list_foreach(const t_list *list,
			     t_list_foreach foo,
			     void *arg)
{
  while (list)
    {
      if (foo)
	foo(list->data, arg);
      list = list->next;
    }
}

void		init_list_foreach(t_list *list)
{
  if (list)
    list->foreach = &list_foreach;
}
