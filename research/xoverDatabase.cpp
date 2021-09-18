
#include <iostream>
#include <random>
#include <fstream>

// MM1 (8) + MM2 (16) + MM3 (24) + MM4 (32) + MM5 (40) + MM6 (48) + MM7 (56) + 
// MM8 (64) + MegaBall (65) + MM&B (73) + MM9 (81) + MM10 (89) + MMV & Terra (98) +
// Punk/Ballade/Enker/Quint (102) + RaThor (103)
#define MAX_1D 103

// This indicates the index at which the ND tier terminates 
#define MAX_2D 23
#define MAX_3D 5
#define MAX_4D 3
#define MAX_5D 2

#define MAX_23D MAX_2D + MAX_3D
#define MAX_234D MAX_23D + MAX_4D
#define MAX_2345D MAX_234D + MAX_5D // "MAX_XOVER_WEAPONS"

#define END_1D MAX_1D
#define END_2D END_1D+MAX_2D
#define END_3D END_2D+MAX_3D
#define END_4D END_3D+MAX_4D

#define TOTAL_WEPS MAX_2345D + MAX_1D
#define TOTAL_INGREDIENTS TOTAL_WEPS - MAX_5D

#define TABLE_CAPACITY 5


std::string names[TOTAL_WEPS] = {
	"Super Arm","Hyper Bomb","Ice Slasher","Thunder Beam",
	"Fire Storm","Rolling Cutter","Time Slow","Oil Slider",
	
	"Bubble Lead","Metal Blade","Atomic Fire","Leaf Shield",
	"Air Shooter","Quick Boomerang","Crash Bomb","Time Stopper",
	
	"Magnet Missile","Top Spin","Needle Cannon","Shadow Blade",
	"Gemini Laser","Search Snake","Hard Knuckle","Spark Shock",
		
	"Drill Bomb","Ring Boomerang","Dust Crusher","Pharaoh Shot",
	"Skull Barrier","Dive Missile","Rain Flush","Flash Stopper",
	
	"Napalm Bomb","Charge Kick","Gyro Attack","Power Stone",
	"Water Wave","Crystal Eye","Star Crash","Gravity Hold",
	
	"Blizzard Attack","Flame Blast","Yamato Spear","Plant Barrier",
	"Silver Tomahawk","Wind Storm","Knight Crush","Centaur Flash",
	
	"Freeze Cracker","Noise Crush","Wild Coil","Danger Wrap",
	"Scorch Wheel","Junk Shield","Slash Claw","Thunder Bolt",
	
	"Astro Crush","Flame Sword","Thunder Claw","Homing Sniper",
	"Water Balloon","Mega Ball","Flash Bomb","Ice Wave","Tornado Hold",
	
	"Tengu Blade","Wave Burner","Spread Drill","Magic Card",
	"Remote Mine","Copy Vision","Ice Wall","Lightning Bolt",
	
	"Plug Ball","Laser Trident","Black Hole Bomb","Jewel Satellite",
	"Concrete Shot","Tornado Blow","Hornet Chaser","Magma Bazooka",
	
	"Solar Blaze", "Wheel Cutter", "Rebound Striker", "Thunder Wool", 
	"Commando Bomb", "Chill Spike", "Water Shield", "Triple Blade",
	
	"Grab Buster", "Bubble Bomb", "Photon Missile", "Salt Water",
	"Electric Shock", "Black Hole", "Deep Digger", "Break Dash", "Spark Chaser",
		
	"Sakugarne", "Ballade Cracker", "Screw Crusher", "Mirror Buster",
	
	"Dawn Breaker",

	// 2D
	"Met Guard 1", "Melt Creeper", "Aiming Laser", "Delay Flame",
	"Recycle Inhaler", "Forest Whip", "Blast Missile", "Thousand Spear",
	"White Rose Cluster", "Leaf Boomerang", "Triad Thunder", "Sonic Slicer",
	"Scatter Ring", "Yoga Inferno", "Glue Shot", "Super Arrow",
	"Ground Dash",	"Hellfire Cutter", "Time Bomb", "Wing Spiral",
	"Virus Outbreak", "Photon Flare", "Brandishing Blade",
	
	// 3D
	"Met Guard 2", "Thousand Spear V2", "Countershading Tracer", "Ice Gatling",
	"Red Hot Kick",
	
	// 4D
	"Met Guard 3", "Thousand Spear V3", "Thousand Knives",
	
	// 5D
	"Met Guard 3 EX", "Thousand Spear V5"
};


			////////////////////////		////////////////////////	
//////////////////////     //////////////////////     ////////////////////////
			////////////////////////		////////////////////////	
//////////////////////     //////////////////////     ////////////////////////
			////////////////////////		////////////////////////	
//                     Keyword List						//

std::vector<std::string> kwNames = {
    "FIRE", "WATER", "EARTH", "WIND",

    "LIGHT", "BOMB", "ICE", "TIME", "ELEC", "NATURE", "CUTTER",

    "PHYSICAL", "SOLIDIFIER",

    "BOOMERANG", "SHIELD", "CRAWLER", "TARGETER", "BOUNCY", "CHARGEABLE", "MELEE", "SPREAD",
    "MOBILITY", "RAPID-FIRE", "PROTECTOR", "STATUS", "AOE",

    "MEGAMAN_5",

    "RM_QUICK", "RM_DUST", "RM_RING", "RM_FLASH", "RM_YAMATO", "RM_CUT",

    "METGUARD1", "METGUARD2", "METGUARD3", "THOUSANDSPEAR1", "THOUSANDSPEAR2", "THOUSANDSPEAR3"
};

// Elements
#define KW_FIRE 1
#define KW_WATER 2
#define KW_EARTH 3
#define KW_WIND 4

#define KW_LIGHT 5
#define KW_BOMB 6
#define KW_ICE 7
#define KW_TIME 8
#define KW_ELEC 9
#define KW_NATURE 10
#define KW_CUTTER 11

#define KW_PHYSICAL 20
#define KW_SOLIDIFIER 21 // SOLID_LIQUID ? hmmm....

// Behavior
#define KW_BOOMERANG 30
#define KW_SHIELD 31
#define KW_CRAWLER 32
#define KW_TARGETER 33 
#define KW_BOUNCY 34
#define KW_CHARGEABLE 35
#define KW_MELEE 36
#define KW_SPREAD 37
#define KW_MOBILITY 38
#define KW_RAPID_FIRE 39
#define KW_PROTECTOR 40
#define KW_STATUS 41
#define KW_AOE 42

// Game
#define KW_GAME_5 85 

// ======> Singletons <====== //

// Vanilla
#define KW_RM_QUICK 100
#define KW_RM_DUST 101
#define KW_RM_RING 102
#define KW_RM_FLASH 103
#define KW_RM_YAMATO 104
#define KW_RM_CUT 105

//Xover 
#define KW_METGUARD1 150
#define KW_METGUARD2 151
#define KW_METGUARD3 152
#define KW_THOUSANDSPEAR1 153
#define KW_THOUSANDSPEAR2 154
#define KW_THOUSANDSPEAR3 155

#define LARGEST_KW_INDEX 155 // right above

			////////////////////////		////////////////////////	
//////////////////////     //////////////////////     ////////////////////////
			//			 #2.2 Weapon keywords                     //
//////////////////////     //////////////////////     ////////////////////////
			////////////////////////		////////////////////////	
std::vector<std::vector<int>> keywords = {
	// MM1
	{ KW_EARTH, KW_PHYSICAL }, // Guts
	{ KW_BOMB }, // Bomb
	{ KW_ICE, KW_RAPID_FIRE }, // Ice
	{ KW_ELEC, KW_SPREAD},  // Elec
	{ KW_FIRE }, // Fire
	{ KW_CUTTER, KW_BOOMERANG, KW_RM_CUT }, // Cut
	{ KW_TIME, KW_STATUS, KW_AOE }, // Time
	{ KW_MELEE, KW_MOBILITY, KW_PHYSICAL, KW_SOLIDIFIER }, // Oil // -SOLIDIFEIR ?
	
	//MM2
	{ KW_CRAWLER, KW_WATER }, // Bubble
	{ KW_CUTTER, KW_RAPID_FIRE }, // Metal
	{ KW_FIRE, KW_CHARGEABLE }, // Heat
	{ KW_SHIELD, KW_NATURE, KW_PROTECTOR }, // Wood
	{ KW_WIND, KW_SPREAD }, // Air
	{ KW_RM_QUICK, KW_BOOMERANG, KW_CUTTER, KW_RAPID_FIRE }, // Quick
	{ KW_BOMB }, // Crash
	{ KW_RM_FLASH, KW_TIME, KW_STATUS, KW_AOE }, // Flash
	
	//MM3
	{ KW_TARGETER }, // Magnet
	{ KW_MELEE, KW_PHYSICAL }, // Top
	{ KW_NATURE, KW_RAPID_FIRE }, // Needle
	{ KW_CUTTER, KW_BOOMERANG }, // Shadow
	{ KW_LIGHT, KW_BOUNCY }, // Gemini
	{ KW_CRAWLER, KW_NATURE }, // Snake
	{ KW_PHYSICAL }, // Hard
	{ KW_ELEC, KW_STATUS }, // Spark

	//MM4
	{ KW_BOMB, KW_EARTH }, // Drill
	{ KW_BOOMERANG, KW_CUTTER, KW_RM_RING }, // Ring
	{ KW_RM_DUST }, // Dust
	{ KW_FIRE, KW_CHARGEABLE }, /// Pharaoh
	{ KW_SHIELD, KW_PROTECTOR }, // Skull
	{ KW_TARGETER }, // Dive
	{ KW_WATER, KW_AOE }, // Toad
	{ KW_LIGHT, KW_STATUS, KW_AOE }, // Bright

	//MM5
	{ KW_BOMB, KW_GAME_5 }, // Napalm
	{ KW_MELEE, KW_MOBILITY, KW_GAME_5, KW_PHYSICAL }, // Charge
	{ KW_WIND, KW_CUTTER, KW_GAME_5  }, // Gyro
	{ KW_SPREAD, KW_GAME_5, KW_EARTH }, // Stone
	{ KW_CRAWLER, KW_WATER, KW_GAME_5, KW_RAPID_FIRE }, // Wave
	{ KW_BOUNCY, KW_GAME_5, KW_EARTH }, // Crystal
	{ KW_SHIELD, KW_GAME_5 }, // Star
	{ KW_GAME_5, KW_AOE }, // Gravity

	//MM6
	{ KW_ICE, KW_SPREAD }, // Blizzard
	{ KW_FIRE }, // Flame
	{ KW_RM_YAMATO, KW_CUTTER, KW_RAPID_FIRE }, // Yamato
	{ KW_SHIELD, KW_NATURE, KW_PROTECTOR }, // Plant
	{ KW_NATURE, KW_CUTTER }, // Tomahawk
	{ KW_CRAWLER, KW_WIND }, // Wind
	{ KW_BOOMERANG }, // Knight
	{ KW_LIGHT, KW_TIME, KW_AOE }, // Centaur

	//MM7
	{ KW_ICE }, // Freeze
	{ KW_CHARGEABLE, KW_BOUNCY }, // Shade
	{ KW_CHARGEABLE, KW_BOUNCY, KW_SPREAD }, // Spring
	{ KW_BOMB }, // Burst
	{ KW_CRAWLER, KW_FIRE, KW_SHIELD, KW_MOBILITY }, // Turbo
	{ KW_SHIELD, KW_SPREAD, KW_CHARGEABLE }, // Junk // KW_PROTECTOR
	{ KW_MELEE, KW_PHYSICAL }, // Slash // KW_NATURE // KW_CUTTER
	{ KW_ELEC, KW_LIGHT }, // Cloud

	// MM8
	{ KW_EARTH, KW_AOE }, // Astro8
	{ KW_FIRE, KW_MELEE }, // Sword // KW_CUTTER ? XW_TRADITIONNAL
	{ KW_ELEC, KW_MELEE, KW_MOBILITY }, // Clown // KW_PHYSICAL ? minus KW_MOBILITY ?
	{ KW_TARGETER, KW_CHARGEABLE }, // Search
	{ KW_WATER, KW_RAPID_FIRE }, // Aqua
	{ KW_BOUNCY, KW_MOBILITY }, // MegaBall 
	{ KW_LIGHT, KW_BOMB }, // Grenade
	{ KW_CRAWLER, KW_ICE }, // Frost
	{ KW_WIND, KW_MOBILITY }, // Tengu8

	//MMB
	{ KW_WIND, KW_CUTTER, KW_MELEE, KW_BOUNCY, KW_MOBILITY  }, // TenguB // CHARGEABLE // KW_MOBILITY
	{ KW_FIRE, KW_RAPID_FIRE }, // Burner
	{ KW_SPREAD, KW_EARTH }, // Ground
	{ KW_BOOMERANG }, // Magic
	{ KW_TARGETER, KW_BOMB }, // Pirate
	{ KW_TARGETER, KW_LIGHT }, // AstroB
	{ KW_SHIELD, KW_CRAWLER, KW_ICE, KW_BOUNCY }, // Cold // KW_PROTECTOR
	{ KW_LIGHT, KW_ELEC, KW_AOE }, // Dynamo

	// MM9
	{ KW_CRAWLER, KW_ELEC, KW_BOUNCY, KW_RAPID_FIRE }, // Plug
	{ KW_LIGHT }, // Splash
	{ KW_TARGETER, KW_AOE }, // Galaxy :: BOMB
	{ KW_SHIELD, KW_EARTH }, // Jewel
	{ KW_SOLIDIFIER, KW_EARTH, KW_STATUS }, // Concrete
	{ KW_WIND, KW_MOBILITY, KW_AOE }, // Tornado
	{ KW_TARGETER, KW_NATURE }, // Hornet
	{ KW_FIRE, KW_CHARGEABLE, KW_SPREAD }, // Magma

	//MM10
	{ KW_FIRE }, // Solar
	{ KW_CUTTER, KW_MOBILITY, KW_CRAWLER }, // Nitro
	{ KW_BOUNCY }, // Strike
	{ KW_ELEC }, // Sheep
	{ KW_BOMB, KW_TARGETER }, // Commando
	{ KW_ICE, KW_SOLIDIFIER, KW_STATUS }, // Chill
	{ KW_SHIELD, KW_WATER, KW_PROTECTOR }, // Pump
	{ KW_CUTTER, KW_SPREAD, KW_RAPID_FIRE }, // Blade
	
	//MMV
	{ KW_PROTECTOR }, // Mercury
	{ KW_WATER, KW_BOMB }, // Venus
	{ KW_BOMB }, // Mars
	{ KW_WATER }, // Neptune // KW_SPREAD
	{ KW_ELEC, KW_MELEE }, // Jupiter
	{ KW_SHIELD, KW_PROTECTOR }, // Saturn
	{ KW_EARTH, KW_PHYSICAL }, // Uranus
	{ KW_CHARGEABLE, KW_MELEE, KW_MOBILITY, KW_PHYSICAL }, // Pluto
	{ KW_LIGHT, KW_TARGETER }, // Terra

	//MMK
	{ KW_MELEE, KW_MOBILITY, KW_TIME }, // Quint // KW8physical ?
	{ KW_BOMB }, // Ballade
	{ KW_CUTTER, KW_RAPID_FIRE }, // Punk // +BOUNCY?
	{ KW_SHIELD, KW_PROTECTOR }, // Enker :: CHARGEABLE
	
	{ KW_LIGHT, KW_CHARGEABLE, KW_CRAWLER, KW_SPREAD }, // Ra Thor
	
	// 2D
	// To add : 
	// SHIELD, MELEE, BOUNCY, TARGETER, RAPID_FIRE, ICE, FIRE, PHYSICAL
	// CUTTER
	{ KW_METGUARD1, KW_SHIELD }, // Met Guard 1
	{ KW_FIRE }, // Melt Creeper
	{ KW_TARGETER }, // Aiming Laser
	{ KW_RAPID_FIRE, KW_FIRE }, // Delay Flame
	{ KW_MELEE, KW_PHYSICAL }, // Recycle Inhaler
	{ KW_MELEE }, // Forest Whip
	{ KW_TARGETER }, // Blast Missile
	{ KW_THOUSANDSPEAR1, KW_MELEE, KW_CUTTER }, // Thousand Spear
	{ KW_MELEE, KW_ICE }, // White Rose Cluster
	{  }, // Leaf Boomerang
	{ KW_SHIELD }, // Triad Thunder
	{ KW_CUTTER, KW_BOUNCY }, // Sonic Slicer
	{  }, // Scatter Ring
	{ KW_RAPID_FIRE, KW_FIRE }, // Yoga Inferno
	{  }, // Glue Shot
	{ KW_TARGETER }, // Super Arrow
	{ KW_PHYSICAL }, // Ground Dash 
	{ KW_CUTTER, KW_FIRE }, // Hellfire Cutter
	{ KW_TARGETER }, // Time Bomb
	{ KW_BOUNCY }, // Wing Spiral
	{ KW_SHIELD }, // Virus Outbreak
	{  }, // Photon Flare
	{ KW_MELEE, KW_CUTTER, KW_RAPID_FIRE }, // Brandishing Blade
	
	// 3D
	// To add : SHIELD, MELEE, CUTTER
	{ KW_METGUARD2, KW_SHIELD }, // Met Guard 2
	{ KW_THOUSANDSPEAR2, KW_MELEE, KW_CUTTER }, // Thousand Spear V2
	{  }, // Countershading Tracer
	{  }, // Ice Gatling
	{ KW_MELEE }, // Red Hot Kick
	
	// 4D
	// To add : SHIELD, MELEE
	{ KW_METGUARD3, KW_SHIELD }, // Met Guard 3
	{ KW_THOUSANDSPEAR3, KW_MELEE }, // Thousand Spear V3
	{  }, // Thousand Knives
	
	// 5D
	// MetGuard 3 EX
    // Thousand Spear V5

};


			////////////////////////		////////////////////////	
//////////////////////     //////////////////////     ////////////////////////
			////////////////////////		////////////////////////	
//////////////////////     //////////////////////     ////////////////////////
			////////////////////////		////////////////////////	
					// #2.4 The recipes

int recipes[MAX_2345D][2] = 
{
	// 2D
	{ KW_CRAWLER, KW_SHIELD },	// Met Guard 1
	{ KW_CRAWLER, KW_FIRE },	// Melt Creeper
	{ KW_TARGETER, KW_LIGHT },	// Aiming Laser
	{ KW_RM_QUICK, KW_FIRE },	// Delay Flame
	{ KW_RM_DUST, KW_WIND },	// Recycle Inhaler
	{ KW_NATURE, KW_MELEE },	// Forest Whip
	{ KW_TARGETER, KW_BOMB },	// Blast Missile
	{ KW_RM_YAMATO, KW_MELEE },	// Thousand Spear
	{ KW_ICE, KW_CHARGEABLE },	// White Rose Cluster
	{ KW_BOOMERANG, KW_NATURE },	// Leaf Boomerang
	{ KW_SPREAD, KW_ELEC },	// Triad Thunder
	{ KW_BOUNCY, KW_CUTTER },	// Sonic Slicer
	{ KW_RM_RING, KW_SPREAD },	// Scatter Ring
	{ KW_FIRE, KW_MOBILITY },	// Yoga Inferno
	{ KW_WATER, KW_SOLIDIFIER },	// Glue Shot
	{ KW_GAME_5, KW_GAME_5 },	// Super Arrow
	{ KW_EARTH, KW_PHYSICAL },	// Ground Dash
	{ KW_RM_CUT, KW_FIRE },	// Hellfire Cutter
	{ KW_TIME, KW_BOMB },	// Time Bomb
	{ KW_WIND, KW_MOBILITY },	// Wing Spiral
	{ KW_PROTECTOR, KW_STATUS },	// Virus Outbreak
	{ KW_LIGHT, KW_AOE },	// Photon Flare
	{ KW_CUTTER, KW_CHARGEABLE },	// Brandishing Blade
	
	// 3D
	{ KW_METGUARD1, KW_SHIELD },	// Met Guard 2
	{ KW_THOUSANDSPEAR1, KW_MELEE },	// Thousand Spear V2
	{ KW_TARGETER, KW_BOUNCY },	// Countershading Tracer
	{ KW_ICE, KW_RAPID_FIRE },	// Ice Gatling
	{ KW_FIRE, KW_PHYSICAL },	// Red Hot Kick
	
	// 4D
	{ KW_METGUARD2, KW_SHIELD },	// Met Guard 3
	{ KW_THOUSANDSPEAR2, KW_MELEE },	// Thousand Spear V3
	{ KW_RM_FLASH, KW_CUTTER },	// Thousand Knives
	
	// 5D
	{ KW_METGUARD3, KW_SHIELD },	// Met Guard 3 EX
	{ KW_THOUSANDSPEAR3, KW_MELEE },	// Thousand Spear V5
};

int recipesCount[MAX_2345D] = { 0 };


int kwCount[LARGEST_KW_INDEX+1][TABLE_CAPACITY];
std::vector<std::vector<int>> fusionDB(
        TOTAL_INGREDIENTS, 
        std::vector<int>(TOTAL_INGREDIENTS, -1));

void countTierKeywords(int start, int end, int tier) {
    for (int i = start; i < end; i++) {
        for (int j = 0; j < keywords[i].size(); j++) {
            kwCount[keywords[i][j]][tier]++;
        }    
    }
    if (tier > 0) {
        for (int i = 0; i < LARGEST_KW_INDEX+1; i++) {
            kwCount[i][tier] += kwCount[i][tier-1];
        }        
    }
}

void countKeywords() {
    countTierKeywords(0,END_1D,0);

        ///////////////////////////////////////////////////////////////////////////////
    // /!\ ra thor exception : Dawn Breaker doesn't count in the weapon priority computation /!\ 
        ///////////////////////////////////////////////////////////////////////////////
    for (int kwThor = 0; kwThor < keywords[END_1D-1].size(); kwThor++)
        kwCount[keywords[END_1D-1][kwThor]][0]--;

    countTierKeywords(END_1D,END_2D,1);
    countTierKeywords(END_2D,END_3D,2);
    countTierKeywords(END_3D,END_4D,3);

    int nameIndex = 0; int activeKeyword;
    for (int i = 0; i < LARGEST_KW_INDEX+1; i++) {
        activeKeyword = 0;
        for (int tierCount = 0; tierCount < TABLE_CAPACITY-1; tierCount++)
            activeKeyword += kwCount[i][tierCount];
        
        if (activeKeyword > 0) {
            std::cout << "\n" << kwNames[nameIndex] << " (" << i << ")";
            for (int tierCount = 0; tierCount < TABLE_CAPACITY-1; tierCount++)
                std::cout << " " << kwCount[i][tierCount];
            nameIndex++;
        }
    }
    std::cout << "\n";
}

int weaponTier(int wep) {
    if (wep >= 0 && wep < END_1D) { return 1; }
    else if (wep >= END_1D && wep < END_2D) { return 2; }
    else if (wep >= END_2D && wep < END_3D) { return 3; }
    else if (wep >= END_3D && wep < END_4D) { return 4; }
    else { return 5; } // (wep >= END_4D && wep < END_5D)
}

int priorityRace(int recipe1, int recipe2, int tier) {
    if (std::min(recipe1, recipe2) == -1) { 
            return std::max(recipe1, recipe2); }
    std::cout << "\n\n   >>> " << tier+2 << "D " << names[recipe1+END_1D] << " vs " << names[recipe2+END_1D];
    if (recipe1 == recipe2) { std::cout << "\n\t>>> SAME RECIPE..."; 
        return recipe1; }

    int recipe1kw1 = kwCount[recipes[recipe1][0]][tier];
    int recipe1kw2 = kwCount[recipes[recipe1][1]][tier];
    int recipe1primary = std::min(recipe1kw1, recipe1kw2);
    
    int recipe2kw1 = kwCount[recipes[recipe2][0]][tier];
    int recipe2kw2 = kwCount[recipes[recipe2][1]][tier];
    int recipe2primary = std::min(recipe2kw1, recipe2kw2);
    std::cout << "\n\t>>> Primary : " << recipe1primary << " vs " << recipe2primary;

    if (recipe1primary > recipe2primary) { return recipe2; }
    else if (recipe1primary < recipe2primary) { return recipe1; }
    
    int recipe1secondary = std::max(recipe1kw1, recipe1kw2);
    int recipe2secondary = std::max(recipe2kw1, recipe2kw2);
    std::cout << "\n\t\t>>> Secondary : " << recipe1secondary << " vs " << recipe2secondary;
    if (recipe1secondary > recipe2secondary) { return recipe2; }
    else if (recipe1secondary < recipe2secondary) { return recipe1; }
    else { std::cout << "\n\t\t>>> They have exact same priority, WTF. Giving victory to recipe1."; }
    return recipe1;
}

int fusionCount[TABLE_CAPACITY-1] = { 0 };

int search(int wep1, int wep2) {
    int bestRecipe = -1;
    int goingForATier =  weaponTier(wep2)+1;//std::max(weaponTier(wep1), weaponTier(wep2))+1;
    int startRecipe, endRecipe; bool count = false;
    switch(goingForATier) {
        case 2: startRecipe = 0; endRecipe = MAX_2D; break;
        case 3: startRecipe = MAX_2D; endRecipe = MAX_23D; break;
        case 4: startRecipe = MAX_23D; endRecipe = MAX_234D; break;
        case 5: startRecipe = MAX_234D; endRecipe = MAX_2345D; break;
    }
    //std::cout << "\n" << names[wep1] << " and " << names[wep2] << " going for " << goingForATier;
    for (int i = 0; i < keywords[wep1].size(); i++) {
        for (int j = 0; j < keywords[wep2].size(); j++) {
            for (int recipe = startRecipe; recipe < endRecipe; recipe++) {
                if ((keywords[wep1][i] == recipes[recipe][0] && keywords[wep2][j] == recipes[recipe][1]) ||
                    (keywords[wep1][i] == recipes[recipe][1] && keywords[wep2][j] == recipes[recipe][0])) {
                        bestRecipe = priorityRace(bestRecipe, recipe, goingForATier-2);
						if (!count) {
							count = true;
							fusionCount[goingForATier-2]++;
						}
                    }
            }
        }
    }
    return (bestRecipe == -1 ? -1 : bestRecipe+END_1D);

}

void computeDatabase() {
    for (int i = 0; i < TOTAL_INGREDIENTS; i++) {
        for (int j = i+1; j < TOTAL_INGREDIENTS; j++) {
            fusionDB[i][j] = search(i,j);
            if (fusionDB[i][j] != -1) {
                std::cout << "\n" << i << "." << names[i] << " + " << 
									j << "." << names[j] << " = " <<
									fusionDB[i][j] << "." << names[fusionDB[i][j]];
				recipesCount[fusionDB[i][j]-MAX_1D]++;
            }
        }
    }
}

int main(int argc, char *argv[]) {
	bool debug;
	std::cout << "\nPrint stuff ? 1 yes 0 no\n";
	std::cin >> debug;
	if (!debug) { std::cout.setstate(std::ios_base::failbit); }
    countKeywords();
    computeDatabase();

    std::ofstream dbFile;
    dbFile.open("xwdb");

	dbFile << 
	
		"// ######### GENERATED #########\n" <<
		"#LIBDEFINE MAX_1D " << MAX_1D << "\n" <<
		"#DEFINE MAX_2D " << MAX_2D << "\n" <<
		"#DEFINE MAX_23D " << MAX_23D << "\n" <<
		"#DEFINE MAX_234D " << MAX_234D << "\n" <<
		"#DEFINE MAX_2345D " << MAX_2345D << "\n" <<
		"#LIBDEFINE TOTAL_WEPS " << TOTAL_WEPS << "\n" <<
		"#LIBDEFINE TOTAL_INGREDIENTS " << TOTAL_INGREDIENTS << "\n" <<
	 	"#DEFINE TOTAL_COMBINATIONS " << ((TOTAL_INGREDIENTS)*(TOTAL_INGREDIENTS-1))/2 << "\n" << 
		"// ######### GENERATED--end #########" << "\n";

    dbFile << "\nint xwdb[TOTAL_COMBINATIONS] =\n{\n\t"; 
    for (int i = 0; i < TOTAL_INGREDIENTS; i++) {
        for (int j = i+1; j < TOTAL_INGREDIENTS; j++) {
            dbFile << fusionDB[i][j] << 
                (j == TOTAL_INGREDIENTS-1 ? 
                    (i == TOTAL_INGREDIENTS-2 ? "\n};" : ",\n\t") :
                    ", ");
        }
    }
    dbFile.close();

	if (!debug) { std::cout.clear(); }
	std::cout << "\n------------------\nDatabase was generated.\n------------------\nStatistics :\n>>> Recipe combination count :\n";
	for (int i = 0; i < MAX_2345D; i++) {
		std::cout << "\n" << names[i+MAX_1D] << " " << recipesCount[i];
	}
	std::cout << "\n\n>>> Total fusion count (among valid combinations, i.e ND fusions only consider combinations using a N-1D weapon):\n";
	for (int i = 0; i < TABLE_CAPACITY-1; i++) {
		int totalCombinations;
		switch(i) {
			case 0: totalCombinations = ((END_1D)*(END_1D-1))/2; break;
						
			case 1: totalCombinations = ((END_2D)*(END_2D-1))/2 - ((END_2D-MAX_2D)*(END_2D-MAX_2D-1))/2; break;
			case 2: totalCombinations = ((END_3D)*(END_3D-1))/2 - ((END_3D-MAX_3D)*(END_3D-MAX_3D-1))/2; break;
			case 3: totalCombinations = ((END_4D)*(END_4D-1))/2 - ((END_4D-MAX_4D)*(END_4D-MAX_4D-1))/2; break;
		}
		std::cout << "\n" << i+2 << "D fusions : " << fusionCount[i] << " / " << totalCombinations <<
			" (" << ((double) fusionCount[i] /(double) totalCombinations*100.0) << " %)";
	}
	std::cout << "\n\nRemember Dawn Breaker is taken into account in the combination counters despite not being obtainable " <<
		"in normal gameplay.\nAlso, higher tier can't dynamically calculate combinations by considering weapons already combined " <<
		"accurately,\nso these numbers are not exact, but should remain representative overall.\n\n";

	system("pause");
    return 0;
}