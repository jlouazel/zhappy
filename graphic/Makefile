CC          = g++

RM          = rm -f

NAME		= zappyVisu

#CPPFLAGS	+= -W -Wall -Wextra -O2

CPPFLAGS	+= -I ./inc/
CPPFLAGS	+= -I ./network/includes/
CPPFLAGS	+= -I ./network/libmy_c/includes/

CPPFLAGS	+= -I /usr/include/OGRE/
CPPFLAGS	+= -I /usr/include/ois/
CPPFLAGS	+= -O3

LDFLAGS		+= -lOgreMain -lOIS
LDFLAGS	        += -L. ./network/libmy_c/libmy_c.so

SRC_DIR		= src/
SRCNETWORK_DIR	= network/sources/

SRCS		= $(SRC_DIR)BaseApplication.cpp \
		$(SRC_DIR)TutorialApplication.cpp \
		$(SRCNETWORK_DIR)Graphic.cpp \
		$(SRCNETWORK_DIR)Parser.cpp \
		$(SRCNETWORK_DIR)Players.cpp \
		$(SRCNETWORK_DIR)Square.cpp \
		$(SRCNETWORK_DIR)Teams.cpp \
		$(SRCNETWORK_DIR)Treatment.cpp \
		$(SRCNETWORK_DIR)World.cpp \
		$(SRCNETWORK_DIR)Selecter.cpp

OBJS		= $(SRCS:.cpp=.o) \

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean
