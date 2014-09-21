CFLAGS = -g -W -Wall -Weffc++ -Wextra -pedantic -std=c++0x -O0
VFLAGS = --leak-cheak=full --show-reachable=yes

SOURCES = $(shell find *.cpp) #All the cpp files of the current directory
#OBJS = $(SOURCES: .cpp = .o) #All the object files that should be generated, they have the same name with the corresponding cpp files, this one should work, I don't know the reason
OBJS = $(addsuffix .o, $(basename $(shell find *.cpp)))
EXEC = run


.PHONY: clang gcc setclang setgcc clean r vg

clang: | setclang $(EXEC)

gcc: | setgcc $(EXEC)

all : $(SOURCES) $(EXEC)
#Here must use $^, it represents all the OBJS but $< just represent the first one of OBJS
$(EXEC): $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^ 

#Here we can use ethier the $^ or $<, because for "%.**" the two behave the same
#$(OBJS): %.o : %.cpp  #This two sentences behave the same
.cpp.o:
	$(CXX) $(CFLAGS) -c $^ -o $@ 

setclang:
	@echo "Setting clang"
	$(eval CXX = clang++)
	$(eval CXX_LINK = clang++)

setgcc:
	@echo "Setting gcc"
	$(eval CXX = g++)
	$(eval CXX_LINK = g++)

clean:
	rm -f $(EXEC) $(OBJS)

r:
	@./$(EXEC)

vg:
	@valgrind ./$(EXEC)
