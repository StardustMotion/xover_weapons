// RUN ARGS :
// 1st arg : how much pairs of 2 weapons to test their combination for
// 2nd arg : a seeed for the RNG

#include <iostream>
#include <random>
#define MAX_WEAPONS (103-1) // go away ra thor
#define MAX_2D 15


#define KW_NONE -1 // means "no keyword/unused in this slot"
#define KW_NULL 0 // a "placeholder" keyword category mostly for debug

// Elements
#define KW_FIRE 1
#define KW_WATER 2
#define KW_EARTH 3
#define KW_WIND 4

#define KW_LIGHT 5
#define KW_BOMB 6
#define KW_ICE 7
#define KW_SPACETIME 8
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

// ======> Singletons <====== //

// Vanilla
#define KW_RM_QUICK 100
#define KW_RM_DUST 101
#define KW_RM_RING 102
#define KW_RM_FLASH 103
#define KW_RM_YAMATO 104

//Xover 
#define KW_METGUARD1 150
#define KW_METGUARD2 151
#define KW_METGUARD3 152
#define KW_THOUSANDSPEAR1 153
#define KW_THOUSANDSPEAR2 154
#define KW_THOUSANDSPEAR3 155


std::string wepRadicals[MAX_WEAPONS] = {
	"SuperArm","HyperBomb","IceSlasher","ThunderBeam",
	"FireStorm","RollingCutter","TimeSlow","OilSlider",
	
	"BubbleLead","MetalBlade","AtomicFire","LeafShield",
	"AirShooter","QuickBoomerang","CrashBomb","TimeStopper",
	
	"MagnetMissile","TopSpin","NeedleCannon","ShadowBlade",
	"GeminiLaser","SearchSnake","HardKnuckle","SparkShock",
		
	"DrillBomb","RingBoomerang","DustCrusher","PharaohShot",
	"SkullBarrier","DiveMissile","RainFlush","FlashStopper",
	
	"NapalmBomb","ChargeKick","GyroAttack","PowerStone",
	"WaterWave","CrystalEye","StarCrash","GravityHold",
	
	"BlizzardAttack","FlameBlast","YamatoSpear","PlantBarrier",
	"SilverTomahawk","WindStorm","KnightCrush","CentaurFlash",
	
	"FreezeCracker","NoiseCrush","WildCoil","DangerWrap",
	"ScorchWheel","JunkShield","SlashClaw","ThunderBolt",
	
	"AstroCrush","FlameSword","ThunderClaw","HomingSniper",
	"WaterBalloon","MegaBall","FlashBomb","IceWave","TornadoHold",
	
	"TenguBlade","WaveBurner","SpreadDrill","MagicCard",
	"RemoteMine","CopyVision","IceWall","LightningBolt",
	
	"PlugBall","LaserTrident","BlackHoleBomb","JewelSatellite",
	"ConcreteShot","TornadoBlow","HornetChaser","MagmaBazooka",
	
	"SolarBlaze", "WheelCutter", "ReboundStriker", "ThunderWool", 
	"CommandoBomb", "ChillSpike", "WaterShield", "TripleBlade",
	
	"GrabBuster", "BubbleBomb", "PhotonMissile", "SaltWater",
	"ElectricShock", "BlackHole", "DeepDigger", "BreakDash", "SparkChaser",
		
	"Sakugarne", "BalladeCracker", "ScrewCrusher", "MirrorBuster",
	
};

// JUST PARSE THE XOVER CODE HERE!!!!!
int ingredients[MAX_WEAPONS][5] = {    
	{ KW_NONE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Guts
	{ KW_BOMB, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Bomb // +BOUNCY?
	{ KW_ICE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Ice
	{ KW_ELEC, KW_SPREAD, KW_NONE, KW_NONE, KW_NONE},  // Elec
	{ KW_FIRE, KW_SHIELD, KW_MELEE, KW_NONE, KW_NONE }, // Fire
	{ KW_CUTTER, KW_BOOMERANG, KW_NONE, KW_NONE, KW_NONE }, // Cut // +BOUNCY?
	{ KW_NONE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Time
	{ KW_MELEE, KW_MOBILITY, KW_WATER, KW_NONE, KW_NONE }, // Oil
	
	//MM2
	{ KW_CRAWLER, KW_WATER, KW_NONE, KW_NONE, KW_NONE }, // Bubble
	{ KW_CUTTER, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Metal
	{ KW_FIRE, KW_CHARGEABLE, KW_NONE, KW_NONE, KW_NONE }, // Heat
	{ KW_SHIELD, KW_NATURE, KW_NONE, KW_NONE, KW_NONE }, // Wood
	{ KW_WIND, KW_SPREAD, KW_NONE, KW_NONE, KW_NONE }, // Air
	{ KW_RM_QUICK, KW_BOOMERANG, KW_CUTTER, KW_NONE, KW_NONE }, // Quick
	{ KW_BOMB, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Crash
	{ KW_RM_FLASH, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Flash
	
	//MM3
	{ KW_TARGETER, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Magnet
	{ KW_MELEE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Top
	{ KW_NATURE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Needle
	{ KW_CUTTER, KW_BOOMERANG, KW_NONE, KW_NONE, KW_NONE }, // Shadow
	{ KW_LIGHT, KW_BOUNCY, KW_NONE, KW_NONE, KW_NONE }, // Gemini
	{ KW_CRAWLER, KW_NATURE, KW_NONE, KW_NONE, KW_NONE }, // Snake
	{ KW_NONE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Hard
	{ KW_ELEC, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Spark

	//MM4
	{ KW_BOMB, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Drill
	{ KW_BOOMERANG, KW_CUTTER, KW_RM_RING, KW_NONE, KW_NONE }, // Ring // +BOUNCY?
	{ KW_RM_DUST, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Dust
	{ KW_FIRE, KW_CHARGEABLE, KW_NONE, KW_NONE, KW_NONE }, /// Pharaoh
	{ KW_SHIELD, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Skull
	{ KW_TARGETER, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Dive
	{ KW_WATER, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Toad
	{ KW_LIGHT, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Bright

	//MM5
	{ KW_BOMB, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Napalm // +BOUNCY?
	{ KW_MELEE, KW_MOBILITY, KW_NONE, KW_NONE, KW_NONE }, // Charge
	{ KW_TARGETER, KW_WIND, KW_CUTTER, KW_NONE, KW_NONE }, // Gyro
	{ KW_SPREAD, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Stone
	{ KW_CRAWLER, KW_WATER, KW_NONE, KW_NONE, KW_NONE }, // Wave
	{ KW_BOUNCY, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Crystal
	{ KW_SHIELD, KW_MELEE, KW_NONE, KW_NONE, KW_NONE }, // Star
	{ KW_NONE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Gravity

	//MM6
	{ KW_ICE, KW_SPREAD, KW_NONE, KW_NONE, KW_NONE }, // Blizzard
	{ KW_FIRE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Flame
	{ KW_RM_YAMATO, KW_CUTTER, KW_NONE, KW_NONE, KW_NONE }, // Yamato
	{ KW_SHIELD, KW_NATURE, KW_NONE, KW_NONE, KW_NONE }, // Plant
	{ KW_NATURE, KW_CUTTER, KW_NONE, KW_NONE, KW_NONE }, // Tomahawk
	{ KW_CRAWLER, KW_WIND, KW_NONE, KW_NONE, KW_NONE }, // Wind
	{ KW_BOOMERANG, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Knight // bouncy/cutter
	{ KW_LIGHT, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Centaur //

	//MM7
	{ KW_ICE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Freeze
	{ KW_CHARGEABLE, KW_BOUNCY, KW_NONE, KW_NONE, KW_NONE }, // Shade
	{ KW_CHARGEABLE, KW_BOUNCY, KW_SPREAD, KW_NONE, KW_NONE }, // Spring
	{ KW_BOMB, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Burst
	{ KW_CRAWLER, KW_FIRE, KW_SHIELD, KW_MOBILITY, KW_NONE }, // Turbo
	{ KW_SHIELD, KW_SPREAD, KW_NONE, KW_NONE, KW_NONE }, // Junk
	{ KW_CUTTER, KW_MELEE, KW_NONE, KW_NONE, KW_NONE }, // Slash // KW_NATURE
	{ KW_ELEC, KW_LIGHT, KW_NONE, KW_NONE, KW_NONE }, // Cloud

	// MM8
	{ KW_NONE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Astro
	{ KW_FIRE, KW_MELEE, KW_NONE, KW_NONE, KW_NONE }, // Sword // KW_CUTTER ? XW_TRADITIONNAL
	{ KW_ELEC, KW_MELEE, KW_MOBILITY, KW_NONE, KW_NONE }, // Clown // KW_BOOMERANG?
	{ KW_TARGETER, KW_CHARGEABLE, KW_SPREAD, KW_NONE, KW_NONE }, // Search
	{ KW_WATER, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Aqua
	{ KW_BOUNCY, KW_MOBILITY, KW_NONE, KW_NONE, KW_NONE }, // MegaBall 
	{ KW_LIGHT, KW_BOMB, KW_NONE, KW_NONE, KW_NONE }, // Grenade
	{ KW_CRAWLER, KW_ICE, KW_NONE, KW_NONE, KW_NONE }, // Frost
	{ KW_WIND, KW_MOBILITY, KW_NONE, KW_NONE, KW_NONE }, // Tengu

	//MMB
	{ KW_WIND, KW_CUTTER, KW_MELEE, KW_BOUNCY, KW_MOBILITY }, // TenguB // CHARGEABLE
	{ KW_FIRE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Burner
	{ KW_SPREAD, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Ground
	{ KW_BOOMERANG, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Magic
	{ KW_TARGETER, KW_BOMB, KW_NONE, KW_NONE, KW_NONE }, // Pirate
	{ KW_TARGETER, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Astro // KW_LIGHT ?
	{ KW_SHIELD, KW_CRAWLER, KW_ICE, KW_BOUNCY, KW_NONE }, // Cold
	{ KW_LIGHT, KW_ELEC, KW_NONE, KW_NONE, KW_NONE }, // Dynamo

	// MM9
	{ KW_CRAWLER, KW_ELEC, KW_BOUNCY, KW_NONE, KW_NONE }, // Plug
	{ KW_LIGHT, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Splash
	{ KW_TARGETER, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Galaxy :: BOMB
	{ KW_SHIELD, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Jewel
	{ KW_SOLIDIFIER, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Concrete
	{ KW_WIND, KW_MOBILITY, KW_NONE, KW_NONE, KW_NONE }, // Tornado
	{ KW_TARGETER, KW_NATURE, KW_NONE, KW_NONE, KW_NONE }, // Hornet
	{ KW_FIRE, KW_CHARGEABLE, KW_SPREAD, KW_NONE, KW_NONE }, // Magma

	//MM10
	{ KW_FIRE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Solar
	{ KW_CUTTER, KW_CRAWLER, KW_MOBILITY, KW_NONE, KW_NONE }, // Nitro // KW_MELEE?
	{ KW_BOUNCY, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Strike
	{ KW_ELEC, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Sheep
	{ KW_BOMB, KW_TARGETER, KW_NONE, KW_NONE, KW_NONE }, // Commando
	{ KW_ICE, KW_SOLIDIFIER, KW_NONE, KW_NONE, KW_NONE }, // Chill
	{ KW_SHIELD, KW_MELEE, KW_WATER, KW_NONE, KW_NONE }, // Pump
	{ KW_CUTTER, KW_SPREAD, KW_NONE, KW_NONE, KW_NONE }, // Blade
	
	//MMV
	{ KW_NONE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Mercury // WATer ?
	{ KW_WATER, KW_BOMB, KW_NONE, KW_NONE, KW_NONE }, // Venus
	{ KW_BOMB, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Mars
	{ KW_WATER, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Neptune // KW_SPREAD
	{ KW_ELEC, KW_MELEE, KW_NONE, KW_NONE, KW_NONE }, // Jupiter
	{ KW_SHIELD, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Saturn
	{ KW_NONE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Uranus
	{ KW_CHARGEABLE, KW_MELEE, KW_MOBILITY, KW_NONE, KW_NONE }, // Pluto
	{ KW_LIGHT, KW_TARGETER, KW_NONE, KW_NONE, KW_NONE }, // Terra

	//MMK
	{ KW_MELEE, KW_MOBILITY, KW_NONE, KW_NONE, KW_NONE }, // Quint
	{ KW_BOMB, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Ballade
	{ KW_CUTTER, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Punk // +BOUNCY?
	{ KW_SHIELD, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Enker :: CHARGEABLE
    };

    int fusions[MAX_2D][2] = {
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
	{ KW_SHIELD, KW_ELEC },	// Triad Thunder
	{ KW_BOUNCY, KW_CUTTER },	// Sonic Slicer
	{ KW_RM_RING, KW_SPREAD },	// Scatter Ring
	{ KW_FIRE, KW_MOBILITY },	// Yoga Inferno
	{ KW_WATER, KW_SOLIDIFIER },	// Glue Shot
    };

bool checkFusion(int kw1, int kw2) {
    for (int i = 0; i < MAX_2D; i++) {
        if (((fusions[i][0] == kw1) && (fusions[i][1] == kw2)) || 
            ((fusions[i][0] == kw2) && (fusions[i][1] == kw1)) )
            return true;

    }
    return false;
}

bool isFusion(int x, int y) {
    //std::cout << "\nAre " << x << " and " << y << " fusions";
    int kw1 = 0; int kw2;
    while ((ingredients[x][kw1] != KW_NONE) && kw1 < 5) {
        //std::cout << "\nGoing keyword " << kw1;
        kw2 = 0;
        while ((ingredients[y][kw2] != KW_NONE) && kw2 < 5) {
         //std::cout << "\nSecond keyword " << kw2;
            if (checkFusion(ingredients[x][kw1], ingredients[y][kw2]))
                return true;
            kw2++;
        }
        kw1++;
    }
    return false;
}

int main(int argc, char *argv[]) {
    
    // Initializing the table
    bool compatibility[MAX_WEAPONS][MAX_WEAPONS];
    for (int i = 0; i < MAX_WEAPONS; i++)
        for (int j = 0; j < MAX_WEAPONS; j++)
            compatibility[i][j] = false;

    // Checking if two weapons combine
    for (int x = 0; x < MAX_WEAPONS; x++) {
        for (int y = x+1; y < MAX_WEAPONS; y++) {
            if (isFusion(x,y))
                compatibility[std::min(x,y)][std::max(x,y)] = true;
        }
    }
    // Counting the total amount of combinations giving a fusion
    int count = 0;
    for (int x = 0; x < MAX_WEAPONS; x++) {
        for (int y = x+1; y < MAX_WEAPONS; y++) {
            count += compatibility[x][y];
        }
    }

	int randomPicks;
	int seed;
	if (argc == 1) { 
		randomPicks = 10000; seed = rand()%100; }
	else {
		seed = atoi(argv[2]); randomPicks = atoi(argv[1]);
	}
    srand(seed);
	
    int allCombination =  ((MAX_WEAPONS*(MAX_WEAPONS-1))/2);
    std::cout << "\n----------------------------------------------\n" << 
        "There exist " << count << " combinations among " << allCombination << " (using the " << MAX_WEAPONS << " vanilla weapons) that is " << 
        ((double) count /(double) allCombination*100.0) << "%";
    std::cout << "\n----------------------------------------------\n" << "trying in practice!! picking " << randomPicks << " combinations... with seed " << seed << "...";
    int val1; int val2; int acc = 0;
    for (int i = 0; i < randomPicks; i++) {
        val1 = rand() % MAX_WEAPONS;
        do {
            val2 = rand() % MAX_WEAPONS;
        }while (val2 == val1);
        acc += isFusion(val1, val2);
       
    }
    std::cout << "\nresult : " << ((double) acc / (double) randomPicks)*100 << "%";


    /*int ind1 = atoi(argv[1]);
    int ind2 = atoi(argv[2]);
    std::cout << "\n\n" << isFusion(ind1, ind2);*/

    std::cout << "\nfinished! Want to display the combinations ?";
	bool printCombination;
	std::cin >> printCombination;
	if (printCombination) {
		for (int x = 0; x < MAX_WEAPONS; x++) {
			for (int y = x+1; y < MAX_WEAPONS; y++) {
				if (compatibility[x][y]) {
					std::cout << "\n" << wepRadicals[x] << " + " << wepRadicals[y];
				}
			}
    }

	}
    return 0;
}