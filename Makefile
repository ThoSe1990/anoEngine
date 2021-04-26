build:
	g++ -shared -w -std=c++14 -Wfatal-errors -fvisibility=hidden -fPIC \
	./src/*.cpp ./api/ezEngine.cpp \
	-DBOOST_LOG_DYN_LINK=1 \
	-o libezEngine.so \
	-I"./" \
	-I"./src" \
	-I"./lib" \
	-I"./api" \
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


python_api:
	g++ -shared -std=c++14 -Wfatal-errors -fPIC \
	-o ezPyEngine.so \
	./api/ezPyEngine.cpp \
	-I/usr/include/python3.8 \
	-I"./api" \
	-I"./" \
	-L. \
	-lezEngine \
	-lboost_python38 \
	-lpython3.8;



chess:
	g++ -w -std=c++14 -Wfatal-errors \
	./examples/Chess/src/*.cpp \
	-o chessExample \
	-I"./examples/Chess/src" \
	-I"./api" \
	-I"./" \
	-I"./lib" \
	-L. \
	-lezEngine \
	-llua5.3;



chess_debug:
	g++ -g -w -std=c++14 -Wfatal-errors \
	./src/*.cpp ./api/*.cpp ./examples/Chess/src/*.cpp \
	-DBOOST_LOG_DYN_LINK=1 \
	-o chess_debug \
	-I"./" \
	-I"./examples/Chess/src" \
	-I"./api" \
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

install:
	cp libezEngine.so /usr/lib 
	cp ezEngine_python.so /usr/lib 

clean:
	rm ./libezEngine.so;
	rm ./chessExample;

run_chess:
	./chessExample;
