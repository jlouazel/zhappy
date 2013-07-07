/*
** replace.c for lib in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul  7 18:21:41 2013 julien fortin
** Last update Sun Jul  7 18:23:19 2013 julien fortin
*/

char	*replace_char(char *str, char c, char r)
{
  unsigned int	i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] == c)
	str[i] = r;
      i++;
    }
  return (str);
}
