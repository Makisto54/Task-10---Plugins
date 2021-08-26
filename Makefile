BIN := calculator

.PHONY : all debug clean

all:
	cd $(BIN) && make

debug:
	cd $(BIN) && make debug
	
clean:
	cd $(BIN) && make clean
