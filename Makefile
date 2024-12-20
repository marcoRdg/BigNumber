all: node.o bignumber.o client.o
	gcc node.o bignumber.o client.o -std=c99 -Wall -Wvla -Wextra -g -o BigNumber

node.o: node.h node.c
	gcc -std=c99 -Wall -Wextra -Wvla -g -c node.c

bignumber.o: bignumber.h bignumber.c
	gcc -std=c99 -Wall -Wextra -Wvla -g -c bignumber.c

client.o: client.c
	gcc -std=c99 -Wall -Wextra -Wvla -g -c client.c

clean:
	rm -f *.o BigNumber *.err