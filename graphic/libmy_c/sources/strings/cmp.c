/*
** cmp.c for lib in /home/fortin_j/libmy/libmy_c
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Apr 14 16:47:15 2013 julien fortin
** Last update Sun Apr 14 17:38:26 2013 julien fortin
*/

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;

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
  int	i;

  if (!s1 && !s2)
    return (0);
  i = 0;
  while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i] && i < n)
    i++;
  if (s1 && s2 && i == n)
    return (0);
  return (-1);
}
