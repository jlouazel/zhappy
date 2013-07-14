/*
** broadcast.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Wed Jul  3 19:00:15 2013 louaze_j
** Last update Sun Jul 14 05:09:31 2013 louaze_j
*/

#include	<stdlib.h>
#include	<stdbool.h>
#include	"player.h"
#include	"inverted_directions.h"
#include	"str_directions.h"
#include	<stdio.h>
#include	<math.h>

static
double		calc_angle(t_player *s, t_player *d)
{
  double	a;
  double	b;
  double	c;
  double	angle;
  int		x_tmp;
  int		y_tmp;

  x_tmp = s->x;
  /* if (s->y == 0) */
  /*   y_tmp = 1; */
  /* else */
  y_tmp = 0;
  a = sqrt(pow(s->x - d->x, 2) + pow(s->y - d->y, 2));
  b = sqrt(pow(s->x - x_tmp, 2) + pow(s->y - y_tmp, 2));
  c = sqrt(pow(d->x - x_tmp, 2) + pow(d->y - y_tmp, 2));
  angle = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2.0 * a * b));
  return (angle * 180.0 /  M_PI);
}

static
e_direction	get_direction(t_player *src, const t_server *server,
			      t_player *dest)
{
  int		angle;
  e_direction	dir;

  angle = (int)calc_angle(src, dest);
  if ((angle > 315 && angle <= 360) || (angle >= 0 && angle < 45))
    dir = UP;
  else if (angle == 45)
    dir = UP_RIGHT;
  else if (angle > 45 && angle < 135)
    dir = RIGHT;
  else if (angle == 135)
    dir = DOWN_RIGHT;
  else if (angle > 135 && angle < 225)
    dir = DOWN;
  else if (angle == 225)
    dir = DOWN_LEFT;
  else if (angle > 225 && angle < 315)
    dir = LEFT;
  else if (angle == 315)
    dir = UP_LEFT;
  else
    dir = IN;
  if (dir != IN && (abs(src->x - dest->x) > server->game->world->width / 2 ||
		    (abs(src->y - dest->y) > server->game->world->height / 2)))
    return (inverted_directions[dir]);
  return (dir);
}

const char	*_player_broadcast(t_player *player, const t_server *server, void *arg)
{
  if (!player->is_allowed(player))
    return (NULL);
  printf("Player %u receive a broadcast from %s\n", ((t_player *)arg)->id, string_directions[get_direction(player, server,
													   (t_player *)arg)]);
  return ("OK\n");
}
