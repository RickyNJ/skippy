Functionalities

TODO:
everything lmao

TOLEARN:
benchmarking in c++
unittesting in c++


Application on startup
- Connect to MQTT broker, fetch all active topics?
- Initiate OpenGL Context

*****FOR MVP*****

Each tile sends data to own MQTT topic.
Each Topic has dedicated listener class with own Tile class. 

The Tile class holds only the most recent data in the mqtt topic.
one MQTT listener per topic.

2 other processes fetch data from the the Tile class? Maybe use mediator pattern?
These processes fetch data at variable intervals.

Process 1:
draw to screen (OpenGL)
60 fps+

Process 2:
write to disk
100+ measurements per second


****LATER FUNCTIONALITIES****

Replaying functionalities


Non funcional requirements:
Interchangability of MQTT broker
Maintaining minimal performace required for upto 4 tiles at 20 by 20 resolution
Drawing and writing to disk should be non blocking tasks
The drawing code must not know if it is real time or playing a replay


Ramblings:
For the replay functionalities I could probably instantiate the required amount of Tile classes.
And stream the data to those Tile classes as if it were real time.
