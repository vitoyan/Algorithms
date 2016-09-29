SRCS = $(wildcard ../util/*.cpp)\
	$(wildcard *.cpp)
OBJS = $(SRCS: .cpp=.o)
INCLUDES = -I../util
CCFLAGS = -g -Wall -O0 -std=c++11
CC = g++

TARGETS = functionRunFunPOJ1579

ALL_OBJS = $(TARGETS:%=%.o)
all : $(TARGETS)

$(ALL_OBJS) : $(@:%.o=%.cpp)
	$(CC) $(CCFLAGS) -c $@.o $@.cpp $(INCLUDES)

$(TARGETS) : $(@:%=%.o) $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@ $(INCLUDES) 

.cpp.o :
	$(CC) $(CCFLAGS) -c $(INCLUDES) %< 

.PHONY: clean
clean :
	rm -f $(obj) *.o all
