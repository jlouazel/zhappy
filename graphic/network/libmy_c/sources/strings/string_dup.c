/*
** my_strndup.c for libmy in /home/fortin_j/libmy/
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Oct 24 18:19:04 2011 julien fortin
** Last update Wed Apr 10 16:06:25 2013 julien fortin
*/

#include	<stdlib.h>
#include	"libmy_c_errs.h"
#include	"libmy_c_strings.h"

char    *my_strdup(const char *src)
{
  char  *str;
  int   len;
  int   i;

  i = 0;
  if (!src)
    return (NULL);
  len = my_strlen(src);
  str = xcalloc((len + 1), sizeof(*str));
  while (str && src && src[i])
    {
      str[i] = src[i];
      i++;
    }
  str[i] = '\0';
  return (str);
}

char    *my_strndup(const char *src, int i, int nb_char)
{
  char	*str;
  int	x;
  int	y;

  if (src == NULL || i < 0 || nb_char <= 0)
    return (NULL);
  x = 0;
  y = i + nb_char;
  str = xcalloc((nb_char + 1), sizeof(*str));
  while (src && src[i] && i < y)
    {
      str[x] = src[i];
      x++;
      i++;
    }
  str[x] = '\0';
  return (str);
}

char    *my_strcat(const char *str1, const char *str2)
{
  char  *str;
  int   len;
  int   i;
  int   x;

  i = 0;
  x = 0;
  len = my_strlen(str1) + my_strlen(str2);
  str = xcalloc(len + 1, sizeof(*str));
  while (str1 != NULL && str1[i])
    {
      str[x] = str1[i];
      x++;
      i++;
    }
  i = 0;
  while (str2 != NULL && str2[i])
    {
      str[x] = str2[i];
      x++;
      i++;
    }
  str[x] = '\0';
  return (str);
}
