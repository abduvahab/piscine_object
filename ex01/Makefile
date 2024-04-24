NAME=graphic
GCC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++98

SRCS=main.cpp Graphic.cpp Vector2.cpp
OBJS=${SRCS:.cpp=.o}

.cpp.o:
			$(GCC) $(CFLAGS) -c $< -o $@ 

all:$(NAME)

$(NAME):$(OBJS)
			$(GCC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -rf $(OBJS)

fclean:clean
		rm -rf $(NAME)
re: fclean all

.PHONY: all re clean fclean 