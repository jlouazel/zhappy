/*
** list.h for list in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Jun 25 17:02:03 2013 julien fortin
** Last update Wed Jul 10 22:43:30 2013 julien fortin
*/

#ifndef	__STDLIST_H__
#define	__STDLIST_H__

#include	<stdlib.h>
#include	<stdbool.h>

typedef void (*t_list_foreach)(void*, void*);

typedef struct	s_list
{
  struct s_list	*next;
  void		*data;

  struct s_list	*(*iterator)(const struct s_list*, size_t);
  bool		(*erase)(struct s_list**, void *);
  void		(*foreach)(const struct s_list*, t_list_foreach, void*);
  void		*(*at)(const struct s_list*, size_t);
  void		*(*pop_front)(struct s_list**);
  void		*(*pop_back)(struct s_list**);
  bool		(*push_back)(struct s_list**, void*);
  bool		(*push_front)(struct s_list**, void*);
  size_t	(*size)(const struct s_list*);
} t_list;

t_list		*new_list(void*);
t_list		*delete_list(t_list*, void (*)(void*));

#endif
