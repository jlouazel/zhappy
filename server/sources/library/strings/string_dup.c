/*
** my_strndup.c for libmy in /home/fortin_j/libmy/
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Oct 24 18:19:04 2011 julien fortin
** Last update Wed Jun 19 15:48:21 2013 julien fortin
*/

#include	<stdlib.h>
#include	"lib_std.h"
#include	"lib_strings.h"

char    *my_strdup(const char *src)
{
  char  *str;
  int   len;
  int   i;

  i = 0;
  if (!src)
    return (NULL);
  len = my_strlen(src);
  if (!(str = xcalloc((len + 1), sizeof(*str))))
    return (NULL);
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
  if (!(str = xcalloc((nb_char + 1), sizeof(*str))))
    return (NULL);
  while (str && src && src[i] && i < y)
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
  if (!len || !(str = xcalloc(len + 1, sizeof(*str))))
    return (NULL);
  while (str && str1 != NULL && str1[i])
    {
      str[x] = str1[i];
      x++;
      i++;
    }
  i = 0;
  while (str && str2 != NULL && str2[i])
    {
      str[x] = str2[i];
      x++;
      i++;
    }
  str[x] = '\0';
  return (str);
}
