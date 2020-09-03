CC = g++

.PHONY: csvedit
csvedit:
	cd src && $(CC) -g csvedit.cpp actions/*.cpp io/*.cpp util/*.cpp -o ../csvedit.out
