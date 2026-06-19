NAME        = unnecessary_violence

CXX         = c++

CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

SRCS        = main.cpp \
			HumanA.cpp \
			HumanB.cpp \
			Weapon.cpp

OBJS        = $(SRCS:.cpp=.o)

INCLUDES    = .

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp HumanA.hpp HumanB.hpp Weapon.hpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re