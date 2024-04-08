CC=g++
DEPS=MinStack.h 
OBJ=main.o MinStack.o 

%.o:%.c $(DEPS)
	$(CC) -c -o $a $<

bin: $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -rf $(OBJ)
	rm bin
