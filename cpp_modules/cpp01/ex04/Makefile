NAME        = SedIsBad
TEST_NAME	= generateTests

CXX         = c++

CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

SRCS        = main.cpp
TEST_SRCS	= tests.cpp

OBJS        = $(SRCS:.cpp=.o)
TEST_OBJS	= $(TEST_SRCS:.cpp=.o)

INCLUDES    = .

all: $(NAME) $(TEST_NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(TEST_NAME): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) -o $(TEST_NAME)

%.o: %.cpp SedIsBad.hpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEST_OBJS)
	find . -type f -name "*.replace" -delete

fclean: clean
	rm -f $(NAME) $(TEST_NAME)
	find . -type f -name "*.txt" -delete

re: fclean all

.PHONY: all clean fclean re