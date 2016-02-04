# colliderUnlocker
Project to make UMD's hackerspace more accessible.

#### Story
When Terrapin Hackers was founded, the members needed a place to work. Enter Collider. Collider is a 1000 sq. ft. room in the basement of the chemistry building at the University of Maryland. The space is filled with a ton of hardware and tools to fulfill any hacker's needs, but the only people who could get in were those with swipe access.

#### What we did.
Someone had created this piano out of Terrapin Hackers' stickers and <a href = "https://www.adafruit.com/products/1361">velostat</a>. 

<img src = "https://github.com/imparikh/colliderUnlocker/blob/master/images/velostat.jpeg" width=500px>

We decided that there would be a specific button order to getting the door unlocked. How do we unlock the door? With a servo.

Our arduino waits for 4 buttons to be pressed, and then compares the sequence with the correct one. If it is correct:
```
void opener(){
      myservo.write(179);
      delay(10000);
      myservo.write(0);
      delay(6000);
      myservo.write(90);
      reseter(1000);
    }
  ```
  That's it. There was a little trial and error to see how long we had to wait for the door to unlock and the let the string back. After it was all wired up, it looked like this.
  
<img src = "https://github.com/imparikh/colliderUnlocker/blob/master/images/precut.JPG" width=500px>

We cut the wires so it looked presentable, and the outside looked like this:

<img src = "https://github.com/imparikh/colliderUnlocker/blob/master/images/final.JPG" width=500px>
#### Final
Check out the final product <a href = "https://www.youtube.com/watch?v=Rq76U-nN76M">here</a>.
