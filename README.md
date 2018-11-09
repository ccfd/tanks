# Tanks!

## The premise
This is a simple game in which you have a tank, and you have to **kill everybody**. The idea of the game is that you have to write a C++ class, which will control the tank. And **kill everybody**.

## Tournament
There will be an online tournament of the created bots.

### How to participate
Participation is restricted to the students of [MEiL PW](https://meil.pw.edu.pl/) for now.
To participate you have to scan a QR code on the corridor of the faculty.
After scaning the code you will have your private copy of repository.
You can edit out the `Bot/BotPlayer.cpp` to develop your AI player.

### Compilation and Running

Under **Linux** you should be able to use `make`, and run the game with `./main`.
In **Windows** you can open the Visual Studio project.
The game has some commandline options:

- `-f` - full screen mode
- `-m` - mute sound
- `-o nubmer` - number of random obstacles
- `-e` - display hitboxes
- `-x` - display only box extents
- `-t seconds` - set time limit
- `-fps fps` - fps (default 24)
- `[bot name]:[number of tanks]` - you can supply the list players (bots) to include in the fight (with number of respective tanks)

### How we include your bot
Your repository will be cloned (every some time).
We then run preliminary tests, and if your repo is working, we copy your `Bot/...` files.
Then we replace the name of the namespace `MyNamespace` (so that there will not be conflicts with other bots), and player name `SimpleBot`.
This will be done just as text replacement, so remember not to mess with these.

### Update your repo
As there will be changes happening to the main repository, it is important to update your reposiotory with the original.
To do it, first add the address of the upstream repo:
```bash
git remote add upstream https://github.com/ccfd/tanks.git
```
Then you have to fetch the data from the upstream, and merge:
```bash
git fetch upstream
git merge upstream/master
```

### Hacking
Yes.
We know you can hack this tournament in 666 ways. Yeah. Good for you.
If you want to hack something, hack Putin's girlfriend instagram account.
See how it goes. This game is to have fun creating AI for a funkin' tank,
not to deal with wannabe hackers making fork bombs.

## If you cannot participate
If you cannot participate in the tournament, but would like to play with the game, just fork it.

## Disclaimers

### C++ course
This repository is used in a course of C++ at MEiL PW (https://meil.pw.edu.pl/ZA)

### Author
[Łukasz Łaniewski-Wołłk](https://github.com/llaniewski/)

### Pictures and sound
The media used in the game are described [here](media/README.md)
