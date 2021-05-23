// RUN ARGS :
// 1st arg : how much pairs of 2 weapons to test their combination for
// 2nd arg : a seeed for the RNG

#include <iostream>
#include <random>
#define MAX_WEAPONS (103-1) // go away ra thor
#define MAX_2D 16			// "number of 2D weapons"
#define MAX_3D MAX_2D+3		// "of 3D weapons"
#define MAX_4D MAX_3D+3 		// etc
#define MAX_5D MAX_4D+2
#define MAX_ALL_WEAPONS MAX_WEAPONS+MAX_5D   // fusions + vailla


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

// Game
#define KW_GAME_5 85 

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

// Initializing the table
bool compatibility[MAX_WEAPONS][MAX_ALL_WEAPONS];



std::string wepRadicals[MAX_ALL_WEAPONS] = {
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
	
	// FUSIONS
	
	// 2D
	"MetGuard1",
	"MeltCreeper",
	"AimingLaser",
	"DelayFlame",
	"RecycleInhaler",
	"ForestWhip",
	"BlastMissile",
	"ThousandSpear",
	"WhiteRoseCluster",
	"LeafBoomerang",
	"TriadThunder",
	"SonicSlicer",
	"ScatterRing",
	"YogaInferno",
	"GlueShot",
	"SuperArrow",
	
	// 3D
	"MetGuard2",
	"ThousandSpearV2",
	"CountershadingTracer",
	
	// 4D
	"MetGuard3",
	"ThousandSpearV3",
	"ThousandKnives",
	
	// 5D
	"MetGuard3EX",
	"ThousandSpearV5",
	
};

// JUST PARSE THE XOVER CODE HERE!!!!!
int ingredients[MAX_ALL_WEAPONS][5] = {    
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
	{ KW_BOMB, KW_GAME_5, KW_NONE, KW_NONE, KW_NONE }, // Napalm // +BOUNCY?
	{ KW_MELEE, KW_MOBILITY, KW_GAME_5, KW_NONE, KW_NONE }, // Charge
	{ KW_TARGETER, KW_WIND, KW_CUTTER, KW_GAME_5, KW_NONE }, // Gyro
	{ KW_SPREAD, KW_GAME_5, KW_NONE, KW_NONE, KW_NONE }, // Stone
	{ KW_CRAWLER, KW_WATER, KW_GAME_5, KW_NONE, KW_NONE }, // Wave
	{ KW_BOUNCY, KW_GAME_5, KW_NONE, KW_NONE, KW_NONE }, // Crystal
	{ KW_SHIELD, KW_MELEE, KW_GAME_5, KW_NONE, KW_NONE }, // Star
	{ KW_GAME_5, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Gravity

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

	
	// 2D
	// To add : SHIELD, MELEE, CUTTER, BOUNCY, TARGETER
	{ KW_METGUARD1, KW_SHIELD, KW_NONE, KW_NONE, KW_NONE }, // Met Guard 1
	{ KW_NONE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Melt Creeper
	{ KW_TARGETER, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Aiming Laser
	{ KW_NONE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Delay Flame
	{ KW_MELEE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Recycle Inhaler
	{ KW_MELEE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Forest Whip
	{ KW_TARGETER, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Blast Missile
	{ KW_THOUSANDSPEAR1, KW_MELEE, KW_CUTTER, KW_NONE, KW_NONE }, // Thousand Spear
	{ KW_MELEE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // White Rose Cluster
	{ KW_NONE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Leaf Boomerang // BOUNCY ?
	{ KW_SHIELD, KW_MELEE, KW_NONE, KW_NONE, KW_NONE }, // Triad Thunder
	{ KW_CUTTER, KW_BOUNCY, KW_NONE, KW_NONE, KW_NONE }, // Sonic Slicer
	{ KW_NONE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Scatter Ring
	{ KW_NONE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Yoga Inferno // KW_MELEE
	{ KW_NONE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Glue Shot
	{ KW_TARGETER, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Super Arrow
	
	// 3D
	// To add : SHIELD, MELEE, CUTTER
	{ KW_METGUARD2, KW_SHIELD, KW_NONE, KW_NONE, KW_NONE }, // Met Guard 2
	{ KW_THOUSANDSPEAR2, KW_MELEE, KW_CUTTER, KW_NONE, KW_NONE }, // Thousand Spear V2
	{ KW_NONE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Countershading Tracer
	
	// 4D
	// To add : SHIELD, MELEE
	{ KW_METGUARD3, KW_SHIELD, KW_NONE, KW_NONE, KW_NONE }, // Met Guard 3
	{ KW_THOUSANDSPEAR3, KW_MELEE, KW_NONE, KW_NONE, KW_NONE }, // Thousand Spear V3
	{ KW_NONE, KW_NONE, KW_NONE, KW_NONE, KW_NONE }, // Thousand Knives
	
	// 5D
	//{ KW_NONE, KW_TGPD, KW_TGPD },
	// MetGuard 3 EX, Thousand Spear V5
	
    };

    int fusions[MAX_5D][2] = {// 2D
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
		{ KW_GAME_5, KW_GAME_5 },	// Super Arrow
		
		// 3D
		{ KW_METGUARD1, KW_SHIELD },	// Met Guard 2
		{ KW_THOUSANDSPEAR1, KW_MELEE },	// Thousand Spear V2
		{ KW_TARGETER, KW_BOUNCY },	// Countershading Tracer
		
		// 4D
		{ KW_METGUARD2, KW_SHIELD },	// Met Guard 3
		{ KW_THOUSANDSPEAR2, KW_MELEE },	// Thousand Spear V3
		{ KW_RM_FLASH, KW_CUTTER },	// Thousand Knives
		
		// 5D
		{ KW_METGUARD3, KW_SHIELD },	// Met Guard 3 EX
		{ KW_THOUSANDSPEAR3, KW_MELEE },	// Thousand Spear V5
    };

bool checkFusion(int kw1, int kw2, int tierOffsetLow, int tierOffsetHigh) {
	//std::cout << "\nlooking from " << tierOffsetLow << " to " << tierOffsetHigh << "\n";
    for (int i = tierOffsetLow; i < tierOffsetHigh; i++) {
        if (((fusions[i][0] == kw1) && (fusions[i][1] == kw2)) || 
            ((fusions[i][0] == kw2) && (fusions[i][1] == kw1)) ) {
				//std::cout << "\n\nmatch!!!!!!!!!\n" << kw1 << " and " << kw2 << "\n";
				return true;
			}
    }
    return false;
}

bool isFusionDeep(int x, int y, int tierOffsetLow, int tierOffsetHigh) {
    //std::cout << "\nAre " << x << " (" << wepRadicals[x] << ") and " << y << " (" << wepRadicals[y] << ") fusions ?";
    int kw1 = 0; int kw2;
    while ((ingredients[x][kw1] != KW_NONE) && kw1 < 5) {
        //std::cout << "\nFIRST element keyword " << kw1 << " = " << ingredients[x][kw1];
        kw2 = 0;
        while ((ingredients[y][kw2] != KW_NONE) && kw2 < 5) {
         //std::cout << "\nSECOND element keyword " << kw2 << " = " << ingredients[y][kw2];
            if (checkFusion(ingredients[x][kw1], ingredients[y][kw2], tierOffsetLow, tierOffsetHigh))
                return true;
            kw2++;
        }
        kw1++;
    }
    return false;
}

bool isFusion(int x, int y) {
	int tierOffsetLow, tierOffsetHigh;
	if (y < MAX_WEAPONS) { tierOffsetLow = 0; tierOffsetHigh = MAX_2D; }
	else if (y < MAX_WEAPONS+MAX_2D) { tierOffsetLow = MAX_2D; tierOffsetHigh = MAX_3D; }
	else if (y < MAX_WEAPONS+MAX_3D) { tierOffsetLow = MAX_3D; tierOffsetHigh = MAX_4D; }
	else { tierOffsetLow = MAX_4D; tierOffsetHigh = MAX_5D; }
	return isFusionDeep(x,y,tierOffsetLow,tierOffsetHigh);
}

void compute(int tier) {
    int allCombination, tierOffsetLow, tierOffsetHigh;
	switch (tier)
	{
		case 2: default: // 2D (vanilla weapons being combined)
			tierOffsetLow = 0; tierOffsetHigh = MAX_WEAPONS;
			allCombination =  ((MAX_WEAPONS*(MAX_WEAPONS-1))/2);
			break;

		case 3:
			tierOffsetLow = MAX_WEAPONS; tierOffsetHigh = MAX_WEAPONS+MAX_2D;
			allCombination = (tierOffsetHigh-tierOffsetLow)*MAX_WEAPONS;
			break;

		case 4:
			tierOffsetLow = MAX_WEAPONS+MAX_2D; tierOffsetHigh = MAX_WEAPONS+MAX_3D;
			allCombination = (tierOffsetHigh-tierOffsetLow)*MAX_WEAPONS;
			break;

		case 5:
			tierOffsetLow = MAX_WEAPONS+MAX_3D; tierOffsetHigh = MAX_WEAPONS+MAX_4D;
			allCombination = (tierOffsetHigh-tierOffsetLow)*MAX_WEAPONS;
			break;
		
	}
	
    int count = 0;
    for (int x = 0; x < MAX_WEAPONS; x++) {
        for (int y = tierOffsetLow; y < tierOffsetHigh; y++) {
			count += compatibility[x][y];	
        }
    }
	std::cout << "\n--------------------------------------------------------------------------------------------\n" << 
        ">>> " << tier << "D <<< : There are " << count << " combinations among " << allCombination << " (" << 
			MAX_WEAPONS << "*" << tierOffsetHigh-tierOffsetLow << ") that is " << 
        ((double) count /(double) allCombination*100.0) << "%";
    std::cout << "\n--------------------------------------------------------------------------------------------\n";// << "trying in practice!! picking " << randomPicks << " combinations... with seed " << seed << "...";
   
	std::cout << "\nPrint the combinations? (1 = yes    0 = no)\n";
	bool printCombination;

	count = 1;
	std::cin >> printCombination;
	if (printCombination) {
		for (int x = 0; x < MAX_WEAPONS; x++) {
			for (int y = tierOffsetLow; y < tierOffsetHigh; y++) {
				if (compatibility[x][y])
					std::cout << "\n" << count++ << ". " << wepRadicals[x] << " + " << wepRadicals[y];
			}
		}
	}

	
}

int main(int argc, char *argv[]) {
    
    for (int i = 0; i < MAX_WEAPONS; i++)
        for (int j = 0; j < MAX_ALL_WEAPONS; j++)
            compatibility[i][j] = false;

    // Checking if two weapons combine
    for (int x = 0; x < MAX_WEAPONS; x++) {
        for (int y = x+1; y < MAX_WEAPONS+MAX_4D; y++) {
            if (isFusion(x,y))
                compatibility[std::min(x,y)][std::max(x,y)] = true;
        }
    }



	/*int randomPicks;
	int seed;
	if (argc == 1) { 
		randomPicks = 10000; seed = rand()%100; }
	else {
		seed = atoi(argv[2]); randomPicks = atoi(argv[1]);
	}
    srand(seed);
	
    int val1; int val2; int acc = 0;
    for (int i = 0; i < randomPicks; i++) {
        val1 = rand() % MAX_WEAPONS;
        do {
            val2 = rand() % MAX_WEAPONS;
        }while (val2 == val1);
        acc += isFusion(val1, val2);
       
    }
    std::cout << "\nresult : " << ((double) acc / (double) randomPicks)*100 << "%";

	*/
    /*int ind1 = atoi(argv[1]);
    int ind2 = atoi(argv[2]);
    std::cout << "\n\n" << isFusion(ind1, ind2);*/

    std::cout << "\nfinished! Select a tier\n(value [2,5] ; 2 displays 2D recipes)\n";
	int tier;
	std::cin >> tier;
	compute(tier);
	
	std::cout << "\n\n";
	system("pause");

    return 0;
}