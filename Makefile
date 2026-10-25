CC=gcc
EXEC=main

${EXEC}: bst.o main.o
	${CC} $^ -o ${EXEC}

main.o: main.c
	${CC} -c $< -o $@

bst.o: bst.c
	$(CC) -c $< -o $@

clean:
	rm *.o
	rm ${EXEC}