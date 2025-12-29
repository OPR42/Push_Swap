# Banner
BANNERSTAMP	= .banner_shown

# Sources
SRCS_DIR	= sources/
SRC			= push_swap.c \
			  push_swap_algo_choice.c \
			  push_swap_generic_helpers.c \
			  push_swap_chainlist_helpers.c \
			  push_swap_instructions_set1.c \
			  push_swap_instructions_set2.c \
			  push_swap_instructions_set3.c \
			  push_swap_algo_simple.c \
			  push_swap_algo_complex.c \
			  push_swap_bench.c \
			  push_swap_bench_helpers.c \
			  push_swap_benchview.c \
			  push_swap_benchview_helpers1.c \
			  push_swap_benchview_helpers2.c \
			  push_swap_anim_helpers1.c \
			  push_swap_anim_sx.c \
			  push_swap_anim_sx_helpers.c \
			  push_swap_anim_px.c \
			  push_swap_anim_px_helpers.c \
			  push_swap_anim_ra.c \
			  push_swap_anim_rb.c \
			  push_swap_anim_rr.c \
			  push_swap_anim_rx_helpers.c

SRCS		= $(addprefix ${SRCS_DIR}, ${SRC})

# Object
OBJS_DIR	= objects/
OBJS		= $(addprefix ${OBJS_DIR}, ${SRC:.c=.o})

NAME		= push_swap
RM			= rm -f
INCLUDE		= -I includes/
CFLAGS		= -Wall -Wextra -Werror ${INCLUDE} -g3
CC			= cc

#Colors
LIGHT_GRAY	= \033[2m
ORANGE		= \033[1;33m
DARK_GRAY	= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m
RESET		= \033[0m

#Forme
BOLD		= \033[1m
ITALIC		= \033[3m
UNDERLINE	= \033[4m
CROSS		= \033[9m
FLASH		= \033[5m
NEGATIVE	= \033[7m


all:			${BANNERSTAMP} ${NAME}

${BANNERSTAMP}:
				@clear
				@echo "\n${ORANGE} #============================================================================#  ${RESET}"
				@echo "${ORANGE} #${MAGENTA}              ____             __         _____                             ${ORANGE}#  ${RESET}"
				@echo "${ORANGE} #${MAGENTA}             / __ \__  _______/ /_       / ___/      ______ _____           ${ORANGE}#  ${RESET}"
				@echo "${ORANGE} #${MAGENTA}            / /_/ / / / / ___/ __ \      \__ \ | /| / / __ '/ __ \          ${ORANGE}#  ${RESET}"
				@echo "${ORANGE} #${MAGENTA}           / ____/ /_/ (__  ) / / /     ___/ / |/ |/ / /_/ / /_/ /          ${ORANGE}#  ${RESET}"
				@echo "${ORANGE} #${MAGENTA}          /_/    \__,_/____/_/ /_/_____/____/|__/|__/\__,_/ .___/           ${ORANGE}#  ${RESET}"
				@echo "${ORANGE} #${MAGENTA}                                /______/                 /_/                ${ORANGE}#  ${RESET}"
				@echo "${ORANGE} #                                                                            #  ${RESET}"
				@echo "${ORANGE} #                        ${CYAN}42${ORANGE} - ${MAGENTA}orobert ${ORANGE}& ${MAGENTA}jreibel${ORANGE} - ${CYAN}2025${ORANGE}                       #  ${RESET}"
				@echo "${ORANGE} #============================================================================# \n${RESET}"


${OBJS_DIR}%.o: ${SRCS_DIR}%.c | ${OBJS_DIR}
				@mkdir -p $(dir $@)
				@${CC} ${CFLAGS} -c $< -o $@

${NAME}:		${OBJS}
				@${CC} ${CFLAGS} ${OBJS} -o $@
				@echo "                    ⏳ ${MAGENTA}$@${RESET} compilation  ${BLUE}in progress${RESET} ⏳\n"
				@echo "                      ✅ ${MAGENTA}$@${RESET} compilation ${GREEN}complete${RESET} ✅\n"

${OBJS_DIR}:
				@mkdir -p ${OBJS_DIR}

clean:			${BANNERSTAMP}
				@${RM} ${OBJS}
				@${RM} -r ${OBJS_DIR}
				@echo "                        🧹 ${MAGENTA}${NAME}${RESET} objects  ${RED}deleted${RESET} 🧹\n"

fclean:			${BANNERSTAMP} clean
				@${RM} ${NAME}
				@echo "                   💥 ${MAGENTA}${NAME}${RESET} /objects directory ${RED}removed${RESET} 💥\n"

launchtest:		${BANNERSTAMP}
				@echo "                        🚀 ${MAGENTA}${NAME}${RESET} project ${CYAN}launched${RESET} 🚀\n"
				@./${NAME} --simple --benchview -4316 6051 -3855 1234 4993 -6079 -251 -6688 6486 -4926 -7353 -21474836 7300 -8071 4544 6969 3798 -6628 -8307 -5949 111 6917 -739 163 -8707 -3968 8717 754 -810 2599 -5457 6661 2562 -9712 -1599 2383 7645 9189 -2764 3094 7785 -321 1864 -6024 -1436 4579 -6252 3877 2147483647 3078 -7042 7471 77 2797 -1559 3946 -5878 691 6253 -1391 -7000 5982 350 -8110 9485 -4295 7702 -456 419 2950 9748 -3017 3217 -1723 -8180 -6511 -5452 4955 9171 -8259 3527 5191 -473 -713 1602 -8851 -2519 8733 0 -8233 7724 5871 8363 -7530 7599 -3153 942 9061 -1827 995
#				@./${NAME} 2147483642 1 --complex 2 4 5 --benchview 0 1337 -42 421337 -892 -2147483648 +2147483647 123 456 789 1234 85 96 74 41 52 63 12 23 45 56 123456 456789 5612 35978 1649
#				@./${NAME} --simple --benchview -4316 6051 -3855 1234 4993 -6079 -251 -6688 6486 -4926 -7353 -21474836 7300 -8071 4544 6969 3798 -6628 -8307 -5949 111 6917 -739 163 -8707 -3968 8717 754 -810 2599 -5457 6661 2562 -9712 -1599 2383 7645 9189 -2764 3094 7785 -321 1864 -6024 -1436 4579 -6252 3877 2147483647 3078 -7042 7471 77 2797 -1559 3946 -5878 691 6253 -1391 -7000 5982 350 -8110 9485 -4295 7702 -456 419 2950 9748 -3017 3217 -1723 -8180 -6511 -5452 4955 9171 -8259 3527 5191 -473 -713 1602 -8851 -2519 8733 0 -8233 7724 5871 8363 -7530 7599 -3153 942 9061 -1827 995
#				@./${NAME} --simple --benchview -4316 6051 -3855 1234 4993 -6079 -251 -6688 6486 -4926 -7353 -21474836 7300 -8071 4544 6969 3798 -6628 -8307 -5949 111 6917 -739 163 -8707 -3968 8717 754 -810 2599 -5457 6661 2562 -9712 -1599 2383 7645 9189 -2764 3094 7785 -321 1864 -6024 -1436 4579 -6252 3877 2147483647 3078 -7042 7471 77 2797 -1559 3946 -5878 691 6253 -1391 -7000 5982 350 -8110 9485 -4295 7702 -456 419 2950 9748 -3017 3217 -1723 -8180 -6511 -5452 4955 9171 -8259 3527 5191 -473 -713 1602 -8851 -2519 8733 0 -8233 7724 5871 8363 -7530 7599 -3153 942 9061 -1827 995
#				@./${NAME} --benchview --simple 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
#				@./${NAME} --benchview --simple 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
#				@./${NAME} 1 --simple 2 4 5 --benchview 0 1337 -42 421337 -892 -2147483648 +2147483647 123 456 789 1234 85 96 74 41 52 63 12 23 45 56 123456
#				@./${NAME} 1 --adaptative 2 4 5 --benchview 0 3 6 9 7 8
#				@./${NAME} --simple 9 0 8 1 7 2 6 3 5 4

re:				${BANNERSTAMP} fclean all

retest:			${BANNERSTAMP} fclean all launchtest

.PHONY:			all clean fclean re launchtest
