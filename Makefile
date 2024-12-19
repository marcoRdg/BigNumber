all: node.o bignumber.o client.o
	gcc node.o bignumber.o client.o -Wall -Wvla -Wextra -g -o BigNumber

node.o: node.h node.c
	gcc -Wall -Wextra -Wvla -g -c node.c

bignumber.o: bignumber.h bignumber.c
	gcc -Wall -Wextra -Wvla -g -c bignumber.c

client.o: client.c
	gcc -Wall -Wextra -Wvla -g -c client.c

clean:
	rm -f *.o BigNumber *.err