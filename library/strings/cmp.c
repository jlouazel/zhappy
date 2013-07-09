/*
** cmp.c for lib in /home/fortin_j/libmy/libmy_c
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Apr 14 16:47:15 2013 julien fortin
** Last update Tue Apr 30 18:58:15 2013 julien fortin
*/

int	my_strcmp(const char *s1, const char *s2)
{
  unsigned int	i;

  if (!s1 && !s2)
    return (0);
  i = 0;
  while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
    i++;
  if (s1 && s2)
    return (s1[i] - s2[i]);
  return (-1);
}

int	my_strncmp(const char *s1, const char *s2, int n)
{
  unsigned int	i;

  if (!s1 && !s2)
    return (0);
  if (n <= 0)
    return (-1);
  i = 0;
  while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i] && i < (unsigned int)n)
    i++;
  if (s1 && s2 && i == (unsigned int)n)
    return (0);
  return (-1);
}
