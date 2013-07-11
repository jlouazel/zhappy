/*
** string_len.c for lib in /home/fortin_j/libmy/libmy_c
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Apr  8 16:50:31 2013 julien fortin
** Last update Sun Apr 28 20:36:57 2013 julien fortin
*/

int	my_strlen(const char *s)
{
  int	i;

  i = 0;
  while (s && s[i])
    i++;
  return (i);
}

int	count_match(const char *s, char c)
{
  unsigned int	i;
  unsigned int	count;

  i = 0;
  count = 0;
  while (s && s[i])
    {
      if (s[i] == c)
	count++;
      i++;
    }
  return (count);
}
