build:
	g++ -g -w -std=c++14 -Wfatal-errors \
	./src/*.cpp  \
	-DBOOST_LOG_DYN_LINK=1 \
	-o ChessExample \
	-I"./src" \
	-I"./../../lib" \
	-L./../../lib/ezEngine \
	-lezEngine;

clean:
	rm ./ChessExample;

run:
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$pwd/../../lib/ezEngine
	export LD_LIBRARY_PATH
	./ChessExample;