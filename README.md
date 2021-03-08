
[![Build Status](https://dev.azure.com/thomassedlmair/SimpleChess/_apis/build/status/ThoSe1990.SimpleChess?branchName=master)](https://dev.azure.com/thomassedlmair/SimpleChess/_build/latest?definitionId=3&branchName=master)


# Simple Chess Game 

Simple Chess Game under development
  
First setup with chess figures 

![first setup](./screenshots/default_setup.PNG)
![game running](./screenshots/chessgame.PNG)


Next Steps:
- ~~validation component~~
- integrating lua for
    - ~~setting up chessboard~~
    - log and replay movements
- implementing game logic (e.g. statemachine )
    - movments almost done (needs refactoring DRY!!)
    - implent castling
    - implent en passant
    - reviving figure when pawn reaches end
    - check checkmate
- ...

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