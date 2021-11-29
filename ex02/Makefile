# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 21:06:11 by rotrojan          #+#    #+#              #
#    Updated: 2021/11/29 17:23:48 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = now_we_re_talking

SRCS =	main.cpp	\
		Fixed.cpp

OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)
DEPENDENCIES = $(OBJS:%.o=%.d)

SRCS_DIR = .
OBJS_DIR = .objs
INCLUDES_DIR = .

MAKE = make
MAKEFLAGS += --no-print-directory
CXX = c++
RM = rm -f
MKDIR = mkdir -p
DEBUG = off

CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98 -pedantic
ifeq ($(DEBUG), on)
	CXXFLAGS += -g3#-fsanitize=address
endif
LDFLAGS = $(LIBS:%=-L lib%)
LDLIBS = $(LIBS:%=-l%)

vpath %.cpp $(addprefix $(SRCS_DIR), /. )

all:
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@printf '\nlinking %s\n' '$@'
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)
	@printf '\033[33m%s built\033[0m\n' '$@'

-include $(DEPENDENCIES)
$(OBJS_DIR)/%.o: %.cpp $(OBJS_DIR)/debug$(DEBUG) | $(OBJS_DIR)
	@printf '\r\033[K\033[33mcompiling %s:\033[0m %s' '$(NAME)' '$@'
	@$(CXX) $(CXXFLAGS) $(INCLUDES_DIR:%=-I %) -c $< -o $@

$(OBJS_DIR):
	@$(MKDIR) $@

$(OBJS_DIR)/debug$(DEBUG): | $(OBJS_DIR)
	@$(RM) $(OBJS_DIR)/debug*
	@touch $@
	@printf '%s removed\n' '$(OBJS_DIR)'

clean:
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@printf '%s removed\n' '$(NAME)'

re: fclean all

.PHONY: all clean fclean re
