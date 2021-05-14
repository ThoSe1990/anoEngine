#!/usr/bin/python3.8

import ezPyEngine
import time


tilesize = ezPyEngine.Vector2d(32,32)
mapsize = ezPyEngine.Vector2d(16,16)

ezPyEngine.Initialize()

ezPyEngine.AddTexture("mymap", "./examples/tilemap/assets/images/32x32_map_tile v3.1.png")

map = ezPyEngine.CreateEntity()
ezPyEngine.Tilemap.Create(map, "./examples/tilemap/assets/map/tilemap.map", "mymap", mapsize, tilesize, 1.0)

ezPyEngine.Tilemap.LoadMap(map)

while ezPyEngine.IsRunning():
    ezPyEngine.ProcessInput()
    ezPyEngine.Update()
    ezPyEngine.Render()


ezPyEngine.Destroy()


