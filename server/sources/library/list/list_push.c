/*
** list_push.c for list in /home/fortin_j/
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Jun 25 17:45:37 2013 julien fortin
** Last update Wed Jun 26 19:13:56 2013 julien fortin
*/

#include	"list.h"

static bool	list_push_back(t_list **list, void *data)
{
  t_list	*tmp;
  t_list	*new;

  if (!list || !(new = new_list(data)))
    return (false);
  tmp = *list;
  while (tmp && tmp->next)
    tmp = tmp->next;
  if (!tmp)
    *list = new;
  else
    tmp->next = new;
  return (true);
}

static bool	list_push_front(t_list **list, void *data)
{
  t_list	*new;

  if (!list || !*list)
    return (false);
  if (!(new = new_list(data)))
    return (false);
  new->next = *list;
  *list = new;
  return (true);
}

void		init_list_push(t_list *list)
{
  if (list)
    {
      list->push_back = &list_push_back;
      list->push_front = &list_push_front;
    }
}
