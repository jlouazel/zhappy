##
## Makefile for zhappy in /home/louaze_j
## 
## Made by louaze_j
## Login   <louaze_j@epitech.net>
## 
## Started on  Tue Jul  9 01:12:19 2013 louaze_j
## Last update Tue Jul  9 02:08:17 2013 louaze_j
##

CC			= g++

RM			= rm -f

CPPFLAGS		+= -W -Wall -Wextra -Werror
CPPFLAGS		+= -I ./includes

LDFLAGS			=

NAME			= graphic
SRCS_DIR		= sources/

SRCS			= $(SRCS_DIR)main.cpp \
			$(SRCS_DIR)World.cpp \
			$(SRCS_DIR)Square.cpp

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
