

local inputs = UserInputs.GetInstance()


if inputs.keyboard_a == true then
    velocity["x"] = -400
elseif inputs.keyboard_d == true then
    velocity["x"] = 800
else    
    velocity["x"] = 0
end


if inputs.mouseButtonLeftDown == true then
    velocity["y"] = -200 
else
    velocity["y"] = 200
end