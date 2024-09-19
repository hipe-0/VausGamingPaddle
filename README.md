# VausGamingPaddle
Arkanoid inspired game paddle for playing Arkanoid 1 or 2 retro games or any other breakout-inspired ball game of the 90's.
The paddle only works if it is played at the bottom of the screen.
The arduino micro powered device is 
- emulating a mouse with only X direction and featurint only 1 button (= 1 is enough for Arkanoid game)
- the main sensor bar is a very smooth large linear potentiometer, like the ones found on DJ mixer devices
- paddle movements are accompanied by led effect when moving and firing (see video attached 20240919_225736.mp4)
- handles the left and right corners by moving the mouse faster
- features a mouse acceleration (not fully linear)
- sentitivity is can be changed (per game) by user using a potentiometer. Useful as screen resolution may differ from one game to the other.
- when idle for a few seconds, starts a beautiful led fireworks demo called "DemoReel100" by Fastled, found here :https://github.com/FastLED/FastLED/tree/master/examples/DemoReel100
- body is 3d printed (models are to be found for free on thingiverse, link for download for free : https://www.thingiverse.com/thing:6772436 )
- main paddle element is shaped to resemble the Arkanoid 1 spaceship
- connexion to a PC or retro console via standard USB A plug
![20240919_225709](https://github.com/user-attachments/assets/4eaff215-005a-4725-a97a-6353222b39ec)

# Bill of Material:
- 1x Arduino micro
- 1x WS2812B led strip cut to a length of 57 leds, density: 144 leds / meter
- 1x Smooth linear potentiometer 128mm 10KOhm
- 1x 3d printed body with optional back cover
- 1x Mini rotational linear potentiometer 100KOhm
- 1x Resistance 1KOhm
- 1x led
- 1x capacitor 1uF 63v
- 1x arcade button switch
- 1x prototype soldering board
- some cables
- solder
- hot glue

![2024-02-04 Vaus Gaming paddle shematic v0 01_bb](https://github.com/user-attachments/assets/390cd52d-bf6a-49aa-a363-2858c70ceaec)

