
[![Build Status](https://dev.azure.com/thomassedlmair/SimpleChess/_apis/build/status/ThoSe1990.SimpleChess?branchName=master)](https://dev.azure.com/thomassedlmair/SimpleChess/_build/latest?definitionId=3&branchName=master)


# Simple Chess Game 

Simple Chess Game under development
  
First setup with chess figures 

![first setup](./screenshots/first_setup.PNG)


Next Steps:
- validation component
    - specific movement for pieces
    - draw possible movement of the selected piece on chess board 
    - drop oppenents piece by moving on their field
- integrating lua for setting up chessboard
- implementing game logic (e.g. statemachine )

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