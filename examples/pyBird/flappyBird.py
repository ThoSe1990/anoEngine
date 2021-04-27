import ezPyEngine


def update(entity):
    if ezPyEngine.Inputs_MouseButtonLeftClick():
        source = ezPyEngine.Rectangle(320,240,320,240)
        ezPyEngine.SpriteComponent_UpdateSourceRect(entity,source)
        print("clicked")
    else :
        source = ezPyEngine.Rectangle(0,0,320,240)
        ezPyEngine.SpriteComponent_UpdateSourceRect(entity,source)        
    ezPyEngine.Update()



ezPyEngine.Initialize()
ezPyEngine.Initialize_sdl()

ezPyEngine.AddTexture("bird", "./examples/python/assets/images/bird_up.png")
entity = ezPyEngine.CreateEntity()

source = ezPyEngine.Rectangle(0,0,320,240)
destination = ezPyEngine.Rectangle(100,100,160,120)
ezPyEngine.SpriteComponent_Create(entity, "bird", source, destination, ezPyEngine.Layer.layer_0)

while ezPyEngine.IsRunning():
    ezPyEngine.ProcessInput()
    update(entity)
    ezPyEngine.Render()


ezPyEngine.Destroy()
