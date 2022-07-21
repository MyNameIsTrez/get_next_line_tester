# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/22 18:42:17 by sbos          #+#    #+#                  #
#    Updated: 2022/07/21 11:43:40 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

export DEBUG=1

GET_NEXT_LINE := get_next_line/libget_next_line.a

CC := cc

LIBS := $(GET_NEXT_LINE)

override TESTS_DIR := tests
OBJ_DIR := obj

CFLAGS := -Wall -Wextra -Werror
CFLAGS += -O3 # -O1 or higher adds tail recursion detection.

ifdef DEBUG
CFLAGS += -DSTATIC=
CFLAGS += -g3 -Wconversion
endif

ifdef SAN
CFLAGS += -fsanitize=address
endif

HEADERS :=\
	$(TESTS_DIR)/get_next_line_tests.h\
	get_next_line/get_next_line.h\
	$(addprefix $(HOME)/Documents/Programming/libctester/, $(shell $(MAKE) -C $(HOME)/Documents/Programming/libctester/ -f headers.mk get_headers))

################################################################################

SOURCES := $(shell find $(TESTS_DIR) -name "*.c")

OBJECTS := $(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

INCLUDES := $(sort $(addprefix -I, $(dir $(HEADERS))))

################################################################################

# Only cleans when MAKE_DATA changes.
DATA_FILE := .make_data
MAKE_DATA := $(CFLAGS) $(SOURCES)
ifneq ($(shell echo "$(MAKE_DATA)"), $(shell cat "$(DATA_FILE)" 2> /dev/null))
PRE_RULES := clean
endif

################################################################################

.PHONY: all
all: $(PRE_RULES) $(GET_NEXT_LINE) $(OBJECTS)
	@echo "$(MAKE_DATA)" > $(DATA_FILE)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

################################################################################

.PHONY: $(GET_NEXT_LINE)
$(GET_NEXT_LINE):
	@$(MAKE) -C $(dir $(GET_NEXT_LINE))

################################################################################

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	@$(MAKE) -C $(dir $(GET_NEXT_LINE)) fclean

.PHONY: re
re: fclean all

################################################################################

.PHONY: get_libs
get_libs:
	@echo $(LIBS)

################################################################################
