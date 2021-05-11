#!/usr/bin/python3.8

import ezPyEngine
import time


window = ezPyEngine.Vector2d(0,0)



class MovingCharacter :

    velocity = ezPyEngine.Vector2d(0,0)
    position = ezPyEngine.Rectangle(0,0,0,0)
    entity = 0
    deltaTime = 0.0
    sprites = []
    currentSprite = 0 

    def __init__(self, velocity, position, spriteId, spriteList) :
        self.velocity = velocity
        self.position = position
        self.sprites = spriteList
        self.currentSprite = 0
        self.entity = ezPyEngine.CreateEntity()
        ezPyEngine.Sprite.Create(self.entity, spriteId, self.sprites[self.currentSprite], self.position, ezPyEngine.Sprite.Flip.none, ezPyEngine.Sprite.Layer.layer_1)
        ezPyEngine.Transform.Create(self.entity, self.position, self.velocity, 1)

    def updateSprite(self):
        self.deltaTime += ezPyEngine.GetDeltaTime()
        if self.deltaTime > 0.15 :
            self.deltaTime = 0.0
            ezPyEngine.Sprite.UpdateSourceRect(self.entity, self.sprites[self.currentSprite])
            self.currentSprite = self.currentSprite + 1
            if self.currentSprite == len(self.sprites):
                self.currentSprite = 0

    def update(self) :
        self.updateSprite()
        transform = ezPyEngine.Transform.GetComponent(self.entity)
        sprite = ezPyEngine.Sprite.GetComponent(self.entity)
        collider = ezPyEngine.Collider.GetComponent(self.entity)
        
        if transform.rectangle.x > window.x or transform.rectangle.x < 0 :
            ezPyEngine.Transform.SetVelocity(self.entity, transform.velocity.x*(-1) , transform.velocity.y)
        if transform.rectangle.y > window.y or transform.rectangle.y < 0 : 
            ezPyEngine.Transform.SetVelocity(self.entity, transform.velocity.x, transform.velocity.y*(-1))        

        if transform.velocity.x > 0 :
            ezPyEngine.Sprite.FlipSprite(self.entity, ezPyEngine.Sprite.Flip.none)
        elif transform.velocity.x < 0 :
            ezPyEngine.Sprite.FlipSprite(self.entity, ezPyEngine.Sprite.Flip.horizontal)

        if collider.collision == 1 : 
            print (collider.type, " collides with ", collider.collisionWithType)


    

ezPyEngine.Initialize()

window = ezPyEngine.GetWindowSize()

ezPyEngine.AddTexture("background", "./examples/debug_playground/assets/images/background.jpg")
ezPyEngine.AddTexture("runningCharacter", "./examples/debug_playground/assets/images/running2.png")
ezPyEngine.AddTexture("flyingBird", "./examples/debug_playground/assets/images/redBird.png")
ezPyEngine.AddTexture("greenGuy", "./examples/debug_playground/assets/images/green.png")


ezPyEngine.AddFont("monster_small", "./examples/debug_playground/assets/fonts/monster.ttf", 35)
ezPyEngine.AddFont("monster_mid", "./examples/debug_playground/assets/fonts/monster.ttf", 55)
ezPyEngine.AddFont("monster_big", "./examples/debug_playground/assets/fonts/monster.ttf", 75)
textlabel_1 = ezPyEngine.CreateEntity()
ezPyEngine.Textlabel.Create(textlabel_1, "Welcome to ezEngine", ezPyEngine.Rectangle(100,150,200,50), "monster_big", ezPyEngine.Color(255,255,255,255))
textlabel_2 = ezPyEngine.CreateEntity()
ezPyEngine.Textlabel.Create(textlabel_2, "a pretty easy 2d game engine for fun", ezPyEngine.Rectangle(1200,350,200,50), "monster_small", ezPyEngine.Color(255,255,255,255))
textlabel_3 = ezPyEngine.CreateEntity()
ezPyEngine.Textlabel.Create(textlabel_3, "give it a try and be creative!", ezPyEngine.Rectangle(1200,150,200,50), "monster_mid", ezPyEngine.Color(255,255,255,255))


background = ezPyEngine.CreateEntity()
ezPyEngine.Sprite.Create(background, "background", ezPyEngine.Rectangle(0,0,2560,1440), ezPyEngine.Rectangle(0,0,1920,1080), ezPyEngine.Sprite.Flip.none, ezPyEngine.Sprite.Layer.layer_0)



runningCharacterSprites = []
runningCharacterSprites.append(ezPyEngine.Rectangle(0,0,150,155))
runningCharacterSprites.append(ezPyEngine.Rectangle(150,0,150,155))
runningCharacterSprites.append(ezPyEngine.Rectangle(300,0,150,155))
runningCharacterSprites.append(ezPyEngine.Rectangle(150,155,150,155))
runningCharacterSprites.append(ezPyEngine.Rectangle(300,155,150,155))

runningCharacter = MovingCharacter(ezPyEngine.Vector2d(500,0), ezPyEngine.Rectangle(10,800,150,155), "runningCharacter", runningCharacterSprites)
ezPyEngine.Collider.Create(runningCharacter.entity, 1.0, "running", 1)
ezPyEngine.UserInput.Create(runningCharacter.entity, "./examples/debug_playground/assets/scripts/playerMovement.lua")


flyingBirdSprites = []
flyingBirdSprites.append(ezPyEngine.Rectangle(0,0,  184,169))
flyingBirdSprites.append(ezPyEngine.Rectangle(184,0,184,169))
flyingBirdSprites.append(ezPyEngine.Rectangle(368,0,184,169))
flyingBirdSprites.append(ezPyEngine.Rectangle(552,0,175,169))
flyingBirdSprites.append(ezPyEngine.Rectangle(736,0,184,169))
flyingBirdSprites.append(ezPyEngine.Rectangle(0,169,  184,169))
flyingBirdSprites.append(ezPyEngine.Rectangle(184,169,184,169))
flyingBirdSprites.append(ezPyEngine.Rectangle(368,169,184,169))
flyingBirdSprites.append(ezPyEngine.Rectangle(552,169,184,169))
flyingBirdSprites.append(ezPyEngine.Rectangle(736,169,184,169))
flyingBirdSprites.append(ezPyEngine.Rectangle(0,338,  184,169))
flyingBirdSprites.append(ezPyEngine.Rectangle(184,338,184,169))
flyingBirdSprites.append(ezPyEngine.Rectangle(368,338,174,169))
flyingBirdSprites.append(ezPyEngine.Rectangle(552,338,184,169))

flyingBird = MovingCharacter(ezPyEngine.Vector2d(300,-150), ezPyEngine.Rectangle(10,500,184,169), "flyingBird", flyingBirdSprites)
ezPyEngine.Collider.Create(flyingBird.entity, 1.0, "bird", 1)

greenGuySprites = []
greenGuySprites.append(ezPyEngine.Rectangle(0,1250,  350,340))
greenGuy = MovingCharacter(ezPyEngine.Vector2d(0,0), ezPyEngine.Rectangle(1200,450,350,340), "greenGuy", greenGuySprites)
ezPyEngine.Collider.Create(greenGuy.entity, 0.5, "greenGuy", 1)


while ezPyEngine.IsRunning():
    ezPyEngine.ProcessInput()
    runningCharacter.update()
    flyingBird.update()
    ezPyEngine.Update()
    ezPyEngine.Render()


ezPyEngine.Destroy()


