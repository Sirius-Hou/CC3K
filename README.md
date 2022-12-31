# The Game of ChamberCrawler3000+ (CC3K)
This is a customized CC3K game designed in C++. This project implements a game that mimics the video game ChamberCrawler3000+ (CC3k+), which is a simplified rogue-like (a genre of video game based upon the game Rogue1 - http://en.wikipedia.org/wiki/Rogue_(video_game)). ChamberCrawler3000+ is a game where the player character moves through a dungeon and slays enemies and collects treasure until reaching the end of the dungeon.

### Some Definitions
It is understandable that this type of game may be new to readers of this document. Accordingly, some definitions are provided here to aid in the reading of this document.

*Definition 1*: A **character** is a person/animal/thing in the game of CC3k+. This can be either the player character (PC), who is controlled by by the player of the game, or non-playable characters, who are strictly enemies in CC3k+.

*Definition 2*: An **item** is something the player character can pick up or use.

*Definition 3*: A **chamber** is an individual room in the game of CC3k+. Chambers are connected by passages.

*Definition 4*: A **floor** in CC3k+is a predefined configuration of 5 chambers with connecting passageways. Figure 1 below depicts an empty floor. Note that the configuration is the same for every floor in a game of CC3k+.

*Definition 5*: **Health Points (HP)** is the representation of a character’s health (both enemies and the player character). When a character’s HP reaches 0, they are slain. For an enemy this means that they are removed from the floor and a tidy sum of gold is given to the player character. When the player character has 0 HP then the current game ends.

*Definition 6*: **Attack (Atk)** is the representation of a character’s strength. This is how hard a character can hit another character. Though in CC3k+conflict is solely between the player character and non-playable characters.

*Definition 7*: **Defense (Def)** is the representation of a character’s toughness. This is how hard a character can be hit by another character.

*Definition 8*: A **cell** is either a wall, floor tile, doorway, or passage.

*Definition 9*: Something is **spawned** means that the particular something (an enemy, gold, etc) should be generated and placed on the board.

*Definition 10*: A **1 block radius** denotes the 8 adjacent cells to the character or item.

![image](https://user-images.githubusercontent.com/118148925/210157617-28403458-3597-4dac-9dc4-8502803be60e.png)


### System Components
The major components of the system are as follows:

#### Player Character

By default, the player character is a **human** (who starts with 140 HP, 20 Atk, 20 Def). However, the player has the option of changing their race to something more fantastical (e.g. offer different attributes). The options include **dwarf** (100 HP, 20 Atk, 30 Def, gold is doubled in value), **elves** (140 HP, 30 Atk, 10 Def, negative potions have positive effect), and **orc** (180 HP, 30 Atk, 25 Def, gold is worth half value). In our game board, the player character is always denoted by the ’**@**’ symbol.

#### Enemies
Enemies are the mortal foes of the player character. In a traditional rogue-like, the enemy character would have some degree
of artificial intelligence. However, for simplicity in CC3k+enemies move one square randomly within the confines of the
chamber they were spawned in. Except dragons, who always guard a treasure horde.
Enemies can be one of vampire(50 HP, 25 Atk, 25 Def), werewolf(120 HP, 30 Atk, 5 Def), troll(120 HP, 25 Atk, 15 Def),
goblin (70 HP, 5 Atk, 10 Def), merchant (30 HP, 70 Atk, 5 Def), dragon (150 HP, 20 Atk, 20 Def, always guards a treasure
horde), phoenix (50 HP, 35 Atk, 20 Def).
Merchants can be attacked and slain by the player character. Attacking or slaying a Merchant will cause every Merchant
from that point forward to become hostile to the player character (and will attack them if they pass within a one block radius).
Dragons always spawn in a one block radius of its dragon horde pile of treasure (see Treasure). That is, if a dragon horde
is spawned then a dragon is spawned.
Upon their demise, any enemy that is not a dragon or a merchant will drop 1 gold. This gold is immediately added to the
player character’s total.
Enemies (except dragons, who are stationary) move randomly 1 floor tile at a time, assuming the floor tile is unoccupied
(see Section for floor tile description). An enemy can never leave the room it was spawned (created) in. Note that enemies
should be moved in a line by line fashion. That is, starting at the leftmost enemy move all enemies on that row and then move
to the next row starting with the leftmost. Any particular enemy should only be moved once per player action (e.g. moving
to a line that has not been processed does not grant an extra move). However, should the player character be within a 1 block
radius of an enemy then the enemy will always attack the player character.
Enemies are denoted on the map as follows: V(ampire), W(erewolf), N(goblin), M(erchant), D(ragon), X(Phoenix),
T(roll), M(erchant).
