/*
** rel_directions.h for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sun Jul 14 03:09:18 2013 louaze_j
** Last update Sun Jul 14 05:25:31 2013 louaze_j
*/

#ifndef	__REL_DIRECTIONS_H__
#define	__REL_DIRECTIONS_H__

static const int	dirs_tab[4][9] =
  {
    { // UP
      1,
      7,
      5,
      3,
      4,
      6,
      2,
      8,
      0
    },
    { // RIGHT
      3,
      1,
      7,
      5,
      6,
      8,
      4,
      2,
      0
    },
    { // DOWN
      5,
      3,
      1,
      7,
      8,
      2,
      6,
      4,
      0
    },
    { // LEFT
      7,
      5,
      3,
      1,
      8,
      4,
      2,
      6,
      0
    }
  };

#endif
