# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/22 17:08:51 by helkhatr          #+#    #+#              #
#    Updated: 2019/12/12 21:57:14 by helkhatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC_P =src/

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
	  print_x.c 			\
	  get_flage.c 			\
	  presicion_zero.c 		\
	  presion_t.c 			\
	  fun_libft.c 			\
	  presicion_neg.c 		\


all : $(NAME)

SRC = $(addprefix $(SRC_P), $(SRC1))
OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ) ./include/ft_printf.h
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	@rm -rf $(OBJ)
	@echo "\x1B[96mles ficher \x1B[90;0m[\x1B[34;1m $(OBJ) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m\n"

fclean : clean
	@rm -rf $(NAME)
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m $(NAME) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m"

re : fclean all

