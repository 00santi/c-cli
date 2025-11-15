all: main

main: main.c conversions.c utils.c
	clang -Wall -Wextra -Werror main.c conversions.c utils.c -o main

clean:
	rm -f main