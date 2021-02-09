CC = clang++
CFLAGS = -c -g -Wall -Wextra -Werror -std=c++98
MAIN_SOURCES = 	main.cpp list_test.cpp vector_test.cpp reverse_iterator_test.cpp map_test.cpp stack_test.cpp queue_test.cpp set_test.cpp
HEADERS =   list/list.hpp list/list_iterator.hpp list/list_node.hpp \
            map/map.hpp map/map_iterator.hpp map/map_node.hpp \
            queue/queue.hpp \
            set/set.hpp set/set_iterator.hpp set/set_node.hpp \
            stack/stack.hpp \
            vector/vector.hpp vector/vector_iterator.hpp
NAME = a.out

OBJECTS = $(MAIN_SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
