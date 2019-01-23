CXX=g++
CXXFLAGS=-lncurses -Wall

KLSBNAS: main.cpp utils.cpp snake.cpp
	${CXX} ${CXXFLAGS} -o $@ $^

clean:
	rm -f *.o KLSBNAS


