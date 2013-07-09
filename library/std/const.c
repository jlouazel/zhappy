/*
** const.c for zhappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Jun  4 03:43:05 2013 julien fortin
** Last update Sun Jun 23 21:07:55 2013 julien fortin
*/

void		*deconst_cast(const void *ptr)
{
  return ((void*)ptr);
}

const void	*const_cast(void *ptr)
{
  return ((const void*)ptr);
}
