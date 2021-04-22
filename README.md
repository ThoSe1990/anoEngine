[![Build Status](https://dev.azure.com/thomassedlmair/ezEngine/_apis/build/status/ThoSe1990.ezEngine?branchName=master)](https://dev.azure.com/thomassedlmair/ezEngine/_build/latest?definitionId=6&branchName=master)

# ezEngine - 2D Game Engine
  
Welcome to my 2D Game Engine! This game engine is still under development. The long term goal is to create different games by using different interfaces. Aside there will be an artificial intelligence which learns how to play chess (therefore i started implementing a chess game) against human players or another AI. Before starting with AI this will be a coding playground. first of all this will be a independent 2D game engine with an different interfaces (dll, python, lua) and an implemented chess game.
  
## Build & Run
Current status is to separate the engine from the chess game. To build and run the game install external dependencies (see External Libraries) and run either `make` for the shared library of the engine or `make chess` for the chess game


By running the game the first setup with chess figures will look like: 

![first setup](./screenshots/default_setup.PNG)
![game running](./screenshots/chessgame.PNG)


Next Steps:
- finishing chess implementation
- extracting chess from current implementation
- adding further basic engine components/systems (fonts, drawing, collision, game control, hud, etc.)
- creating api's
- starting AI


## External Libraries

````
sudo apt install libsdl2-dev
sudo apt install libsdl2-image-dev
sudo apt install libsdl2-ttf-dev
sudo apt install libsdl2-mixer-dev
sudo apt install liblua5.3-dev
sudo apt-get install libboost-all-dev
````
