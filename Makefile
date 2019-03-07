##
## EPITECH PROJECT, 2018
## Sans titre(Espace de travail)
## File description:
## 
##

NAME		=	InitDir

DIR			=	sources

SRCS		=	InitDir.cpp
		
INCDIRS 	:= $(addprefix -I,$(shell find headers -type d -print))

CXXFLAGS	+=	-W -Wall -Wextra -g
CXXFLAGS	+=	-std=c++11 -pedantic $(INCDIRS)

ALL_SOURCES = $(SRCS)

LDFLAGS	+=	

LDLIBS	+=

CXX	=	g++

RM	=	rm -f

OBJS	=	$(ALL_SOURCES:.cpp=.o)

SRCS	:=	$(patsubst %,$(DIR)/%,$(SRCS))

%.o: %.cpp
		@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< | tr ' ' '.'
		@$(CXX) -c -o $@ $(CXXFLAGS) $< $(LDFLAGS) $(LDLIBS)

all:$(NAME)

$(NAME):	$(OBJS)
		@$(CXX) $^  -o $(NAME) $(LDFLAGS) $(LDLIBS)
		@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '.'

clean:
		@$(RM) $(OBJS)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJS) | tr ' ' '.'

fclean:		clean
		@$(RM) $(NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.'

re:		fclean all


.PHONY:		all clean fclean re##
