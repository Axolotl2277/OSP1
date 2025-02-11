oss : oss.o user.o
	g++ -o oss oss.o user.o
oss.o : oss.cpp
	g++ -c oss.cpp
user.o : user.cpp
	g++ -c user.cpp

clean:
	rm oss oss.o user.o
