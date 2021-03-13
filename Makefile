build:
	g++ -g -w -std=c++14 -Wfatal-errors \
	./src/*.cpp ./src/Entity/*.cpp ./src/Chesscontroller/*.cpp \
	-DBOOST_LOG_DYN_LINK=1 \
	-o SimpleChess \
	-I"./src" \
	-I"./lib" \
	-I"./src/lua" \
	-lboost_log \
	-lboost_log_setup \
	-lboost_system \
	-lboost_thread \
	-llua5.3 \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \
	-lSDL2_mixer \
	-lpthread;

clean:
	rm ./SimpleChess;

run:
	./SimpleChess;
