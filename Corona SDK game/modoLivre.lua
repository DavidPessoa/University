local composer = require( "composer" )
local scene = composer.newScene()

---------------------------------------------------------------------------------
-- All code outside of the listener functions will only be executed ONCE
-- unless "composer.removeScene()" is called.
---------------------------------------------------------------------------------

-- local forward references should go here

---------------------------------------------------------------------------------

-- "scene:create()"
function scene:create( event )

   local sceneGroup = self.view

   -- Initialize the scene here.
   -- Example: add display objects to "sceneGroup", add touch listeners, etc.
end

-- "scene:show()"
function scene:show( event )

   local sceneGroup = self.view
   local phase = event.phase

   if ( phase == "will" ) then
      -- Called when the scene is still off screen (but is about to come on screen).
   elseif ( phase == "did" ) then
      -- Called when the scene is now on screen.
      -- Insert code here to make the scene come alive.
      -- Example: start timers, begin animation, play audio, etc.
   end
end

-- "scene:hide()"
function scene:hide( event )

   local sceneGroup = self.view
   local phase = event.phase

   if ( phase == "will" ) then
      -- Called when the scene is on screen (but is about to go off screen).
      -- Insert code here to "pause" the scene.
      -- Example: stop timers, stop animation, stop audio, etc.
   elseif ( phase == "did" ) then
      -- Called immediately after scene goes off screen.
   end
end

-- "scene:destroy()"
function scene:destroy( event )

   local sceneGroup = self.view

   -- Called prior to the removal of scene's view ("sceneGroup").
   -- Insert code here to clean up the scene.
   -- Example: remove display objects, save state, etc.
end

display.setStatusBar(display.HiddenStatusBar)
-----------------------------------------------------------------------------------------
-- Physics Engine
-----------------------------------------------------------------------------------------
local physics = require "physics"
physics.start()
physics.setGravity(0, 9.81)  -- 9.81 m/s*s in the positive x direction
physics.setScale(80)  -- 80 pixels per meter
physics.setDrawMode("normal")
-----------------------------------------------------------------------------------------
-- Background
-----------------------------------------------------------------------------------------
local Background = display.newImage ("imagens/Level.jpg", display.contentCenterX, display.contentCenterY)
-----------------------------------------------------------------------------------------
-- Music
-----------------------------------------------------------------------------------------
local gameMusic = audio.loadStream( "musica/infinity.mp3" )
local gameMusicChannel = audio.play( gameMusic,{ channel = 1, loops = -1 } )
audio.setVolume( 0.5, { channel=1 } )
-----------------------------------------------------------------------------------------
-- Player
-----------------------------------------------------------------------------------------
local player = display.newImage("imagens/Player.png",56,235)
local Hand = display.newRect(88, 230, 4, 4)
staticHand = {density=2, friction=10, bounce=0}
physics.addBody(Hand, "static", staticHand)
Hand.fill=nill
-----------------------------------------------------------------------------------------
-- Ball
-----------------------------------------------------------------------------------------
local ball = display.newImage("bolas/8.png", 88, 216)
physics.addBody(ball, {density=0.8, friction=.3, bounce=0.5, radius=18})
-----------------------------------------------------------------------------------------
-- Walls
-----------------------------------------------------------------------------------------
local floor = display.newRect(240, 313, 480, 50)
floor.fill=nill
local lWall = display.newRect(0, 160, 2, 320)
lWall.fill= nill
local rWall = display.newRect(480, 160, 2, 320)
rWall.fill= nill
local ceiling = display.newRect(240, 0, 480, 2)
ceiling.fill=nill 

staticMaterial = {density=2, friction=.3, bounce=.5}
physics.addBody(floor, "static", staticMaterial)
physics.addBody(lWall, "static", staticMaterial)
physics.addBody(rWall, "static", staticMaterial)
-----------------------------------------------------------------------------------------
-- Score
-----------------------------------------------------------------------------------------
local score = display.newText("Score: 0", 70, 20)
score:setTextColor(0, 0, 0)
score.rotation = 0
score.size = 30
-----------------------------------------------------------------------------------------
-- Backboard
-----------------------------------------------------------------------------------------
local vertPost = display.newRect(415, 214.5, 8, 147)
vertPost.fill=nill
local aro1 = display.newCircle(355, 133, 3)
aro1.fill=nill
local aro2 = display.newCircle(404, 133, 3)
aro2.fill= nill
local backboard = display.newRect(415, 109, 16, 65)
backboard.fill=nill
local aro = display.newImage ("imagens/aro.png",379.5,153)

staticAro = {density=2, friction=.3, bounce=0.4}
staticTabela = {density=2, friction=.3, bounce=.2}

physics.addBody(vertPost, "static", staticMaterial)
physics.addBody(aro1, "static", staticAro)
physics.addBody(aro2, "static", staticAro)
physics.addBody(backboard, "static", staticTabela)
------------------------------------------------------------------------------------------
-- Sound Images
-----------------------------------------------------------------------------------------
local invisiblebutton=display.newCircle(460, 20, 15)
local soundbutton = display.newImage("imagens/sound.png", 460, 20)
local mutebutton = display.newImage("imagens/mute.png", 460, 20)
mutebutton.isVisible = false
soundbutton.isVisible = true
------------------------------------------------------------------------------------------
-- Mute button
------------------------------------------------------------------------------------------
local function mute( event )
    local invisiblebutton = event.target
     
    local phase = event.phase
    if "began" == phase then
            display.getCurrentStage():setFocus( invisiblebutton )
            composer.removeScene("modoLivre") 
            composer.gotoScene("mainMenu")
    else
        if "ended" == phase or "cancelled" == phase then
          local click = audio.loadStream( "musica/click.mp3" )  
          local clickChannel = audio.play( click, { loops = 0 } )
          display.getCurrentStage():setFocus( nil )
          
          if soundbutton.isVisible == true then
           soundbutton.isVisible=false
           mutebutton.isVisible=true
           audio.setVolume( 0, { channel=1 } )
          else
            soundbutton.isVisible=true
            mutebutton.isVisible=false
            audio.setVolume( 0.5, { channel=1 } )
          end                        
        end
    end
 
    return true
end
invisiblebutton:addEventListener("touch", mute)
-----------------------------------------------------------------------------------------
-- Ball Return
-----------------------------------------------------------------------------------------
local function returnball(event)
  ball:setLinearVelocity(0, 0)
  ball.angularVelocity = 0
  transition.to(ball, {time=10, x=88, y=216} )  
end
-----------------------------------------------------------------------------------------
-- Shoot System
-----------------------------------------------------------------------------------------
local speedX = 0
local speedY = 0 
local prevTime = 0
local prevX = 0
local prevY = 0

local function drag( event )
    local ball = event.target
     
    local phase = event.phase
    if "began" == phase then
        display.getCurrentStage():setFocus( ball )

 
        -- Store initial position
        ball.x0 = event.x - ball.x
        ball.y0 = event.y - ball.y
         
        -- Avoid gravitational forces
        event.target.bodyType = "kinematic"
         
        -- Stop current motion, if any
        event.target:setLinearVelocity( 0, 0 )
        event.target.angularVelocity = 0
 
    else
        if "moved" == phase then
            ball.x = event.x - ball.x0
            ball.y = event.y - ball.y0
        elseif "ended" == phase or "cancelled" == phase then
            display.getCurrentStage():setFocus( nil )
            event.target.bodyType = "dynamic"
            timer.performWithDelay(3200, returnball, 1);
            ball:setLinearVelocity(speedX, speedY)
                        
        end
    end
 
    return true
end
ball:addEventListener("touch", drag)
-----------------------------------------------------------------------------------------
-- Shot System 
-----------------------------------------------------------------------------------------
function trackVelocity(event) 
    local timePassed = event.time - prevTime
    prevTime = prevTime + timePassed
     
    speedX = (ball.x - prevX)/(timePassed/1000)
    speedY = ((ball.y - prevY)/(timePassed/1000))*0.8
 
    prevX = ball.x
    prevY = ball.y
end
 
Runtime:addEventListener("enterFrame", trackVelocity)
-----------------------------------------------------------------------------------------
-- Score System 
-----------------------------------------------------------------------------------------
scoreCtr = 0
local lastGoalTime = 1000
 
function monitorScore(event) 
    if event.time - lastGoalTime > 1000  then
        if ball.x > 358 and ball.x < 401 and ball.y > 130 and ball.y < 136 then
            scoreCtr = scoreCtr + 1
            print(score)
            lastGoalTime = event.time
            score.text = "Score: " .. scoreCtr
            local cesto = audio.loadStream( "musica/cesto.mp3" )
      local cestoChannel = audio.play( cesto, { loops = 0 } )
        end
    end
end
Runtime:addEventListener("enterFrame", monitorScore)
---------------------------------------------------------------------------------

-- Listener setup
scene:addEventListener( "create", scene )
scene:addEventListener( "show", scene )
scene:addEventListener( "hide", scene )
scene:addEventListener( "destroy", scene )

---------------------------------------------------------------------------------

return scene