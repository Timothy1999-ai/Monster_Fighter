// Monster_Fighter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Coauthors: Timothy Stubblefield, John Stubblefield

#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <ctime>
#include <time.h>


using namespace std;

// Print Vector Function
template <typename T>

void print_vector(const vector<T>& vec, string sep = "\n")
{
	for (auto elem : vec)
	{
		cout << elem << sep;
	}
	cout << endl;
}

// Sub Vector Function
template<typename T>
vector<T> sub_Vector(vector<T> const& v, int m, int n) {
	auto first = v.begin() + m;
	auto last = v.begin() + n + 1;
	vector<T> vector(first, last);
	return vector;
}

int weapon_Option();
int battlefieldOption();
int allyOption();
int kills = 0;

int practiceMode(vector<string> monsters);
string choiceToWeapon(int choice);
string choiceToBattlefield(int choice);
string choiceToAlly(int choice);
vector<string> monster();
void beginGame();
string battle(string weapon, string monster, string battlefield, string ally);

// The main method
int main()
{
	beginGame();
	vector<string> monsters = monster();
	// Practice Mode
	int practice = practiceMode(monsters);
	int battlefieldChoice = 0;
	string battlefieldString = "";
	int allyChoice = 0;
	string allyString = "";
	string result = "";

	while (kills < 20)
	{
		if (kills % 3 == 0 && kills != 0)
		{
			cout << "You got Three Kills!" << endl;
			cout << "The Next Monster is: " << monsters[kills] << endl;
		}
		if (practice == 1)
		{
			cout << "The Next Monster is: " << monsters[kills] << endl;
		}
		if (result != "Stun")
		{
			battlefieldChoice = battlefieldOption();
			battlefieldString = choiceToBattlefield(battlefieldChoice);
			allyChoice = allyOption();
			allyString = choiceToAlly(allyChoice);
		}
		int choice = weapon_Option();
		string weapon = choiceToWeapon(choice);
		result = battle(weapon, monsters[kills], battlefieldString, allyString);

		if (result == "Victory")
		{
			kills++;
		}
		else if (result == "Death")
		{
			cout << "Game Over!" << endl;
			break;
		}
		else if (result == "Stun")
		{
			cout << "The Monster is Stunned! Keep Fighting!" << endl;
		}

	}

	cout << "You killed " << kills << " monsters!" << endl;
}

int practiceMode(vector<string> monsters)
{
	int mode = 0;
	cout << "Practice Mode displays the list of monsters at the top of the screen, allowing You to see what You are fighting ahead of time." << endl;
	cout << "Also, in Practice Mode, the next monster You fight will also be reprinted right before battle for Your convenience." << endl;
	cout << "Do You want to enter Practice Mode or Not." << endl;
	do
	{
		cout << "Enter 1 for YES and 0 for NO: ";
		cin >> mode;
		if (mode == 1)
		{
			cout << "You chose Practice Mode!" << endl;
			print_vector(monsters);
			return 1;
		}
		else if (mode == 0)
		{
			cout << "You are NOT in Practice Mode" << endl;
			return 0;
		}
		else
		{
			cout << "You did not hit 0 or 1. Choose again." << endl;
		}
	} while (mode != 0 && mode != 1);
	
}
void beginGame()
{
	cout << "You are playing Monster Figher." << endl;
	cout << "Gameplay: Choose a battlefield. Then choose a weapon. Then you will approach a monster." << endl;
	cout << "Each weapon will either kill, stun, or fail against the given monster." << endl;
	cout << "If you die, it is Game Over. If you stun the monster, then you can choose another weapon and try to fight again." << endl;
	cout << "If you kill the monster, you then proceed and choose another battlefield and weapon before engaging another monster." << endl;
	cout << "The game will automatically track the number of monsters you killed and tell you at the end." << endl;
	cout << "After every Third Monster You kill, the game will tell You what the Next Monster is." << endl;
	cout << "Win the game by killing  20 monsters " << endl;
	cout << endl << endl;
}

int weapon_Option()
{
	int weapon = 0;
	cout << endl;
	cout << "Choose what weapon you want!" << endl;
	cout << "The options are: " << endl;
	cout << "1 - Holy Water" << endl;
	cout << "2 - Silver Bullet Six Shooter" << endl;
	cout << "3 - Magic Wand" << endl;
	cout << "4 - Self Cloning Device" << endl;
	cout << "5 - Chainsaw" << endl;
	cout << "6 - Diamond Shield" << endl;
	cout << "7 - Fire Sword" << endl;
	cout << "8 - Grenade" << endl;
	cout << "9 - Gamma Ray Projector" << endl;
	cout << "10 - Giant Magnet" << endl;
	cin >> weapon;
	return weapon;
}

string choiceToWeapon(int choice)
{
	if (choice == 1)
	{
		cout << "You have chosen the Holy Water!" << endl;
		return "Holy_Water";
	}
	else if (choice == 2)
	{
		cout << "You have chosen the Silver Bullet Six Shooter" << endl;
		return "Silver_Bullet_Six_Shooter";
	}
	else if (choice == 3)
	{
		cout << "You have chosen the Magic Wand" << endl;
		return "Magic_Wand";
	}
	else if (choice == 4)
	{
		cout << "You have chosen the Self Cloning Device" << endl;
		return "Self_Cloning_Device";
	}
	else if (choice == 5)
	{
		cout << "You have chosen the Chainsaw" << endl;
		return "Chainsaw";
	}
	else if (choice == 6)
	{
		cout << "You have chosen the Diamond Shield" << endl;
		return "Diamond_Shield";
	}
	else if (choice == 7)
	{
		cout << "You have chosen the Fire Sword" << endl;
		return "Fire_Sword";
	}
	else if (choice == 8)
	{
		cout << "You have chosen the Grenade" << endl;
		return "Grenade";
	}
	else if (choice == 9)
	{
		cout << "You have chosen the Gamma Ray Projector" << endl;
		return "Gamma_Ray_Projector";
	}
	else if (choice == 10)
	{
		cout << "You have chosen the Giant Magnet" << endl;
		return "Giant_Magnet";
	}
	else
	{
		cout << "You need to choose 1-10" << endl;
		return "";
	}

}

int battlefieldOption()
{
	int battlefield = 0;
	cout << endl;
	cout << "Choose the Battlefield! " << endl;
	cout << "The options are:" << endl;
	cout << "1 - Wolfsbane Field" << endl;
	cout << "2 - Sunny Beach" << endl;
	cout << "3 - Wax Museum" << endl;
	cout << "4 - Disease Research Lab" << endl;
	cout << "5 - Eye of a Hurricane" << endl;
	cout << "6 - Space Spation" << endl;
	cout << "7 - Graveyard" << endl;
	cout << "8 - Church" << endl;
	cout << "9 - Planet Void of Oxygen" << endl;
	cout << "10 - Carnival" << endl;

	cin >> battlefield;
	return battlefield;
}

string choiceToBattlefield(int choice)
{
	if (choice == 1)
	{
		cout << "You have chosen the Wolfsbane Field!" << endl;
		return "Wolfsbane_Field";
	}
	else if (choice == 2)
	{
		cout << "You have chosen the Sunny Beach!" << endl;
		return "Sunny_Beach";
	}
	else if (choice == 3)
	{
		cout << "You have chosen the Wax Museum!" << endl;
		return "Wax_Museum";
	}
	else if (choice == 4)
	{
		cout << "You have chosen the Disease Reaseach Lab!" << endl;
		return "Disease_Research_Lab";
	}
	else if (choice == 5)
	{
		cout << "You have chosen the Eye of the Hurricane!" << endl;
		return "Eye_of_the_Hurricane";
	}
	else if (choice == 6)
	{
		cout << "You have chosen the Space Station!" << endl;
		return "Space_Station";
	}
	else if (choice == 7)
	{
		cout << "You have chosen the Graveyard!" << endl;
		return "Graveyard";
	}
	else if (choice == 8)
	{
		cout << "You have chosen the Church!" << endl;
		return "Church";
	}
	else if (choice == 9)
	{
		cout << "You have chosen the Planet Void of Oxygen!" << endl;
		return "Planet_Void_of_Oxygen";
	}
	else if (choice == 10)
	{
		cout << "You have chosen the Carnival" << endl;
		return "Carnival";
	}
}

int allyOption()
{
	int ally = 0;
	cout << endl;
	cout << "Choose an Ally to help You in your Fight!" << endl;
	cout << "Your options are:" << endl;
	cout << "1 - Exorcist" << endl;
	cout << "2 - Cyborg" << endl;
	cout << "3 - Ice Drake" << endl;
	cout << "4 - Talisman" << endl;
	cout << "5 - Goblin Thief" << endl;
	cout << "6 - Undertaker" << endl;
	cout << "7 - Ancient Flutist" << endl;
	cout << "8 - Fireman" << endl;
	cout << "9 - Giant Spider" << endl;
	cout << "10 - Angel" << endl;

	cin >> ally;
	return ally;

}

string choiceToAlly(int choice)
{
	if (choice == 1)
	{
		cout << "You have chosen the Exorcist!" << endl;
		return "Exorcist";
	}
	else if (choice == 2)
	{
		cout << "You have chosen the Cyborg!" << endl;
		return "Cyborg";
	}
	else if (choice == 3)
	{
		cout << "You have chosen the Ice Drake!" << endl;
		return "Ice_Drake";
	}
	else if (choice == 4)
	{
		cout << "You have chosen the Talisman!" << endl;
		return "Talisman";
	}
	else if (choice == 5)
	{
		cout << "You have chosen the Goblin Thief!" << endl;
		return "Goblin_Thief";
	}
	else if (choice == 6)
	{
		cout << "You have chosen the Undertaker!" << endl;
		return "Undertaker";
	}
	else if (choice == 7)
	{
		cout << "You have chosen the Ancient Flutist!" << endl;
		return "Ancient_Flutist";
	}
	else if (choice == 8)
	{
		cout << "You have chosen the Fireman!" << endl;
		return "Fireman";
	}
	else if (choice == 9)
	{
		cout << "You have chosen the Giant Spider!" << endl;
		return "Giant_Spider";
	}
	else if (choice == 10)
	{
		cout << "You have chosen the Angel!" << endl;
		return "Angel";
	}
}

vector<string> monster()
{
	vector<double> monsters;
	vector<string> monsterName;
	int number = 50;
	monsters.resize(number);
	time_t nTime;
	srand((unsigned)time(&nTime));
	for (int i = 0; i < monsters.size(); i++)
	{
		monsters[i] = rand() % 10;
	}
	for (int i = 0; i < number; i++)
	{
		if (monsters[i] == 0)
		{
			monsterName.push_back("Werewolf");
		}
		else if (monsters[i] == 1)
		{
			monsterName.push_back("Vampire");
		}
		else if (monsters[i] == 2)
		{
			monsterName.push_back("Ghost");
		}
		else if (monsters[i] == 3)
		{
			monsterName.push_back("Alien");
		}
		else if (monsters[i] == 4)
		{
			monsterName.push_back("Zombie");
		}
		else if (monsters[i] == 5)
		{
			monsterName.push_back("Dark_Wizard");
		}
		else if (monsters[i] == 6)
		{
			monsterName.push_back("Robot");
		}
		else if (monsters[i] == 7)
		{
			monsterName.push_back("Bloodworm");
		}
		else if (monsters[i] == 8)
		{
			monsterName.push_back("Phoenix");
		}
		else if (monsters[i] == 9)
		{
			monsterName.push_back("Mummy");
		}
	}
	return monsterName;

}

string battle(string weapon, string monster, string battlefield, string ally)
{
	// Evaluate Battlefields First
	if (battlefield == "Wolfsbane_Field" && monster == "Werewolf")
	{
		cout << "The Wolfsbane Flowers transforms the Werewolf into a Human. It is left completely defenseless and weak." << endl;
		cout << "You kill it easy!" << endl << "The Werewolf Dies." << endl;
		return "Victory";
	}
	else if (battlefield == "Sunny_Beach" && monster == "Vampire")
	{
		cout << "Abundant sunshine scorches and vaporizes the Vampire." << endl << "The Vampire Dies." << endl;
		return "Victory";
	}
	else if (battlefield == "Wax_Museum" && monster == "Ghost")
	{
		cout << "The Ghost possesses a wax statue. You destroy the statue and thus the Ghost easily. " << endl;
		cout << "The Ghost Dies." << endl;
		return "Victory";
	}
	else if (battlefield == "Disease_Research_Lab" && monster == "Alien")
	{
		cout << "The Alien is exposed to a deadly human disease." << endl << "The Alien Dies." << endl;
		return "Victory";
	}
	else if (battlefield == "Church" && monster == "Dark_Wizard")
	{
		cout << "God prohibits dark sorcery and magic in a Temple of God. Unable to attack or defend, you kill the Dark Wizard easily." << endl;
		cout << "The Dark Wizard Dies." << endl;
		return "Victory";
	}
	else if (battlefield == "Eye_of_the_Hurricane" && monster == "Robot")
	{
		cout << "Waves of water and torrential rain short circuit the Robot." << endl << "The Robot Dies." << endl;
		return "Victory";
	}
	else if (battlefield == "Space_Station" && monster == "Bloodworm")
	{
		cout << "The Bloodworm is unable to dig into the ground, leaving it extremely vulnerable." << endl;
		cout << "You kill it easily." << endl << "The Bloodworm Dies." << endl;
		return "Victory";
	}
	else if (battlefield == "Planet_Void_of_Oxygen" && monster == "Phoenix")
	{
		cout << "Without oxygen, the Phoenix ceases to burn leaving it unable to attack, fly, or defend." << endl;
		cout << "You kill it easily." << endl << "The Phoenix Dies." << endl;
		return "Victory";
	}
	else if (battlefield == "Carnival" && monster == "Mummy")
	{
		cout << "The carousel unravels the Mummy." << endl << "The Mummy Dies." << endl;
		return "Victory";
	}
	else if (battlefield == "Graveyard" && monster == "Zombie")
	{
		cout << "The Zombie walks over its Grave and returns to the Earth." << endl << "The Zombie Dies." << endl;
		return "Victory";
	}

	// Evaluate Ally Second
	else if (ally == "Angel" && monster == "Zombie")
	{
		cout << "The Angel forgives the Zombie, who was a good person in its previous life, and takes it to Heaven." << endl;
		cout << "The Zombie Dies." << endl;
		return "Victory";
	}
	else if (ally == "Exorcist" && monster == "Ghost")
	{
		cout << "As the Ghost possesses your body, the Exorcist exorcises the Ghost and destroys it." << endl;
		cout << "The Ghost Dies." << endl;
		return "Victory";
	}
	else if (ally == "Cyborg" && monster == "Robot")
	{
		cout << "The Cyborg uses its cybernetics to Hack the Robot and cause itself to Detonate." << endl;
		cout << "The Robot Dies." << endl;
		return "Victory";
	}
	else if (ally == "Ice_Drake" && monster == "Alien")
	{
		cout << "The Ice Drake freezes the Alien in a cube of Ice, lowering its body temperature to lethal levels." << endl;
		cout << "The Alien Dies." << endl;
		return "Victory";
	}
	else if (ally == "Talisman" && monster == "Mummy")
	{
		cout << "The Talisman uses an Amulet to control the Mummy's Ankh of Anubis, removing its Lifeforce." << endl;
		cout << "The Mummy Dies." << endl;
		return "Victory";
	}
	else if (ally == "Goblin_Thief" && monster == "Dark_Wizard")
	{
		cout << "With its fast speed, the Goblin Thief steals the Dark Wizard's Wand, leaving it completely vulnerable and defenseless." << endl;
		cout << "You kill it easily." << endl << "The Dark Wizard Dies." << endl;
		return "Victory";
	}
	else if (ally == "Undertaker" && monster == "Vampire")
	{
		cout << "The Undertaker finds the Vampire's Coffin, digs it up, and destroys it, killing the Vampire." << endl;
		cout << "The Vampire Dies." << endl;
		return "Victory";
	}
	else if (ally == "Ancient_Flutist" && monster == "Werewolf")
	{
		cout << "The Ancient Flutist plays a Lunar Tune that reverts the Werewolf to Human form, making it extremely vulnerable." << endl;
		cout << "You kill it easily." << endl << "The Werewolf Dies." << endl;
		return "Victory";
	}
	else if (ally == "Fireman" && monster == "Phoenix")
	{
		cout << "Immune to the Phoenix's Fire Breath, the Fireman extinguishes the Phoenix with a Water Hose, and kills it with an Axe." << endl;
		cout << "The Phoenix Dies." << endl;
		return "Victory";
	}
	else if (ally == "Giant_Spider" && monster == "Bloodworm")
	{
		cout << "The Giant Spider shoots a Web to trap the Bloodworm and then Feasts on its sticky prey, sucking its innards dry." << endl;
		cout << "The Bloodworm Dies." << endl;
		return "Victory";
	}

	//Evaluate Weapon Third
	else if (weapon == "Holy_Water")
	{
		if (monster == "Werewolf")
		{
			cout << "As the Werewolf charges You, you pour the Holy Water on the ground. The Werewolf steps in the Holy Water and jumps back in pain and Howls." << endl;
			cout << "Be ready for its next attack." << endl;
			return "Stun";
		}
		else if (monster == "Vampire")
		{
			cout << "You splash the Vampire with Holy Water, disintegrating it." << endl << "You killed the Vampire." << endl;
			return "Victory";
		}
		else if (monster == "Ghost")
		{
			cout << "You splash the Ghost with Holy Water but it phases through the Ghost." << endl;
			cout << "The Ghost possesses You and stops Your Heart." << endl << "The Ghost killed You." << endl;
			return "Death";
		}
		else if (monster == "Alien")
		{
			cout << "You splash the Alien with Holy Water but it has no effect since the Alien has no understanding of Earth's Religions." << endl;
			cout << "The Alien slashes Your jugular with its Claws." << endl << "The Alien killed You." << endl;
			return "Death";
		}
		else if (monster == "Zombie")
		{
			cout << "You splash the Zombie with Holy Water, disintegrating every part of the Zombie." << endl << "You killed the Zombie." << endl;
			return "Victory";
		}
		else if (monster == "Dark_Wizard")
		{
			cout << "The Dark Wizard shoots a Shadow Spell at the Holy Water, unblessing it and turning it black." << endl;
			cout << "The vial breaks of black liquid breaks as Shadow Demons rush out and kill You." << endl;
			cout << "The Dark Wizard killed You." << endl;
			return "Death";
		}
		else if (monster == "Robot")
		{
			cout << "You splash the Robot with the Holy Water, but the Water runs down the sleek surface of the Godless Souless Robot." << endl;
			cout << "The Robot fires its Machine Gun at You." << endl << "The Robot killed You." << endl;
			return "Death";
		}
		else if (monster == "Bloodworm")
		{
			cout << "You pour the Holy Water down the Bloodworm's tunnel and the Bloodworm drinks it up." << endl;
			cout << "The Bloodworm then grows 4 times larger than its normal self." << endl;
			cout << "The ground opens up beneath You as You fall down the wide dark tunnel leading to the Bloodworm." << endl << "The Bloodworm killed You." << endl;
			return "Death";
		}
		else if (monster == "Phoenix")
		{
			cout << "The Phoenix shoots a Fireball at You, but You throw the vial of Holy Water in the air." << endl;
			cout << "The Fireball dissipates and the Phoenix comes around, ready to attack again." << endl;
			return "Stun";
		}
		else if (monster == "Mummy")
		{
			cout << "After splashing the Mummy with the Holy Water, it has no effect since the Mummy believes in Ra and Apophis, not the Devil." << endl;
			cout << "It wraps You up and kills You." << endl << "The Mummy killed You." << endl;
			return "Death";
		}
	}
	else if (weapon == "Silver_Bullet_Six_Shooter")
	{
		if (monster == "Werewolf")
		{
			cout << "You shoot the Werewolf with a Silver Bullet Six Shooter." << endl << "You killed the Werewolf." << endl;
			return "Victory";
		}
		else if (monster == "Vampire")
		{
			cout << "You shoot at the Vampire but it turns into a Bat. As it tries to get close, You ward it off with the 5 other bullets." << endl;
			cout << "Try and kill the Vampire before it returns to its True Form." << endl;
			return "Stun";
		}
		else if (monster == "Ghost")
		{
			cout << "You shoot the Ghost, but the Bullet phases through the Ghost. The Ghost possesses You." << endl;
			cout << "The Ghost killed You." << endl;
			return "Death";
		}
		else if (monster == "Alien")
		{
			cout << "You shoot the Alien with a Silver Bullet Six Shooter. Silver is an Earth metal toxic to the Alien." << endl;
			cout << "You killed the Alien." << endl;
			return "Victory";
		}
		else if (monster == "Zombie")
		{
			cout << "You unload the Revolver into the Zombie, but it regenerates and continues charging toward You." << endl;
			cout << "The Zombie bites and infects You." << endl << "The Zombie killed You." << endl;
			return "Death";
		}
		else if (monster == "Dark_Wizard")
		{
			cout << "The Silver Bullet penetrates the Dark Wizard's arm. He uses a Spell of Regeneration to heal the wound." << endl;
			return "Stun";
		}
		else if (monster == "Robot")
		{
			cout << "The Silver Bullet bounces off the Robot's Titanium Armor. The Robot annihilates you with its Laser Vision." << endl;
			cout << "The Robot killed You." << endl;
			return "Death";
		}
		else if (monster == "Bloodworm")
		{
			cout << "The Bloodworm leaps from the ground unexpectedly and quickly disarms You." << endl;
			cout << "Its razor sharp Teeth tear You to shreds." << endl << "The Bloodworm killed You." << endl;
			return "Death";
		}
		else if (monster == "Phoenix")
		{
			cout << "You shoot the Phoenix but the molten hot Fire melts the Bullet dead in its tracks." << endl;
			cout << "The Phoenix scorches You with Fire Breath." << endl << "The Phoenix killed You." << endl;
			return "Death";
		}
		else if (monster == "Mummy")
		{
			cout << "The Bullet travels throught the Mummy's Bandages leaving it unharmed." << endl;
			cout << "The Mummy proceeds to wrap You up and mummify You." << endl << "The Mummy killed You." << endl;
			return "Death";
		}
	}
	else if (weapon == "Magic_Wand")
	{
		if (monster == "Werewolf")
		{
			cout << "You transform the Werewolf into Human form, making it vulnerable to kill. You then unleash a Bolt of Lightning toward the Werewolf." << endl;
			cout << "You killed the Werewolf." << endl;
			return "Victory";
		}
		else if (monster == "Vampire")
		{
			cout << "You cast a beam as bright and hot as the Sun but the Vampire reflects it with the Mirror of Dracula, burning You alive." << endl;
			cout << "The Vampire killed You." << endl;
			return "Death";
		}
		else if (monster == "Ghost")
		{
			cout << "You cast a Spell of Invisibility on Yourself. Unable to see and possess You, you plan your next strike on the Ghost." << endl;
			return "Stun";
		}
		else if (monster == "Alien")
		{
			cout << "You raise the Magic Wand to cast a Spell, but the Alien's Barbed Tail knocks it out of Your hand." << endl;
			cout << "The Alien rips out Your spine with its Claws." << endl << "The Alien killed You." << endl;
			return "Death";
		}
		else if (monster == "Zombie")
		{
			cout << "You shoot a Ligtning Bolt at the Zombie with the Magic Wand hoping to kill it, but it Supercharges the Zombie." << endl;
			cout << "The Supercharged Zombie rushes to You in a blur and feasts on Your Brains." << endl;
			return "Death";
		}
		else if (monster == "Dark_Wizard")
		{
			cout << "Using his own wand, the Dark Wizard controls your Magic Wand and uses it to stop your Heart." << endl;
			cout << "The Dark Wizard killed You." << endl;
			return "Death";
		}
		else if (monster == "Robot")
		{
			cout << "You cast a Water Bubble toward the Robot, temporarily disabling it." << endl;
			cout << "Attack quickly before it finishes Rebooting." << endl;
			return "Stun";
		}
		else if (monster == "Bloodworm")
		{
			cout << "You shoot a Magical Blast at the Bloodworm, but it dives into the Ground to avoid it, before emerging to bite You with its Venomous Pincers." << endl;
			cout << "THe Bloodworm killed You." << endl;
			return "Death";
		}
		else if (monster == "Phoenix")
		{
			cout << "You overpower the Phoenix's Firebreath with Ice Storm, freezing the Phoenix." << endl << "You killed the Phoenix." << endl;
			return "Victory";
		}
		else if (monster == "Mummy")
		{
			cout << "You fire Magical Blast at the Mummy, but the Mummy's Ankh of Anubis protects it from Magical attacks." << endl;
			cout << "The Mummy wraps You up and mummifies You." << endl << "The Mummy killed You." << endl;
			return "Death";
		}
	}
	else if (weapon == "Self_Cloning_Device")
	{
		if (monster == "Werewolf")
		{
			cout << "You make 3 clones of yourself with the Self Cloning Device, but the Werewolf's speed and ferocity attacks You and the clones." << endl;
			cout << "The Werewolf killed You." << endl;
			return "Death";
		}
		else if (monster == "Vampire")
		{
			cout << "You create 2 clones of yourself with the Self Cloning Device, but the Vampire bites both clones turning them into slaves of the Undead." << endl;
			cout << "The 3 Vampires proceed to suck your Blood." << endl << "The Vampire killed You." << endl;
			return "Death";
		} 
		else if (monster == "Ghost")
		{
			cout << "You create 10 clones of yourself with the Self Cloning Device, and the Ghost possesses one of the clones. " << endl;
			cout << "You and the rest of the clones beat the possessed clone to Death." << endl << "You killed the Ghost" << endl;
			return "Victory";
		}
		else if (monster == "Alien")
		{
			cout << "You create 5 clones of yourself with the Self Cloning Device, but the Alien's Heat Vision disinguishes You from the clones." << endl;
			cout << "It attacks You with its Venomous Claws." << endl << "The Alien killed You." << endl;
			return "Death";
		}
		else if (monster == "Zombie")
		{
			cout << "You create 3 clones of yourself with the Self Cloning Device, but the Zombie bites 2 of the clones who overwhelm You and the 3rd clone." << endl;
			cout << "The Zombie killed You." << endl;
			return "Death";
		}
		else if (monster == "Dark_Wizard")
		{
			cout << "You create 3 clones of yourself with the Self Cloning Device. The Dark Wizard perfoms an incantation and steals the Soul of one of the clones." << endl;
			cout << "He prepares a new Spell." << endl;
			return "Stun";
		}
		else if (monster == "Robot")
		{
			cout << "You create 5 clones of yourself with the Self Cloning Device." << endl;
			cout << "The Robot waves its laser across all the clones, cutting all of them in half." << endl << "The Robot killed You." << endl;
			return "Death";
		}
		else if (monster == "Bloodworm")
		{
			cout << "You create 5 clones of yourself with the Self Cloning Device." << endl;
			cout << "The Bloodworm emerges from a Tunnel and attacks a clone. While feasting, You and the rest of the clones attack the Bloodworm." << endl;
			cout << "You killed the Bloodworm." << endl;
			return "Victory";
		}
		else if (monster == "Phoenix")
		{
			cout << "You create 5 clones of yourself with the Self Cloning Device. The Phoenix flys up and burns you all with Fire Breath." << endl;
			cout << "The Phoenix killed You." << endl;
			return "Death";
		}
		else if (monster == "Mummy")
		{
			cout << "You create 3 clones of yourself with the Self Cloning Device. The Mummy wraps one clone up and mummifies it." << endl;
			cout << "It prepares for another attack." << endl;
			return "Stun";
		}
	}
	else if (weapon == "Chainsaw")
	{
		if (monster == "Werewolf")
		{
			cout << "The chainsaw fails to cut through the Werewolf's fur and it mauls You." << endl;
			cout << "The Werewolf killed You." << endl;
			return "Death";
		}
		else if (monster == "Vampire")
		{
			cout << "The Vampire avoids the Chainsaw by teleporting behind You. It sucks your blood dry." << endl;
			cout << "The Vampire killed You." << endl;
			return "Death";
		}
		else if (monster == "Ghost")
		{
			cout << "The Ghost is intangible to the Chainsaw. It possesses You and takes over your Soul." << endl;
			cout << "The Ghost killed You." << endl;
			return "Death";
		}
		else if (monster == "Alien")
		{
			cout << "You parry the Alien's Barbed Tail with the Chainsaw. It prepares to strike again." << endl;
			return "Stun";
		}
		else if (monster == "Zombie")
		{
			cout << "The Chainsaw cuts all the parts of the Zombie up. The Zombie reforms and eats your Brains." << endl;
			cout << "The Zombie killed You." << endl;
			return "Death";
		}
		else if (monster == "Dark_Wizard")
		{
			cout << "You cut off the Dark Wizard's arm with the Chainsaw, separating his Wand from him." << endl;
			cout << "Unable to defend, You hack him to pieces." << endl << "You killed the Dark Wizard." << endl;
			return "Victory";
		}
		else if (monster == "Robot")
		{
			cout << "The Robot's titanium metal is impenetrable to the Chainsaw. The Robot zaps You with a laser." << endl;
			cout << "The Robot killed You." << endl;
			return "Death";
		}
		else if (monster == "Bloodworm")
		{
			cout << "You cut off one of the Bloodworm's legs, slowing its mobility. It returns to its tunnels to prepare its next attack." << endl;
			return "Stun";
		}
		else if (monster == "Phoenix")
		{
			cout << "The Chainsaw cannot reach the Flying Phoenix. It burns You to death with a Fireball." << endl;
			cout << "The Phoenix killed You." << endl;
			return "Death";
		}
		else if (monster == "Mummy")
		{
			cout << "You cut the Mummy's bandages into strips with the Chainsaw. " << endl << "You killed the Mummy" << endl;
			return "Victory";
		}
	}
	else if (weapon == "Diamond_Shield")
	{
		if (monster == "Werewolf")
		{
			cout << "You raise the Diamond Shield to block the Werewolf's charging attack, but the Werwolf's strength disarms You." << endl;
			cout << "The Werewolf rips your throat out." << endl << "The Werewolf killed You." << endl;
			return "Death";
		}
		else if (monster == "Vampire")
		{
			cout << "You raise the Diamond Shield to defend youself, but the Vampire bites You in the neck with its Agility." << endl;
			cout << "The Vampire killed You." << endl;
			return "Death";
		}
		else if (monster == "Ghost")
		{
			cout << "The Ghost easily passes through your Diamond Shield and possess You." << endl << "The Ghost killed You." << endl;
			return "Death";
		}
		else if (monster == "Alien")
		{
			cout << "You block the Alien's Claws with the Diamond Shield, but its Barbed Tail stabs You in the back." << endl << "The Alien killed You." << endl;
			return "Death";
		}
		else if (monster == "Zombie")
		{
			cout << "You charge the Zombie with the Diamond Shield and hit it, launching the Zombie on its back." << endl;
			cout << "Prepare Your next attack before it gets back up." << endl;
			return "Stun";
		}
		else if (monster == "Dark_Wizard")
		{
			cout << "The Dark Wizard casts a Lightning Spell, but you reflect it back at the Dark Wizard with Diamond Shield." << endl;
			cout << "You killed the Dark Wizard." << endl;
			return "Victory";
		}
		else if (monster == "Robot")
		{
			cout << "The Robot shoots its Machine Gun at You, but you block it with the Diamond Shield." << endl;
			cout << "The Robot runs out of Ammunition and prepares another attack." << endl;
			return "Stun";
		}
		else if (monster == "Bloodworm")
		{
			cout << "You place the Diamond Shield over the Bloodworm Tunnel, but the Bloodworm emerges from another Tunnel behind You." << endl;
			cout << "The Bloodworm bites You with its Venomous Fangs" << endl;
			return "Death";
		}
		else if (monster == "Phoenix")
		{
			cout << "You reflect the Phoenix's Fire Breath with the Diamond Shield, vaporizing it." << endl << "You killed the Phoenix." << endl;
			return "Victory";
		}
		else if (monster == "Mummy")
		{
			cout << "The Mummy's Wraps rip the Diamond Shield from your hands." << endl;
			cout << "The Mummy swings the Diamond Shield rapidly and crashes it into You." << endl << "The Mummy killed You." << endl;
			return "Death";
		}
	}
	else if (weapon == "Fire_Sword")
	{
		if (monster == "Werewolf")
		{
			cout << "You slash the ground with Fire Sword, spewing flames everywhere." << endl;
			cout << "Afraid of the fire, the Werewolf backs away and circles around to prepare its next attack." << endl;
			return "Stun";
		}
		else if (monster == "Vampire")
		{
			cout << "You slash the Vampire but it is unaffected by the heat and rips the Fire Sword out of Your hand with its Super Strength." << endl;
			cout << "The Vampire bisects You with the Fire Sword." << endl << "The Vampire killed You." << endl;
			return "Death";
		}
		else if (monster == "Ghost")
		{
			cout << "You swing the Fire Sword at the Ghost but it is intangible to the Fire." << endl;
			cout << "The Ghost possess You and makes You impale Yourself with the Fire Sword." << endl << "The Ghost killed You." << endl;
			return "Death";
		}
		else if (monster == "Alien")
		{
			cout << "You swing the Fire Sword at the Alien but it blocks it with its tough, scaly Claws that are impervious to the heat" << endl;
			cout << "The Alien plunges its Barbed Tail through Your chest and out through Your skull." << endl << "The Alien killed You." << endl;
			return "Death";
		}
		else if (monster == "Zombie")
		{
			cout << "You swing the Fire Sword at the Zombie burning every piece to ash, preventing Regeneration." << endl;
			cout << "You killed the Zombie." << endl;
			return "Victory";
		}
		else if (monster == "Dark_Wizard")
		{
			cout << "The Dark Wizard casts a cold Wave of Darkness that extinguishes the Fire Sword." << endl;
			cout << "In the Darkness, it sends its Shadow Minions to steal Your soul." << endl << "The Dark Wizard killed You." << endl;
			return "Death";
		}
		else if (monster == "Robot")
		{
			cout << "You swing at the Robot, but it has heat resistant armor that protects it." << endl;
			cout << "The Robot electrocutes You with its Zap Gun." << endl << "The Robot killed You." << endl;
			return "Death";
		}
		else if (monster == "Bloodworm")
		{
			cout << "You swirl the Fire Sword in a Bloodworm's tunnel creating a lot of smoke." << endl;
			cout << "The Bloodworm tunnels down further and waits for the smoke to clear." << endl;
			return "Stun";
		}
		else if (monster == "Phoenix")
		{
			cout << "The Phoenix absorbs the flames from the Fire Sword, leaving only the hilt." << endl;
			cout << "The Phoenix grabs with its Talons and impales You with its Beak." << endl << "The Phoenix killed You." << endl;
			return "Death";
		}
		else if (monster == "Mummy")
		{
			cout << "You slash the Mummy with the Fire Sword, burning the bandages to a crisp." << endl;
			cout << "You killed the Mummy." << endl;
			return "Victory";
		}
	}
	else if (weapon == "Grenade")
	{
		if (monster == "Werewolf")
		{
			cout << "You thrown the Grenade at the Werwolf but its Gray Fur is invulnerable to the explosion." << endl;
			cout << "The Werewolf leaps at You and tears You to shreds." << endl << "The Werewolf killed You." << endl;
			return "Death";
		}
		else if (monster == "Vampire")
		{
			cout << "The Vampire transforms into a Bat and flys away to avoid the explosion." << endl;
			cout << "Prepare for Your next attack before it returns to its True Form." << endl;
			return "Stun";
		}
		else if (monster == "Ghost")
		{
			cout << "You throw the Grenade, but the Ghost is invulnerable to the explosion." << endl;
			cout << "The Ghost possesses You and suffocates You." << endl << "The Ghost killed You." << endl;
			return "Death";
		}
		else if (monster == "Alien")
		{
			cout << "You throw the Grenade at the Alien. As it explodes, the Alien turns its armored back to the explosion." << endl;
			cout << "Attack while its back is turned." << endl;
			return "Stun";
		}
		else if (monster == "Zombie")
		{
			cout << "You throw the Grenade at the Zombie, blowing it to pieces scattering the pieces and blood over Your body." << endl;
			cout << "The Zombie quickly regenerates and bites You." << endl << "The Zombie killed You." << endl;
			return "Death";
		}
		else if (monster == "Dark_Wizard")
		{
			cout << "Just before throwing the Grenade, the Dark Wizard surrounds You in an Aura Shield with the Grenade." << endl;
			cout << "Unable to escape, the Grenade blows up." << endl << "The Dark Wizard killed You." << endl;
			return "Death";
		}
		else if (monster == "Robot")
		{
			cout << "You thrown the Grenade at the Robot and it obliterates it to pieces." << endl << "You killed the Robot." << endl;
			return "Victory";
		}
		else if (monster == "Bloodworm")
		{
			cout << "You throw the Grendade into the Bloodworm's tunnel which rolls down and explodes, killing the Bloodworm." << endl;
			cout << "You killed the Bloodworm." << endl;
			return "Victory";
		}
		else if (monster == "Phoenix")
		{
			cout << "You throw the Grenade but the Phoenix burns the Grenade before it can explode." << endl;
			cout << "The Phoenix flaps its wings, sending a wave of Fire toward You." << endl << "The Phoenix killed You." << endl;
			return "Death";
		}
		else if (monster == "Mummy")
		{
			cout << "You throw the Grenade at the Mummy, but it reaches out and slings the Grenade back at You with its Bandages." << endl;
			cout << "The Mummy killed You." << endl;
			return "Death";
		}
	}
	else if (weapon == "Gamma_Ray_Projector")
	{
		if (monster == "Werewolf")
		{
			cout << "You fire the Gamma Ray Projector at the Werewolf, but it is impervious to the attack." << endl;
			cout << "The Werewolf rushes You and clamps down on Your neck with its powerful Jaws." << endl << "The Werewolf killed You." << endl;
			return "Death";
		}
		else if (monster == "Vampire")
		{
			cout << "You fire the Gamma Ray Projector at the Vampire and the high radiation Gamma Rays disintegrate it." << endl << "You killed the Vampire." << endl;
			return "Victory";
		}
		else if (monster == "Ghost")
		{
			cout << "You fire the Gamma Ray Projector at the Ghost, decimating it." << endl << "You killed the Ghost" << endl;
			return "Victory";
		}
		else if (monster == "Alien")
		{
			cout << "You shoot the Alien with the Gamma Ray Projector, but its Exosuit protects it." << endl;
			cout << "The Alien gores You with its Horns." << endl << "The Alien killed You." << endl;
			return "Death";
		}
		else if (monster == "Zombie")
		{
			cout << "You shoot the Gamma Ray Projector at the Zombie. The Zombie becomes mutated but slowed." << endl;
			cout << "Try and prepare another attack as it slowly approaches." << endl;
			return "Stun";
		}
		else if (monster == "Dark_Wizard")
		{
			cout << "You shoot the Gamma Ray Projector at the Dark Wizard, but it uses a Veil of Shadow to reduce the power of the Gamma Rays." << endl;
			cout << "The Dark Wizard then sends a Bolt of Lightning at You." << endl << "The Dark Wizard killed You." << endl;
			return "Death";
		}
		else if (monster == "Robot")
		{
			cout << "You fire the Gamma Ray Projector at the Robot, but it uses its Shield Reflector to divert the attack." << endl;
			cout << "Then, the Robot vaporizes You with its Laser Vision." << endl << "The Robot killed You." << endl;
			return "Death";
		}
		else if (monster == "Bloodworm")
		{
			cout << "You shoot the Gamma Ray Projector at the Bloodworm, but the Bloodworm retreats to its Tunnels before emerging behind You and biting You with its Venomous pincers." << endl;
			cout << "The Bloodworm killed You." << endl;
			return "Death";
		}
		else if (monster == "Phoenix")
		{
			cout << "You shoot the Gamma Ray Projector at the Phoenix, dissipating the Phoenix's flames." << endl;
			cout << "Prepare another attack while it tries to Reignite." << endl;
			return "Stun";
		}
		else if (monster == "Mummy")
		{
			cout << "You shoot the Gamma Ray Projector but the Mummy's Ankh of Anubis transforms the Gamma Rays into a swarm of venomous Scorpions that sting You." << endl;
			cout << "The Mummy killed You." << endl;
			return "Death";
		}
	}
	else if (weapon == "Giant_Magnet")
	{
		if (monster == "Werewolf")
		{
			cout << "You try to use the Giant Magnet, but the Werewolf has no Magnetic items." << endl << "The Werewolf Mauls You." << endl;
			cout << "The Werewolf killed You." << endl;
			return "Death";
		}
		else if (monster == "Vampire")
		{
			cout << "You try to use the Giant Magnet, but the Vampire has no Magnetic items." << endl << "The Vampire bites You and sucks Your blood." << endl;
			cout << "The Vampire killed You." << endl;
			return "Death";
		}
		else if (monster == "Ghost")
		{
			cout << "You point the Giant Magnet at the Ghost, which interferes with the Parapsychomagnetic Waves and prevents the Ghost from possessing You temporarily." << endl;
			cout << "Be ready to finish the Ghost before the Giant Magnet's effects wear off." << endl;
			return "Stun";
		}
		else if (monster == "Alien")
		{
			cout << "You point the Giant Magnet at the Alien which deactivates the Alien's lifegiving Exosuit, and prevents it from breathing." << endl;
			cout << "You killed the Alien" << endl;
			return "Victory";
		}
		else if (monster == "Zombie")
		{
			cout << "You try to use the Giant Magnet, but the Zombie has no Magnetic items." << endl << "The Zombie attacks You and eats Your brains." << endl;
			cout << "The Zombie killed You." << endl;
			return "Death";
		}
		else if (monster == "Dark_Wizard")
		{
			cout << "You point the Giant Magnet at the Dark Wizard. As You do so. the Dark Wizard creates Metal Spikes which are attracted to the Giant Magnet." << endl;
			cout << "The Giant Magnet pulls the Metal Spikes toward You, impaling You." << endl << "The Dark Wizard killed You." << endl;
			return "Death";
		}
		else if (monster == "Robot")
		{
			cout << "You point the Giant Magnet at the Robot, interrupting its machinery and pulling it apart." << endl << "You killed the Robot." << endl;
			return "Victory";
		}
		else if (monster == "Bloodworm")
		{
			cout << "You try to use the Giant Magnet, but the Bloodworm has no Magnetic items." << endl;
			cout << "The Bloodworm launches from a Tunnel and shreds You with thousands of Teeth." << endl << "The Bloodworm killed You." << endl;
			return "Death";
		}
		else if (monster == "Phoenix")
		{
			cout << "You try to use the Giant Magnet, but the Phoenix has no Magnetic Items." << endl;
			cout << "The Phoenix grabs You with its Talons and plucks Your head off with its sharp Beak." << endl << "The Phoenix killed You." << endl;
			return "Death";
		}
		else if (monster == "Mummy")
		{
			cout << "You point the Giant Magnet at the Mummy which pulls the Ankh of Anubis from the Mummy's chest, collapsing the Mummy into a pile of Bandages. " << endl;
			cout << "The Bandages snakes toward the Ankh of Anubis as the Mummy begins to reform." << endl << "Prepare Your next attack." << endl;
			return "Stun";
		}
	}
}
