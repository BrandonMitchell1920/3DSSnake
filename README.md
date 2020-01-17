I ported my snake game to the 3DS!  I will be making many more 3DS applications as time goes on.  This is basically just running 
in a console, so nothing too crazy yet.  Yes, I realize my file structure is wacky with all headers, so I will change that in 
future projects.  

I have included the source code, the images and audio I used, some tools I used to build the .cia and .3ds, and the pre-compiled
.3dsx, .smdh, .3ds, and .cia, so you don't need to compile it yourself (I found that incredible annoying when I used to not know
how to compile the files and/or couldn't due not having my own computer).  The .3ds and .cia are in the CIABUILDER-master.  Use 
the tools in there for your own projects.  Also, the documentation.md is a file including all of the ctrulib functions.

Anyhow, There are three game modes.  One is the normal snake, one is two snakes (one on each screen), and the third is just a sped
up version of the first.  You start at a menu that lets you choose.  Pressing start will terminate a game if in a game and exit
the program if in the menu.  There is also an exit option in the menu that does the same thing.  It does keep track of your score.
Intially, it will be zero, but it will go up after the first game to at least five.  Exiting the game saves your score.  A file is
created automatically is there is none, so don't bother about creating one.  The .3dsx and .cia share the same save file, so if you
install one first, play, and then install the other, you don't have to worry about losing your score.  It is saved to the root of 
the SD card as a .hiss file.  Get it?  .hiss because it's a snake?  Installs like every other homebrea program.
