/*
** string_len.c for lib in /home/fortin_j/libmy/libmy_c
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Apr  8 16:50:31 2013 julien fortin
** Last update Thu May  2 10:01:44 2013 julien fortin
*/

unsigned int	my_strlen(const char *s)
{
  unsigned int	i;

  i = 0;
  while (s && s[i])
    i++;
  return (i);
}
