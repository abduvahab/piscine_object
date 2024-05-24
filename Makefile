NAME=relation
GCC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98


SRC_PREFIX = ex00/
SRCS=$(wildcard $(addprefix $(SRC_PREFIX), *.cpp))
# SRCS=ex00/main.cpp ex00/Tool.cpp ex00/Worker.cpp ex00/Hammer.cpp ex00/Shovel.cpp
OBJS=${SRCS:.cpp=.o}

.cpp.o:
			$(GCC) $(CFLAGS) -c $< -o $@

all:$(NAME)

$(NAME):$(OBJS)
			$(GCC) $(CFLAGS) $^ -o $@

clean:
			rm -rf $(OBJS)

fclean:clean
			rm -rf $(NAME)

re: fclean all

.PHONY:all re clean fclean 