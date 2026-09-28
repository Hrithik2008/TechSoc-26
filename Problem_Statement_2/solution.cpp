//Level 1

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <tuple>


using namespace std;

class Bender{
    private:
        string name;
        string type;
        int hp{};
        int attack{};
        int defense{};
        int speed{};
        vector<tuple<string, int>> moves;

    public:

        void createBender(string benderName, string benderType, int benderHp, int benderAttack, int benderDefense, int benderSpeed, vector<tuple<string, int>> benderMoves){
            name = benderName;
            type = benderType;
            hp = benderHp;
            attack = benderAttack;
            defense = benderDefense;
            speed = benderSpeed;
            moves = benderMoves;
        }

        void attackBender(Bender& target, int moveIndex){
            int damage = round((get<1>(moves[moveIndex]) * (static_cast<float>(attack) / target.defense)));
            target.hp -= damage;
            cout << name << " used " << get<0>(moves[moveIndex]) << "!" << endl;
            cout << target.name << " took " << damage << " damage!" << endl;
        }

        bool isFainted(){
            if(hp <= 0){
                return true;
            }
            return false;
        }
        void displayStats(){
            cout << name << "(" << type << ")" << " - " << "HP: " << hp << ", " << "Attack: " << attack << ", " << "Defense: " << defense << ", " << "Speed: " << speed << endl;
            cout << "Moves: " << endl;
            for(int i = 0; i < moves.size(); i++){
                cout << get<0>(moves[i]) << " - " << get<1>(moves[i]);
                if (i != moves.size() - 1) {
                    cout << ", ";
                }
            }
            cout << endl << endl;
    }
};

int main(){
    Bender kael;
    kael.createBender("Kael", "Fire", 100, 58, 38, 88, {{"Ember Slash", 40}, {"Quick Jab", 30}, {"Focus", 0}, {"Flame Surge", 70}});
    kael.displayStats();

    Bender mira;
    mira.createBender("Mira", "Water", 92, 50, 45, 60, {{"Water Whip", 35}, {"Tide Push", 25}, {"Mist Veil", 0}, {"Tidal Wave", 60}});
    mira.displayStats();

    kael.attackBender(mira, 0);
    mira.displayStats();

    cout << "Mira Fainted: " << boolalpha << mira.isFainted() << endl;
}