#include<iostream> 
#include<string> 
#include<map>
#include<vector>
#include<cstdlib>
#include<sstream>

using namespace std;

#define H1 6
#define H2 10
#define H3 15
#define no -1
vector<string> empty = {""};
int map1_link[4][9] = {1,3,4,6,-1,-1,-1,-1,-1,-1,2,-1,4,5,-1,-1,3,7,-1,0,-1,1,2,-1,3,-1,-1,-1,-1,1,7,3,4,-1,8,-1};

//  0   1   2   3   4   5   6   7   8
//  1   3   4   6   -1  -1  -1  -1  -1
//  -1  2   -1  4   5   -1  -1  3   7
//  -1  0   -1  1   2   -1  3   -1  -1
//  -1  -1  1   7   3   4   -1  8   -1
string map1_name[9] = {"lobby","corridor","kitchen","living room","dining room","balcony","bedroom 1","restroom","bathing room"};
/*
                 north
                   0
                   ^
                   |
                   |
 west    3 < — — O — — > 1    east
                   |
                   |
                   v
                   2
                 south
*/
class ROOM
{
private:
    int room_index;
    int room_access[4];
    string room_name;
public:
    ROOM(){}
    ROOM(int index, string name);
    void welcome_message();
    int get_access_roomindex(int i);
    void set_access_room(int direction, int goal_room_index){ room_access[direction] = goal_room_index;}
    int get_room_index() { return room_index; }
    int isFullNeighbour();
    string get_room_name() { return room_name; }
};

class castle
{
private:
    ROOM* room_queue;
    int entrance;
    int room_num;       //1
    int room_princess;  //2
    int room_evil;      //3
    // int stairs;      //4
public:
    castle(int hardmode);
        // initialized, print welcome messeges
        // room_num is related to hardmode;
        // room_princess comes from randomint, the same as room_evil

    ROOM get_randomRoom();
    ROOM get_room(int index);
    int get_info(int infotype);
    friend int check(ROOM room);
    friend void player::move(castle game_map, int direction);

    ~castle() { delete[] room_queue; }
};

class player
{
private:
    string P_name;
    int Position;
    int with_princess;
    int steps;

public:
    player(string name);
        // initial welcome_message
    void move(castle game_map, int direction);
    int get_Position() {return Position;}
    int get_princess_status() {return with_princess;}
    int get_steps() {return steps;}
};

int randomInt(int max)
{
    int a = rand();
    return a%max+1;
}
int randomInt(int min, int max)
{
    int a = rand();
    return a%(max-min)+1+min;
}

int check(player P, castle C)
{
    int position = P.get_Position();
    int bring_Princess = P.get_princess_status();
    int evil_Position = C.get_info(3);
    int princess_Position = C.get_info(2);
    ROOM ent = C.get_room(0);

    //checking
    cout<<"you are now checking this room" << endl;

    if(position == evil_Position)
    {
        return -1;  // encounter evil! gg!!!
    }
    if(position == princess_Position)
    {
        return 1;   // get princess
    }
    if(position == ent.get_room_index() && bring_Princess)
    {
        return 2;   // successfully save the princess
    }
    else{
        return 0;   // on going
    }
}

// <class> ROOM function part
ROOM::ROOM(int index, string name): room_index(index),room_name(name)
{
    for(int i = 0; i<4;i++) room_access[i] = -1;
}

void ROOM::welcome_message()
{
    cout<<"welcome to the room: "<< this->room_name <<endl;
    cout<<"you can do sth here"<<endl;
    cout<<"now you can go to: ";
    if(this->room_access[0] != -1) cout<<"north ";
    if(this->room_access[1] != -1) cout<<"east ";
    if(this->room_access[2] != -1) cout<<"south ";
    if(this->room_access[3] != -1) cout<<"west ";
    cout<<endl;
}

int ROOM::get_access_roomindex(int i)
{
    return this->room_access[i];
}

int ROOM::isFullNeighbour()
{
    for(int i = 0;i<4;i++)
    {
        if(this->room_access[i] == -1)
        {
            return 1;
        }
    }
    return 0;
}

// <class> castle function part
castle::castle(int hardmode)
{
    if(hardmode == 1) room_num = 9;
    if(hardmode == 2) room_num = 10;
    if(hardmode == 3) room_num = 15;
    entrance = 0;
    room_princess = randomInt(room_num/2,room_num);
    room_evil = randomInt(room_num/2,room_num);
    while( room_evil == room_princess )
    {
        room_evil = randomInt(room_num / 2, room_num);
    }

    room_queue = new ROOM[room_num];

    for( int i = 0; i < room_num; i++)
    {
        room_queue[i] = ROOM(i, map1_name[i]);
        for( int j = 0; j < 4; j++)
        {
            room_queue->set_access_room(j,map1_link[j][i]);
        }
    }

    cout<<"castle initialized"<<endl;
}

ROOM castle::get_randomRoom()
{
    int tmp = randomInt(this->room_num);
    return room_queue[tmp];
}

ROOM castle::get_room(int index)
{
    return room_queue[index];
}

int castle::get_info(int infotype)
{
    switch(infotype)
    {
    case 1:
        return this->room_num;
        break;
    case 2:
        return this->room_princess;
        break;
    case 3:
        return this->room_evil;
        break;
    default:
        break;
    }
}

// <class> player function part
player::player(string name = "default"):P_name(name)
{
    Position = 0;
    with_princess = 0;
    steps = 0;
}

void player::move(castle game_map,int direction)
{
    Position = game_map.get_room(Position).get_access_roomindex(direction);
    steps++;
}

string& trim(string &s) 
{
    if (s.empty()) 
    {
        return s;
    }
 
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

vector<string> command2string(string line)
{
    if ( line.size() <1 ) return empty;
    istringstream f(line);
    vector<string> a;
    string w;
    while (getline(f, w, ' ') ) {
        trim(w);
        a.push_back(w);
    }
    return a;
}
int main()
{
    cout<<"Welcome to the game of Advancture! Your Mission is to save the Princess."<<endl;
    cout<<"However, there lives a monster in the castle, so you need to avoid meeting it"<<endl;
    cout<<"now, start you own advanture!"<<endl;
    cout<<"Press any key to start!"<<endl;
    getchar();
    cout<<"please input your nickname"<<endl;
    
    string nickname;
    cin>>nickname;
    player P1(nickname);
    
    int status = 0;
    while(1)
    {

    }

}