import ezEngine_python


ezEngine_python.Initialize()
ezEngine_python.Initialize_sdl()


while ezEngine_python.IsRunning():
    ezEngine_python.ProcessInput()
    ezEngine_python.Update()
    ezEngine_python.Render()


ezEngine_python.Destroy()
