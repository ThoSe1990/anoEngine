build:
	g++ -w -std=c++14 -Wfatal-errors \
	./src/*.cpp ./src/Entity/*.cpp \
	-o SimpleChess \
	-I"./src" \
	-I"./lib" \
	-I"./src/lua" \
	-llua5.3 \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \
	-lSDL2_mixer;

clean:
	rm ./SimpleChess;

run:
	./SimpleChess;
