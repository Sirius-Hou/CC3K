# The Game of ChamberCrawler3000+ (CC3K)
This is a customized CC3K game designed in C++. This project implements a game that mimics the video game ChamberCrawler3000+ (CC3k+), which is a simplified rogue-like (a genre of video game based upon the game Rogue1 - http://en.wikipedia.org/wiki/Rogue_(video_game)).
ChamberCrawler3000+ is a game where the player character moves through a dungeon and slays enemies and collects treasure until reaching the end of the dungeon.

### Some Definitions
It is understandable that this type of game may be new to readers of this document. Accordingly, some definitions are provided
here to aid in the reading of this document.
*Definition 1*: A **character** is a person/animal/thing in the game of CC3k+. This can be either the player character (PC), who
is controlled by by the player of the game, or non-playable characters, who are strictly enemies in CC3k+.\\
*Definition 2*: An **item** is something the player character can pick up or use.
*Definition 3*: A **chamber** is an individual room in the game of CC3k+. Chambers are connected by passages.
*Definition 4*: A **floor** in CC3k+is a predefined configuration of 5 chambers with connecting passageways. Figure 1 below depicts
an empty floor. Note that the configuration is the same for every floor in a game of CC3k+.
*Definition 5*: **Health Points (HP)** is the representation of a character’s health (both enemies and the player character). When
a character’s HP reaches 0, they are slain. For an enemy this means that they are removed from the floor and a tidy sum
of gold is given to the player character. When the player character has 0 HP then the current game ends.
*Definition 6*: **Attack (Atk)** is the representation of a character’s strength. This is how hard a character can hit another
character. Though in CC3k+conflict is solely between the player character and non-playable characters.
*Definition 7*: **Defense (Def)** is the representation of a character’s toughness. This is how hard a character can be hit by
another character.
*Definition 8*: A **cell** is either a wall, floor tile, doorway, or passage.
*Definition 9*: Something is **spawned** means that the particular something (an enemy, gold, etc) should be generated and
placed on the board.
*Definition 10*: A **1 block radius** denotes the 8 adjacent cells to the character or item.
![image](https://user-images.githubusercontent.com/118148925/210157617-28403458-3597-4dac-9dc4-8502803be60e.png)



