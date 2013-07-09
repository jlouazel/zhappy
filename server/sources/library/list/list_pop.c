/*
** list_pop.c for list in /home/fortin_j/
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Wed Jun 26 17:32:30 2013 julien fortin
** Last update Sun Jul  7 18:04:55 2013 louaze_j
*/

#include	<stdlib.h>
#include	"lib_std.h"
#include	"list.h"


static void	*list_pop_front(t_list **list)
{
  t_list	*tmp;
  void		*data;

  data = NULL;
  if (list && *list)
    {
      tmp = *list;
      data = (*list)->data;
      *list = (*list)->next;
      tmp = xfree((void**)&tmp, sizeof(*tmp));
    }
  return (data);
}

static void	*list_pop_back(t_list **list)
{
  size_t	size;
  t_list	*tmp;
  void		*data;

  data = NULL;
  if (list && *list)
    {
      size = (*list)->size(*list);
      tmp = (*list)->iterator(*list, size - 1 > 0 ? size - 2 : 0);
      data = tmp->next ? tmp->next->data : tmp->data;
      if (tmp->next)
	tmp->next = xfree((void**)&tmp->next, sizeof(*tmp));
      else
	{
	  tmp = xfree((void**)&tmp, sizeof(*tmp));
	  *list = NULL;
	  list = NULL;
	}
    }
  return (data);
}

static void	*list_erase(t_list **list, void *elem)
{
  t_list	*tmp;
  t_list	*tmp2;

  tmp = *list;
  if (tmp->data == elem)
    return (list_pop_front(list));
  while (tmp && tmp->next)
    {
      if (tmp->next->data == elem)
	{
	  tmp2 = tmp;
	  tmp2->next = tmp2->next->next;
	  tmp = xfree((void**)&tmp, sizeof(*tmp));
	}
      tmp = tmp->next;
    }
  return (*list);
}

void		init_list_pop(t_list *list)
{
  if (list)
    {
      list->pop_front = &list_pop_front;
      list->pop_back = &list_pop_back;
      list->erase = &list_erase;
    }
}
