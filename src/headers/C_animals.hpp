#ifndef __C_ANIMALS_H_INCLUDED__
#define __C_ANIMALS_H_INCLUDED__

#include "U_randomGenerator.hpp"
#include "C_environment.hpp"

#include <string>
#include <vector>
#include <iostream>

class Environment;

class Animals
{
public :
    Animals ( int newId = 99,
              std::vector<unsigned int> newlifeCycle = {1,1,1},
              std::vector<int> newprobabilities = {0,0,0,0,0,0,0},
              std::vector<int> newDetectionRadius = {2,2,2},
              std::vector<int> newActionRadius = {1,1,1},
              bool isBorn = false
            );

    virtual ~Animals () = 0;

    int run ( Environment * environment );

    int getID();

    int setLocation ( std::vector<int> newLocation );
    std::vector <int> getLocation();

    bool isDead();
    bool isSpawn();

    int getSex();

    bool getHiddenState();

    int setSpawnAbility ( bool newSpawnAbility );

    int getSpawnProbability();

protected :

    int id = 0;

    std::vector <int> location{0,0,0};
    std::vector<int> actionRadius{0,0,0};
    std::vector<int>  detectionRadius{0,0,0};

    int sex = 0; // 0 = male 1 = female

    int length = 0;
    int growthState = 0;

    int satietyIndex = 100; // MAX 100 MIN 0

    int moveProbability = 0;
    int eatProbability = 0;
    int growthProbability = 0;
    int spawnProbability = 0;
    int deadProbability = 0 ;
    int reproductionProbability = 0;
    int attackProbability = 0;

    unsigned int timeLifeCycle = 0;
    std::vector<unsigned int> lifeCycle{0,0,0};

    bool hidden = false;
    bool death = false;
    bool spawnAbility = false;

    // Detection step
    int detection ( Environment * environment );

    // Action step
    virtual int decision ( Environment * environment, std::unordered_multimap<int, Animals *> * VisibleAnimals, std::unordered_map<int,int> * VisiblePlants, std::vector<int> * CellSpecs ) = 0;

    int move ( Environment * environment );
    int moveTowards ( Environment * environment, int X, int Y );
    int eat ();
    int setHiddenState ( bool state );
    int reproduction ( std::unordered_multimap<int, Animals *> * VisibleAnimals, int specie );
    int attack ( Environment * environment );
    int spawn ( Environment * environment );

    int growth ( Environment * environment );
    int dead ( Environment * environment );

};

class Leucorrhinia: public Animals
{
public :
    Leucorrhinia ( int id = 0,
                   std::vector<unsigned int> lifeCycle = {1,24,1},
                   std::vector<int> probabilities = {0,0,0,100,1,20,100},
                   std::vector<int> detectionRadius = {1,1,2},
                   std::vector<int> actionRadius = {1,1,1},
                   bool isBorn = false ) : Animals ( id, lifeCycle, probabilities, detectionRadius, actionRadius, isBorn ) {}
    ~Leucorrhinia() {};
protected :
    int decision ( Environment * environment, std::unordered_multimap<int, Animals *> * VisibleAnimals, std::unordered_map<int,int> * VisiblePlants, std::vector<int> * CellSpecs );
};

class Hyla: public Animals
{
public :
    Hyla ( int id = 1 ) :Animals ( id ) {}
    ~Hyla() {};
protected :
    int decision ( Environment * environment, std::unordered_multimap<int, Animals *> * VisibleAnimals, std::unordered_map<int,int> * VisiblePlants, std::vector<int> * CellSpecs );
};

class Phengaris: public Animals
{
public :
    Phengaris ( int id = 2 ) :Animals ( id ) {}
    ~Phengaris() {};
protected :
    int decision ( Environment * environment, std::unordered_multimap<int, Animals *> * VisibleAnimals, std::unordered_map<int,int> * VisiblePlants, std::vector<int> * CellSpecs );
};

class Zootoca: public Animals
{
public :
    Zootoca ( int id = 3 ) :Animals ( id ) {}
    ~Zootoca() {};
protected :
    int decision ( Environment * environment, std::unordered_multimap<int, Animals *> * VisibleAnimals, std::unordered_map<int,int> * VisiblePlants, std::vector<int> * CellSpecs );
};

class Vipera: public Animals
{
public :
    Vipera ( int id = 4 ) :Animals ( id ) {}
    ~Vipera() {};
protected :
    int decision ( Environment * environment, std::unordered_multimap<int, Animals *> * VisibleAnimals, std::unordered_map<int,int> * VisiblePlants, std::vector<int> * CellSpecs );
};

#endif // __C_ANIMALS_H_INCLUDED__




