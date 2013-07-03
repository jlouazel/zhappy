/*
** player.h for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jun 28 16:40:55 2013 louaze_j
** Last update Wed Jul  3 15:08:36 2013 julien fortin
*/

#ifndef __PLAYERS_H__
#define __PLAYERS_H__

#include	"server_data_io.h"
#include	"lib_socket.h"
#include	"list.h"
#include	"world.h"
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
  unsigned int		inventory[7];

  const t_io		*io;
  const t_socket	*socket;

  const char    *(*avance)(struct s_player *, t_world *);
  const char    *(*droite)(struct s_player *);
  const char    *(*gauche)(struct s_player *);
  const char    *(*voir)(struct s_player *, t_world *);
  const char    *(*inventaire)(struct s_player *);
  const char    *(*prend)(struct s_player *, t_world *, void *);
  const char    *(*pose)(struct s_player *);
  const char    *(*expulse)(struct s_player *);
  const char    *(*broadcast)(struct s_player *);
  const char    *(*fork)(struct s_player *);
  const char    *(*connect_nbr)(struct s_player *);
} t_player;

t_player        *create_player(const t_socket *);

void            delete_player(t_player *);

void		_avance(t_player *);
void		_droite(t_player *);
void		_gauche(t_player *);
void		_voir(t_player *);
void		_inventaire(t_player *);
void		_prend(t_player *);

#endif
