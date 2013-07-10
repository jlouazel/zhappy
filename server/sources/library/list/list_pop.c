/*
** list_pop.c for list in /home/fortin_j/
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Wed Jun 26 17:32:30 2013 julien fortin
** Last update Wed Jul 10 10:57:03 2013 julien fortin
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
      tmp = xfree((void**)&tmp, 0);
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
  t_list	*prev;
  t_list	*tmp;
  void		*data;

  if (!list || !*list || !elem)
    return (NULL);
  tmp = *list;
  prev = NULL;
  while (tmp)
    {
      if (tmp->data && tmp->data == elem)
	{
	  data = tmp->next;
	  if (!prev)
	    return (tmp->pop_front(list));
	  prev->next = tmp->next;
	  xfree((void**)&tmp, 0);
	  return (data);
	}
      prev = tmp;
      tmp = tmp->next;
    }
  return (NULL);
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
