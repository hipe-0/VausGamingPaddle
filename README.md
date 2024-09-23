# VausGamingPaddle

I created a 3D printed, open sourced, arduino based, "Arkanoid"-inspired game paddle for playing Arkanoid 1 or 2 games realistically.

![20240919_225709](https://github.com/user-attachments/assets/4eaff215-005a-4725-a97a-6353222b39ec)

https://github.com/user-attachments/assets/acdfcfb8-230b-40b3-95ee-57034bec4c22

Also works with other "breakout" inspired ball game that accept USB mouse as input.

Reference:
https://fr.wikipedia.org/wiki/Arkanoid

# Game controller description
- low, near zero latency
- USB A to usb Micro cable required
- compatibility with PC emulators or consoles
- The device emulates a mouse with only X direction
- 1 game button (for the Arkanoid game it is used as fire button)
- Main sensor bar is a large linear potentiometer, like the ones found on DJ mixer devices
- Paddle movements are accompanied by led effect when moving and firing
- Handles the left and right corners by moving the mouse faster
- Some mouse acceleration is added based on mouse speed, to improve reactivity
- Sensitivity can be changed by user using a potentiometer. Useful as screen resolution may differ from one game to the other.
- When idle for a few seconds, starts a beautiful led fireworks demo called "DemoReel100" by Fastled, found here: https://github.com/FastLED/FastLED/tree/master/examples/DemoReel100
- 3D printed model
- Main paddle element is shaped to resemble the Arkanoid 1 spaceship

https://github.com/user-attachments/assets/506902b2-bb77-4744-a214-cb1bdf7f73fd

# 3D models for 3D printing
3D model are available for free download on thingiverse
https://www.thingiverse.com/thing:6772436 

# Bill of Material:
- 1x Arduino micro (rev 3) 
- 1x WS2812B led strip cut to a length of 57 leds, density: 144 leds / meter
- 1x Smooth linear potentiometer 128mm 10K
- 1x 3D printed PETG body (dowload the files for free for 3D printing)
- 1x Mini rotational linear potentiometer 100K
- 1x Resistance 1K
- 1x led
- 1x capacitor 1uF 63v
- 1x arcade button switch diameter 24mm
- 1x prototype soldering board
- 1x USB cable, 2m, USB A male to micro USB male
- some cables to solder
- solder
- hot glue

# Shematic
![2024-09-23 Vaus Gaming paddle shematic v1 02_bb](https://github.com/user-attachments/assets/1107ea42-73ac-42d4-ab53-eb1af8b17601)
![2024-09-23 Vaus Gaming paddle shematic v1 02_schéma](https://github.com/user-attachments/assets/c4b865e1-c4c2-4b7e-8709-02a82149234d)

# PCB Printed Circuit board
Not tested yet, but you can try my new PCB design (file in repository) for this project
![2024-09-23 Vaus Gaming paddle shematic v1 02_circuit imprimé](https://github.com/user-attachments/assets/4b17c5f1-ba64-4fda-b940-1f1fbeddcd6f)
