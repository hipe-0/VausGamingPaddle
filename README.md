# VausGamingPaddle

I created a 3D printed, open sourced, arduino based, "Arkanoid"-inspired game paddle for playing Arkanoid 1 or 2 games realistically.

![20240919_225709](https://github.com/user-attachments/assets/4eaff215-005a-4725-a97a-6353222b39ec)

https://github.com/user-attachments/assets/acdfcfb8-230b-40b3-95ee-57034bec4c22

Also works with other "breakout" inspired ball game that accept USB mouse as input.

Reference:
https://fr.wikipedia.org/wiki/Arkanoid

This game controller is 
- emulating a mouse with only X direction
- has 1 button (for Arkanoid game it is used as fire button)
- main sensor bar is a very smooth large linear potentiometer, like the ones found on DJ mixer devices
- paddle movements are accompanied by led effect when moving and firing
- handles the left and right corners by moving the mouse faster
- some mouse acceleration based on mouse speed
- sentitivity can be changed by user using a potentiometer. Useful as screen resolution may differ from one game to the other.
- when idle for a few seconds, starts a beautiful led fireworks demo called "DemoReel100" by Fastled, found here: https://github.com/FastLED/FastLED/tree/master/examples/DemoReel100
- body is 3d printed (models are to be found for free on thingiverse, link for download for free : https://www.thingiverse.com/thing:6772436 )
- main paddle element is shaped to resemble the Arkanoid 1 spaceship
- connexion to a PC or retro console via standard USB A plug

https://github.com/user-attachments/assets/506902b2-bb77-4744-a214-cb1bdf7f73fd


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

# Shematic
![2024-09-23 Vaus Gaming paddle shematic v1 02_bb](https://github.com/user-attachments/assets/1107ea42-73ac-42d4-ab53-eb1af8b17601)
![2024-09-23 Vaus Gaming paddle shematic v1 02_schéma](https://github.com/user-attachments/assets/c4b865e1-c4c2-4b7e-8709-02a82149234d)
