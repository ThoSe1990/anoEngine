import ezPyEngine


def update():
    if ezPyEngine.UserInputs_MouseClicked():
        vec = ezPyEngine.UserInputs_GetMouseCoordinates()
        print("mouse clicked", vec.x , vec.y)
    ezPyEngine.Update()



ezPyEngine.Initialize()
ezPyEngine.Initialize_sdl()


while ezPyEngine.IsRunning():
    ezPyEngine.ProcessInput()
    update()
    ezPyEngine.Render()


ezPyEngine.Destroy()
