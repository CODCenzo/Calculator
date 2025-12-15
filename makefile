CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g
LDFLAGS = -lm
EXEC = calc

all: $(EXEC)

$(EXEC): main.o math_operators.o
	$(CC) -o $(EXEC) main.o math_operators.o $(CFLAGS) $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS) $(LDFLAGS)

math_operators.o: math_operators.c
	$(CC) -c math_operators.c $(CFLAGS) $(LDFLAGS)

clean:
	rm -f *.o *.gch $(EXEC)