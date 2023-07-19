#include <iostream>
#include <random>
#include <fstream>

// MM1 (8) + MM2 (16) + MM3 (24) + MM4 (32) + MM5 (40) + MM6 (48) + MM7 (56) + 
// MM8 (64) + MegaBall (65) + MM&B (73) + MM9 (81) + MM10 (89) + MMV & Terra (98) +
// Punk/Ballade/Enker/Quint (102) + RaThor (103)
#define MAX_1D 103

// This indicates the index at which the ND tier terminates 
#define MAX_2D 26
#define MAX_3D 7
#define MAX_4D 4
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
	"Virus Outbreak", "Photon Flare", "Brandishing Blade",	"Doppler Attack",
	"Splash Laser", "Ice Javelin",
	
	// 3D
	"Met Guard 2", "Thousand Spear V2", "Countershading Tracer", "Ice Gatling",
	"Red Hot Kick",	"Boomerang Cutter",	"Jawz Hunters",
	
	// 4D
	"Met Guard 3", "Thousand Spear V3", "Thousand Knives",	"Falling Steel Sword",
	
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

    "LIGHT", "BOMB", "ICE", "TIME", "ELEC", "NATURE", "CUTTER",	"SPACE",

    "PHYSICAL", "SOUL", "TRADITIONAL", "SCRAP", "ANIMAL", "MISSILE", "BUBBLE", "ENTERTAINMENT", "SPIKY",

    "BOOMERANG", "SHIELD", "CRAWLER", "TARGETER", "BOUNCY", "CHARGEABLE", "MELEE", "SPREAD",
    "MOBILITY", "RAPID-FIRE", "SURVIVAL", "STATUS", "AOE",	"SPLIT", "TRAP", "SUPERPOWERFUL", "SPIN",

    "MEGAMAN_5", "MEGAMAN_BASS",

    "RM_QUICK", "RM_DUST", "RM_RING", "RM_FLASH", "RM_YAMATO", "RM_CUT",

    "METGUARD1", "METGUARD2", "METGUARD3", "THOUSANDSPEAR1", "THOUSANDSPEAR2", "THOUSANDSPEAR3"
};

// Public elements
ice
elec
fire
time
water
earth
wind
nature
light
physical
bomb
missile
scrap
saws (cutter)
ancient
space
dark
toy

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
#define KW_SPACE 12
// DARK

#define KW_PHYSICAL 20
#define KW_SOUL 21
#define KW_TRADITIONAL 22
#define KW_SCRAP 23
#define KW_ANIMAL 24
#define KW_MISSILE 25
#define KW_BUBBLE 26
#define KW_SPIKY 28

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
#define KW_SURVIVAL 40
#define KW_STATUS 41
#define KW_AOE 42
#define KW_SPLIT 43
#define KW_TRAP 44 // au sens "terrain miné"
#define KW_SUPERPOWERFUL 45
#define KW_SPIN 46
//#define KW_UPWARD 47 // do we even care

// Game
#define KW_GAME_5 85
#define KW_GAME_BASS 86

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
	{ KW_SPLIT }, // Guts
	{ KW_SUPERPOWERFUL }, // Bomb
	{ KW_RAPID_FIRE }, // Ice
	{ KW_SPREAD },  // Elec
	{ KW_SPIN }, // Fire
	{ KW_BOOMERANG, KW_RM_CUT }, // Cut
	{ KW_TIME, KW_STATUS, KW_AOE }, // Time
	{ KW_MELEE, KW_MOBILITY }, // Oil
	
	//MM2
	{ KW_CRAWLER, KW_BUBBLE }, // Bubble
	{ KW_RAPID_FIRE, KW_SCRAP }, // Metal
	{ KW_CHARGEABLE, KW_SUPERPOWERFUL }, // Heat
	{ KW_SHIELD, KW_SURVIVAL }, // Wood
	{ KW_WIND, KW_SPREAD }, // Air
	{ KW_RM_QUICK, KW_BOOMERANG, KW_CUTTER, KW_RAPID_FIRE }, // Quick // amusement?
	{ KW_TRAP }, // Crash
	{ KW_RM_FLASH, KW_STATUS, KW_AOE }, // Flash
	
	//MM3
	{ KW_TARGETER, KW_SCRAP }, // Magnet
	{ KW_MELEE, KW_SUPERPOWERFUL, KW_SPIN }, // Top
	{ KW_RAPID_FIRE, KW_SPIKY }, // Needle
	{ KW_BOOMERANG, KW_TRADITIONAL }, // Shadow
	{ KW_BOUNCY, KW_SOUL }, // Gemini
	{ KW_CRAWLER, KW_ANIMAL }, // Snake
	{ }, // Hard
	{ KW_STATUS }, // Spark

	//MM4
	{ }, // Drill
	{ KW_RM_RING, KW_BOOMERANG }, // Ring
	{ KW_RM_DUST, KW_SCRAP, KW_SPLIT }, // Dust
	{ KW_FIRE, KW_CHARGEABLE }, // Pharaoh
	{ KW_SHIELD, KW_SURVIVAL, KW_SOUL }, // Skull
	{ KW_TARGETER, KW_MISSILE }, // Dive
	{ KW_WATER, KW_AOE }, // Toad
	{ KW_LIGHT, KW_STATUS, KW_AOE }, // Bright

	//MM5
	{ KW_GAME_5 }, // Napalm
	{ KW_MELEE, KW_GAME_5, KW_PHYSICAL }, // Charge
	{ KW_WIND, KW_GAME_5, KW_SCRAP, KW_SPLIT  }, // Gyro
	{ KW_SPREAD, KW_GAME_5, KW_SPIN }, // Stone
	{ KW_CRAWLER, KW_WATER, KW_GAME_5, KW_RAPID_FIRE }, // Wave
	{ KW_BOUNCY, KW_GAME_5, KW_SPLIT }, // Crystal
	{ KW_SHIELD, KW_GAME_5 }, // Star
	{ KW_GAME_5, KW_AOE }, // Gravity trespuissant

	//MM6
	{ KW_ICE, KW_SPREAD }, // Blizzard
	{ KW_FIRE, KW_TRAP }, // Flame
	{ KW_RM_YAMATO, KW_RAPID_FIRE }, // Yamato
	{ KW_SHIELD, KW_NATURE, KW_SURVIVAL }, // Plant
	{ KW_NATURE }, // Tomahawk
	{ KW_CRAWLER, KW_WIND }, // Wind
	{ KW_BOOMERANG, KW_SPIKY }, // Knight
	{ KW_TIME, KW_AOE, KW_SOUL }, // Centaur

	// MM7
	{ KW_ICE, KW_SPLIT }, // Freeze
	{ KW_CHARGEABLE, KW_BOUNCY }, // Shade
	{ KW_CHARGEABLE, KW_BOUNCY, KW_SPREAD }, // Spring
	{ KW_TRAP, KW_BUBBLE }, // Burst
	{ KW_FIRE, KW_SHIELD, KW_MOBILITY, KW_CRAWLER }, // Turbo
	{ KW_SHIELD, KW_SPREAD, KW_CHARGEABLE }, // Junk
	{ KW_MELEE, KW_PHYSICAL }, // Slash
	{ KW_ELEC, KW_LIGHT, KW_SPLIT }, // Cloud

	// MM8
	{ KW_AOE }, // Astro8
	{ KW_FIRE, KW_MELEE }, // Sword
	{ KW_ELEC, KW_MELEE }, // Clown
	{ KW_TARGETER, KW_CHARGEABLE, KW_MISSILE, KW_SPREAD }, // Search
	{ KW_WATER, KW_RAPID_FIRE }, // Aqua
	{ KW_BOUNCY, KW_MOBILITY }, // MegaBall 
	{ KW_LIGHT, KW_TRAP }, // Grenade
	{ KW_CRAWLER, KW_ICE }, // Frost
	{ KW_WIND, KW_TRAP }, // Tengu8

	//MMB
	{ KW_GAME_BASS, KW_MELEE, KW_BOUNCY }, // TenguB
	{ KW_FIRE, KW_RAPID_FIRE, KW_GAME_BASS }, // Burner
	{ KW_EARTH, KW_GAME_BASS, KW_SPLIT }, // Ground
	{ KW_BOOMERANG, KW_SOUL, KW_GAME_BASS }, // Magic
	{ KW_TARGETER, KW_BOMB, KW_GAME_BASS, KW_TRAP }, // Pirate
	{ KW_TARGETER, KW_LIGHT, KW_SOUL, KW_GAME_BASS }, // AstroB
	{ KW_ICE, KW_GAME_BASS, KW_SHIELD, KW_BOUNCY }, // Cold
	{ KW_LIGHT, KW_ELEC, KW_AOE, KW_GAME_BASS }, // Dynamo

	// MM9
	{ KW_CRAWLER, KW_ELEC, KW_BOUNCY, KW_RAPID_FIRE }, // Plug
	{ KW_LIGHT }, // Splash
	{ KW_TARGETER, KW_AOE }, // Galaxy
	{ KW_SHIELD }, // Jewel
	{ KW_STATUS }, // Concrete
	{ KW_WIND, KW_MOBILITY, KW_AOE }, // Tornado
	{ KW_TARGETER, KW_NATURE, KW_ANIMAL, KW_SPIKY }, // Hornet
	{ KW_FIRE, KW_CHARGEABLE, KW_SPREAD }, // Magma

	//MM10
	{ KW_FIRE, KW_SPLIT }, // Solar // piege?see v6b
	{ KW_MOBILITY, KW_SCRAP }, // Nitro
	{ KW_BOUNCY }, // Strike
	{ KW_TRAP }, // Sheep
	{ KW_TARGETER }, // Commando
	{ KW_ICE, KW_STATUS, KW_TRAP, KW_SPIKY }, // Chill
	{ KW_SHIELD, KW_WATER, KW_SPIN, KW_BUBBLE, KW_SURVIVAL, KW_SPREAD }, // Pump
	{ KW_RAPID_FIRE, KW_SPREAD  }, // Blade
	
	//MMV
	{ KW_SURVIVAL, KW_SOUL, KW_SPACE }, // Mercury
	{ KW_BUBBLE }, // Venus
	{ KW_MISSILE }, // Mars
	{ KW_WATER, KW_SPLIT }, // Neptune
	{ KW_ELEC, KW_MELEE }, // Jupiter // rapedetir
	{ KW_SHIELD, KW_SPLIT, KW_SPACE, KW_SPIN }, // Saturn
	{ KW_PHYSICAL, KW_SPLIT }, // Uranus
	{ KW_CHARGEABLE, KW_MELEE, KW_MOBILITY, KW_PHYSICAL }, // Pluto
	{ KW_LIGHT, KW_TARGETER, KW_SOUL }, // Terra	//lespace

	//MMK
	{ KW_MELEE, KW_MOBILITY, KW_TIME, KW_SUPERPOWERFUL }, // Quint
	{ }, // Ballade
	{ KW_RAPID_FIRE, KW_SCRAP }, // Punk
	{ KW_SHIELD, KW_SURVIVAL }, // Enker
	
	{ KW_LIGHT, KW_CHARGEABLE, KW_CRAWLER, KW_SPREAD, KW_SUPERPOWERFUL }, // Ra Thor
	
	// 2D
	// To add : 
	// SHIELD, MELEE, BOUNCY, TARGETER, RAPID_FIRE, ICE, FIRE, PHYSICAL, SCRAP, TRADITIONNAL
	// CUTTER, BOOMERANG, ANIMAL
	{ KW_METGUARD1, KW_SHIELD }, // Met Guard 1
	O { KW_FIRE }, // Melt Creeper
	O { KW_TARGETER }, // Aiming Laser
	X { KW_RAPID_FIRE, KW_FIRE }, // Delay Flame
	X { KW_MELEE, KW_PHYSICAL, KW_SCRAP }, // Recycle Inhaler
	{ KW_MELEE, KW_TRADITIONAL }, // Forest Whip
	O { KW_TARGETER }, // Blast Missile
	X { KW_THOUSANDSPEAR1, KW_MELEE, KW_CUTTER, KW_TRADITIONAL }, // Thousand Spear
	{ KW_MELEE, KW_ICE }, // White Rose Cluster
	{ KW_BOOMERANG }, // Leaf Boomerang
	O { KW_SHIELD }, // Triad Thunder // SCRAP ?
	O { KW_CUTTER, KW_BOUNCY }, // Sonic Slicer
	{ }, // Scatter Ring
	{ KW_RAPID_FIRE, KW_FIRE }, // Yoga Inferno
	{  }, // Glue Shot
	{ KW_TARGETER }, // Super Arrow
	O { KW_PHYSICAL, KW_SCRAP }, // Ground Dash 
	{ KW_CUTTER, KW_FIRE, KW_BOOMERANG }, // Hellfire Cutter
	{ KW_TARGETER }, // Time Bomb
	O { KW_BOUNCY }, // Wing Spiral
	{ KW_SHIELD, KW_ANIMAL }, // Virus Outbreak
	{  }, // Photon Flare
	{ KW_MELEE, KW_CUTTER, KW_RAPID_FIRE, KW_TRADITIONAL }, // Brandishing Blade
	{ KW_MELEE, KW_PHYSICAL }, // Doppler Attack // -KW_Physical ?
	O { KW_RAPID_FIRE }, // Splash Laser
	{ KW_ICE, KW_TRADITIONAL }, // Ice Javelin

	// 3D
	// To add : SHIELD, MELEE, CUTTER, SCRAP, TRADITIONNAL
	{ KW_METGUARD2, KW_SHIELD }, // Met Guard 2
	{ KW_THOUSANDSPEAR2, KW_MELEE, KW_CUTTER, KW_TRADITIONAL }, // Thousand Spear V2
	{  }, // Countershading Tracer
	{  }, // Ice Gatling
	{ KW_MELEE }, // Red Hot Kick
	O { KW_CUTTER, KW_TRADITIONAL }, // Boomerang Cutter
	{ }, // Jawz Hunters +KW_SHIELD ? +KW_SCRAP ?
	
	// 4D
	// To add : SHIELD, MELEE
	{ KW_METGUARD3, KW_SHIELD }, // Met Guard 3
	{ KW_THOUSANDSPEAR3, KW_MELEE }, // Thousand Spear V3
	{  }, // Thousand Knives,
	{ KW_MELEE }, // Falling Steel Sword
	
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
	{ KW_MISSILE, KW_BOMB },	// Blast Missile
	{ KW_RM_YAMATO, KW_MELEE },	// Thousand Spear
	{ KW_ICE, KW_CHARGEABLE },	// White Rose Cluster
	{ KW_BOOMERANG, KW_NATURE },	// Leaf Boomerang
	{ KW_SPREAD, KW_ELEC },	// Triad Thunder
	{ KW_BOUNCY, KW_CUTTER },	// Sonic Slicer
	{ KW_RM_RING, KW_SPREAD },	// Scatter Ring
	{ KW_FIRE, KW_MOBILITY },	// Yoga Inferno
	{ KW_WATER, KW_STATUS },	// Glue Shot
	{ KW_GAME_5, KW_GAME_5 },	// Super Arrow
	{ KW_EARTH, KW_PHYSICAL },	// Ground Dash
	{ KW_RM_CUT, KW_FIRE },	// Hellfire Cutter
	{ KW_TIME, KW_BOMB },	// Time Bomb
	{ KW_WIND, KW_MOBILITY },	// Wing Spiral
	{ KW_SURVIVAL, KW_STATUS },	// Virus Outbreak
	{ KW_LIGHT, KW_AOE },	// Photon Flare
	{ KW_TRADITIONAL, KW_CHARGEABLE },	// Brandishing Blade
	{ KW_SOUL, KW_GAME_BASS },	// Doppler Attack
	{ KW_RAPID_FIRE, KW_WATER },	// Splash Laser
	{ KW_ICE, KW_TRADITIONAL }, // Ice Javelin
	
	// 3D
	{ KW_METGUARD1, KW_SHIELD },	// Met Guard 2
	{ KW_THOUSANDSPEAR1, KW_MELEE },	// Thousand Spear V2
	{ KW_TARGETER, KW_BOUNCY },	// Countershading Tracer
	{ KW_ICE, KW_RAPID_FIRE },	// Ice Gatling
	{ KW_FIRE, KW_PHYSICAL },	// Red Hot Kick
	{ KW_BOOMERANG, KW_CUTTER },	// Boomerang Cutter
	{ KW_ANIMAL, KW_TARGETER },	// Jawz Hunters
	
	// 4D
	{ KW_METGUARD2, KW_SHIELD },	// Met Guard 3
	{ KW_THOUSANDSPEAR2, KW_MELEE },	// Thousand Spear V3
	{ KW_RM_FLASH, KW_CUTTER },	// Thousand Knives
	{ KW_TRADITIONAL, KW_SCRAP },	// Falling Steel Sword
	
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
    int goingForATier =  weaponTier(wep2)+1;
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
	std::cout << "\nEnter a key to go on.\n";
	system("pause");
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


/*

graph {
    fire -- mele [label=fire]
    fire -- over [label=heat]
    fire -- trap [label=flame]
    fire -- util [label=turbo]
    fire -- fast [label=burner]
    fire -- sprd [label=magma]

    elec -- sprd [label=elec]
    elec -- stat [label=spark]
    elec -- splt [label=cloud]
    elec -- sprd [label=dynamo]
    elec -- bnce [label=plug]
    elec -- trap [label=sheep]
    elec -- fast [label=jupiter]
    elec -- mele [label=clown]
    
    watr -- crwl [label=bubble]
    watr -- trap [label=toad]
    watr -- crwl [label=wave]
    watr -- fast [label=aqua]
    watr -- defs [label=pump]
    watr -- trgt [label=venus]
    watr -- splt [label=neptune]
    
    wind -- sprd [label=air]
    wind -- splt [label=gyro]
    wind -- crwl [label=wind]
    wind -- util [label=tengu8]
    wind -- util [label=tornado]

    lght -- chrg [label=pharaoh]
    lght -- stat [label=bright]
    lght -- splt [label=solar]
    lght -- trap [label=grenade]
    lght -- trgt [label=astroB]
    lght -- chrg [label=enker]

    cutr -- bmrg [label=cut]
    cutr -- bmrg [label=quick]
    cutr -- fast [label=metal]
    cutr -- bmrg [label=ring]
    cutr -- mele [label=tenguB]
    cutr -- util [label=nitro]
    cutr -- fast [label=punk]
    
    ice -- fast [label=ice]
    ice -- sprd [label=blizzard]
    ice -- splt [label=freeze]
    ice -- bnce [label=cold]
    ice -- stat [label=chill]
    ice -- crwl [label=frost]
    
    natr -- defs [label=wood]
    natr -- fast [label=needle]
    natr -- defs [label=plant]
    natr -- trgt [label=hornet]
    natr -- crwl [label=snake]
    
    phys -- over [label=top]
    phys -- over [label=hard]
    phys -- mele [label=charge]
    phys -- mele [label=slash]
    phys -- bnce [label=megaball]
    phys -- mele [label=pluto]
    
    trad -- bmrg [label=shadow]
    trad -- fast [label=yamato]
    trad -- bmrg [label=knight]
    trad -- swft [label=tomahawk]
    trad -- mele [label=sword]
    trad -- swft [label=splash]
    trad -- sprd [label=blade]
    
    eart -- util [label=oil]
    eart -- splt [label=guts]
    eart -- sprd [label=stone]
    eart -- stat [label=concrete]
    eart -- swft [label=uranus]
    eart -- bnce [label=crystal]
    eart -- defs [label=jewel]
    eart -- over [label=astro8]
    
    arti -- over [label=bomb]
    arti -- trap [label=crash]
    arti -- trgt [label=dive]
    arti -- trap [label=napalm]
    arti -- trap [label=burst]
    arti -- chrg [label=search]
    arti -- trgt [label=pirate]
    arti -- trgt [label=commando]
    arti -- swft [label=ballade]
    arti -- swft [label=mars]
    
    junk -- swft [label=magnet]
    junk -- trgt [label=drill]
    junk -- splt [label=dust]
    junk -- bnce [label=spring]
    junk -- chrg [label=junk]
    junk -- splt [label=ground]
    junk -- bnce [label=strike]
    junk -- util [label=sakugarne]
    
    soul -- bnce [label=gemini]
    soul -- defs [label=skull]
    soul -- chrg [label=shade]
    soul -- bmrg [label=magic]
    soul -- defs [label=mercury]
    soul -- trgt [label=terra]
    
    sptm -- stat [label=time]
    sptm -- stat [label=flash]
    sptm -- over [label=gravity]
    sptm -- mele [label=star]
    sptm -- defs [label=centaur]
    sptm -- trap [label=galaxy]
    sptm -- defs [label=saturn]

}



*/