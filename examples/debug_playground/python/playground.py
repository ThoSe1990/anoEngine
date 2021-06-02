#!/usr/bin/python3.8

import anoPyEngine
import time


window = anoPyEngine.Vector2d(0,0)



class MovingCharacter :

    velocity = anoPyEngine.Vector2d(0,0)
    position = anoPyEngine.Rectangle(0,0,0,0)
    entity = 0
    deltaTime = 0.0
    sprites = []
    currentSprite = 0 

    def __init__(self, velocity, position, spriteId, spriteList) :
        self.velocity = velocity
        self.position = position
        self.sprites = spriteList
        self.currentSprite = 0
        self.entity = anoPyEngine.CreateEntity()
        anoPyEngine.Sprite.Create(self.entity, spriteId, self.sprites[self.currentSprite], self.position, anoPyEngine.Sprite.Flip.none, anoPyEngine.Sprite.Layer.layer_1)
        anoPyEngine.Transform.Create(self.entity, self.position, self.velocity, 1)

    def updateSprite(self):
        self.deltaTime += anoPyEngine.GetDeltaTime()
        if self.deltaTime > 0.15 :
            self.deltaTime = 0.0
            anoPyEngine.Sprite.UpdateSourceRect(self.entity, self.sprites[self.currentSprite])
            self.currentSprite = self.currentSprite + 1
            if self.currentSprite == len(self.sprites):
                self.currentSprite = 0

    def update(self) :
        self.updateSprite()
        transform = anoPyEngine.Transform.GetComponent(self.entity)
        sprite = anoPyEngine.Sprite.GetComponent(self.entity)
        collider = anoPyEngine.Collider.GetComponent(self.entity)
        
        if transform.rectangle.x > window.x or transform.rectangle.x < 0 :
            anoPyEngine.Transform.SetVelocity(self.entity, transform.velocity.x*(-1) , transform.velocity.y)
        if transform.rectangle.y > window.y or transform.rectangle.y < 0 : 
            anoPyEngine.Transform.SetVelocity(self.entity, transform.velocity.x, transform.velocity.y*(-1))        

        if transform.velocity.x > 0 :
            anoPyEngine.Sprite.FlipSprite(self.entity, anoPyEngine.Sprite.Flip.none)
        elif transform.velocity.x < 0 :
            anoPyEngine.Sprite.FlipSprite(self.entity, anoPyEngine.Sprite.Flip.horizontal)

        if collider.collision == 1 : 
            print (collider.type, " collides with ", collider.collisionWithType)


    

anoPyEngine.Initialize()

window = anoPyEngine.GetWindowSize()

anoPyEngine.AddTexture("background", "./examples/debug_playground/assets/images/background.jpg")
anoPyEngine.AddTexture("runningCharacter", "./examples/debug_playground/assets/images/running2.png")
anoPyEngine.AddTexture("flyingBird", "./examples/debug_playground/assets/images/redBird.png")
anoPyEngine.AddTexture("greenGuy", "./examples/debug_playground/assets/images/green.png")
anoPyEngine.AddTexture("virus", "./examples/debug_playground/assets/images/virus.png")


anoPyEngine.AddFont("monster_small", "./examples/debug_playground/assets/fonts/monster.ttf", 35)
anoPyEngine.AddFont("monster_mid", "./examples/debug_playground/assets/fonts/monster.ttf", 55)
anoPyEngine.AddFont("monster_big", "./examples/debug_playground/assets/fonts/monster.ttf", 75)
textlabel_1 = anoPyEngine.CreateEntity()
anoPyEngine.Textlabel.Create(textlabel_1, "Welcome to anoEngine", anoPyEngine.Rectangle(100,150,200,50), "monster_big", anoPyEngine.Color(255,255,255,255))
textlabel_2 = anoPyEngine.CreateEntity()
anoPyEngine.Textlabel.Create(textlabel_2, "just another 2d game engine for fun", anoPyEngine.Rectangle(1200,350,200,50), "monster_small", anoPyEngine.Color(255,255,255,255))
textlabel_3 = anoPyEngine.CreateEntity()
anoPyEngine.Textlabel.Create(textlabel_3, "give it a try and be creative!", anoPyEngine.Rectangle(1200,150,200,50), "monster_mid", anoPyEngine.Color(255,255,255,255))


background = anoPyEngine.CreateEntity()
anoPyEngine.Sprite.Create(background, "background", anoPyEngine.Rectangle(0,0,2560,1440), anoPyEngine.Rectangle(0,0,1920,1080), anoPyEngine.Sprite.Flip.none, anoPyEngine.Sprite.Layer.layer_0)



runningCharacterSprites = []
runningCharacterSprites.append(anoPyEngine.Rectangle(0,0,150,155))
runningCharacterSprites.append(anoPyEngine.Rectangle(150,0,150,155))
runningCharacterSprites.append(anoPyEngine.Rectangle(300,0,150,155))
runningCharacterSprites.append(anoPyEngine.Rectangle(150,155,150,155))
runningCharacterSprites.append(anoPyEngine.Rectangle(300,155,150,155))

runningCharacter = MovingCharacter(anoPyEngine.Vector2d(500,0), anoPyEngine.Rectangle(10,800,150,155), "runningCharacter", runningCharacterSprites)
anoPyEngine.Collider.Create(runningCharacter.entity, 1.0, "running", 1)
anoPyEngine.UserInput.Create(runningCharacter.entity, "./examples/debug_playground/assets/scripts/playerMovement.lua")


flyingBirdSprites = []
flyingBirdSprites.append(anoPyEngine.Rectangle(0,0,  184,169))
flyingBirdSprites.append(anoPyEngine.Rectangle(184,0,184,169))
flyingBirdSprites.append(anoPyEngine.Rectangle(368,0,184,169))
flyingBirdSprites.append(anoPyEngine.Rectangle(552,0,175,169))
flyingBirdSprites.append(anoPyEngine.Rectangle(736,0,184,169))
flyingBirdSprites.append(anoPyEngine.Rectangle(0,169,  184,169))
flyingBirdSprites.append(anoPyEngine.Rectangle(184,169,184,169))
flyingBirdSprites.append(anoPyEngine.Rectangle(368,169,184,169))
flyingBirdSprites.append(anoPyEngine.Rectangle(552,169,184,169))
flyingBirdSprites.append(anoPyEngine.Rectangle(736,169,184,169))
flyingBirdSprites.append(anoPyEngine.Rectangle(0,338,  184,169))
flyingBirdSprites.append(anoPyEngine.Rectangle(184,338,184,169))
flyingBirdSprites.append(anoPyEngine.Rectangle(368,338,174,169))
flyingBirdSprites.append(anoPyEngine.Rectangle(552,338,184,169))

flyingBird = MovingCharacter(anoPyEngine.Vector2d(300,-150), anoPyEngine.Rectangle(10,500,184,169), "flyingBird", flyingBirdSprites)
anoPyEngine.Collider.Create(flyingBird.entity, 1.0, "bird", 1)

greenGuySprites = []
greenGuySprites.append(anoPyEngine.Rectangle(0,1250,  350,340))
greenGuy = MovingCharacter(anoPyEngine.Vector2d(0,0), anoPyEngine.Rectangle(1200,450,350,340), "greenGuy", greenGuySprites)
anoPyEngine.Collider.Create(greenGuy.entity, 0.5, "greenGuy", 1)


virus = anoPyEngine.CreateEntity()
anoPyEngine.Sprite.Create(virus, "virus", anoPyEngine.Rectangle(0,0, 2500,2500), anoPyEngine.Rectangle(1000,1000, 100,100), anoPyEngine.Sprite.Flip.none, anoPyEngine.Sprite.Layer.layer_1)
anoPyEngine.Transform.Create(virus, anoPyEngine.Rectangle(1000,1000, 100,100), anoPyEngine.Vector2d(0,0), 1)
anoPyEngine.Position.Create(virus, 
                        anoPyEngine.Vector2d(10,10),
                        anoPyEngine.Vector2d(500,500), 
                        anoPyEngine.Vector2d(2,2),
                        anoPyEngine.Vector2d(10,10),
                        anoPyEngine.Vector2d(0,0)
                        )

while anoPyEngine.IsRunning():
    anoPyEngine.ProcessInput()
    runningCharacter.update()
    flyingBird.update()
    anoPyEngine.Update()
    anoPyEngine.Render()


anoPyEngine.Destroy()


