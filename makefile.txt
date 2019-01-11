assignment6 : Producer.o Consumer.o Main.o
	gcc -o assignment6 Producer.o Consumer.o Main.o
	make clean
producer.o : Producer.c Producer.h
	gcc -c Producer.c
consumer.o : Consumer.c Consumer.h
	gcc -c Consumer.c
Main.o : Main.c Producer.h Consumer.h
	gcc -c Main.c
clean:
	rm -rf *.o
