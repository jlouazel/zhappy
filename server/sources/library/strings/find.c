/*
** index.c for lib in /home/fortin_j/libmy/libmy_c/sources/strings
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Fri Apr  5 11:26:40 2013 julien fortin
** Last update Wed May  1 00:32:15 2013 julien fortin
*/

int	find_first_of(const char *s, char c)
{
  unsigned int	i;

  i = 0;
  while (s && s[i] && s[i] != c)
    i++;
  if (s && s[i] && s[i] == c)
    return (i);
  return (-1);
}

int     count_match(const char *s, char c)
{
  unsigned int  i;
  unsigned int  count;

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
