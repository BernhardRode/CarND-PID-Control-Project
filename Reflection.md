# CarND-PID-Control-Project
## Reflections

I've implemented a simple PID controller in C++.

* P Component : it compensates the actual error
* I Component : it compensates the long term error
* D Component : it compensates the overshooting

It is able to drive a car around the track in the Udacity simulator.
A video of my final Solution is available on Youtube:

[![PID Controlled Simulator](https://i9.ytimg.com/vi/I7VB-3qC2Ps/hqdefault.jpg?sqp=CKCSxs0F&rs=AOn4CLCBofo6Bw75B-pIGCeLBApcRlBivA)](http://www.youtube.com/watch?v=I7VB-3qC2Ps)


At the beginning I've used the parameters from the lessons before:

* Kp: 0.2
* Ki: 0.004
* Kd: 3
* throttle: 0.1

These worked kindof... 

so I played around with modifiying the parameters and ended up with:

* Kp: 0.1
* Ki: 0.002
* Kd: 7.5
* throttle: 0.1

During this phase I've also added filters to flatten out outliers into my PID.cpp.

With these parameters a simple PID Controller, the car was able to drive around the track, very slowly (thottle set to 0.1).

Now I wanted to get around the track faster and started to implement tiddle based parameter optimization.

So i started to add a throttle parameter, which is also controlled by a PID. I merged the absolute PID throttle value together with the current steering angle.

The car is now able to drives around the track without leaving it. Speed has improved alot.

Maybe I could also add a twiddle step to find better parameters every once in a while. But so far I'm quite happy with the result.