NAME=ex00
GCC= c++
CFLAGS=-Wall -Werror -Wextra -std=c++98

SRCS=main.cpp classRoom.cpp course.cpp room.cpp secretary.cpp student.cpp professor.cpp

OBJS=${SRCS:.cpp=.o}

.cpp.o:
	$(GCC) $(CFLAGS) -c $< -o $@

ALL: $(NAME)

$(NAME):$(OBJS)
	$(GCC) $(CFLAGS) $^ -o $@


clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean ALL

.PHONY: clean fclean re all
