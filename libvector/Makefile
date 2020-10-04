# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/29 13:18:57 by ttamesha          #+#    #+#              #
#    Updated: 2020/09/28 15:09:05 by ttamesha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libvector.a
O_DIR		=	./bin
SRC			:=	color_mult.c color_multn.c color_new.c color_plus.c color_divn.c\
				int_color.c argb_color.c color_average.c filter_sepia.c\
				v_cross.c v_dist.c v_divn.c v_dot.c v_inv.c v_minus.c v_plus.c v_mod.c \
				v_mult.c v_multn.c v_new.c v_normalize.c normal.c check_color_range.c\
				p_trans.c
OBJ			=	$(addprefix $(O_DIR)/, $(SRC:.c=.o))
INCLUDES	=	../Includes/vector.h ../Includes/color.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	@ar rc $@ $?
	@ranlib $@
	@echo "$(NAME) compiled"

$(O_DIR)/%.o: ./*/%.c $(INCLUDES) | $(O_DIR)
	@gcc -Wall -Wextra -Werror -c $< -o $@

$(O_DIR):
	@mkdir $(O_DIR)

clean:
	@rm -rf $(O_DIR)
	@echo "$(NAME) object files deleted"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) deleted"

re: fclean all
