#include "stdafx.h"
using namespace std;

void MenuGet(int &menuSelect, int &gold, int &totalSoldiers); //This function is to bring up the menu screen/options
void soldierShop(int &gold, int &totSoldier, int soldierPrice, int &menuSelect); //This function is for the "Buy Soldiers" option. Opens up that menu and does the calculations to purchase soldiers.
void BuyingUpgrades(int &gold, int &menuSelect, int &dmgUp, int &bw, int &sw, int &dcw, int &fbEW, int &cw, int &cwOO, int &aa, int &rsw, int &das, int &sps, int &gobSpell, int &masMisHam, int &dioFlask, int &jarLoDice, int &sentientWoChop, int &abySym, int &viVamBlo, int &disHalo, int &galaJournal, int &darkSign);
void BuyingProperty(int &gold, int &farms, int &castle, int &watermill, int &food, int &wood, int &stone);
void BuyingItems(int &gold, int &menuSelect, int &spices, int &food, int &stone, int &wood, int &gem, int &treasure, int &wine, int &medicine);
void Combat(int &totalSoldiers, int &dmgUp, int &food, int &AC, int &eventNum);
void Explore(int &gold, int &farms, int &castle, int &UnderRealm, int &verdantWilds, int &foreverNightmare, int &northBabylon, int &watermill, int &spices, int &food, int &stone, int &wood, int &gem, int &treasure, int &wine, int &medicine, int &totalSoldiers, int &villages, int &cities, int &AC, int&eventNum, int &gobSpell, int &masMisHam, int &dioFlask, int &sentientWoChop, int &viVamBlo);

int baseArmor = 12;
int baseDMG = 1;
int dmgUp = 0;

//Put in a game over thing if soldiers ever reach 0

int main()
{
	int verdantWilds = 0; int foreverNightmare = 0; int northBabylon = 0; int UnderRealm = 0;//Unlocks additional areas
	int bw = 0; int sw = 0; int dcw = 0; int fbEW = 0; int cw = 0; int cwOO = 0; int aa = 0; int rsw = 0; int das = 0; int sps = 0;
	int gobSpell = 0; int masMisHam = 0; int dioFlask = 0; int jarLoDice = 0; int sentientWoChop = 0; int abySym = 0;  int viVamBlo = 0; int disHalo = 0; int galaJournal = 0; int darkSign = 0;

	int menuSelect;
	int totalSoldiers = 300;

	srand(time(NULL));
	// Sleep(500);
	int soldierPrice = (rand() % 100) + 50; // determines price of soldiers when checking.


	int AC = 0;
	

	int event, eventNum;

	int castle = 0;
	int farms = 0;
	int watermill = 0;
	

	int cities = 0;
	int villages = 1;

	int spices = 0;
	int food = 0;
	int gem = 0;
	int treasure = 0;
	int stone = 100;
	int wine = 50;
	int wood = 100;
	int medicine = 10;
	int gold = 100000;

	bool wantExit = false;																													  
		
	cout << "Welcome to Heroes of Babylon!\n";
	cout << "Prepare yourself to embark on an epic journey where you will befriend heroes, discover ancient relics, wage war, and raise an empire." << endl;
	cout << "You have a long adventure ahead of you. Good luck! " << endl;
	//cout a message that describes what the game is about and the goal.
																																	  																									  																															  
	while(wantExit == false)																													  
	{	
		MenuGet(menuSelect, gold, totalSoldiers);
		
		if (menuSelect == 1)
		{
			int soldierPrice = (rand() % 100) + 50; // determines price of soldiers when checking.
			cout << endl;
			soldierShop(gold, totalSoldiers, soldierPrice, menuSelect);
		}
		if (menuSelect == 2)
		{
			cout << endl;
			BuyingUpgrades(gold, menuSelect, dmgUp,bw, sw, dcw, fbEW, cw, cwOO, aa, rsw, das, sps, gobSpell, masMisHam, dioFlask, jarLoDice, sentientWoChop, abySym, viVamBlo, disHalo, galaJournal, darkSign);
		}
		if (menuSelect == 3)
		{
			cout << endl;
			BuyingProperty(gold, farms, castle, watermill, food, wood, stone);
		}
		if (menuSelect == 4)
		{
			cout << endl;
			BuyingItems(gold, menuSelect, spices, food, stone, wood, gem, treasure, wine, medicine);
		}
		if (menuSelect == 5)
		{
			cout << endl;
			Explore(gold, farms, castle, UnderRealm, verdantWilds, foreverNightmare, northBabylon, watermill, spices, food, stone, wood, gem, treasure, wine, medicine, totalSoldiers, villages, cities, AC, eventNum, gobSpell, masMisHam, dioFlask, sentientWoChop, viVamBlo);
		}
		else if (menuSelect == 8)
		{
			wantExit = true;
		}
	}																																  
	

	system("pause");
	return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void MenuGet(int &menuSelect, int &gold, int &totalSoldiers)
{
	cout << "################################################################################" << endl;
	cout << "Enter 1 to Buy Soldiers \n";
	cout << "Enter 2 to Buy Upgrades \n";
	cout << "Enter 3 to Buy Property \n";
	cout << "Enter 4 to Buy Items \n";
	cout << "Enter 5 to Explore \n";
	cout << "Enter 6 to view Empire's Assets\n";
	cout << "Enter 7 for Help \n";
	cout << "Enter 8 to Quit" << endl;
	cout << "################################################################################" << endl;
	cout << endl;
	cout << "You have " << gold << " gold." << endl;
	cout << "You have " << totalSoldiers << " soldiers." << endl;
	cout << endl;
	

	cin >> menuSelect;
	
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void soldierShop(int &gold, int &totSoldiers, int soldierPrice, int &menuSelect)
{
	int soldierBought; //s is the amount soldiers being purchased.
	string choice = "z";
	char letter;
	bool correctInput = false;

	while (!correctInput)
	{
		cout << "----------------------------------------------------------------------------------------" << endl;
		cout << "You have " << gold << " gold\n";
		cout << "1 Soldier is " << soldierPrice << " gold." << endl;
		cout << "Do you want to buy some soldiers? Type Y for yes, or N for no." << endl;
		cin >> choice;

		letter = toupper(choice[0]);

		switch (letter)
		{

		case 'Y':
			cout << "How many?" << endl;
			cin >> soldierBought;


			while (gold < soldierPrice * soldierBought)
			{
				cout << "You can't afford this.";
				cout << "How many do you want to buy now?" << endl;
				cin >> soldierBought;

			}

			totSoldiers = soldierBought + totSoldiers;
			gold = gold - (soldierPrice * soldierBought);
			cout << "----------------------------------------------------------------------------------------" << endl;
			cout << "Total gold after purchase is: " << gold << endl;
			cout << "Total soldiers after purchase is: " << totSoldiers << endl;
			cout << endl;

			correctInput = true;
			break;

		case 'N':
			correctInput = true;
			break;

		default:
			cout << "Wrong input. Type Y for yes, or N for no.";
			break;
		}
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void BuyingUpgrades(int &gold, int &menuSelect, int &dmgUp, int &bw, int &sw, int &dcw, int &fbEW, int &cw, int &cwOO, int &aa, int &rsw, int &das, int &sps, int &gobSpell, int &masMisHam, int &dioFlask, int &jarLoDice, int &sentientWoChop, int &abySym, int &viVamBlo, int &disHalo, int &galaJournal, int &darkSign)
{
	int bwPrice = 12000; int swPrice = 36000; int dcwPrice = 75000; int fbEWPrice = 123321; int cwPrice = 250000; int cwOOPrice = 487389; int aaPrice = 666666; int rswPrice = 1000000; int dasPrice = 5000000;  int spsPrice = 10000000;
	
	int gobSpellPrice = 4000; int masMisHamPrice = 30000; int dioFlaskPrice = 120000; int jarLoDicePrice = 300000; int sentientWoChopPrice = 700000; int abySymPrice = 1400000; int viVamBloPrice = 2400000; int disHaloPrice = 3800000; int galaJournalPrice = 6000000; int darkSignPrice = 10000000;
	

	//these will adjust the modifiers you get by purchasing items that passively grant a resource
	int wineGet = 0; int woodGet = 0; int stoneGet;



	string choice = "z";
	char letter;
	int wepChoice;
	bool correctInput = false;

	while (!correctInput)
	{
		cout << "----------------------------------------------------------------------------------------" << endl;
		cout << "Welcome to Agamemnom's Armory!\n";
		cout << "\"I've got plenty of relics and weapons, if you have the coin, traveler.\"" << endl;
		cout << "You have " << gold << " gold." << endl;
		cout << endl;
		cout << "Would you like to view weapon and relic upgrades? Type Y for yes, and N for no." << endl;
		cout << "You answer: ";
		cin >> choice;

		letter = toupper(choice[0]);

		switch (letter)
		{

		case 'Y':
			//cout << "\"  \"" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "### Weapons Menu ###" << endl;
			cout << "One Time Purchase" << endl;
			cout << "1. Bronze Weapons......................" << bwPrice << " gold" << endl;
			cout << "\"Basic Bronze weapons, stronger than plain old iron.\"" << endl;
			cout << "2. Steel Weapons......................." << swPrice << " gold" << endl;
			cout << "\"Twice as sharp, at three times the price!\"" << endl;
			cout << "3. Diamond-Crusted Weapons.............75,000 gold" << endl;
			cout << "\"These are probably blood diamonds.\"" << endl;
			cout << "4. Fairy-Blood Enchanted Weapons.......123,321 gold" << endl;
			cout << "\"The blades themselves are light, but I carry the weight of what I did to those poor fairies.\"" << endl;
			cout << "5. Crystal Weapons.....................250,000 gold" << endl;
			cout << "\"The crystals are fresh from the back of a crystal-basilisk.\"" << endl;
			cout << "6. Cursed Weapons of the Old Order.....487,389 gold" << endl;
			cout << "\"Overconfidence is a slow and insidious killer, the knights of the Old Order know that best...\"" << endl;
			cout << "7. Abyssal Armory......................666,666 gold" << endl;
			cout << "\"Financing an expedition to the abyss is costly, and lighting an abyssal furnace even more so.\"" << endl;
			cout << "8. Radiant Steel Weapons...............1,000,000 gold" << endl;
			cout << "\"Blessed by the tweleve holy paladins of Elesh Mountain, these blades are imbued with angel feathers and forged in holy light.\"" << endl;
			cout << "9. Dwarven Auto-Saws...................5,000,000 gold" << endl;
			cout << "\"The pinnacle of Dwarven engineering, perfect for carving wood and flesh alike.\"" << endl;
			cout << "10. Seraphim's Peacful Scythe..........10,000,000 gold" << endl;
			cout << "\"Seraphim was a villain cast out of heaven after stealing away a weapon capable of slaying a god. And now that weapon is yours.\"" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << "### Upgrades ###" << endl;
			cout << "One Time Purchase" << endl;
			cout << "11. Goblin Shaman Spellbook......4,000 gold" << endl;
			cout << "\"Gives you access to a basic fire making spell, allowing you to create a campfire without all the toil. Passively provides food everyday.\"" << endl;
			cout << "12. Mason's Misplaced Hammer.....30,000 gold" << endl;
			cout << "\"Oh you found it! Joking, but seriously this thing is pretty powerful...Passively provides stone everyday.\"" << endl;
			cout << "13. Dionysus' Flask..............120,000 gold" << endl;
			cout << "\"He won't be missing it. Passively provides wine everyday.\"" << endl;
			cout << "14. Jaraad's Loaded Dice.........300,000 gold" << endl;
			cout << "\"Cheater's never prosper, but sometimes tipping the scale will make it a fair fight...Passively grants additional +1 to attack!\"" << endl;
			cout << "15. Sentient Wood-Chopper........700,000 gold" << endl;
			cout << "\"It's kind of annoying how much of a tree-hugger this axe is. The name Paul is etched into the hilt. Passively provides wood every day.\"" << endl;
			cout << "16. Abyssal Symbol...............1,400,000 gold" << endl;
			cout << "\"It burns with an infernal magic about it. Staring at it for too long gives you nightmares and visions of blood. Passively grants +1 to attack.\"" << endl;
			cout << "17. Vial of Vampire Blood........2,400,000 gold" << endl;
			cout << "\"Just one sip...Passively create a large amount of medicine every other day\"" << endl;
			cout << "18. Diseased Halo................3,800,000 gold" << endl;
			cout << "\"What sickness could be strong enough to befall an angel, I wonder...\"" << endl; //!
			cout << "19. Galaxous' Journal............6,000,000 gold" << endl;
			cout << "\"He was said to have sealed away the World-Gorger Dragon, but other texts point to him being the World-Gorger. More importantly though, are the lessons in necromancy written inside this tome! Now you have a chance to revive a portion of fallen soldiers after combat.\"" << endl;
			cout << "20. Darksign.....................10,000,000 gold" << endl; //!
			cout << "\"It's wispy, eerie, and whispers promises of power at the slightest stare. Surrender to the Darksign...\"" << endl << endl;
			
			cin >> wepChoice;

			switch (wepChoice)
			{
			case 1:
				if (bw == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < bwPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - bwPrice;
					bw = 1;
					dmgUp = dmgUp + 1;
					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "These new weapons grant +1 damage." << endl;
					cout << "----------------------------------------------------------------------------------------" << endl;
					break;
				}

			case 2:
				if (sw == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < swPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - swPrice;
					sw = 1;
					dmgUp = dmgUp + 1;
					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "These new weapons grant +1 damage." << endl;
					cout << "----------------------------------------------------------------------------------------" << endl;
					break;
				}

			case 3:
				if (dcw == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < dcwPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - dcwPrice;
					dcw = 1;
					dmgUp = dmgUp + 1;
					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "These new weapons grant +1 damage." << endl;
					cout << "----------------------------------------------------------------------------------------" << endl;
					break;
				}

			case 4:
				if (fbEW == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < fbEWPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - fbEWPrice;
					fbEW = 1;
					dmgUp = dmgUp + 1;
					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "These new weapons grant +1 damage." << endl;
					cout << "----------------------------------------------------------------------------------------" << endl;
					break;
				}

			case 5:
				if (cw == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < cwPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - cwPrice;
					cw = 1;
					dmgUp = dmgUp + 1;
					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "These new weapons grant +1 damage." << endl;
					cout << "----------------------------------------------------------------------------------------" << endl;
					break;
				}

			case 6:
				if (cwOO == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < cwOOPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - cwOOPrice;
					cwOO = 1;
					dmgUp = dmgUp + 1;
					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "These new weapons grant +1 damage." << endl;
					cout << "----------------------------------------------------------------------------------------" << endl;
					break;
				}
			case 7:
				if (aa == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < aaPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - aaPrice;
					aa = 1;
					dmgUp = dmgUp + 1;
					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "These new weapons grant +1 damage." << endl;
					cout << "----------------------------------------------------------------------------------------" << endl;
					break;
				}

			case 8:
				if (rsw == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < rswPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - rswPrice;
					rsw = 1;
					dmgUp = dmgUp + 1;
					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "These new weapons grant +1 damage." << endl;
					cout << "----------------------------------------------------------------------------------------" << endl;
					break;
				}

			case 9:
				if (das == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < dasPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - dasPrice;
					das = 1;
					dmgUp = dmgUp + 1;
					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "These new weapons grant +1 damage." << endl;
					cout << "----------------------------------------------------------------------------------------" << endl;
					break;
				}

			case 10:
				if (sps == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < spsPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - spsPrice;
					sps = 1;
					dmgUp = dmgUp + 1;
					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "These new weapons grant +1 damage." << endl;
					cout << "----------------------------------------------------------------------------------------" << endl;
					break;
				}

			case 11:
				if (gobSpell == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < gobSpellPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - gobSpellPrice;
					gobSpell = 1;

					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "\"The goblin shamans of the red-rock practie magic, in order to subdue their brethern of green-rock.\"" << endl;
					cout << "\"Firemaking is a basic spell in their arsenal, with some shamans having risen to heights of power so high\n that they can call down comets of blazing hellfire.\"" << endl;
					cout << "\"Most goblins aren't smart enough to understand the sigils and runes that have gone in to these worn, and somewhat soggy, tomes.\n Beneath the constant references and praises to Garherx, the goblin god, there are powerful incantation in these pages...\"" << endl;
					cout << "You now gain a small amount of food passively each day." << endl;
					cout << "----------------------------------------------------------------------------------------" << endl;
					break;
				}


			case 12:
				if (masMisHam == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < masMisHamPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - masMisHamPrice;
					masMisHam = 1;

					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "\"The great stone shaper, Mason, was said to have shaped every mountain by hand at the beggining of time.\"" << endl;
					break;
				}

			case 13:
				if (dioFlask == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < dioFlaskPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - dioFlaskPrice;
					dioFlask = 1;

					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "" << endl;
					break;
				}

			case 14:
				if (jarLoDice == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < jarLoDicePrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - jarLoDicePrice;
					jarLoDice = 1;
					dmgUp = dmgUp + 1;
					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "These new weapons grant +1 damage." << endl;
					break;
				}

			case 15:
				if (sentientWoChop == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < sentientWoChopPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - sentientWoChopPrice;
					sentientWoChop = 1;

					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "" << endl;
					break;
				}

			case 16:
				if (abySym == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < abySymPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - abySymPrice;
					abySym = 1;
					dmgUp = dmgUp + 1;
					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "These new weapons grant +1 damage." << endl;
					break;
				}

			case 17:
				if (viVamBlo == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < viVamBloPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - viVamBloPrice;
					viVamBlo = 1;

					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "" << endl;
					break;
				}

			case 18:
				if (disHalo == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < disHaloPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - disHaloPrice;
					disHalo = 1;
					dmgUp = dmgUp + 1;
					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "" << endl;
					break;
				}

			case 19:
				if (galaJournal == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < galaJournalPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - galaJournalPrice;
					galaJournal = 1;
					dmgUp = dmgUp + 1;
					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "\"Galaxous' spirit is sealed away in this journal, all his thoughts and feelings. Powerful magics bind him to the pages and only powerful magics can release him. We're not sure if he's a hero, or a destroyer...probably best to keep him sealed up.\"" << endl;
					break;
				}

			case 20:
				if (darkSign == 1)
				{
					cout << "You already own this upgrade!" << endl;
					cout << "Come back when you want to buy something new, traveler!" << endl;
					break;
				}
				else
				{
					while (gold < darkSignPrice)
					{
						cout << "You don't have enough gold to purchase this!" << endl;
						break;
					}
					gold = gold - darkSignPrice;
					darkSign = 1;
					dmgUp = dmgUp + 1;
					cout << "----------------------------------------------------------------------------------------" << endl;
					cout << "Total gold after purchase is: " << gold << endl;
					cout << "These new weapons grant +1 damage." << endl;
					break;
				}

			default:
				cout << "Wrong input. Enter the corresponding number to the upgrade you wish to purchase." << endl;
				cin >> wepChoice;
				break;


			}


			correctInput = true;
			break;

		case 'N':
			correctInput = true;
			break;

		default:
			cout << "Wrong input. Type Y for yes, or N for no.";
			break;
		}
	}



}
	

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void BuyingProperty(int &gold, int &farms, int &castle, int &watermill, int &food, int &wood, int &stone)
{
	int farmsBought;
	int castlesBought;
	int watermillsBought;
	int watermillPrice = 5000;
	int farmPrice = 2000;
	int castlePrice = 100000;

	string choice = "y";
	char letter;
	int propertyMenuChoice;
	bool correctInput = false;

	while (!correctInput)
	{
		cout << endl << "----------------------------------------------------------------------------------------" << endl;
		cout << "Welcome to Jace's Real Estate." << endl;
		cout << "You currently own " << farms << " farms." << endl;
		cout << "You currently own " << watermill << " watermills." << endl;
		cout << "You currently own " << castle << " castles." << endl;
		cout << endl;
		cout << "Would you like to buy some property? Y for yes, and N for no.";
		cin >> choice;

		letter = toupper(choice[0]);

		switch (letter)
		{

		case 'Y':
			cout << "What would you like to buy?" << endl;

			cout << "Enter 1 to buy farms." << endl;
			cout << "Enter 2 to buy watermills." << endl;
			cout << "Enter 3 to buy castles." << endl;
			cin >> propertyMenuChoice;

			switch (propertyMenuChoice)
			{
			case 1:

				cout << "How many farms do you want to purchase?";
				cin >> farmsBought;

				while (gold < farmPrice * farmsBought)
				{
					cout << "You can't afford this.";
					cout << "How many do you want to buy now?" << endl;
					cin >> farmsBought;

				}

				farms = farmsBought + farms;
				gold = gold - (farmPrice * farmsBought);
				cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
				cout << "Total gold after purchase is: " << gold << endl;
				cout << "Total farms owned after purchase is: " << farms << endl;
				cout << endl;

				correctInput = true;
				break;

			case 2:

				cout << "How many watermills do you want to purchase?";
				cin >> watermillsBought;

				while (gold < watermillPrice * watermillsBought)
				{
					cout << "You can't afford this.";
					cout << "How many do you want to buy now?" << endl;
					cin >> watermillsBought;

				}

				farms = farmsBought + farms;
				gold = gold - (farmPrice * farmsBought);
				cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
				cout << "Total gold after purchase is: " << gold << endl;
				cout << "Total farms owned after purchase is: " << farms << endl;
				cout << endl;

				correctInput = true;
				break;



			case 3:

				cout << "How many castles do you want to purchase?";
				cin >> castlesBought;

				while (gold < castlePrice * castlesBought)
				{
					cout << "You can't afford this.";
					cout << "How many do you want to buy now?" << endl;
					cin >> castlesBought;

				}

				castle = castlesBought + castle;
				gold = gold - (castlePrice * castlesBought);
				cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
				cout << "Total gold after purchase is: " << gold << endl;
				cout << "Total watermills owned after purchase is: " << castle << endl;
				cout << endl;

				correctInput = true;
				break;

			default:
				cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
				cout << "Wrong input." << endl;
				cout << "Enter 1 to buy farms." << endl;
				cout << "Enter 2 to buy watermills." << endl;
				cout << "Enter 3 to buy castles." << endl;

				break;
			}
			break;





		case 'N':
			correctInput = true;
			break;

		default:
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			cout << "Wrong input. Type Y for yes, or N for no." << endl;
			cout << endl;
			break;



		}

	}
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void BuyingItems(int &gold, int &menuSelect, int &spices, int &food, int &stone, int &wood, int &gem, int &treasure, int &wine, int &medicine)
{
	int stonePrice = 75;
	int woodPrice = 50;
	int spicesPrice = 150;

	int stoneBought; int woodBought; int spicesBought;
	int gemSold; int woodSold; int spicesSold; int treasureSold; int wineSold; int foodSold;  //how many you are selling

	// These int's are for how much they are worth when selling back
	int woodSell = 30;
	int wineSell = 20;
	int gemSell = 120;
	int spicesSell = 50;
	int foodSell = 35;
	int treasureSell = 140;
	//

	string choice = "z";
	char letter;
	int purchase; 
	int sell;
	bool correctInput = false;


	while (!correctInput)
	{
		cout << "----------------------------------------------------------------------------------------" << endl;
		cout << "Welcome to the market!\n";
		cout << "You have " << gold << " gold." << endl;
		cout << "You have " << wood << " wood." << endl;
		cout << "You have " << stone << " stone." << endl;
		cout << "You have " << spices << " spices." << endl;
		cout << endl;
		cout << "Would you like to buy more? Type B for buy, and S for sell." << endl;
		cin >> choice;

		letter = toupper(choice[0]);
		switch (letter)
		{
		case 'B':
			cout << "1. Wood.....50 gold per log" << endl;
			cout << "2. Stone....75 gold per slab" << endl;
			cout << "3. Spice....150 gold per pound" << endl;
			cout << "Enter the number corresponding to the product you'd like to purchase." << endl;
			cin >> purchase;


			switch (purchase)
			{

			case 1:
				cout << "How many? Enter an ammount." << endl;
				cin >> woodBought;


				while (gold < woodPrice * woodBought)
				{
					cout << "You can't afford this.";
					cout << "How many do you want to buy now?" << endl;
					cin >> woodBought;

				}

				wood = woodBought + wood;
				gold = gold - (woodPrice * woodBought);
				cout << "----------------------------------------------------------------------------------------" << endl;
				cout << "Total gold after purchase is: " << gold << endl;
				cout << "Total weapons and armors after purchase is: " << wood << endl;
				cout << endl;

				correctInput = true;
				break;

			case 2:
				cout << "How many?" << endl;
				cin >> stoneBought;


				while (gold < stonePrice * stoneBought)
				{
					cout << "You can't afford this.";
					cout << "How many do you want to buy now?" << endl;
					cin >> stoneBought;

				}

				stone = stoneBought + stone;
				gold = gold - (stonePrice * stoneBought);
				cout << "----------------------------------------------------------------------------------------" << endl;
				cout << "Total gold after purchase is: " << gold << endl;
				cout << "Total weapons and armors after purchase is: " << stone << endl;
				cout << endl;

				correctInput = true;
				break;

			case 3:
				cout << "How many?" << endl;
				cin >> spicesBought;


				while (gold < spicesPrice * spicesBought)
				{
					cout << "You can't afford this.";
					cout << "How many do you want to buy now?" << endl;
					cin >> spicesBought;

				}

				spices = spicesBought + spices;
				gold = gold - (spicesPrice * spicesBought);
				cout << "----------------------------------------------------------------------------------------" << endl;
				cout << "Total gold after purchase is: " << gold << endl;
				cout << "Total weapons and armors after purchase is: " << stone << endl;
				cout << endl;

				correctInput = true;
				break;



			default:
				cout << "----------------------------------------------------------------------------------------" << endl;
				cout << "Wrong input." << endl;
				cout << "Enter 1 to buy wood." << endl;
				cout << "Enter 2 to buy stone." << endl;
				cout << "Enter 3 to buy spices." << endl;
				break;
			}

			correctInput = true;
			break;

		case 'S':
			cout << "What would you like to sell?" << endl;
			cout << "1. Wood.........30 gold" << endl;
			cout << "2. Gems.........120 gold" << endl;
			cout << "3. Wine.........20 gold" << endl;
			cout << "4. Spices.......50 gold" << endl;
			cout << "5. Treasure.....140 gold" << endl;
			cout << "6. Food.........35 gold" << endl;
			cin >> sell;

			switch (sell)
			{
			case 1:
				cout << "How many logs? Enter an ammount." << endl;
				cin >> woodSold;


				while (wood < woodSold)
				{
					cout << "You don't have enough to sell!";
					cout << "How many do you actually want to sell now?" << endl;
					cin >> woodSold;

				}

				wood = wood - woodSold;
				gold = gold + (woodSell * woodSold);
				cout << "----------------------------------------------------------------------------------------" << endl;
				cout << "Total gold after purchase is: " << gold << endl;
				cout << "Total weapons and armors after purchase is: " << wood << endl;
				cout << endl;
				correctInput = true;
				break;

			case 2:
				cout << "How many gems? Enter an ammount." << endl;
				cin >> gemSold;


				while (gem < gemSold)
				{
					cout << "You don't have enough to sell!";
					cout << "How many do you actually want to sell now?" << endl;
					cin >> gemSold;

				}

				gem = gem - gemSold;
				gold = gold + (gemSell * gemSold);
				cout << "----------------------------------------------------------------------------------------" << endl;
				cout << "Total gold after purchase is: " << gold << endl;
				cout << "Total weapons and armors after purchase is: " << gem << endl;
				cout << endl;
				correctInput = true;
				break;

			case 3:
				cout << "How many gems? Enter an ammount." << endl;
				cin >> wineSold;


				while (wine < wineSold)
				{
					cout << "You don't have enough to sell!";
					cout << "How many do you actually want to sell now?" << endl;
					cin >> wineSold;

				}

				wine = wine - wineSold;
				gold = gold + (wineSell * wineSold);
				cout << "----------------------------------------------------------------------------------------" << endl;
				cout << "Total gold after purchase is: " << gold << endl;
				cout << "Total wine after purchase is: " << wine << endl;
				cout << endl;
				correctInput = true;
				break;



			case 4:
				cout << "How many spices? Enter an ammount." << endl;
				cin >> spicesSold;


				while (spices < spicesSold)
				{
					cout << "You don't have enough to sell!";
					cout << "How many do you actually want to sell now?" << endl;
					cin >> spicesSold;

				}

				spices = spices - spicesSold;
				gold = gold + (spicesSell * spicesSold);
				cout << "----------------------------------------------------------------------------------------" << endl;
				cout << "Total gold after purchase is: " << gold << endl;
				cout << "Total spices purchase is: " << spices << endl;
				cout << endl;
				correctInput = true;
				break;

			case 5:
				cout << "How many treasures? Enter an ammount." << endl;
				cin >> treasureSold;


				while (treasure < treasureSold)
				{
					cout << "You don't have enough to sell!";
					cout << "How many do you actually want to sell now?" << endl;
					cin >> treasureSold;

				}

				treasure = treasure - treasureSold;
				gold = gold + (treasureSell * treasureSold);
				cout << "----------------------------------------------------------------------------------------" << endl;
				cout << "Total gold after purchase is: " << gold << endl;
				cout << "Total spices purchase is: " << treasure << endl;
				cout << endl;

				correctInput = true;
				break;

			case 6:
				cout << "How many treasures? Enter an ammount." << endl;
				cin >> foodSold;


				while (food < foodSold)
				{
					cout << "You don't have enough to sell!";
					cout << "How many do you actually want to sell now?" << endl;
					cin >> foodSold;

				}

				food = food - foodSold;
				gold = gold + (foodSell * foodSold);
				cout << "----------------------------------------------------------------------------------------" << endl;
				cout << "Total gold after purchase is: " << gold << endl;
				cout << "Total food purchase is: " << treasure << endl;
				cout << endl;

				correctInput = true;
				break;


			default:
				cout << "----------------------------------------------------------------------------------------" << endl;
				cout << "\"What was that? Tell me again what you want.\"" << endl;
				cout << "Enter 1 to buy wood." << endl;
				cout << "Enter 2 to buy gems." << endl;
				cout << "Enter 3 to buy wine." << endl;
				cout << "Enter 4 to buy spices." << endl;
				cout << "Enter 5 to buy treasure." << endl;
				cout << "Enter 6 to buy food." << endl;
				cin >> sell;
				break; 

			}
			
			correctInput = true;
			break;



		default:
			cout << "Incorrect input, type B to buy or S to sell" << endl;
			cin >> choice;
			correctInput = true;
			break;

		}

	} //while loop

}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Combat(int &totalSoldiers, int &dmgUp, int &food, int &AC, int &eventNum)
{
	int enemy;

	int d20;
	
	int enemyDamage; //damage bonuses
	int enemyArmor; // armor bonuses
	int enemyNumber; //Enemy army size

	bool inCombat = false;

	int smallestArmySize;

	vector<int>yourArmy(totalSoldiers, 1);

		if (1 <= eventNum && eventNum <= 50) //Bandits
		{
			cout << "Your army consists of " << totalSoldiers << " soldiers." << endl;
			cout << "Keep your wits about you, the enemy lusts for blood!" << endl;

			enemyNumber = (rand() % 2) + 11; //adjust enemy army size
			enemyDamage = 1; //edit this
			enemyArmor = 12; //edit this

			vector<int>enemyArmy(enemyNumber, 1);

			if (yourArmy.size() < enemyArmy.size())
			{
				smallestArmySize = yourArmy.size();
			}
			else
				smallestArmySize = enemyArmy.size();

			for  (int i = 0; i < smallestArmySize; i++)
			{
				d20 = (rand() % 20) + 1;
				Sleep(1);
				if (d20 + baseDMG + dmgUp >= enemyArmor) //Player's Roll
				{
					enemyArmy[i] -= 1;
					
				}

				d20 = (rand() % 20) + 1;
				Sleep(1);
				if (d20 + enemyDamage >= baseArmor + AC) //Enemy's Roll
				{
					yourArmy[i] -= 1;
				}
			}
			for (int i = smallestArmySize - 1; 0 < i; i--)
			{
				if (enemyArmy[i] == 0)
				{
					enemyArmy.erase(enemyArmy.begin() + i);
				}
				if (yourArmy[i] == 0)
				{
					yourArmy.erase(yourArmy.begin() + i);
					totalSoldiers--;
				}
			}
		}
		if (51 <= eventNum && eventNum <= 100) //Undead Combat
		{
			cout << "Your army consists of " << totalSoldiers << " soldiers." << endl;
			cout << "Keep your wits about you, the enemy hungers for flesh!" << endl;

			enemyNumber = (rand() % 15) + 20; //adjust enemy army size
			enemyDamage = 1; //edit this
			enemyArmor = 10; //edit this

			vector<int>enemyArmy(enemyNumber, 1);

			if (yourArmy.size() < enemyArmy.size())
			{
				smallestArmySize = yourArmy.size();
			}
			else
				smallestArmySize = enemyArmy.size();

			for (int i = 0; i < smallestArmySize; i++)
			{
				d20 = (rand() % 20) + 1;
				Sleep(1);
				if (d20 + baseDMG + dmgUp >= enemyArmor) //Player's Roll
				{
					enemyArmy[i] -= 1;

				}

				d20 = (rand() % 20) + 1;
				Sleep(1);
				if (d20 + enemyDamage >= baseArmor + AC) //Enemy's Roll
				{
					yourArmy[i] -= 1;
				}
			}
			for (int i = smallestArmySize - 1; 0 < i; i--)
			{
				if (enemyArmy[i] == 0)
				{
					enemyArmy.erase(enemyArmy.begin() + i);
				}
				if (yourArmy[i] == 0)
				{
					yourArmy.erase(yourArmy.begin() + i);
					totalSoldiers--;
				}
			}
		} 
		if (126 <= eventNum && eventNum <= 150)
		{
			cout << "Your army consists of " << totalSoldiers << " soldiers." << endl;
			cout << "Vampyres are vial creatures. Large and feral; they stand eight feet tall and are covered in fur. Send them back to the pit!" << endl;

			enemyNumber = (rand() % 5) + 3; //adjust enemy army size
			enemyDamage = 2; //edit this
			enemyArmor = 13; //edit this

			vector<int>enemyArmy(enemyNumber, 1);

			if (yourArmy.size() < enemyArmy.size())
			{
				smallestArmySize = yourArmy.size();
			}
			else
				smallestArmySize = enemyArmy.size();

			for (int i = 0; i < smallestArmySize; i++)
			{
				d20 = (rand() % 20) + 1;
				Sleep(1);
				if (d20 + baseDMG + dmgUp >= enemyArmor) //Player's Roll
				{
					enemyArmy[i] -= 1;

				}

				d20 = (rand() % 20) + 1;
				Sleep(1);
				if (d20 + enemyDamage >= baseArmor + AC) //Enemy's Roll
				{
					yourArmy[i] -= 1;
				}
			}
			for (int i = smallestArmySize - 1; 0 < i; i--)
			{
				if (enemyArmy[i] == 0)
				{
					enemyArmy.erase(enemyArmy.begin() + i);
				}
				if (yourArmy[i] == 0)
				{
					yourArmy.erase(yourArmy.begin() + i);
					totalSoldiers--;
				}
			}
		}
		


		cout << "Combat Done" << endl;
		cout << "After-combat report: " << endl;
		cout << "Soldiers: " << totalSoldiers << endl;

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Explore(int &gold, int &farms, int &castle, int &UnderRealm, int &verdantWilds, int &foreverNightmare, int &northBabylon, int &watermill, int &spices, int &food, int &stone, int &wood, int &gem, int &treasure, int &wine, int &medicine, int &totalSoldiers, int &villages, int &cities, int &AC, int &eventNum, int &gobSpell, int &masMisHam, int &dioFlask, int &sentientWoChop, int &viVamBlo)
{
	

	eventNum = (rand() % 1500) +1;
	Sleep(500);
	int eventNum2 = (rand() % 100) + 1;
	Sleep(100);
	int earthquake = (rand() % 50) + 20;
	int plague;

	static int day = 0;
	day++; //Everytime this function is called (meaning the explore menu is opened), the day will go up by one.

	//Calculates income based on properties you own.
	int income;
	//Calculates how much food is produced based on farms you own.
	int harvest;

	for (static int z = 0; z < day; z++)
	{

		if ((z % 2) == 1)
		{
			if (gobSpell == 1)
			{
				food = food + 25;
			}
			if (masMisHam == 1)
			{
				stone = stone + 25;
			}
			if (dioFlask == 1)
			{
				wine = wine + 25;
			}
			if (sentientWoChop)
			{
				sentientWoChop = wood + 25;
			}
			if (viVamBlo == 1)
			{
				medicine = medicine + 25;
			}
		}
		if ((z % 7) == 0)
		{
			income = (farms * 100) + (castle * 50) + (watermill * 750);
			gold = gold + income;
			cout << endl;
			cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
			cout << "Income this week is: " << income << endl;
			cout << "Total gold after income is: " << gold << endl;
		}
		if ((z % 16) == 0)
		{
			harvest = (farms * 100) + (watermill * 25);
			cout << "This season's harvest garnered this much food: " << harvest << endl;
			cout << "Total food in our food-stores is: " << food << endl;
			cout << endl;
		}
		if ((z % 30) == 0) //Monthly events
		{
			cout << "!!!!!!!!!!!!!!The monthly report is in!!!!!!!!!!!!!! " << endl;


			if (1 <= eventNum2 && eventNum2 <= 20)
			{
				cout << "\"My liege, our supply lines and reserve forces were struck by an earthquake, a minor set back in the construction of our empire.\"" << endl;
				cout << "Casualties: " << totalSoldiers - earthquake;
				cout << "Supplies lost: " << food - earthquake;
			}
			if (21 <= eventNum2 && eventNum2 <= 40)
			{
				if (totalSoldiers >= 100 && totalSoldiers >= 500)
				{
					cout << "\"My liege, a plague has spread throughout our ranks. Soldiers burn the dead and try to quarentine the afflicted.\"" << endl; 
					cout << "\"This is a major blow to our forces.\"" << endl;
					plague = (rand() % 40) + 20;
					cout << "Casualties: " << totalSoldiers - plague;
				}
				if (totalSoldiers >= 501 && totalSoldiers >= 1000)
				{
					cout << "\"My liege, a plague has spread throughout our ranks. Soldiers burn the dead and try to quarentine the afflicted.\"" << endl;
					cout << "\"This is a major blow to our forces.\"" << endl;
					plague = (rand() % 100) + 40;
					cout << "Casualties: " << totalSoldiers - plague;
				}
				if (totalSoldiers >= 1001 && totalSoldiers >= 3000)
				{
					cout << "\"My liege, a plague has spread throughout our ranks. Soldiers burn the dead and try to quarentine the afflicted.\"" << endl;
					cout << "\"This is a major blow to our forces.\"" << endl;
					plague = (rand() % 300) + 60;
					cout << "Casualties: " << totalSoldiers - plague;
				}
				if (totalSoldiers >= 3001 && totalSoldiers >= 5000)
				{
					cout << "\"My liege, a plague has spread throughout our ranks. Soldiers burn the dead and try to quarentine the afflicted.\"" << endl;
					cout << "\"This is a major blow to our forces.\"" << endl;
					plague = (rand() % 500) + 80;
					cout << "Casualties: " << totalSoldiers - plague;
				}
				if (totalSoldiers >= 5001 && totalSoldiers >= 10000)
				{
					cout << "\"My liege, a plague has spread throughout our ranks. Soldiers burn the dead and try to quarentine the afflicted.\"" << endl;
					cout << "\"This is a major blow to our forces.\"" << endl;
					plague = (rand() % 1000) + 50;
					cout << "Casualties: " << totalSoldiers - plague;
				}

			}
			if (41 <= eventNum2 && eventNum2 <= 80)
			{
				cout << "\"The report says that this month has been quite effecient for our empire. Our merchants have found room in our gold-margins to add to our total funding.\"" << endl;
				cout << "Total gold last month: " << gold << endl;
				gold = gold + 10000;
				cout << "Total gold after additionalo funds are generated: " << gold << endl;
			}
			if (81 <= eventNum2 && eventNum2 <= 100)
			{
				cout << "\"A caravan of merchants and refugees stopped by our encampent. Our forces and wealth are ever growing \"" << endl;
				cout << "Total gold last month: " << gold << endl;
				cout << "Total soldiers last month: " << totalSoldiers << endl;
				gold = gold + 10000;
				totalSoldiers = totalSoldiers + 300;
				cout << "Total gold after additional funds are generated: " << gold << endl;
				cout << "Total soldiers after additional troops are trained: " << totalSoldiers << endl;
			}

		}
	}

	string choice = "z";
	char letter;
	int exploreChoice;
	bool correctInput = false;


	cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "Day: " << day << endl;
	cout << "Preparing to embark on a journey today?" << endl;
	cout << "Would you like to camp or embark? Y for yes, and N for no." << endl;
	cin >> choice;
	cout << endl;

	letter = toupper(choice[0]);

	while (!correctInput)
	{
		switch (letter)
		{

		case 'Y':
			cout << "Everyone seems ready to leave!" << endl;
			cout << "Press 1 to Camp" << endl;
			cout << "Press 2 to Explore South Babylon" << endl;
			if (verdantWilds == 1)
				cout << "Press 3 to Explore the Verdant Wilds" << endl;
			if (foreverNightmare == 1)
				cout << "Press 4 to Explore the Forever Nightmare" << endl;
			if (northBabylon == 1)
				cout << "Press 5 to explore North Babylon" << endl;
			if (UnderRealm == 1)
				cout << "Press 6 to explore the Under Realm" << endl;

			cin >> exploreChoice;
			cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

			switch (exploreChoice)
			{
			case 1: //this case is to camp, do nothing and let time pass, need to figure out how to code this

				break;

			case 2: 
				if (1 <= eventNum && eventNum <= 50)
				{
					//Event 1
					cout << "The day is warm, and the sun sits directly above our forces, its rays only broken by the forest's canopy above.\n";
					cout << "As we march through these shaded woods, some of your troops begin to feel uneasy.\n";
					cout << "Several troops have reported a shifting in the woods. The soldiers feel as though they are being watched.\n!";
					cout << "Scouts report their are empty remnants of encampents in the woods just north of our position, whatever was there has moved out now...\n";
					cout << "An arrow whizzes just past your face, the steel tip embedding itself in a nearby tree as you turn to face the direction it came from.\n";
					cout << "Turning quickly, a woman riding atop a large wolf-bear has come over a nearby ridge, several other outriders at her side.\n";
					cout << "A volley of arrows comes down onto our troops!\n";
					cout << "Prepare for battle, we're being attacked by bandits!\n";

					Combat(totalSoldiers, dmgUp, food, AC, eventNum);
					gold += 1500;

				}
				if (51 <= eventNum && eventNum <= 100)
				{
					//Event 2
					cout << "A heavy fog begins to set in, and the roads start to wind." << endl;
					cout << "Weary soldiers bicker and argue amongst themselves as an uneasy feelings comes over them." << endl;
					cout << "A soldier breaks down onto his knees screaming and uncontrollably crying. Madness comes. " << endl;
					cout << "Another soldier begins to feverishly repeat to himself, \"The Grove of Nightmares, The Grove of Nightmares, doomed are all who dare to sleep, for here the night will claim the weak!\" " << endl;
					cout << "A sudden scream causes stares all about as the dirt beneath your forces begins to shift. At the very edge of the fog shadowy figures shift about..." << endl;
					cout << "Prepare for combat, ready your arms! The dead have risen!" << endl;

					Combat(totalSoldiers, dmgUp, food, AC, eventNum);
					gold += 400;
				}
				if (101 <= eventNum && eventNum <= 125)
				{
					//Event Dwarven armorsmith
					//Event 3
					if (AC == 3)
					{
						cout << "You've come across the old smithy again. The girl working the anvil doesn't want to be bothered...perhaps it'd be best to simply pay your respect to the old smith's resting place." << endl;
					}
					if (AC == 2)
					{
						cout << "A storm has divivded you from your forces, and in the dead of night you are your detachment hold up in an aold watch tower." << endl;
						cout << "As the wind blows, and the fire wavers to the dampness of the icy stone, one of your soldiers says he recognizes this place." << endl;
						cout << "\"My liege, this is the mountain where that old smithy lives\" one of you lieutenants points out." << endl;
						cout << "Amidst the darkness, you decide to pay a visit to the old smithy. Trying your best to circumvent the path, you make your way up the mountain." << endl;
						cout << "Finally you make your way through mud and rain until you are at the top of the mountain where a disheveled and slightly rundown furnace burns, accompanied by the sound of metal clanging against metal." << endl;
						cout << "Approaching the smithy, you are very surprised to see a younger dwarf girl working the anvil, her cheeks dirtied with oil, but a bright blush still comes through." << endl;
						cout << "\"Aye! You must be the one the old coot went on about! Are ya here for his armor?\" she asks, not turning away from the anvil." << endl;
						cout << "\"He went on and on about how it was his finest work yet, my uncle took pride in furnishing these armors. Ye had given him purpose after he settled far out here...He's gone now, but he left that behind for ya.\" the dwarf continues pounding away at the metal." << endl;
						cout << "\"Where ever he is, I'm sure the old coot is happy that his works of art are still in use.\" she finishes, pointing a free hand towards a shiny piece of ploished adamantium armor." << endl;
						cout << "Your AC has gone up by 1!" << endl;
						AC += 1;

					}
					if (AC == 1)
					{
						cout << "Your trekking and exploring have led your forces back to the very same crumbling watch tower at the base of the Icewatch Mountains." << endl;
						cout << "Scouts report that in light of a recent avalanche, the pass you and your soldiers had taken previously is blocked." << endl;
						cout << "Seeking a way past, you hear legend of an old cave at the base of the mountain." << endl;
						cout << "After another soldier steps forth to provide additonal information on the cave, you learn two things!" << endl;
						cout << "The cave was home to an anicent coven of witches who had nurtured the egg for the first dragon." << endl;
						cout << "Second, it has a secret passage that leads to an ancient ruin at the top of the mountain, conveiently just a ways off from the old smithy." << endl;
						cout << "After making the long and arduous journey through torch-lit darkness, you spring forth from the crumbled ruins of the old Dwarven stronghold" << endl;
						cout << "Following a dusty path, you finally come across the old smithy you had visited prior!" << endl;
						cout << "\"Ello' thar' old friend! Got yerself armor that needs fixin'?\" an old, grumbly voice calls out between the loud clangs of a hammer smacking the anvil." << endl;
						cout << "Between thick coughs and heavy wheezes, the old dwarf finishes reinforcing your armor." << endl;
						cout << "Your AC has gone up by 1!" << endl;
						AC += 1;
					}
					if (AC == 0)
					{
						cout << "The scouts report that there is a small smithery just north of a crumbling watch tower, on the side of the Icewatch Mountains." << endl;
						cout << "Taking a small detachment of your forces up there, the rest of your soldiers set up camp." << endl;
						cout << "It's about a day's journey up and around the mountain. When the smithery finally comes into view, you can see smoke billowing out of an old, iron chimney." << endl;
						cout << "As you and your detachment approach the old smithy, a stout looking dwarf with grayish hair and a balding head comes out." << endl;
						cout << " \"G'day, are ye' a customer of sorts? I can spruce up that rusted tin ye'call armor!\" " << endl;
						cout << "\"It's hard gettin' customers thes far out ye' see. Bein' aloyn oan the mountain has left me...a bit lonely.\", his accent as thick as his beard.";
						cout << "\"I'll do er' up for ye', let me modify yer' armor there, see. She'll be able to take more of a beating in battle!\" " << endl;
						cout << "****************************************************************************************" << endl;
						int AC = 1;
						cout << "Your armor class has risen by 1." << endl;
					}

				}
				if (126 <= eventNum && eventNum <= 150)
				{	
					cout << "The mist here grows thick, as our armies approach a rundown abbey." << endl;
					cout << "The bricks smell like rot, and the stench of death permeates the air, it’s so heavy…" << endl;
					cout << "The town surrounding is burnt to cinders, and the buildings razed." << endl;
					cout << "Our soldiers feel uneasy, something is watching us from the surrounding thicket, this place is cursed!" << endl;
					cout << "A lieutenant stumbles forward, and he is bleeding from both eyes. “Sir!The woods, the vampyres! They’re here, they’ve come for human blood!” he screams." << endl;
					cout << "Feral vampyres are spilling out from the woods, they’re massive and covered in blood-matted fur." << endl;
					cout << "They’re claws scrape against the mud while trees splinter around their enormous bat-like forms." << endl;
					cout << "They stumble onto the cobble roads, charging at our ranks...prepare for battle!" << endl;

					Combat(totalSoldiers, dmgUp, food, AC, eventNum);
					gold += 200;

				}
				if (151 <= eventNum && eventNum <= 200)
				{
					//Event 5
					cout << "We seem to have stumbled upon the entrance to an old mine shaft." << endl;
					cout << "Our troops are currently exploring it the entrance, and there seems to be dwarves posted all around it!" << endl;
					cout << "Cut into the side of the mountain, the mine shaft leads down about 600 feet before it merges into an massive cavern..." << endl;
					cout << "At the mouth of the cavern, near the foot fo the mine shaft, the dwarves greet our soldiers with open arms. " << endl;
					cout << "They say that they haven't seen any friendly faces in months and that the king who led them on the expedition into this cavern has disappeared." << endl;
					cout << " " << endl;

				} 
				if (201 <= eventNum && eventNum <= 250)
				{
					//Event 6
					cout << "We seem to have stumbled upon the entrance to an underground city." << endl;

				}

				break; //case 2

			default: 
				cout << "////////////////////////////////////////////////////////////////////////////////" << endl;
				cout << "Wrong input. Type a number that correlates to the menu!" << endl;
				cout << endl;
				break;
			}
			correctInput = true; //case Y
			break; // case Y
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		case 'N':

			break;

		default:
			cout << "----------------------------------------------------------------------------------------" << endl;
			cout << "Wrong input. Type Y for yes, or N for no." << endl;
			cout << endl;
			break;

		}


	}
	
	}

