# Robo-Arm
6 jointed arm and controller <br />
Project based on https://www.youtube.com/watch?v=wI4Jh-T0Tlo&t=794s with added mirrored controller variation <br />

Reference for 3D prints <br />
Arm - https://www.dropbox.com/s/gp74rmva8efm28f/Arduino%20robot%20arm%20files%20%2B%20step.zip?dl=0&file_subpath=%2FArduino+robot+arm+files+%2B+step (altered parts are in AlteredArm folder, some parts will need to be drilled or dremeled to fit) <br />
Controller - https://github.com/BuildSomeStuff/CompactRoboticArm/blob/main/P.O.T.%20Arm%20Controller%20-%20STL.stl (Updated controller with 6th axis and pen in /Models/Controller) <br />

# Parts

Arduino Mega <br />
Ramps 1.4 <br />
DRV8825 (x6) <br />
Nema 17 Bipolar 40mm 45Ncm 2A (x2) <br />
Nema 17 Stepper Motor with 5:1 Planetary Gearbox <br />
Nema 14 Stepper Motor Bipolar 0.5A 7Ncm 0.9deg <br />
Nema 14 Bipolar 1.8deg 5Ncm 0.4A <br />
Nema 8 Bipolar 1.6Ncm/2.3oz.in 1.8deg 28mm 0.2A <br />
608 Bearings (x2) <br />
625 Bearings (x6) <br />
51104 Thrust Bearing <br />
6002-2RS Bearing (x4) <br />
5mm Aluminum Rod <br />
GT2 Belts <br />
10k Ohm Potentiometers (x6) <br />
Variety of M3, M4, and M8 bolts (M8 for the stand) <br />
Micro Limit switches (preferably ones with a wheel) <br/>

# Assembly

Setting up stepper motors with the code before assembly is recommended to ensure they are moving in the correct direction. Failure to do so can result in broken parts or torn timing belts. <br/>

Use a piece of patching cloth and super glue to cut and connect GT2 Timing belts to the correct lengths. This can be demonstrated here (https://www.youtube.com/watch?v=T9wjR0HEk3I). <br/>
