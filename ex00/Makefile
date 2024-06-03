NAME=car
GCC=c++
CFLAGS= -Wall -Werror -Wextra -std=c++98


SRCS=main.cpp
OBJS=${SRCS:.cpp=.o}

.cpp.o:
	$(GCC) $(CFLAGS) -c $< -o $@

all:$(NAME)

$(NAME) : $(OBJS)
	$(GCC) $(CFLAGS)  $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)


re :clean fclean all

.PHONY: all re clean fclean re