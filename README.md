# Music Converter by tyzrichard
This is a simple program in C that converts music from one scale to another. I made this as part of my Year 1 Programming Project under my school.

This project is kinda weird(?) in that we are only allowed to use concepts taught before the point of submission despite me knowing all the taught concepts beforehand - its all pretty basic (except the last one). Due to these restrictions, this project will be scaled up in three distinct phases, each having more capabilities than the previous one:

### Version 1
Being restricted to printf, scanf, simple variables and arithmetic (no if-else, loops, or other 'complex' concepts), the simplest version of the code just takes in a singular music note, the number of semitones to shift it out, and simply just outputs a summary of the user's inputs.

### Version 2
With If-Else statements being allowed, I upgraded my program to convert music notes from C Major to any of the following scales:
- E Major
- C# Minor
- Ab Major
- F Minor
basically the majors and minors with the 4 sharps/flats

What I wanted to achieve here was my program being able to convert from a Major to Major scale, and a Major to Minor scale.

### Version FINAL - Extra Features, Scaling and QOL Improvements
I'll be serious: the above two versions were finished REALLY QUICK. Well, that's to be expected seeing how it was so basic.
And then I decided to scale it up using extra concepts taught outside class and make it an actually good music converter. Here's some examples of what I did:
- Used loops to allow users to **enter more than one note** in order to get an entire string of converted notes.
- Added lots of **functions** to make my code more modular, with functions such as searching for a note or scale within a list, and printing out an ASCII piano.
- Finally used **arrays** to shift those music notes
- Allowed conversion of notes from C Major to ANY Major scale
- And then, I made it possible to convert from **any Major scale to any Major scale, and any Minor scale to Minor scale**. Just so you know, there's 24 music scales in total!
- For those who aren't as acquianted with music theory and how scale conversion works, I also created a little in-code **Music Theory Guide** to the keys of a piano, the 24 music scales and how transposition actually works. There's also options to reflect the latter when using the program the transpose!
- And lastly, **Input Validation**. Can't have the program crashing due to incorrect inputs!

### Learning Takeaways
While I've played around with Python and a little bit of web development in the past, this was my first actual project in C Programming. Being a low-level knowledge, trivial things like manipulating strings or grabbing stuff from arrays became very troublesome here.

Trying to implement a function or piece of code created many bugs and required me to do a lot of research on how the program works and workarounds I could take. Through this, I've learned many useful commands such as fgets, strcpy, strcmp, and concepts such as string arrays (arrays in an array) and memory allocation (which I chose not to delve too deep into).

Programming in C was thus a very refreshing experience. It really gave me that sense of starting anew, like how a complete beginner to code would feel. 

Have fun reading through my code, and thanks for being here :D