//
//  main.cpp
//  Arena multi
//
//  Created by Leo Ramzell on 2018-09-18.
//  Copyright © 2018 Leo Ramzell. All rights reserved.
//

#include <iostream>
using namespace std;
// 1 = player 1 & 2 = player 2 for example str1 = Strength of player 1 & str2 = Strength of player 2
char omstart, tuto, weapon1, weapon2, choise1, choise2, statch1, statch2;

int pl1weapon, pl2weapon, wdmg1, multi1, plpoison1, poisontick1, wblockdmg1, wblockmulti1, wdmg2, multi2, plpoison2, poisontick2, wblockdmg2, wblockmulti2, str1, con1, dex1, str2, con2, dex2, pl1hp, pl2hp , bodmg1, bodmg2, poisondmg1, poisondmg2, pl1wblock, pl2wblock, pldagerdmg1, pldagerdmg2, hitchance1, hitchance2, /*shieldhp1, shieldhp2,*/ pl1hpmax, pl2hpmax, pldmg1, pldmg2, shieldblock1, shieldblock2, block1, block2, recover1, recover2, totalstat1 = 30, totalstat2 = 30;
 //bodmg == Bonus dmg

void attack1 ();
void attack2 ();
void blocka1 ();
void blocka2 ();
void dmgtake1 ();
void dmgtake2 ();
void blockall ();
void reset();

int main ()
{
    cout << "----------------------------------------" << endl;
    cout << "------Welcome to the arena players------" << endl;
    cout << "-----Two joins the arena one leaves-----" << endl;
    cout << "----------------------------------------" << endl;
    cout << "----Have you played this before? Y/N----" << endl;
    cin >> tuto;
    if (tuto == 'N' || tuto == 'n') {
        cout << "In this game you try to kill the other player." << endl;
        cout << " " << endl;
        cout << "First the both of you pick your stats." << endl;
        cout << "Then you pick your weapons." << endl;
        cout << " " << endl;
        cout << "In combat there is two actions: (A)ttack and (B)lock." << endl;
        cout << "Attack - It's does what it says. It's attack your opponent." << endl;
        cout << "Block - You block your opponent attack and heal a small amount." << endl;
    }
    do {
    cout << "----------------------------------------" << endl;
    cout << "------You have 30 points in total-------" << endl;
    cout << "---To put in the three different stats--" << endl;
    cout << "--(Str)ength-(Con)stitution-(Dex)terity-" << endl;
    cout << "----------------------------------------" << endl;
    cout << "-----Now to pick your stats Player 1----" << endl;
    cout << "----------------------------------------" << endl;
    do {
        do{
        totalstat1 = 30;
            str1 = 0;
            dex1 = 0;
            con1 = 0;
        cout << "How much do you wanna have in Strength?" << endl;
        cin >> str1;
        cout << " " << endl;
        totalstat1 -= str1;
        cout << "You have " << totalstat1 << " stats left." << endl;
        cout << "How much do you wanna have in Constituion?" << endl;
        cin >> con1;
        cout << " " << endl;
        totalstat1 -= con1;
        cout << "You have " << totalstat1 << " stats left." << endl;
        cout << "How much do you wanna have in Dexterity?" << endl;
        cin >> dex1;
        cout << " " << endl;
        if (str1 + con1 + dex1 != 30) {
            cout << "You have to have a total of 30 points not more nor less" << endl;
        }
        if (str1 <= 5) {
            bodmg1 = 2;
        }
        else if (str1 <= 10){
            bodmg1 = 4;
        }
        else if (str1 <= 15){
            bodmg1 = 6;
        }
        else if (str1 <= 20){
            bodmg1 = 9;
        }
        else if (str1 > 20){
            bodmg1 = 11;
        }
        
        if (con1 <= 5) {
            pl1hp = 20;
            pl1hpmax = 30;
        }
        else if (con1 <= 10){
            pl1hp = 40;
            pl1hpmax = 50;
        }
        else if (con1 <= 15){
            pl1hp = 65;
            pl1hpmax = 75;
        }
        else if (con1 <= 20){
            pl1hp = 80;
            pl1hpmax = 90;
        }
        else if (con1 > 20){
            pl1hp = 100;
            pl1hpmax = 110;
        }
        
        if (dex1 <= 5) {
            shieldblock1 = 2;
        }
        else if (dex1 <= 10){
            shieldblock1 = 4;
        }
        else if (dex1 <= 15){
            shieldblock1 = 6;
        }
        else if (dex1 <= 20){
            shieldblock1 = 8;
        }
        else if (dex1 > 20){
            shieldblock1 = 10;
        }
            
    } while (str1 + con1 + dex1 != 30);
        cout << "Strength:" << str1 << endl;
        if (str1 <= 5) {
            cout << "You have +2 bonus damage." << endl;
        }
        else if (str1 <= 10){
            cout << "You have +4 bonus damage." << endl;
        }
        else if (str1 <= 15){
            cout << "You have +6 bonus damage." << endl;
        }
        else if (str1 <= 20){
            cout << "You have +9 bonus damage." << endl;
        }
        else if (str1 > 20){
            cout << "You have +11 bonus damage." << endl;
        }
        cout << "Constitution:" << con1 << endl;
        if (con1 <= 5) {
            cout << "You have 20hp and 30 max hp." << endl;
        }
        else if (con1 <= 10){
            cout << "You have 40hp and 50 max hp." << endl;
        }
        else if (con1 <= 15){
            cout << "You have 65hp and 75 max hp." << endl;
        }
        else if (con1 <= 20){
            cout << "You have 80hp and 90 max hp." << endl;
        }
        else if (con1 > 20){
            cout << "You have 100hp and 110 max hp." << endl;
        }
        cout << "Dexterity:" << dex1 << endl;
        if (dex1 <= 5) {
            cout << "You block 2-9 damage." << endl;
        }
        else if (dex1 <= 10){
            cout << "You block 4-11 damage." << endl;
        }
        else if (dex1 <= 15){
            cout << "You block 6-13 damage." << endl;
        }
        else if (dex1 <= 20){
            cout << "You block 8-15 damage." << endl;
        }
        else if (dex1 > 20){
            cout << "You block 11-18 damage." << endl;
        }
        cout << "You sure you want these stats? Y/N" << endl;
        cin >> statch1;
    }while (statch1 == 'N' || statch1 == 'n');
        do {
            cout << "----------------------------------------" << endl;
            cout << "------Now pick your weapon player 1-----" << endl;
            cout << "-----(1) Axe--(2) Sword--(3) Daggers----" << endl;
            cout << "--(4) Poison dagger--(5) spiked shield--" << endl;
            cout << "----------------------------------------" << endl;
            cin >> pl1weapon;
            
            if (pl1weapon == 1) { // Axe dmg (5-12)
                cout << "So you have picked the Axe." << endl;
                cout << "Its has high dmg but its hard to hit with." << endl;
                wdmg1 = 8;
                multi1 = 5;
            }
            else if (pl1weapon == 2){ // Sword dmg (5-8)
                cout << "So you have picked the sword." << endl;
                cout << "Its has medium dmg but is more reliable weapon." << endl;
                wdmg1 = 4;
                multi1 = 5;
            }
            else if (pl1weapon == 3){ // Daggers dmg (1-4)*2 aka (2-8)
                cout << "So you have picked the daggers." << endl;
                cout << "Its does the low amout of dmg but you have 2 of them." << endl;
                wdmg1 = 4;
                multi1 = 1;
            }
            else if (pl1weapon == 4){ //Posinus dagger  dmg (1-4) + dot
                cout << "So you have picked the posion dager." << endl;
                cout << "Its does the low amout of dmg but its poisons your enemy each time hit them." << endl;
                wdmg1 = 4;
                multi1 = 1;
                plpoison1 = 0;
                poisontick1 = 0;
                plpoison1 = 0;
            }
            else if (pl1weapon == 5){ //Spiked shield dmg (3-6) + (1-3) dmg block
                cout << "So you have picked the spike shield." << endl;
                cout << "Its does the low to medium amout of dmg but you have also block dmg." << endl;
                wdmg1 = 4;
                multi1 = 3;
                wblockdmg1 = 3;
                wblockmulti1 = 1;
            }
            else{ //If you pick no weapon you get no weapon and start to fight with fists (1-3)
                cout << "You have pick no weapon and choisen to fight bare handed." << endl;
                cout << "Good luck" << endl;
                wdmg1 = 3;
                multi1 = 1;
            }
            cout << "You sure want that weapon? Y/N" << endl;
            cin >> weapon1;
        }while (weapon1 == 'N' || weapon1 == 'n');
    cout << string(100, '\n');
    cout << "----------------------------------------" << endl;
    cout << "------You have 30 points in total-------" << endl;
    cout << "---To put in the three different stats--" << endl;
    cout << "--(Str)ength-(Con)stitution-(Dex)terity-" << endl;
    cout << "----------------------------------------" << endl;
    cout << "-----Now to pick your stats Player 2----" << endl;
    cout << "----------------------------------------" << endl;
    do {
        do {
        totalstat2 = 30;
            str2 = 0;
            con2 = 0;
            dex2 = 0;
        cout << "How much do you wanna have in Strength?" << endl;
        cin >> str2;
        totalstat2 -= str2;
        cout << " " << endl;
        cout << "You have " << totalstat2 << " stats left." << endl;
        cout << "How much do you wanna have in Constituion?" << endl;
        cin >> con2;
        totalstat2 -= con2;
        cout << " " << endl;
        cout << "You have " << totalstat2 << " stats left." << endl;
        cout << "How much do you wanna have in Dexterity?" << endl;
        cin >> dex2;
        cout << " " << endl;
        if (str2 + con2 + dex2 != 30) {
            cout << "You have to have a total of 30 points not more nor less" << endl;
        }
        if (str2<= 5) {
            bodmg2 = 2;
        }
        else if (str2 <= 10){
            bodmg2 = 4;
        }
        else if (str2 <= 15){
            bodmg2 = 6;
        }
        else if (str2 <= 20){
            bodmg2 = 9;
        }
        else if (str2 > 20){
            bodmg2 = 11;
        }
        
        if (con2 <= 5) {
            pl2hp = 20;
            pl2hpmax = 30;
        }
        else if (con2 <= 10){
            pl2hp = 40;
            pl2hpmax = 50;
        }
        else if (con2 <= 15){
            pl2hp = 65;
            pl2hpmax = 75;
        }
        else if (con2 <= 20){
            pl2hp = 80;
            pl2hpmax = 90;
        }
        else if (con2 > 20){
            pl2hp = 100;
            pl2hpmax = 110;
        }
        
        if (dex2 <= 5) {
            shieldblock2 = 2;
        }
        else if (dex2 <= 10){
            shieldblock2 = 4;
        }
        else if (dex2 <= 15){
            shieldblock2 = 6;
        }
        else if (dex2 <= 20){
            shieldblock2 = 8;
        }
        else if (dex2 > 20){
            shieldblock2 = 10;
        }
    } while (str2 + con2 + dex2 != 30);
        cout << "Strength:" << str2 << endl;
        if (str2 <= 5) {
            cout << "You have +2 bonus damage." << endl;
        }
        else if (str2 <= 10){
            cout << "You have +4 bonus damage." << endl;
        }
        else if (str2 <= 15){
            cout << "You have +6 bonus damage." << endl;
        }
        else if (str2 <= 20){
            cout << "You have +9 bonus damage." << endl;
        }
        else if (str2 > 20){
            cout << "You have +11 bonus damage." << endl;
        }
        cout << "Constitution:" << con2 << endl;
        if (con2 <= 5) {
            cout << "You have 20hp and 30 max hp." << endl;
        }
        else if (con2 <= 10){
            cout << "You have 40hp and 50 max hp." << endl;
        }
        else if (con2 <= 15){
            cout << "You have 65hp and 75 max hp." << endl;
        }
        else if (con2 <= 20){
            cout << "You have 80hp and 90 max hp." << endl;
        }
        else if (con2 > 20){
            cout << "You have 100hp and 110 max hp." << endl;
        }
        cout << "Dexterity:" << dex2 << endl;
        if (dex2 <= 5) {
            cout << "You block 2-9 damage." << endl;
        }
        else if (dex2 <= 10){
            cout << "You block 4-11 damage." << endl;
        }
        else if (dex2 <= 15){
            cout << "You block 6-13 damage." << endl;
        }
        else if (dex2 <= 20){
            cout << "You block 8-15 damage." << endl;
        }
        else if (dex2 > 20){
            cout << "You block 11-18 damage." << endl;
        }
        cout << "You sure you want these stats? Y/N" << endl;
        cin >> statch1;
    } while (statch2 == 'N' || statch2 == 'n');
    do {

    cout << "----------------------------------------" << endl;
    cout << "------Now pick your weapon player 2-----" << endl;
    cout << "-----(1) Axe--(2) Sword--(3) Daggers----" << endl;
    cout << "--(4) Poison dagger--(5) spiked shield--" << endl;
    cout << "----------------------------------------" << endl;
    cin >> pl2weapon;
    if (pl2weapon == 1) { // Axe dmg (5-12)
        cout << "So you have picked the Axe." << endl;
        cout << "Its has high dmg but its hard to hit with." << endl;
        wdmg2 = 8;
        multi2 = 5;
    }
    else if (pl2weapon == 2){ // Sword dmg (5-8)
        cout << "So you have picked the sword." << endl;
        cout << "Its has medium dmg but is more reliable weapon." << endl;
        wdmg2 = 4;
        multi2 = 5;
    }
    else if (pl2weapon == 3){ // Daggers dmg (1-4)*2 aka (2-8)
        cout << "So you have picked the daggers." << endl;
        cout << "Its does the low amout of dmg but you have 2 of them." << endl;
        wdmg2 = 4;
        multi2 = 1;
    }
    else if (pl2weapon == 4){ //Posinus dagger  dmg (1-4) + dot
        cout << "So you have picked the posion dager." << endl;
        cout << "Its does the low amout of dmg but its poisons your enemy each time hit them." << endl;
        wdmg2 = 4;
        multi2 = 1;
        plpoison2 = 0;
        poisontick2 = 0;
        plpoison2 = 0;
    }
    else if (pl2weapon == 5){ //Spiked shield dmg (3-6) + (1-3) dmg block
        cout << "So you have picked the spike shield." << endl;
        cout << "Its does the low to medium amout of dmg but you have also block dmg." << endl;
        wdmg2 = 4;
        multi2 = 3;
        wblockdmg2 = 3;
        wblockmulti2 = 1;
    }
    else{ //If you pick no weapon you get no weapon and start to fight with fists (1-3)
        cout << "You have pick no weapon and choisen to fight bare handed." << endl;
        cout << "Good luck" << endl;
        wdmg2 = 3;
        multi2 = 1;
    }
    cout << "You sure want that weapon? Y/N" << endl;
    cin >> weapon2;
    } while (weapon2 == 'N' || weapon2 == 'n');
        
        cout << string(100, '\n');
        do {
        if (dex1 > dex2) {
            cout << "So what do you do player 1?" << endl;
            cout << "(A)ttack,(B)locking" << endl; // Choose what to do
            cin >> choise1;
            cout << " " << endl;
            
            if (choise1 == 'A' || choise1 == 'a') {
                attack1();
            }
            else if (choise1 == 'B' || choise1 == 'b'){
                blocka1();
                }

            else
            {
                cout << "You did nothing, nice job idiot." << endl;
                cout << " " << endl;
            }
            cout << "So what do you do? player 2" << endl;
            cout << "(A)ttack,(B)locking" << endl; // Choose what to do
            cin >> choise2;
            cout << " " << endl;
            
            if (choise2 == 'A' || choise2 == 'a') {
                attack2();
            }
            else if (choise2 == 'B' || choise2 == 'b')
            {
                blocka2();
            }
            else
            {
                cout << "You did nothing, nice job idiot." << endl;
                cout << " " << endl;
            }
            blockall();
            dmgtake1();
            dmgtake2();
            reset();

        }
        else if (dex1 < dex2){
            cout << "So what do you do? player 2" << endl;
            cout << "(A)ttack,(B)locking" << endl; // Choose what to do
            cin >> choise2;
            cout << " " << endl;
            
            if (choise2 == 'A' || choise2 == 'a') {
                attack2();
            }
            else if (choise2 == 'B' || choise2 == 'b')
            {
                blocka2();
            }
                else
                    {
                        cout << "You did nothing, nice job idiot." << endl;
                        cout << " " << endl;
                    }
            cout << "So what do you do player 1?" << endl;
            cout << "(A)ttack,(B)locking" << endl; // Choose what to do
            cin >> choise1;
            cout << " " << endl;
            
            if (choise1 == 'A' || choise1 == 'a') {
                attack1();
                
            }
            else if (choise1 == 'B' || choise1 == 'b'){
                blocka1();
            }
            else
                {
                    cout << "You did nothing, nice job idiot." << endl;
                    cout << " " << endl;
                }
            blockall();
            dmgtake2();
            dmgtake1();
            reset ();

        }
        else{
            cout << "So what do you do player 1?" << endl;
            cout << "(A)ttack,(B)locking" << endl; // Choose what to do
            cin >> choise1;
            cout << " " << endl;
            
            if (choise1 == 'A' || choise1 == 'a') {
                attack1();
            }
            else if (choise1 == 'B' || choise1 == 'b'){
                blocka1();
            }
            else
            {
                cout << "You did nothing, nice job idiot." << endl;
                cout << " " << endl;
            }
            cout << "So what do you do? player 2" << endl;
            cout << "(A)ttack,(B)locking" << endl; // Choose what to do
            cin >> choise2;
            cout << " " << endl;
            
            if (choise2 == 'A' || choise2 == 'a') {
                attack2();
            }
            else if (choise2 == 'B' || choise2 == 'b')
            {
                blocka2();
            }
            else
            {
                cout << "You did nothing, nice job idiot." << endl;
                cout << " " << endl;
            }
            blockall();
            dmgtake1();
            dmgtake2();
            reset();
        }
            
            if (pl1hp > pl1hpmax){
                pl1hp = pl1hpmax;
            }
            if (pl2hp > pl2hpmax){
                pl2hp = pl2hpmax;
            }
        } while (pl1hp > 0 && pl2hp > 0);
        
        if (dex1 > dex2) {
            if (pl1hp > 0) {
                cout << "Player 1 have won" << endl;
            }
            else if (pl2hp > 0){
                cout << "Player 2 have won" << endl;
            }
        }
        else if (dex1 < dex2){
            if (pl2hp > 0) {
                cout << "Player 2 have won" << endl;
            }
            else if (pl1hp > 0){
                cout << "Player 1 have won" << endl;
            }
        }

        cout << "Do you wanna play again? Y/N" << endl;
        cin >> omstart;
    } while (omstart =='Y' || omstart == 'y');
    return 0;

}
            
            void attack1 (){
                pldmg1 = rand() % wdmg1 + multi1; // How much dmg you would deal
                
                if (pl1weapon == 1)
                {
                    hitchance1 = rand() % 10 +1;
                    if (hitchance1 <= 8) // 80% to hit
                    {
                        
                    }
                    else // 20% to miss
                    {
                        pldmg1 = pldmg1 - pldmg1;
                    }
                }
                if (pl1weapon == 3) //The other dagger
                {
                    pldagerdmg1 = rand() % wdmg1 + multi1;
                    pldmg1 = pldagerdmg1 + pldmg1;
                }
                if (pl1weapon == 4) {
                    if (poisontick1 == 0) { //Inc every other time
                        plpoison1+= 2; //How much poison inc
                        poisontick1++;
                    } else {
                        poisontick1--;
                    }
                    poisondmg1 = plpoison1;
                    pl2hp -= poisondmg1;
                }
                if (pl1weapon == 5) {
                    pl1wblock = rand() % wblockdmg1 + wblockmulti1;
                }
                
                pldmg1 += bodmg1;
            };
            
            
            void attack2 (){
                pldmg2 = rand() % wdmg2 + multi2; // How much dmg you would deal
                
                if (pl2weapon == 1)
                {
                    hitchance2 = rand() % 10 +1;
                    if (hitchance2 <= 8) // 80% to hit
                    {
                        
                    }
                    else // 20% to miss
                    {
                        pldmg2 = pldmg2 - pldmg2;
                    }
                }
                if (pl2weapon == 3) //The other dagger
                {
                    pldagerdmg2 = rand() % wdmg2 + multi2;
                    pldmg2 = pldagerdmg2 + pldmg2;
                }
                if (pl2weapon == 4) {
                    if (poisontick2 == 0) { //Inc every other time
                        plpoison2+= 2; //How much poison inc
                        poisontick2++;
                    } else {
                        poisontick2--;
                    }
                    poisondmg2 = plpoison2;
                    pl1hp -= poisondmg2;
                }
                if (pl2weapon == 5) {
                    pl2wblock = rand() % wblockdmg2 + wblockmulti2;
                }
                
                pldmg2 += bodmg2;

            };

void blocka1 (){
        cout << "You try to block the incoming attack" << endl;
        cout << " " << endl;
        block1 = rand() % 7 +shieldblock1; //How much dmg blocked
        cout << "You block " << block1 << " dmg";
        recover1 = rand() % 5 +3; //How much health you recover (3-7)
        cout << " and you recover " << recover1 << "hp." << endl;
        pl1hp += recover1;
};

void blocka2 (){
        cout << "You try to block the incoming attack" << endl;
        cout << " " << endl;
    block2 = rand() % 7 +shieldblock2; //How much dmg blocked
    recover2 = rand() % 5 +3; //How much health you recover (3-7)
    pl2hp += recover2;
};
void dmgtake1 (){
    if (choise1 == 'A' || choise1 == 'a') {
    if (pl1weapon == 1) {
        if (hitchance1 <= 8) // 80% to hit
        {
            cout << "You feel the hit with your axe." << endl;
            cout << " " << endl;
        }
        else // 20% to miss
        {
            cout << "You feel that your axe misses your enemy." << endl;
            cout << " " << endl;
        }
    }
        if (pl1weapon == 4) {
            pl2hp -= plpoison1;
        }
   
    cout << "Player 1 deal " << pldmg1 << endl;
    
    if (pl1weapon == 5) {
        pldmg2 -= pl1wblock;
        cout << "You block " << pl1wblock << " dmg." << endl;
    }
        if (pl1wblock > pldmg2) {
            pldmg2 = 0;
        }
        pl1hp -= pldmg2;
    }
    if (pl1weapon == 4) {
        cout << "The poison deals " << poisondmg1 << " dmg" << endl;
    }
    cout << "Player 1 have " << pl1hp << "hp" << endl;
    cout << " " << endl;
};
void dmgtake2 (){
    if (choise2 == 'A' || choise2 == 'a'){
    if (pl2weapon == 1) {
        if (hitchance2 <= 8) // 80% to hit
        {
            cout << "You feel the hit with your axe." << endl;
            cout << " " << endl;
        }
        else // 20% to miss
        {
            cout << "You feel that your axe misses your enemy." << endl;
            cout << " " << endl;
        }

    }

        if (pl2weapon == 4) {
            pl1hp -= plpoison2;
        }
    cout << "Player 2 deal " << pldmg2 << endl;
    
    if (pl2weapon == 5) {
        pldmg1 -= pl2wblock;
        cout << "You block " << pl2wblock << " dmg." << endl;
    }
        if (pl2wblock > pldmg1) {
            pldmg1 = 0;
        }
    pl2hp -= pldmg1;
    }
    if (choise2 == 'B' || choise2 == 'b') {
        
        cout << "You block " << block2 << " dmg";
        cout << " and you recover " << recover2 << "hp." << endl;

    }
    if (pl2weapon == 4) {
        cout << "The poison deals " << poisondmg2 << " dmg" << endl;
    }
    
    cout << "Player 2 have " << pl2hp << "hp" << endl;
    cout << " " << endl;
    
};

void blockall (){
    if (choise1 == 'B' || choise1 == 'b') {
        if (block1 > pldmg2) {
            pldmg2 = 0;
        }
        else{
        pldmg2 -=block1;
        }
    }
    if (choise2 == 'B' || choise2 == 'b') {
        if (block2 > pldmg1) {
            pldmg1 = 0;
        } else {
             pldmg1 -=block2;
        }
       
    }
};
void reset (){
    pl2wblock = 0;
    pl1wblock = 0;
    pldmg1 = 0;
    pldmg2 = 0;
}
