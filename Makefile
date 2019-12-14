# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/22 17:08:51 by helkhatr          #+#    #+#              #
#    Updated: 2019/12/13 14:16:14 by helkhatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC_P =src/
OPG_P = obgs/
INC = ./include/ft_printf.h

SRC1 = ft_printf.c			\
	  check.c				\
	  ft_atoi.c				\
	  presicion_hex.c 		\
	  presicion_integer.c 	\
	  presicion_u.c 		\
	  presicion.c			\
	  presionpoint_tw.c 	\
	  presionpoint.c 		\
	  print_csmu.c 			\
	  print_x.c 			\
	  print_dip.c 			\
	  get_flage.c 			\
	  presicion_zero.c 		\
	  presion_t.c 			\
	  fun_libft.c 			\
	  presicion_neg.c 		\


SRC = $(addprefix $(SRC_P), $(SRC1))
OBJ = $(addprefix $(OPG_P), $(SRC1:.c=.o))

all : $(NAME)

$(NAME) :$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "\x1B[96mle fichier bainery \x1B[90;0m[\x1B[34;1m $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"
$(OPG_P)%.o: $(SRC_P)%.c
	@mkdir -p $(OPG_P)
	@gcc $(CFLAGS) -c $< -o $@ -I $(INC)
	@echo "\x1B[96mle fichier \x1B[90;0m[\x1B[34;1m $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

clean :
	@rm -rf $(OPG_P)
	@echo "\x1B[96mFile objcs \x1B[90;0m[\x1B[34;1m $(OPG_P) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m\n"

fclean : clean
	@rm $(NAME)
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m $(NAME) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m"

re : fclean all
PHONY: all fclean clean
