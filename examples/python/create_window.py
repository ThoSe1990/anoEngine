import ezPyEngine


def update():
    if ezPyEngine.UserInputs_MouseClicked():
        vec = ezPyEngine.UserInputs_GetMouseCoordinates()
        print("mouse clicked", vec.x , vec.y)
    ezPyEngine.Update()



ezPyEngine.Initialize()
ezPyEngine.Initialize_sdl()

ezPyEngine.AddTexture("bird_falling", "./examples/python/assets/images/bird_falling.png")
entity = ezPyEngine.CreateEntity()

source = ezPyEngine.Rectangle(0,0,900,780)
destination = ezPyEngine.Rectangle(10,110,900,780)
ezPyEngine.SpriteComponent_Create(entity, "bird_falling", source, destination, 0)

while ezPyEngine.IsRunning():
    ezPyEngine.ProcessInput()
    update()
    ezPyEngine.Render()


ezPyEngine.Destroy()
