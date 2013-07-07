/*
** epur.c for lib in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul  7 16:42:06 2013 julien fortin
** Last update Sun Jul  7 17:25:40 2013 julien fortin
*/

unsigned int		char_match_with(char c, const char *with)
{
  unsigned int	i = 0;

  while (with && with[i])
    {
      if (with[i] == c)
	return (1);
      i++;
    }
  return (0);
}

char		*epur_begin_str(char *str, const char *epur)
{
  unsigned int	i;

  i = 0;
  while (str && str[i] && char_match_with(str[i], epur))
    i++;
  return (str + i);
}
