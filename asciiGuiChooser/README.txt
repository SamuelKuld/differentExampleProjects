In order to understand the goal of this, you should probably understand what I was struggling with at the time. 

In short, I was too lazy to follow tutorials or Visual Studio 2019 or such in order to properly compile GUI programs using GUI libraries such as OpenGL. So I decided, instead of working with a whole new area (Not the best choice, mind you), I decided to completely make an ASCII 2 Dimensional Engine from scratch using Vector Based mechanics. 

This is how it came about,

During a simulated 9-5 experience, I decided I would make an engine only ASCII Based. "."s to represent empty space, and a "0" to represent full space. Then I decided, "Wouldn't it be cool if you could choose options that are text based?", so I decided to make that a feature using several extra functions.

One of the largest weaknesses of this program is its efficiency. The way I created a screen buffer only using the terminal was spawning the "cls" host process included for clearing the Window's terminal/command prompt. This... Is incredibly slow. It takes about one tenth of a second to complete. Making a 50/50 tile grid to be incredibly difficult to navigate comfortably. 

The primary thing I learned from this is that sometimes the easiest option is not the best. But with that in mind, I do think that this helped me understand 2 dimensional vectors loads more than I did before. I was able to complete a whole lot of other things after learning that. 


So, with that said, here's how to use this,

1 ) There is a preset vector inside the source code in the main function that allows you to add words to choose within the GUI. For your sake, I added the presets of "Martha", "Joe", and "Pepe". Believe it or not, I know no one with those names. I picked completely random names off the top of my head.

2 ) In order to move, instead of using the arrow keys I assigned it to "W A S D" movement controls. Not the most traditional, but do-able. "W" for up (towards the top of the screen), "S" for down, "A" for right, and "D" for left. 

3 ) In order to select a specific menu, you need to bring the cursor ("0") to the words. At the first frame, the cursor will not show up. That is because the cursor's position is not instantiated until after you move. Simply press one of the characters in "WASD" to move. With that said, once you have moved over one of the names, it should show that you are touching the name in the lower left of the console. If you select "E", it will allow you to access that menu.

4 ) Simply press any character to exit the current menu that you are in

And here is the applications that you could have with the program,

I suppose you could make an ASCII Game with a similar concept as I have made using this. You could also make a menu for, say, automating emails. I plan to convert all this to be "header friendly" so that someone could import it treating it as a library and allow for them to construct their own programs using it. But for now I think it will stay as is. 

As far as everything goes with this project, it is completed. I think I have completed the goal of it, at the least. I was able to persist with something that was not the most fun to make yet still a piece of my experience that allowed me to learn something. 