[![Build Status](https://dev.azure.com/thomassedlmair/ezEngine/_apis/build/status/ThoSe1990.ezEngine?branchName=master)](https://dev.azure.com/thomassedlmair/ezEngine/_build/latest?definitionId=6&branchName=master)

# ezEngine - 2D Game Engine
  
Welcome to my 2D Game Engine! This game engine is still under development. The long term goal is to create different games by using different interfaces. Aside there will be an artificial intelligence which learns how to play chess (therefore i started implementing a chess game) against human players or another AI. Before starting with AI this will be a coding playground. first of all this will be a independent 2D game engine with an different interfaces (dll, python, lua) and an implemented chess game.
  

## ezEngine Documentation

This engine works with an Entity-Component-System which is illustrated below (simplified). 

1. Each entity is represented as an id, as just a integer number. 
2. Each Entity can have multiple components. 
3. The components are just plain data, no logic. 
4. Each component is handled by a component manager (instantiated inside singelton class Components, see `./Components/Components.hpp`).
5. Components are modified by the systems, which means one system can modify multiple components.
6. All systems inherit from the same interface, to store them in a container inside the Systemsmanager, see `./Systems/SystemManager.hpp`. 
  
  
![ecs](./screenshots/ecs.png)

  
All given API function are defined in `./api/ezEngine.hpp`. A description will follow. For now see the two examples, this readme or the function singatures how to use.
  
  
To create a game there is only the api needed. For instance we want to create an Entity and assign some components like:  
  
  
C++ (see `./examples/Chess/src/Chess.cpp`):
````
...
// create an entity
auto newEntity = ezEngine::CreateEntity();

// add one or more components to it 
ezEngine::Transform::Create(newEntity, 
    coordinates.x,
    coordinates.y,
    Constants::chesspiece_sidelength,
    Constants::chesspiece_sidelength,
    ezEngine::Vector2d{Constants::chespieces_velocity,Constants::chespieces_velocity},
    Constants::scale
);
...
````

Python (see `./examples/pyBird/pyBird.py`):
````
...
# add some components to the entity
ezPyEngine.SpriteComponent.Create(player, "bird_up", ezPyEngine.Rectangle(0,0,300,230), ezPyEngine.Rectangle(0,0,0,0), ezPyEngine.Layer.layer_1)
ezPyEngine.TransformComponent.Create(player, birdSize, ezPyEngine.Vector2d(0,0), 1)
ezPyEngine.UserInputComponent.Create(player, "./examples/pyBird/assets/scripts/playerMovement.lua")
ezPyEngine.ColliderComponent.Create(player, "player", 1)
....
````

## Components

Within this section the provided components are described and illustrated with some examples how to create and use them.
  
### SpriteComponent
A SpriteComponent holds the information to render an image or a sprite. To access given sprites it is mandatory to add the image with an id to the assetmanager. All sprite components are rendered by the sprite system. 
  
````
// C++ 

// add your sprite 
ezEngine::AddTexture("YOUR_ID", "PATH_TO_THE_IMAGE");

// create an enttiy
auto newEntity = ezEngine::CreateEntity();

// create a sprite component
ezEngine::Sprite::Create(
    newEntity,
    "YOUR_ID",
    ezEngine::Rectangle{}, // source position in given sprite file
    ezEngine::Rectangle{}, // destination position in game
    ezEngine::Sprite::Layer::layer_0 
);


# Python:
ezPyEngine.AddTexture("YOUR_ID", "PATH_TO_THE_IMAGE")
# add your sprite

# create Entity
newEntity = ezPyEngine.CreateEntity()
# create a entity
ezPyEngine.SpriteComponent.Create(newEntity, "YOUR_ID", ezPyEngine.Rectangle(source position), ezPyEngine.Rectangle(destination position in game), ezPyEngine.Layer.layer_0)

````
  
Note: If an enttiy has also a transfrom component, the destination position will be overwritten by it.

### TransformComponent
...
### PositionComponent
...
### UserInputComponent
...
### ColliderComponent
...
### TileComponent
...
### TextlabelComponent
...
## Systems

Within this section all provided systems are described, to get an overview which systems accessing which components (therefore which data specifically)

### SpriteSystem
The sprite system renders all spritecomponents according to the given rendering layers.
  
If a sprite should be moveable then the destination possition will be overwritten in the update function by the according transform component.
### TransformSystem

### PositionSystem
...
### UserControlSystem
...
### CollisionSystem
...

## Build 
There are different targets in the makefile. If there are permission issues by copying to /usr/lib or loading the shared library run with `sudo`.

1. Install the external dependencies
````
sudo apt install libsdl2-dev
sudo apt install libsdl2-image-dev
sudo apt install libsdl2-ttf-dev
sudo apt install libsdl2-mixer-dev
sudo apt install liblua5.3-dev
sudo apt-get install libboost-all-dev
apt-get install python-dev
sudo apt install python3.8
````

2. Run `make all` to builds the engine, the python api and the chess example
3. Run `make install` copy shared library to /usr/lib and ./examples/pyBird


## Examples

On the current state of this project there are two examples.

### Chess Example

By running `make run_chess` the Chessgame starts. It's a C++ implementation which uses the ezEngine. All game rules aren' implemented. A running game looks like:

![first setup](./screenshots/default_setup.PNG)
![game running](./screenshots/chessgame.PNG)
  
### pyBird

Long time goal is to create a flappy bird game with python. Currently, first implementation for the python API done. Run the script `python3.8 ./examples/pyBird/pyBird.py`. This will create a flappy bird game. The bird controls are implemented in `./assets/scirpts/playerMovement.lua` and can easily changed since this script will be executed during runtime.
  
Note: this is a first naive approach of the game with keyboard keys a and d for moving left right and clicking for upwards movement



![pybird example 1](./screenshots/pybird.gif)
![pybird example 1](./screenshots/pybird_1.PNG)
![pybird example 2](./screenshots/pybird_2.PNG)


## Known Issues

- api function to add custom systems
- proper position control (refactor 2point control, chess figure jiggles on arriving at given square)
- layer rendering of spritesystem