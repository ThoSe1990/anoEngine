#!/usr/bin/python3.8

import anoPyEngine
import time
import random

birdSize = anoPyEngine.Rectangle(0,0,130,105)
pipe_size = anoPyEngine.Rectangle(0,0,180,800)
pipe_gap = 200
pipe_spawn_x = 1920-130

future = 0

pipes = []

def createPipe(now , future):
    if now > future:
        
        pipe_top_spawn_y = pipe_size.h*random.uniform(0.1, 0.9) - pipe_size.h 
        pipe_bottom_spawn_y = pipe_top_spawn_y + pipe_size.h + pipe_gap

        pipe_top = anoPyEngine.CreateEntity()
        anoPyEngine.Sprite.Create(pipe_top, "pipe_top", anoPyEngine.Rectangle(0,0,261,1000), anoPyEngine.Rectangle(0,0,0,0), anoPyEngine.Sprite.Flip.none, anoPyEngine.Sprite.Layer.layer_1)
        anoPyEngine.Transform.Create(pipe_top, pipe_spawn_x, int(pipe_top_spawn_y), pipe_size.w, pipe_size.h, anoPyEngine.Vector2d(-250,0), 1)
        anoPyEngine.Collider.Create(pipe_top, 1.0, "pipe", 1)

        pipes.append(pipe_top)
        
        pipe_bottom = anoPyEngine.CreateEntity()
        anoPyEngine.Sprite.Create(pipe_bottom, "pipe_bottom", anoPyEngine.Rectangle(0,0,261,1000), anoPyEngine.Rectangle(0,0,0,0), anoPyEngine.Sprite.Flip.none, anoPyEngine.Sprite.Layer.layer_1)
        anoPyEngine.Transform.Create(pipe_bottom, pipe_spawn_x, int(pipe_bottom_spawn_y),pipe_size.w, pipe_size.h, anoPyEngine.Vector2d(-250,0), 1)
        anoPyEngine.Collider.Create(pipe_bottom, 1.0, "pipe", 1)

        pipes.append(pipe_bottom)

        if (len(pipes) > 8) :
            popped = pipes.pop(0)
            anoPyEngine.RemoveAllComponents(popped)
            popped = pipes.pop(0)
            anoPyEngine.RemoveAllComponents(popped)
        return 1
    else :
        return 0


def update():
    if anoPyEngine.Inputs.MouseButtonLeftDown():
        anoPyEngine.Sprite.UpdateTextureId(player, "bird_up")
    else:
        anoPyEngine.Sprite.UpdateTextureId(player, "bird_down")
    
    if anoPyEngine.Collider.CollidesWithType(player) == "pipe" :
        anoPyEngine.Sprite.UpdateTextureId(player, "bird_dead")
    else :
        anoPyEngine.Update()
    

anoPyEngine.Initialize()


anoPyEngine.AddTexture("background", "./examples/pyBird/assets/images/background.png")
anoPyEngine.AddTexture("bird_up", "./examples/pyBird/assets/images/bird_up.png")
anoPyEngine.AddTexture("bird_down", "./examples/pyBird/assets/images/bird_down.png")
anoPyEngine.AddTexture("bird_dead", "./examples/pyBird/assets/images/bird_dead.png")
anoPyEngine.AddTexture("pipe_bottom", "./examples/pyBird/assets/images/pipe_bottom.png")
anoPyEngine.AddTexture("pipe_top", "./examples/pyBird/assets/images/pipe_top.png")
anoPyEngine.AddFont("font", "./examples/pyBird/assets/fonts/TakeChances.ttf", 75)


background = anoPyEngine.CreateEntity()
anoPyEngine.Sprite.Create(background, "background", anoPyEngine.Rectangle(0,0,1912,855), anoPyEngine.Rectangle(0,0,1920,1080), anoPyEngine.Sprite.Flip.none, anoPyEngine.Sprite.Layer.layer_0)

player = anoPyEngine.CreateEntity()
anoPyEngine.Sprite.Create(player, "bird_up", anoPyEngine.Rectangle(0,0,300,230), anoPyEngine.Rectangle(0,0,0,0), anoPyEngine.Sprite.Flip.none, anoPyEngine.Sprite.Layer.layer_1)
anoPyEngine.Transform.Create(player, birdSize, anoPyEngine.Vector2d(0,0), 1)
anoPyEngine.UserInput.Create(player, "./examples/pyBird/assets/scripts/playerMovement.lua")
anoPyEngine.Collider.Create(player, 0.5, "player", 1)


textlabel = anoPyEngine.CreateEntity()
anoPyEngine.Textlabel.Create(textlabel, "pyBird: an easy flappy bird!!!", anoPyEngine.Rectangle(20,50,200,50), "font", anoPyEngine.Color(255,255,255,255))


future = time.time() + 3

while anoPyEngine.IsRunning():
    anoPyEngine.ProcessInput()

    player_bird = anoPyEngine.Transform.GetComponent(player)

    if createPipe(time.time(), future) == 1 :
        future = time.time() + 3
    
    update()
    anoPyEngine.Render()


anoPyEngine.Destroy()
