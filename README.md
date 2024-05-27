# Music Converter by tyzrichard
This is a simple program in C that converts music from one key to another. I made this as part of my Year 1 Programming Project taught in school.

This project is kinda weird(?) in that we are only allowed to use concepts taught before the point of submission (4 chapters, 4 submissions, one at the end of each) despite me knowing all the taught concepts beforehand - its all pretty basic. Due to these restrictions, this project will be scaled up in four distinct phases (five if you count the final), each having more capabilities than the previous one:

### Version 1
Being restricted to printf, scanf, simple variables and arithmetic (no if-else, loops, or other 'complex' concepts), the simplest version of the code just takes in a singular music note, the number of semitones to shift it out, and simply just outputs a summary of the user's inputs.

### Version 2
With If-Else statements being allowed, I upgraded my program to convert music notes from C Major to any of the following scales:
- E Major
- C# Minor
- Ab Major
- F Minor
basically the majors and minors with the 4 sharps/flats

What I wanted to achieve here was my program being able to convert from a Major to Major key, and a Major to Minor key.

### Version 3
Now we get to play around with While Loops! The scaleup is simpler this time: I use the loop to allow a user to enter more than one note in order to get an entire string of converted notes.

### Version 4
With the introduction of Functions, I decided to simplify my code by turning the semitone shifter into a function. Other than that, I also introduced more functions such as [elaborate here when I get to it yea]

### Version FINAL - Extra Features, Scaling and QOL Improvements
I'll be serious: the above four versions were finished REALLY QUICK. Well, that's to be expected seeing how it was so basic.
And then I decided to scale it up using extra concepts taught outside class and make it an actually good music converter. Here's some examples of what I did:
- Finally usec arrays to shift those music notes
- Allowed conversion of notes from C Major to ANY key
- And then, I made it possible to convert from ANY key to ANY key.
- For those who aren't as acquianted with music theory and how key/scale conversion works, I also created the options to allow the program to explain in detail (how detailed, you can adjust for yourself) how exactly the conversion worked. It can also give simple music theory lessons, i guess.
- Input Validation. Can't have the program crashing due to incorrect inputs!
- And last but not least, it can auto-detect the key of the notes that you enter, saving time and effort! Its a cool feature that _maybe_ works all the time. I'm not training a model for this little project.

