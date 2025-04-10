TARGET := 10.1.c
FLAGS  := -std=c17 -O0 -g3 -Werror -Wall -Wextra -Wpedantic -fsanitize=address,undefined \
		  -Wcast-qual -Wconversion -Wdouble-promotion -Wfloat-equal -Winline -Wlogical-op \
		  -Wold-style-definition -Wshadow -Wswitch-default -Wswitch-enum -Wundef

all:
	gcc $(FLAGS) $(TARGET) -o ./bin
	./bin
