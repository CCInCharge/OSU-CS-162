# Final Project makefile
# Author: Charles Chen
# Date: 3/11/2017

CXX = g++
CXXFLAGS = -std=c++0x
OBJS = Backpack.o ExitRoom.o Game.o inputValidator.o ItemRoom.o MonsterRoom.o Player.o Room.o FinalProject.o
SRCS = Backpack.cpp ExitRoom.cpp Game.cpp inputValidator.cpp ItemRoom.cpp MonsterRoom.cpp Player.cpp Room.cpp FinalProject.cpp

all: ${OBJS}
	${CXX} ${OBJS} -o FinalProject

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f a.out ${OBJS} FinalProject
