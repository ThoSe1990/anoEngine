build:
	g++ -g -w -std=c++14 -Wfatal-errors \
	./src/*.cpp  \
	-DBOOST_LOG_DYN_LINK=1 \
	-o ChessExample \
	-I"./src" \
	-I"../../.." \
	-L./../.. \
	-lezEngine;

clean:
	rm ./ChessExample;

run:
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$pwd/../../
	export LD_LIBRARY_PATH
	./ChessExample;