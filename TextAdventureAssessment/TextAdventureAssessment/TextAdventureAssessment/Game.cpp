#include "Game.h"

Game::Game()
{
}

Game::Game()
	: playerAlive(true), winState(false), round(1), isPlayerTurn(true) 
{
}

Game::~Game()
{
}

void Game::Run()
{
	string playerName;
	cout << "Your vision is dark, yet... you can hear the echo of a noise within the void. Something that resembles a voice...\n"
		<< "It continues to repeat, over and over, each time becoming clearer than the last. Forming something of a name. Your name.\n"
		<< "Can you hear it? What is your name?\n";
	cout << "[[ Please enter a name ]]\n";
	cin >> playerName;
	Player PlayerCharacter{ playerName,"An average Pawn like any other upon first glance.\n", 70, 50, {"BREATHE", "ERUPTION","INFERNO"} };
	cout << "\n'" << PlayerCharacter.Name() << "!! Wake UP!!'\n"
		<< "As you raise your head from the pillow, standing over you is a cloaked figure with a horned skull mask.\n"
		<< "This here is a Pawn, just like yourself. You all are dressed the same, as the Emperor commands.\n"
		<< "Pawns like them and yourself only know how to defend with low-level magic, that's what makes you Pawns.\n"
		<< "The Pawn taps their foot as you continue to lay in your bed.\n"
		<< "'Get UP!! There's a Bishop waiting for you at the end of the Pawn hall, and you know Bishops.\n"
		<< "They don't like to be kept waiting. Get up and GO! Now " << PlayerCharacter.Name() << "!!'\n\n"
		<< "Your head pangs as you rise from your resting bed. Begrudginly, you put on your own mask and cloak.\n"
		<< "'Oh, and I'm locking the door behind you as it's my turn for some privacy. So get out. NOW.'\n\n";
	bool playerAlive = true;
	bool winState = false;
	while (playerAlive == true || winState == false)
	{
		Room& CurrentRoom = r1;
		if (CurrentRoom.isBattle == false)
		{
			CurrentRoom.Description();
			Action(PlayerCharacter, CurrentRoom);
			CurrentRoom = roomChange(Movement(CurrentRoom));
		}
		else
		{
			if (CurrentRoom.RoomID == 2)
			{
				cout << "As you enter the room, a voice booms from the corner from another Pawn.\n"
					<< "'You there! All these dummies have been beaten to a pulp, by yours truly. I need a live one. FIGHT ME.'\n"
					<< "The Pawn doesn't seem to give you much of a choice. Probably a good point to warm up youself.\n\n"
					<< "[[[[[[ BATTLE EXPLINATION ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]\n"
					<< "[[ During battle, you are given the option to CAST or display INFO on your spells ]]\n"
					<< "[[ When using CAST, you will be prompted to enter a spell                        ]]\n"
					<< "[[ Be careful when entering your spell, as a spelling mistake or attempting to    ]]\n"
					<< "[[ cast something you don't know will waste your turn. Don't be a fool.           ]]\n"
					<< "[[ You only know three spells as of now, those being :                            ]]\n"
					<< "[[ Inferno   || A spell of fire, causing average damage to it's target            ]]\n"
					<< "[[ Erruption || A spell of lava, causing strong damage but cost more MP to cast   ]]\n"
					<< "[[ Breathe   || A spell of air, restoring some of it's caster's HP                ]]\n"
					<< "[[ If you wish for specifics or forget during a fight, you can check with INFO    ]]\n"
					<< "[[ When using INFO, your spell's stats and current HP and MP status will display. ]]\n"
					<< "[[ However, this will also use up your turn, leaving you open for an attack.      ]]\n"
					<< "[[ Battle wisely my friend!                                                       ]]\n"
					<< "[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]\n";
				Battle(PlayerCharacter, HotHeadPawn);
				if (PlayerCharacter.HP == 0) {
					playerAlive = false;
					break;
				}
				else {
					cout << "'Woah. You really know how to hold youself, mate. Okay, you've sated my boiling blood. For now.'\n"
						<< "The Pawn sits down on a barrel in the corner, exhausted.\n";
					CurrentRoom.isBattle = false;
					r2.isBattle = false;
				}
			}
			else
			{
				Battle(PlayerCharacter, Bishop);
				if (PlayerCharacter.HP == 0) {
					playerAlive = false;
					break;
				}
				else {
					CurrentRoom.isBattle = false;
					r6.isBattle = false;
					winState = true;
					break;
				}
			}
		}
	}
	if (playerAlive == false)
	{
		cout << PlayerCharacter.Name() << " has been knocked out!\n";
		return;
	}
	if (winState == true)
	{
		cout << "After knocking out the Bishop, you have no choice but to exit the Pawn base.\n"
			<< "As you open the door to leave, you're greeted by the Emperor himself. He looks past you to see the state of the Bishop and speaks.\n"
			<< "'" << PlayerCharacter.Name() << ", is it? This is your doing?'\n"
			<< "You nod in response quite sheepishly, this is your first time meeting the Emperor face-to-face like this.\n"
			<< "'Interesting... for a Pawn to be able to take out someone who out-ranks them thrice-fold... follow me.'\n"
			<< "Noddig once more, you follow the Emperor to the fate that his mind is developing.\n"
			<< "[[ GAME END. THANK YOU FOR PLAYING!! ]]\n";
		return;
	}
}

Game PawnMaze;

//rooms[3][3]{
//	{r1,r2,r3},
//	{r4,r5,r6},
//	{r7,r8,r9} };