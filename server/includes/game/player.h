/*
** player.h for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jun 28 16:40:55 2013 louaze_j
** Last update Wed Jul  3 19:00:49 2013 louaze_j
*/

#ifndef __PLAYERS_H__
#define __PLAYERS_H__

#include	"server_data_io.h"
#include	"lib_socket.h"
#include	"list.h"
#include	"world.h"
#include	"server.h"
#include	"edirections.h"

#define DEFAULT_PID     0
#define DEFAULT_LVL     1
#define DEFAULT_LIFE    10

#define	PLAYER_ALLOWED		42
#define	PLAYER_NOT_ALLOWED	0

typedef struct  s_player
{
  int			x;
  int			y;
  unsigned int		id;
  unsigned int		level;
  unsigned char		status;
  e_direction		direction;
  unsigned int		inventory_tab[7];

  const t_io		*io;
  const t_socket	*socket;

  const char    *(*advance)(struct s_player *, t_server *, void *);
  const char    *(*right)(struct s_player *, t_server *, void *);
  const char    *(*left)(struct s_player *, t_server *, void *);
  const char    *(*see)(struct s_player *, t_server *, void *);
  const char    *(*inventory)(struct s_player *, t_server *, void *);
  const char    *(*take)(struct s_player *, t_server *, void *);
  const char    *(*put)(struct s_player *, t_server *, void *);
  const char    *(*expulse)(struct s_player *);
  const char    *(*broadcast)(struct s_player *, t_world *, void *);
  const char    *(*fork)(struct s_player *);
  const char    *(*connect_nbr)(struct s_player *);
} t_player;

t_player        *create_player(const t_socket *);

void            delete_player(t_player *);

void		_advance(t_player *);
void		_right(t_player *);
void		_left(t_player *);
void		_see(t_player *);
void		_inventory(t_player *);
void		_take(t_player *);
void		_put(t_player *);
void		_broadcast(t_player *);

#endif
