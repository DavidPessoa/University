local composer = require( "composer" )

local scene = composer.newScene()

-- -----------------------------------------------------------------------------------------------------------------
-- All code outside of the listener functions will only be executed ONCE unless "composer.removeScene()" is called.
-- -----------------------------------------------------------------------------------------------------------------

-- local forward references should go here

-- -------------------------------------------------------------------------------


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

-----------------------------------------------------------------------------------------
local gameMode = 1


-----------------------------------------------------------------------------------------
-- Physics Engine
-----------------------------------------------------------------------------------------
local physics = require "physics"
physics.start()
physics.setGravity(0, 9.81)  -- 9.81 m/s*s in the positive x direction
physics.setScale(80)  -- 80 pixels per meter
physics.setDrawMode("normal")

-----------------------------------------------------------------------------------------------------------
--IMAGES
-----------------------------------------------------------------------------------------------------------
local Background = display.newImage ("imagens/Home_Screen2.JPG", display.contentCenterX, display.contentCenterY)
local playButton = display.newImage ("imagens/play.png", 207, 219)
local buttonin= display.newCircle(307, 219, 25)
local mode1= display.newImage("imagens/mode1.png",307, 219)
local mode2= display.newImage("imagens/mode2.png",307, 219)
local ball = display.newImage ( "bolas/8.png", 40,230)
local floor = display.newRect(240, 313, 480, 50)
local settingsButton = display.newImage ("imagens/settings.png", 400, 290)
local creditsButton = display.newImage ("imagens/credits.png", 74, 290)
mode1.isVisible=true
mode2.isVisible=false
floor.fill=nill
staticMaterial = {density=2, friction=.3, bounce=.5}
physics.addBody(floor, "static", staticMaterial)
physics.addBody(ball, {density=0.8, friction=.3, bounce=0.9, radius=18})
-----------------------------------------------------------------------------------------------------------
--Functions
-----------------------------------------------------------------------------------------------------------

local function mode( event )
    local buttonin = event.target
     
    local phase = event.phase
    if "began" == phase then
            display.getCurrentStage():setFocus( buttonin )
    else
        if "ended" == phase or "cancelled" == phase then
            local click = audio.loadStream( "musica/click.mp3" )  
            local clickChannel = audio.play( click, { loops = 0 } )
            display.getCurrentStage():setFocus( nil )
            if mode1.isVisible == true then
            mode1.isVisible=false
            mode2.isVisible=true    
            gameMode = 2

            else
            gameMode = 1 
            mode1.isVisible=true
            mode2.isVisible=false
            
            end

        end
    end
 
    return true
end
buttonin:addEventListener("touch", mode)


local function play( event )
    playButton = event.targetlocal 

    local phase = event.phase

    if phase=="began" then 
        display.getCurrentStage():setFocus(playButton)

    else
        if phase == "ended" or phase== "cancelled" then
        display.getCurrentStage():setFocus(nil)
        local click = audio.loadStream( "musica/click.mp3" )  
        local clickChannel = audio.play( click, { loops = 0 } )
        if gameMode ==1 then
            composer.removeScene("mainMenu")
            composer.gotoScene ("modoBarra")

        elseif gameMode == 2 then
            composer.removeScene("mainMenu")
            composer.gotoScene ("modoLivre")



        end
        end
    end

    return true

end
playButton:addEventListener("touch", play)

local function credits( event )
    creditsButton = event.targetlocal 

    local phase = event.phase

    if phase=="began" then 
        display.getCurrentStage():setFocus(creditsButton)

    else
        if phase == "ended" or phase== "cancelled" then
        display.getCurrentStage():setFocus(nil)
        local click = audio.loadStream( "musica/click.mp3" )  
        local clickChannel = audio.play( click, { loops = 0 } )     
            composer.removeScene("mainMenu")
            composer.gotoScene ("credits")         
        end
    end

    return true

end
creditsButton:addEventListener("touch", credits)

-- -------------------------------------------------------------------------------

-- Listener setup
scene:addEventListener( "create", scene )
scene:addEventListener( "show", scene )
scene:addEventListener( "hide", scene )
scene:addEventListener( "destroy", scene )
-- -------------------------------------------------------------------------------

return scene