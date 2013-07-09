##
## Makefile for zhappy in /home/louaze_j
## 
## Made by louaze_j
## Login   <louaze_j@epitech.net>
## 
## Started on  Tue Jul  9 01:12:19 2013 louaze_j
## Last update Tue Jul  9 19:05:12 2013 louaze_j
##

CC			= g++

RM			= rm -f

CPPFLAGS		+= -W -Wall -Wextra -Werror
CPPFLAGS		+= -I ./includes/
CPPFLAGS		+= -I ../server/includes/lib/
CPPFLAGS		+= -L ./libmy_c_.so

LDFLAGS			= -L ./libmy_c_.so

NAME			= graphic
SRCS_DIR		= sources/

SRCS			= $(SRCS_DIR)main.cpp \
			$(SRCS_DIR)World.cpp \
			$(SRCS_DIR)Square.cpp \
			$(SRCS_DIR)Graphic.cpp

OBJS			= $(SRCS:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean
