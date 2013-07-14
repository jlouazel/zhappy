/*
** bct.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Mon Jul  8 16:23:31 2013 louaze_j
** Last update Sun Jul 14 06:49:29 2013 louaze_j
*/

#include	"square.h"
#include	"server.h"
#include	"graphical.h"
#include	"eressources.h"
#include	<stdio.h>

void		_bct(t_graphical *graphical)
{
  if (graphical)
    {
      graphical->bct = &bct;
    }
}
