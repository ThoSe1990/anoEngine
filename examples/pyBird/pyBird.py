import ezPyEngine


def update():
    if ezPyEngine.Inputs.MouseButtonLeftClick():
        print("clicked")  
    ezPyEngine.Update()



ezPyEngine.Initialize()
ezPyEngine.Initialize_sdl()

ezPyEngine.AddTexture("background", "./examples/pyBird/assets/images/background.png")
ezPyEngine.AddTexture("bird_up", "./examples/pyBird/assets/images/bird_up.png")
ezPyEngine.AddTexture("bird_dead", "./examples/pyBird/assets/images/bird_dead.png")


background = ezPyEngine.CreateEntity()
ezPyEngine.SpriteComponent.Create(background, "background", ezPyEngine.Rectangle(0,0,1912,855), ezPyEngine.Rectangle(0,0,1920,1080), ezPyEngine.Layer.layer_0)

player = ezPyEngine.CreateEntity()
ezPyEngine.SpriteComponent.Create(player, "bird_up", ezPyEngine.Rectangle(0,0,300,230), ezPyEngine.Rectangle(0,0,300,230), ezPyEngine.Layer.layer_1)
ezPyEngine.TransformComponent.Create(player, 0,0,150,115, ezPyEngine.Vector2d(0,0), 1)
ezPyEngine.UserInputComponent.Create(player, "./examples/pyBird/assets/scripts/playerMovement.lua")
ezPyEngine.ColliderComponent.Create(player, "player", 1)


enemy = ezPyEngine.CreateEntity()
ezPyEngine.SpriteComponent.Create(enemy, "bird_dead", ezPyEngine.Rectangle(0,0,300,230), ezPyEngine.Rectangle(300,300,300,230), ezPyEngine.Layer.layer_1)
ezPyEngine.TransformComponent.Create(enemy, 950,450,150,115, ezPyEngine.Vector2d(0,0), 1)
ezPyEngine.ColliderComponent.Create(enemy, "enmey", 1)




while ezPyEngine.IsRunning():
    ezPyEngine.ProcessInput()
    update()
    ezPyEngine.Render()


ezPyEngine.Destroy()
