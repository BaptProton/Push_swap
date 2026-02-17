# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proton <proton@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 16:17:05 by bproton           #+#    #+#              #
#    Updated: 2026/02/17 12:02:07 by proton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
INCDIR = include
OBJDIR = obj

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

CFLAGS += -I$(INCDIR) -I$(LIBFTDIR)

SRC = 	Errors_Check.c push_swap.c list_related.c \
		Sorting.c instruction_sa_sb_ss.c instruction_ra_rb_rr.c \
		instruction_rra_rrb_rrr.c instruction_pa_pb.c \
		sort_helper.c

SRCS = $(addprefix $(SRCDIR)/,$(SRC))
OBJS = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o : $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean : clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re : fclean all

.PHONY: all clean fclean re