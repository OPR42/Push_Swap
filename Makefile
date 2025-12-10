# Sources
SRCS_DIR	= sources/
SRC			= push_swap.c \
			  push_swap_algochoice.c \
			  push_swap_generic_helpers.c \
			  push_swap_chainlist_helpers.c

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


all:			${NAME}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c | ${OBJS_DIR}
				@mkdir -p $(dir $@)
				@${CC} ${CFLAGS} -c $< -o $@

${NAME}:		${OBJS}
				@echo "\n${ORANGE} #============================================================================# ${RESET}"
				@echo "${ORANGE} #${MAGENTA}              ____             __         _____                             ${ORANGE}# ${RESET}"
				@echo "${ORANGE} #${MAGENTA}             / __ \__  _______/ /_       / ___/      ______ _____           ${ORANGE}# ${RESET}"
				@echo "${ORANGE} #${MAGENTA}            / /_/ / / / / ___/ __ \      \__ \ | /| / / __ '/ __ \          ${ORANGE}# ${RESET}"
				@echo "${ORANGE} #${MAGENTA}           / ____/ /_/ (__  ) / / /     ___/ / |/ |/ / /_/ / /_/ /          ${ORANGE}# ${RESET}"
				@echo "${ORANGE} #${MAGENTA}          /_/    \__,_/____/_/ /_/_____/____/|__/|__/\__,_/ .___/           ${ORANGE}# ${RESET}"
				@echo "${ORANGE} #${MAGENTA}                                /______/                 /_/                ${ORANGE}# ${RESET}"
				@echo "${ORANGE} #                                                                            # ${RESET}"
				@echo "${ORANGE} #                       ${CYAN}42${ORANGE} - ${MAGENTA}orobert ${ORANGE}& ${MAGENTA}jreibel${ORANGE} - ${CYAN}2025${ORANGE}                        # ${RESET}"
				@echo "${ORANGE} #============================================================================# ${RESET}"
				@${CC} ${CFLAGS} ${OBJS} -o $@
				@echo "\n\n                    ⏳ ${MAGENTA}$@${RESET} compilation ${BLUE}in progress${RESET} ⏳"
				@echo "\n                     ✅ ${MAGENTA}$@${RESET} compilation  ${GREEN}complete${RESET} ✅\n"

${OBJS_DIR}:
				@mkdir -p ${OBJS_DIR}

clean:
				@${RM} ${OBJS}
				@${RM} -r ${OBJS_DIR}
				@echo "\n                         🧹 ${MAGENTA}${NAME}${RESET} objects ${RED}deleted${RESET} 🧹\n"

fclean:			clean
				@${RM} ${NAME}
				@echo "                   💥 ${MAGENTA}${NAME}${RESET} /objects directory ${RED}removed${RESET} 💥\n"

re:				fclean all

.PHONY:			all clean fclean re
