##
## Makefile for 42sh in /home/VEYSSI_B/rendu/Programmation_Shell/test/test_42tree
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Wed May 18 21:26:30 2016 Baptiste veyssiere
##

NAME	= nanotekspice

LIBNAME	= nanotekspice.a

RM	= rm -f

CC	= g++

MKDIR	= mkdir -p

SRC	= srcs/component_4001.cpp \
	srcs/component_4040.cpp \
	srcs/component_4094.cpp \
	srcs/AComponent.cpp \
	srcs/component_4008.cpp \
	srcs/component_4069.cpp \
	srcs/component_4011.cpp \
	srcs/component_4013.cpp \
	srcs/component_4030.cpp \
	srcs/component_4071.cpp \
	srcs/component_4081.cpp \
	srcs/component_clock.cpp \
	srcs/component_false.cpp \
	srcs/component_input.cpp \
	srcs/component_output.cpp \
	srcs/component_true.cpp \
	srcs/isValid.cpp \
	srcs/main.cpp \
	srcs/Parser.cpp \
	srcs/pin_check.cpp \
	srcs/nanotekspice.cpp \
	srcs/command_handler.cpp

LIBSRC	= srcs/component_4001.cpp \
	srcs/component_4008.cpp \
	srcs/component_4011.cpp \
	srcs/component_4013.cpp \
	srcs/component_4030.cpp \
	srcs/component_4071.cpp \
	srcs/component_4081.cpp \
	srcs/component_clock.cpp \
	srcs/component_false.cpp \
	srcs/component_input.cpp \
	srcs/component_output.cpp \
	srcs/component_true.cpp \
	srcs/isValid.cpp \
	srcs/Parser.cpp \
	srcs/pin_check.cpp \
	srcs/nanotekspice.cpp \
	srcs/command_handler.cpp

SRCDIR	= srcs

OBJDIR	= objs

OBJ	= $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

LIBOBJ	= $(SRCLIB:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

CFLAGS	= -Iinclude

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@echo "Linking complete!"

$(LIBNAME): $(OBJ)
	@ar rcs $(LIBNAME) $(LIBOBJ)
	@ranlib $(LIBNAME)
	@echo "Static library created"

$(OBJ): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(MKDIR) $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

all: $(NAME) $(LIBNAME)

clean:
	@$(RM) $(OBJ)
	@echo "Cleanup complete!"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBNAME)

re: fclean all

.PHONY: all clean fclean re
