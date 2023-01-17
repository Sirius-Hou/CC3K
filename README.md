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

Enemies are the mortal foes of the player character. In a traditional rogue-like, the enemy character would have some degree of artificial intelligence. However, for simplicity in CC3k+ enemies move one square randomly within the confines of the chamber they were spawned in. Except dragons, who always guard a treasure horde. Enemies can be one of:
1. **vampire** (50 HP, 25 Atk, 25 Def),
2. **werewolf** (120 HP, 30 Atk, 5 Def),
3. **troll** (120 HP, 25 Atk, 15 Def),
4. **goblin** (70 HP, 5 Atk, 10 Def),
5. **merchant** (30 HP, 70 Atk, 5 Def),
6. **dragon** (150 HP, 20 Atk, 20 Def, always guards a treasure horde),
7. **phoenix** (50 HP, 35 Atk, 20 Def).

Merchants can be attacked and slain by the player character. Attacking or slaying a Merchant will cause every Merchant from that point forward to become hostile to the player character (and will attack them if they pass within a one block radius).

Dragons always spawn in a one block radius of its dragon horde pile of treasure (see Treasure). That is, if a dragon horde is spawned then a dragon is spawned. Upon their demise, any enemy that is not a dragon or a merchant will drop 1 gold. This gold is immediately added to the player character’s total.

Enemies (except dragons, who are stationary) move randomly 1 floor tile at a time, assuming the floor tile is unoccupied (see Section for floor tile description). An enemy can never leave the room it was spawned (created) in. Note that enemies should be moved in a line by line fashion. That is, starting at the leftmost enemy move all enemies on that row and then move to the next row starting with the leftmost. Any particular enemy should only be moved once per player action (e.g. moving to a line that has not been processed does not grant an extra move). However, should the player character be within a 1 block radius of an enemy then the enemy will always attack the player character.

Enemies are denoted on the map as follows: V(ampire), W(erewolf), N(goblin), M(erchant), D(ragon), X(Phoenix),
T(roll), M(erchant).


### Items

#### Potions

Potions are of two types: positive and negative. Potions can provide the player character with positive and negative bonuses as outlined below. Regardless of the potion itself, all potions are denoted on the map with a **P**. A player may not hold any potions. Accordingly, a potion cannot be used unless a player is standing within a 1 block radius of it. The effects of a particular potion are not known until it is used for the first time, e.g. the player character will not know what a potion does until they use it for the first time in a session. However, they will only learn about the effects of that particular potion. Other potions will not have their effects revealed. The exception is for purchasing potions from the Merchant2, which have their abilities displayed.

#### Positive Potions:

* Restore health (RH): restore up to 10 HP (cannot exceed maximum prescribed by race)
* Boost Atk (BA): increase ATK by 5
* Boost Def (BD): increase Def by 5

#### Negative Potions:

* Poison health (PH): lose up to 10 HP (cannot fall below 0 HP)
* Wound Atk (WA): decrease Atk by 5
* Wound Def (WD): decrease Def by 5

The effects of RH and PH are permanent while the effects of all other potions are limited to the floor they are used on. For example, using a BA potion will only boost the player character’s Atk until the beginning of the next floor. Note that the PC’s Atk and Def can never drop below 0.

#### Treasure

Treasure in CC3k+consists only of gold. Gold can be in several types of piles: **normal** (value 1), **small horde** (value 2), **merchant hoard** (value 4), and **dragon hoard** (value 6). Thus, a dragon must always protect a dragon hoard whenever it randomly spawns. A dragon horde can only be picked up once the dragon guarding it has been slain. Gold, regardless of type, is denoted by ’**G**’ on the map. A merchant horde is dropped upon the death of a merchant.


#### Major Items

In the game of CC3k+there are only two major items - one which appears once per floor, and one that appears only once in the game.

The **Compass** is an item which appears once per floor. Every time a floor is generated (see floors section below) one enemy is chosen to be the holder of the compass. When that enemy is slain the Compass drops at their location denoted by a ’**C**’. When the player picks up the stairs then become visible.

The **Barrier Suit** is an item which appears once per game. When it appears it should be denoted by a ’**B**’, and it follows the same rules as a dragon horde. That is, the Barrier Suit is always spawned being protected by a dragon, and cannot be picked up until that dragon has been slain.


### Floors

Levels are generated to consist of the 5 chambers connected in the manner outlined in Figure 1.

The player character is spawn randomly in a chamber (every chamber is equally likely) but it will never be the case that the player spawns in the chamber with the stairs going down to the next level. Note that the stairway and player character may be spawned with equal probability on any floor tile in a chamber. That is, a larger chamber should be no more likely to spawn the PC/stairs than a smaller chamber, where any floor tile in the selected chamber is equally likely to spawn the PC/stairs. Stairs are denoted by ’**\\**’, but only become visible on that floor once the player has picked up the compass for that floor. That is, until the compass is picked up the stairs are not denoted on the screen at all. Instead, the stairs looks like a regular tile, however if the player character walks over the stairs tile without the compass they will still take them down to the next level. 

Potions are spawned with equal probability on every level (e.g 1/6 chance to spawn a particular potion) and any chamber has a 1/5 chance to spawn a potion, such that any square in the room has an equal probability of spawning a potion. 10 potions are spawned on every floor.

We might like to have gold spawn more or less frequently as the game gets more difficult. However, to again simplify design the spawn rate of gold is 5/8 chance of normal, 1/8 dragon hoard, 1/4 small horde. Chambers are equally likely (as are floor tiles in any particular chamber) to spawn gold. 10 piles of gold are spawned on every floor.

With the exception of dragons, enemies have the following probability distribution of being spawned:
* Werewolf: 2/9
* Vampire: 3/18
* Goblin: 5/18
* Troll: 1/9
* Phoenix: 1/9
* Merchant: 1/9

20 enemies are spawned per floor. Every chamber is equally likely to spawn any particular monster (similarly for floor tiles).

Note that multiple objects (enemies, gold, and potions) cannot occupy the same cell on the game board. That is, no two objects can ever occupy the same space. Except in the case of gold, which is picked up when the player character walks over it.

Additionally, when the PC would move onto the stairway down to the next level (e.g. the PC is in the block to the immediate east of the stairs and the player enters the command to move 1 block west) the next floor is generated and displayed to the player.

Additionally, items and enemies should only ever spawn on a floor tile and never in a doorway, passage, or the stairs leading down to the next floor.


#### Combat

By default, all enemies except for Merchants and Dragons are (by default) hostile to the player character. If the player character enters within a 1 block radius of any hostile enemy, they will attempt to attack the player character. Dragons are only hostile when the player is next to (read: in the 1 block radius of) its dragon horde and never hostile otherwise. Enemies never pursue the player character. If the player character is not within a 1 block radius of the enemy then it moves. Recall that Merchants can become hostile when one is attacked/slain by the player character.

Combat is resolved as follows: Enemies will auto-attack players given the previously specified criteria, however, there is a 50% chance their attack misses. The player character has the option of attacking in a 1 block radius around them. Recall, that the PC has initiative and always attacks first.

Damage is calculated as follows: *Damage(Defender) = ceiling((100/(100 + Def(Defender))) ∗ Atk(Attacker))*, where Attacker specifies the attacking character (enemy or PC) and defender specifies the character being attacked. Thus, in a single round a character can be both an attacker and a defender.

If the player character has the Barrier Suit, then their damage calculation is changed such that $Damage(P C) = ceiling(\left( \frac {Damage(Def ender)}{2} \right)$. That is, the damage the player character takes is exactly half the damage they would have taken otherwise (rounded up).

### Display

The display of our version of CC3k+ is relatively simple, Figure 1 depicts an empty board. Walls are denoted by ‘|’ and ‘−’, doorways by ‘+’, and passages by ‘#’. Floor tiles that can be walked upon are denoted by ‘.’. Chambers are denoted by the smaller polygons inside the larger rectangle. The player character can only ever occupy a passage block, doorway block, or a floor tile inside a chamber. The player character can see in all chambers simultaneously, e.g. through walls or doors. Figures 2, 3, 4, 5, depict various board states. Note that Figure 1 represents a completely empty game board and is meant to act as a reference of what the game board would look like before any generation occurs.

We also use ASCII colour output codes to make each system component more visible and can be easily spotted (as shown below). In our termcodes.h file, we defined several different color codes which are used to set the color of texts we print to the standard output stream. We used this to make different game elements stand out in the text display. For example, we used the color yellow to show the player, red to show all the NPCs, cyan to display potions, green to show treasures and the barrier suit, etc. We also printed the following additional information below the grid:
1. the current state of the player character, which includes
the HP, attack, defence, and coin;
2. the area around the PC (the NPCs and potions
within two units of the PC);
3. the action of the player for the current round;
4. the combat details with NPC if there were any along when printing the grid.

![image](https://user-images.githubusercontent.com/118148925/210158459-13636419-5259-47b3-a26a-dabd3c4c3066.png)

### Command Interpreter

Initially, the game will demand the player enter one of the specified races or quit. Play will then continue in the obvious way until the player restarts, reaches the end of floor 5, the PC dies, or the player quits. If the player reaches the end of the game or their character is slain, give them the option of playing again. Otherwise, do the appropriate thing (restart or quit). The following commands can be supplied to your command interpreter:
* no,so,ea,we,ne,nw,se,sw: moves the player character one block in the appropriate cardinal direction
* u [direction]: uses the potion indicated by the direction (e.g. no, so, ea)
* a [direction]: attacks the enemy in the specified direction, if the monster is in the immediately specified block (e.g. must be one block north of the @)
* h, e, d, o: specifies the race the player wishes to be when starting a game
* r: restarts the game. All stats, inventory, and gold are reset. A new race should be selected.
* q: allows the player to admit defeat and exit the game.

Note that the board should be redrawn as appropriate every time a command is entered


### Ending the Game and Scoring

A game session ends in one of the following ways:
* the player character reaches the stairs on floor 5,
* the player character’s health reaches 0, or
* the player restarts the game.

A player’s score is only generated in the first of above two cases. Score is determined by the amount of gold they have collected in their current character’s life time. Except for humans who have a 50% increase to their score.

![image](https://user-images.githubusercontent.com/118148925/210158520-b12bb690-555f-4b7e-9a5d-f61c2c572144.png)

![image](https://user-images.githubusercontent.com/118148925/210158525-a628e343-1c1a-4a08-a813-d3f494241386.png)

![image](https://user-images.githubusercontent.com/118148925/210158528-850ba3d7-1a25-4757-a54b-207ef74191ab.png)

![image](https://user-images.githubusercontent.com/118148925/210158529-162a230c-7b47-40e8-9b8d-3d0434b51bf7.png)

![image](https://user-images.githubusercontent.com/118148925/210158534-0b02bd6d-6d69-462e-915b-2e67a3a1f8f1.png)


(*Team Project for CS246 (University of Waterloo)*)


