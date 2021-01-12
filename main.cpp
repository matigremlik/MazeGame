#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

struct mobList 
{
  unsigned int health;
  signed int dmg;
  std::string name;
}mob0, mob1, mob2;

struct player: public mobList{
    public:
    void plConst(int hp,int damg){
        health = hp;
        dmg = damg;
    }
    void plInit(){
        plConst(80,5);
        toughness = 0;
        strength = 1;
        inteligence = 0;
        maxhp = 100;
        pots = 3;
    }
    int toughness;
    int strength;
    int inteligence;
    int maxhp;
    int pots;
}pl1;


void mobInit()
{
    pl1.plInit();
    mob0.name = "Skeleton";
    mob0.health = 80;
    mob0.dmg = 8;
    mob1.name = "Cultist";
    mob1.health = 40;
    mob1.dmg = 12;
    mob2.name = "Grotesque";
    mob2.health = 220;
    mob2.dmg = 4;
}

int combat(int depth)
{
    srand (time(NULL));
    int v1 = rand() % 3;
    std::string crname = "";
    int crhealth;
    int crdmg;
    float mulr = (depth*0.6);
    int rounddepth = round(mulr);
    srand (time(NULL));
    int moblvl = (rand() % (depth+9+rounddepth)) + depth;
   if (moblvl ==0){
        moblvl =1;
    }
    if (v1== 0){
        crname = mob0.name;
        crhealth = mob0.health;
        crdmg = mob0.dmg;
    }
    if (v1== 1){
        crname = mob1.name;
        crhealth = mob1.health;
        crdmg = mob1.dmg;
    }
    if (v1== 2){
        crname = mob2.name;
        crhealth = mob2.health;
        crdmg = mob2.dmg;
    }
    std::cout << "You have encountered a lvl: "<<moblvl<<" " <<crname<<"\n";
    while ((pl1.health > 0) and (crhealth > 0)){
        srand (time(NULL));
        float v2 = (((rand() % 100)+1));
        v2 = 9;
        if (v2 < (10 - pl1.inteligence)){ 
            float fdmgdealt = (pl1.dmg*(v2/2)*(1+((1+pl1.strength)/ 2)));
            int idmgdealt = round(fdmgdealt);
            std::cout<<fdmgdealt<<" "<<idmgdealt<<"\n";
        } 

        std::cout<<"The "<<crname<<" has "<<crhealth<<" health"<<"\n";
        std::cout<<"You have : "<<pl1.health<<" health"<<"\n";
        unsigned short int choice = 0;
        while(choice != 1){    
            std::cout <<"Chose your action: 1.Attack, 2.Heal: ";
            std::cin>> choice;
            std::cout <<"\n";
            if (choice == 2){
                pl1.health = pl1.health + 15;
                if(pl1.health> pl1.maxhp){
                    pl1.health = pl1.maxhp;
                }
                std::cout<<"You have : "<<pl1.health<<" health"<<"\n";
            }
        }
        crhealth = crhealth - pl1.dmg;
        if(crhealth == 0){
            std::cout<<"mob ded"<<"\n";
        }
        pl1.health = pl1.health - crdmg;
        if(pl1.health == 0){
            std::cout<<"player ded"<<"\n";
        }
    }
    return 0;
}

int main()
{
    mobInit();
    int depth = 1;
    int z = 0;
    z = combat(depth);
    return 0;
}