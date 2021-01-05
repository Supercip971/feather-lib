
GCC := g++
LD := ld
PROJDIRS := src/
SRCFILES := $(shell find $(PROJDIRS) -type f -name \*.cpp)

OBJFILES := $(patsubst %.cpp,%.o,$(SRCFILES))
HDRFILES := $(shell find $(PROJDIRS) -type f -name \*.h)
%.o: %.cpp $(SRCFILES) $(HDRFILES)
	@echo "[ FEATHER ] (C++) building $<"
	@$(GCC) -c -pthread -fpermissive -std=c++20 -m64 -Wall -g -march=x86-64 -I . -O2 -msse -o $@ $<
 

all: $(OBJFILES)

	@echo "[ FEATHER ] (exe) linking $<" 
	@$(GCC) $(OBJFILES) -fpermissive -pthread -o build/feather 
	@make -C . run
run:
	./build/feather 


	
format:
	clang-format -i --verbose --style=file $(SRCFILES) $(HDRFILES)
clean:
	rm $(OBJFILES)

