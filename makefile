test: Parking.o main.o
	cc -o test Parking.o main.o -lStack -lQueue  #加入静态链接库

Parking.o: Parking.c 

main.o: main.c

clean:
	rm -f *.o
