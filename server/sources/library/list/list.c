/*
** list.c for list in /home/fortin_j/
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Jun 25 17:12:46 2013 julien fortin
** Last update Wed Jul 10 11:45:08 2013 julien fortin
*/

#include	"lib_std.h"
#include	"list_func.h"
#include	"list.h"

static size_t	list_size(const t_list *list)
{
  size_t	i;

  i = 0;
  while (list)
    {
      i++;
      list = list->next;
    }
  return (i);
}

static t_list	*list_iterator(const t_list *list, size_t index)
{
  while (index != 0 && list)
    {
      index--;
      list = list->next;
    }
  return (deconst_cast(list));
}

static void	*list_at(const t_list *list, size_t index)
{
  t_list	*tmp;

  return ((tmp = list_iterator(list, index)) ? tmp->data : NULL);
}

t_list		*new_list(void *data)
{
  t_list	*list;

  if (!(list = xcalloc(1, sizeof(*list))))
    return (NULL);
  list->next = NULL;
  list->data = data;
  list->size = &list_size;
  list->iterator = &list_iterator;
  list->at = &list_at;
  init_list_push(list);
  init_list_pop(list);
  init_list_foreach(list);
  return (list);
}

t_list		*delete_list(t_list *list, void (*foo)(void*))
{
  t_list	*tmp;

  tmp = NULL;
  while (list)
    {
      if (tmp)
	tmp = xfree((void**)&tmp, sizeof(*tmp));
      tmp = list;
      if (foo)
	foo(list->data);
      list = list->next;
    }
  if (tmp)
    tmp = xfree((void**)&tmp, sizeof(*tmp));
  return (NULL);
}
