
[![Build Status](https://dev.azure.com/thomassedlmair/SimpleChess/_apis/build/status/ThoSe1990.SimpleChess?branchName=master)](https://dev.azure.com/thomassedlmair/SimpleChess/_build/latest?definitionId=3&branchName=master)


# Simple Chess Game 

Redesign to an entity component system on branch ecs.

Welcome to my Chessgame! This game is still under development. The long term goal is to use artificial intelligence which learns how to play chess against human players or another AI. Currently plan is about to run laters AI in python and communicate via google protocol buffers on localhost to the game. 
  
First setup with chess figures and a gaming scenario 

![first setup](./screenshots/default_setup.PNG)
![game running](./screenshots/chessgame.PNG)


Next Steps:
- ~~validation component~~
- integrating lua for
    - ~~setting up chessboard~~
    - log and redo movements
- implementing game logic (e.g. statemachine )
    - movments almost done (needs refactoring DRY!!)
    - implent castling
    - implent en passant
    - reviving figure when pawn reaches end
    - check checkmate
    - restart game
    - a bit of an UI (captured figures, time, game result, game state, etc.)
- preparing interface to move chessfigures with protobuffer
- implementing server side (boost asio)
- defining protocol buffers
- read / write proto


Optimizing:
- moving figures diagonal (slower speed on the shorter axis)
- ~~click event delayed only on vm???~~ done
- ... 

## External Libraries

````
sudo apt install libsdl2-dev
sudo apt install libsdl2-image-dev
sudo apt install libsdl2-ttf-dev
sudo apt install libsdl2-mixer-dev
sudo apt install liblua5.3-dev
sudo apt-get install libboost-all-dev
````
