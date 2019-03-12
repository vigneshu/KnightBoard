# default:
# 	g++ -c -w -std=c++11 KnightBoard.cpp
# 	g++ -c -w -std=c++11 Knight.cpp
# 	g++ -c -w -o -std=c++11 main.cpp
#   g++ -o output.o-std=c++11 main.o Knight.o KnightBoard.o


default:
	g++ -c -w -std=c++11 KnightBoard.cpp
	g++ -c -w -std=c++11 Knight.cpp
	g++ -c -w -std=c++11 main.cpp
	g++ -o output.exe -w -std=c++11 main.o Knight.o KnightBoard.o

clean:
	rm -f *.o *.exe

# CC=g++
# CFLAGS=-std=c++11
# SOURCES=Knight.cpp KnightBoard.cpp
# OBJECTS=$(SOURCES:.cpp=.o)
# OUT=libknightboard.a
# EXECUTABLE=knightboard
# LDFLAGS = -static

# default:build
# build:binary-executable make-so
# binary-executable:
# 	$(CC) $(CFLAGS) -o knightboard main.cpp	
# make-binary:
# make-so:make-binary
# 	$(CC) --shared -o libKnightBoard.so libKnightBoard.o
#clean:
# rm -f *.o


# default:
# 	g++ -c -w -std=c++11 KnightBoard.cpp
# 	g++ -c -w -std=c++11 Knight.cpp
# 	g++ -c -w -o -std=c++11 main.cpp
#   g++ -o output.o -std=c++11 main.o Knight.o KnightBoard.o


# default:
# 	g++ -c KnightBoard.cpp
# 	g++ -c Knight.cpp
# 	g++ -c main.cpp
# 	g++ -o main main.o Knight.o KnightBoard.o