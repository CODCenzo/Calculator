CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g
LDFLAGS = -lm
EXEC = calc

all: $(EXEC)

$(EXEC): main.o math_operators.o expression_logic.o
	$(CC) -o $(EXEC) main.o math_operators.o expression_logic.o $(CFLAGS) $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS) $(LDFLAGS)

math_operators.o: math_operators.c
	$(CC) -c math_operators.c $(CFLAGS) $(LDFLAGS)

expression_logic.o: expression_logic.c
	$(CC) -c expression_logic.c $(CFLAGS) $(LDFLAGS)

clean:
	rm -f *.o *.gch $(EXEC)