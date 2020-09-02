CC = g++

.PHONY: csvedit
csvedit:
	cd src && $(CC) -g csvedit.cpp actions/*.cpp io/*.cpp -o ../csvedit.out
