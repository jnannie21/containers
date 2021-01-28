CC = clang++
CFLAGS = -c -g -Wall -Wextra -Werror -std=c++98
MAIN_SOURCES = 	main.cpp list_test.cpp vector_test.cpp reverse_iterator_test.cpp map_test.cpp stack_test.cpp queue_test.cpp
NAME = a.out

OBJECTS = $(MAIN_SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
