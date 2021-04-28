import ezPyEngine


def update(entity):
    if ezPyEngine.Inputs_MouseButtonLeftClick():
        print("clicked")  
    ezPyEngine.Update()



ezPyEngine.Initialize()
ezPyEngine.Initialize_sdl()

ezPyEngine.AddTexture("bird", "./examples/pyBird/assets/images/bird_up.png")
entity = ezPyEngine.CreateEntity()

source = ezPyEngine.Rectangle(0,0,300,230)
destination = ezPyEngine.Rectangle(0,0,300,230)
ezPyEngine.SpriteComponent_Create(entity, "bird", source, destination, ezPyEngine.Layer.layer_1)

velocity = ezPyEngine.Vector2d(0,0)
ezPyEngine.TransformComponent_Create(entity, 0,0,300,230, velocity, 1)
ezPyEngine.UserInputComponent_Create(entity, 1)

while ezPyEngine.IsRunning():
    ezPyEngine.ProcessInput()
    update(entity)
    ezPyEngine.Render()


ezPyEngine.Destroy()
