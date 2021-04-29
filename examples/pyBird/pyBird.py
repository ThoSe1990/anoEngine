import ezPyEngine


def update():
    if ezPyEngine.Inputs.MouseButtonLeftClick():
        print("clicked")  
    ezPyEngine.Update()



ezPyEngine.Initialize()
ezPyEngine.Initialize_sdl()

ezPyEngine.AddTexture("bird_up", "./examples/pyBird/assets/images/bird_up.png")
ezPyEngine.AddTexture("bird_dead", "./examples/pyBird/assets/images/bird_dead.png")


player = ezPyEngine.CreateEntity()
ezPyEngine.SpriteComponent.Create(player, "bird_up", ezPyEngine.Rectangle(0,0,300,230), ezPyEngine.Rectangle(0,0,300,230), ezPyEngine.Layer.layer_1)
ezPyEngine.TransformComponent.Create(player, 0,0,150,115, ezPyEngine.Vector2d(0,0), 1)
ezPyEngine.UserInputComponent.Create(player, 1)
ezPyEngine.ColliderComponent.Create(player, "player", 1)


enemy = ezPyEngine.CreateEntity()
ezPyEngine.SpriteComponent.Create(enemy, "bird_dead", ezPyEngine.Rectangle(0,0,300,230), ezPyEngine.Rectangle(300,300,300,230), ezPyEngine.Layer.layer_1)
ezPyEngine.TransformComponent.Create(enemy, 300,300,150,115, ezPyEngine.Vector2d(0,0), 1)
ezPyEngine.ColliderComponent.Create(enemy, "enmey", 1)





while ezPyEngine.IsRunning():
    ezPyEngine.ProcessInput()
    update()
    ezPyEngine.Render()


ezPyEngine.Destroy()
