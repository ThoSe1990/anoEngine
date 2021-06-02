#!/usr/bin/python3.8

import anoPyEngine
import time


tilesize = anoPyEngine.Vector2d(32,32)
mapsize = anoPyEngine.Vector2d(16,16)

anoPyEngine.Initialize()

anoPyEngine.AddTexture("mymap", "./examples/tilemap/assets/images/32x32_map_tile v3.1.png")

map = anoPyEngine.CreateEntity()
anoPyEngine.Tilemap.Create(map, "./examples/tilemap/assets/map/tilemap.lua", "mymap")

anoPyEngine.Tilemap.LoadMap(map)

while anoPyEngine.IsRunning():
    anoPyEngine.ProcessInput()
    anoPyEngine.Update()
    anoPyEngine.Render()


anoPyEngine.Destroy()


