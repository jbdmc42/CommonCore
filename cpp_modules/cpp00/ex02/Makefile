NAME        = logs

CXX         = c++

CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

SRCS        = tests.cpp \
			Account.cpp

OBJS        = $(SRCS:.cpp=.o)

INCLUDES    = .

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Contact.hpp PhoneBook.hpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re