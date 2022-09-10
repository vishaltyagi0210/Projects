#include<iostream>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<string.h>
using namespace std;
//color functions
void yellow();
void white();
void reset();
void orange();
void red();
void blue();
void green();
//global
int gamers_variable;
//some constant declarations
const int row = 3;
const int column = 3;
//some global declared variables for better functions calling
char name[30];
int switch_case;
int check = 1;
int player = 0;
char mark;
char show_off[row][column] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
char array[row][column] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int board[row][column] = {{2,2,2},{2,2,2},{2,2,2}};
//variables for status display

//class for players history
class player_class{
    private:
    char name[30];
    int player_wins = 0 , player_lose = 0 , player_draws = 0 , Ai_computer_wins = 0 , Ai_computer_lose = 0 , Ai_computer_draws = 0 , cheater_computer_wins = 0 , cheater_computer_lose = 0 , cheater_computer_draws = 0;

    public:
    void setname(){
        (gamers_variable>0)?
        cout<<"\n\n\t\tEnter new player name: ":
        cout<<"\n\n\t\tEnter your name: ";
        yellow();
        cin.getline(name,30);
        reset();
    }
    char* getname(){
        return name;
    }
    int get_totalplays(){
        return player_wins + player_lose + player_draws + Ai_computer_wins + Ai_computer_lose + Ai_computer_draws + cheater_computer_wins + cheater_computer_lose + cheater_computer_draws;
    }
        void print_winner_name(int switch_case);
        void status_display();
        void display_choices();
};



player_class gamers[10];

//functions declarations (line by line)
void sorting();
void show_all_players_data();
void add_member();
void display_intro();
// void display_choices();
void display();
void choose_player();
void choose_mark();
void taking_move(int*,int=0);
int is_place_empty(int , int);
void filling_move(int);
void computer_move_details_input();
void computer_first_move();
void computer_move(int);
int check_result();
// void print_winner_name(int);
void while_last_display_input_statement(int *while_case , int switch_case);
// void status_display();
void pause_screen();
void reset_all_game();



//main functio//////////////
int main(){
    system("cls");
    int only_once = 1;
    int while_case;
    display_intro();
    add_member(); // member adding by class
    main_menu: // goto variable
    system("cls");
    gamers[gamers_variable].display_choices();
    while((check && check > 0)){
        display();
        int move;
        switch (switch_case)
        {
            case_1: //goto variable
            case 1:
            {
                choose_player();
                choose_mark();
                taking_move(&move);
                filling_move(move);
                check = check_result();
                system("cls");
            } 
            break;
            
            case_2: //goto variable
            case 2:
            {
                if(only_once){
                computer_move_details_input();
                only_once--;
                }
                choose_player();
                choose_mark();
                taking_move(&move);
                if(player){
                filling_move(move);
                }
                check = check_result();
                system("cls");
            }
            break;
            
            case_3:  //goto variable
            case 3:
            {
                if(only_once){
                computer_move_details_input();
                only_once--;
                }
                int evil_or_not = 1;
                choose_player();
                choose_mark();
                taking_move(&move,evil_or_not);
                if(player){
                    filling_move(move);
                }
                check = check_result();
                system("cls");
            }
            break;
            
            case 4:  
            {
                system("cls");
                gamers[gamers_variable].status_display();
                cout<<"\n\n\n\n\t\t\tif you want to go on menu ";
                green();
                cout<<"press space ";
                reset();
                cout<<"\n\t\t\tor for exit "; 
                red();
                cout<<"press E";
                reset();
                cout<<endl;
                int tempp_ = getch();
                if(tempp_ == ' '){
                    goto main_menu;
                }
                else if(tempp_ == 'e' || tempp_ == 'E'){
                    exit(0);
                }
            }
            case 5:
            {
                system("cls");
                reset_all_game();
                gamers_variable++;
                cin.ignore();
                gamers[gamers_variable].setname();
                goto main_menu;
            }
            break;
            
            case 6:
            {
                system("cls");
                show_all_players_data();
                cout<<"\n\tpress something to continue";
                blue();
                cout<<"..............";
                reset();
                getch();
                system("cls");
                cout<<"\n\n\t\tPress 'S' for ";
                green();
                cout<<"Sorting";
                reset();
                cout<<"\n\t\tPress Space bar for ";
                blue();
                cout<<"main menu";
                reset();
                cout<<"\n\t\tPress (0) for ";
                red();
                cout<<"immediate exit";
                reset();
                cout<<"\n\t\t\t\t";
                int temp = getch();
                if(temp == 's' || temp == 'S'){
                    for(int i = 0; 1 ; i++){
                        system("cls");
                        sorting();
                        cout<<"\n\n\t\tPress Space bar for: ";
                        blue();
                        cout<<"Main menu\n";
                        reset();
                        cout<<"\t\tpress Enter for continue ";
                        blue();
                        cout<<"Sorting\n";
                        reset();
                        int temp = getch();
                        if(temp == ' '){
                            goto main_menu;
                        }
                    }
                    
                }
                else if(temp == ' '){
                    goto main_menu;
                }
                else if(temp == '0'){
                    exit(0);
                }
            }
        }
        
    }
    gamers[gamers_variable].print_winner_name(switch_case);

    //checking what player wants plays the game or not by calling function
    while_last_display_input_statement(&while_case,switch_case);
    if(while_case == 1 && switch_case == 1){
        //resetting all values
        reset_all_game();
        only_once = 1;
        display();
        goto case_1;
    }
    else if(while_case == 1 && switch_case == 2){
        //resetting all values
        reset_all_game();
        only_once = 1;
        display();
        goto case_2;
    }
    else if(while_case == 1 && switch_case == 3){
        //resetting all values
        reset_all_game();
        only_once = 1;
        display();
        goto case_3;
    }
    else if(while_case == 0){
        //resetting all values
        only_once = 1;
        reset_all_game();
        goto main_menu;
    }
    else if(while_case == 2){
        gamers[0].status_display();
        green();
        cout<<"\n\n\n\t\tTHANKYOU FOR PLAYING ";
        reset();
        cout<<name;
        cout<<"\n\n\t\tEnter any key to";
        yellow();
        cout<<".............";
        reset();
        //exit
        getch();
    }
}


//function definition
void show_all_players_data(){
    for(int i = 0; i<=gamers_variable; i++){
        gamers[i].status_display();
    }
}
void sorting(){
    player_class temp_[10];
    system("cls");
    cout<<"\n\n\t\tSorting with respect to\n";
    green();
    cout<<"\t\tPress 1: ";
    reset();
    cout<<"Names\n";
    green();
    cout<<"\t\tPress 2: ";
    reset();
    cout<<"Game play\n\n";
    cout<<"\tEnter your choice ";
    blue();
    cout<<gamers[gamers_variable].getname()<<": ";
    reset;
    int temp;
    cin>>temp;
    //copying data
    for(int i = 0; i<=gamers_variable; i++){
        temp_[i] = gamers[i];
    }
    if(temp == 1){
        for(int i = 0; i<=gamers_variable; i++){
            for(int j = 0; j<gamers_variable-i; j++){
                if(strcmp(gamers[j].getname() , gamers[j+1].getname()) > 0){
                    player_class temp = gamers[j];
                    gamers[j] = gamers[j+1];
                    gamers[j+1] = temp;
                }
            }
        }
    }
    else if(temp == 2){
        for(int i = 0; i<=gamers_variable; i++){
            for(int j = 0; j<gamers_variable-i; j++){
                    if(gamers[j].get_totalplays() < gamers[j+1].get_totalplays()){
                    player_class temp_1 = gamers[j];
                    gamers[j] = gamers[j+1];
                    gamers[j+1] = temp_1;
                }
            }
        }
    }
    system("cls");
    for(int i = 0; i<=gamers_variable; i++){
        gamers[i].status_display();
    }
    //reset as it is
    for(int i = 0; i<=gamers_variable; i++){
        gamers[i] = temp_[i];
    }
}

void add_member(){
    gamers[0].setname();
}

void display_intro(){
    yellow();
    cout<<"\n\n\t\t\t\t\tTIC TAC TOE\n";
    cout<<"\n";
    for(int i = 0; i<row; i++){
        cout<<"\t\t\t\t\t";
        for(int j = 0; j< column; j++){
            (j != column-1)?
            cout<<array[i][j]<<" | ":
            cout<<array[i][j];
        }
        cout<<endl;
    }
    reset();
    blue();
    cout<<"\n\n\t\t\t*Choose corospondent DIGIT for your move*\n";
    reset();
    cout<<"\n\tpress any key to continue";
    yellow();
    cout<<".......";
    reset();
    getch();
    system("cls");
}

void player_class::display_choices(){
    yellow();
    cout<<"\n\t\t\t\t\t\t\tCHOICES\n\n";
    reset();
    green();
    cout<<"\n\tPress 1: ";
    reset();
    cout<<"for playing with friend\n";
    green();
    cout<<"\tPress 2: ";
    reset();
    cout<<"for playing with AI computer\n";
    green();
    cout<<"\tPress 3: ";
    reset();
    cout<<"for playing with Cheater computer\n\n";
    blue();
    cout<<"\tPress 4: ";
    reset();
    cout<<"for checking your game status\n";
    blue();
    cout<<"\tPress 5: ";
    reset();
    cout<<"for Entering new player\n";
    blue();
    cout<<"\tPress 6: ";
    reset();
    cout<<"for Displaying all play history\n\n";
    cout<<"\t\tEnter your choice ";
    yellow();
    cout<<name<<": ";
    reset();
    cin>>switch_case;
    system("cls");
}

void display(){
    cout<<"\n\n";
    for(int i = 0; i<row; i++){
        cout<<"\t\t";
        for(int j = 0; j < column; j++){
            (j!=column-1)?
                cout<<show_off[i][j]<<" | ":
                cout<<show_off[i][j];
        }
        cout<<endl;
    }
    
}

void choose_player(){
    player = !player;
}

void choose_mark(){
    player?
        mark = 'o':
        mark = 'x';
}

void taking_move(int *move , int evil_or_not){
    switch (switch_case)
    {
        case 1:
        {
            if(player){
                cout<<"\n\t\tEnter your move ";
                yellow();
                cout<<gamers[gamers_variable].getname()<<": ";
                reset();
                cin>>*move;   
        }
            else{
                cout<<"\n\t\tEnter your move ";
                red();
                cout<<"opponent: ";
                reset();
                cin>>*move;
        }
        }
        break;
        
        case 2:
        {
            if(player){
                cout<<"\n\t\tEnter your move ";
                yellow();
                cout<<gamers[gamers_variable].getname()<<": ";
                reset();
                cin>>*move;
                return;
            }
            else{
                green();
                cout<<"\n\t\tAI";
                reset();
                cout<<" computer thinking";
                yellow();
                cout<<".....";
                reset();
                Sleep(1500);
                computer_move(evil_or_not);
                return;
            }
        }
        break;
        case 3:
        {
            if(player){
                cout<<"\n\t\tEnter your move ";
                yellow();
                cout<<gamers[gamers_variable].getname()<<": ";
                reset();
                cin>>*move;
                return;
            }
            else{
                red();
                cout<<"\n\t\tevil";
                reset();
                cout<<" computer thinking";
                yellow();
                cout<<".....";
                reset();
                Sleep(1500);
                computer_move(evil_or_not);
                return;
                return;
            }
        }
    }
}

int is_place_empty(int row , int column){
    if(array[row][column] != 'o' && array[row][column] != 'x'){
        return 1;
    }
    else{
        return 0;
    }
}

void filling_move(int move){
    for(int i = 0; i<row; i++){
        for(int j = 0; j <column; j++){
            int place = (3*i)+(j+1);
            if(move == place && is_place_empty(i,j)){
                show_off[i][j] = mark;
                array[i][j] = mark;
                board[i][j] = 1;
                return;
            }
            else if(move==place && is_place_empty(i,j) == 0){
                player = !player;
                return;
            }
        }
    }
}

void computer_move_details_input(){
    system("cls");
    cout<<"\n\n\tIf you want to take first move Press: ";
    green();
    cout<<"Enter.";
    reset();
    cout<<"\n\tIf you want that computer take first move Press: ";
    blue();
    cout<<"Space key.";
    reset();
    int a = getch();
    system("cls");
    if(a == ' '){
        computer_first_move();
        display();
    }
    else{
        display();
    }
}

void computer_first_move(){
    int temp_ , temp_2;
    srand(time(NULL));
    temp_ = rand()%3;
    temp_2 = rand()%3;
    array[temp_][temp_2] = 'x';
    board[temp_][temp_2] = 3;
    show_off[temp_][temp_2] = 'x';
}

void computer_move(int evil_or_not){
    int multi = 0 , max_multi = 0 , cordinate_i = 0 , cordinate_j = 0;
    //for row input by computer
    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            if(board[i][j] == 2){
                board[i][j] = 3;
                multi = board[i][0] * board[i][1] * board[i][2];
                if(multi == 27){
                    board[i][j] = 3;
                    array[i][j] = mark;
                    show_off[i][j] = mark;
                    return;
                
                }
                else if(max_multi < multi){
                    max_multi = multi;
                    cordinate_i = i;
                    cordinate_j = j;
                }
                board[i][j] = 2;
            }
            //for column input by computer
            if(board[j][i] == 2){
                board[j][i] = 3;
                multi = board[0][i] * board[1][i] * board[2][i];
                if(multi == 27){
                    board[j][i] = 3;
                    array[j][i] = mark;
                    show_off[j][i] = mark;
                    return;
                }
                else if(max_multi<multi){
                    max_multi = multi;
                    cordinate_i = j;
                    cordinate_j = i;
                }
                board[j][i] = 2;
            }
            //for diagonal
            if(i == j){
                if(board[i][j] == 2){
                    board[i][j] = 3;
                    multi = board[0][0] * board[1][1] * board[2][2];
                    if(multi == 27){
                        board[i][j] = 3;
                        array[i][j] = mark;
                        show_off[i][j] = mark;
                        return;
                    }
                    else if(max_multi<multi){
                        max_multi = multi;
                        cordinate_i = i;
                        cordinate_j = j;
                    }
                    board[i][j] = 2;
                }
            }
            //for right diagonal
            if(j == column-1-i){
                if(board[i][column-1-i] == 2){
                    board[i][column-1-i] = 3;
                    multi = board[0][2] * board[1][1] * board[2][0];
                    if(multi == 27){
                        cout<<"i am in";
                        board[i][column-1-i] = 3;
                        show_off[i][column-1-i] = mark;
                        array[i][column-1-i] = mark;
                        return;
                    }
                    else if(max_multi<multi){
                        max_multi = multi;
                        cordinate_i = i;
                        cordinate_j = column-1-i;
                    }
                    board[i][column-1-i] = 2;
                }
            }
        }
    }
    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            //code for resist player from winning
                //for row
            if(board[i][j] == 2){
                board[i][j] = 3;
                multi = board[i][0] * board[i][1] * board[i][2];
                if(multi == 3){
                    show_off[i][j] = mark;
                    board[i][j] = 3;
                    array[i][j] = mark;
                    //cheater computer code is also here
                    if(evil_or_not){
                        
                    }else{
                        return;
                    }
                }
                else if(max_multi < multi){
                    max_multi = multi;
                    cordinate_i = i; 
                    cordinate_j = j;
                }
                board[i][j] = 2;
            }
            //code for columns
            if(board[j][i] == 2){
                board[j][i] = 3;
                multi = board[0][i] * board[1][i] * board[2][i];
                if(multi == 3){
                    show_off[j][i] = mark;
                    board[j][i] = 3;
                    array[j][i] = mark;
                    //cheater computer code is here
                    if(evil_or_not){
                        
                    }else{
                        return;
                    }
                }
                else if(max_multi < multi){
                    max_multi = multi;
                    cordinate_i = j; 
                    cordinate_j = i;
                }
                board[j][i] = 2;
            }
            //for diagonal input
            if(i == j ){
                if(board[i][j] == 2){
                    board[i][j] = 3;
                    multi = board[0][0] * board[1][1] * board[2][2];
                    if(multi == 3){
                        board[i][j] = 3;
                        array[i][j] = mark;
                        show_off[i][j] = mark;
                        //code for cheater computer
                        if(evil_or_not){
                        
                        }else{
                            return;
                        }
                    }
                    else if(max_multi < multi){
                        max_multi = multi;
                        cordinate_i = i; 
                        cordinate_j = j;
                    }
                    board[i][j] = 2;
                }
            }
            //for right diagonal
            if(board[i][column-1-i] == 2){
                board[i][column-1-i] = 3;
                multi = board[0][2] * board[1][1] * board[2][0];
                if(multi == 3){
                    board[i][column-i-1] = 3;
                    array[i][column-1-i] = mark;
                    show_off[i][column-1-i] = mark;
                    if(evil_or_not){
                        
                    }else{
                        return;
                    }
                }
                else if(max_multi < multi){
                    max_multi = multi;
                    cordinate_i = i; 
                    cordinate_j = column-1-i;
                }
                board[i][column-i-1] = 2;
            }
        }
    }
        board[cordinate_i][cordinate_j] = 3;
        array[cordinate_i][cordinate_j] = mark;
        show_off[cordinate_i][cordinate_j] = mark;
}

int check_result(){
    for(int i = 0; i<row; i++){
        if((array[i][0] == array[i][1]) && (array[i][1] == array[i][2])){
            return 0;
        }
    }
    for(int j = 0; j<column; j++){
        if((array[0][j] == array[1][j]) && (array[1][j] == array[2][j])){
            return 0;
        }
    }
    //for diagonals
    if((array[0][0] == array[1][1]) && (array[1][1] == array[2][2])){
        return 0;
    }
    else if((array[0][2] == array[1][1]) && (array[1][1] == array[2][0])){
        return 0;
    }
    int temp = 0;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            if(is_place_empty(i,j) == 0){
                temp++;
            }
        }
    }
    if(temp == 9){
        return -1;
    }
    else{
        return 1;
    }
}

void player_class::print_winner_name(int switch_case){
    if(check == -1){
        blue();
        display();
        reset();
    }
    else if(player){
        green();
        display();
        reset();
    }
    else{
        red();
        display();
        reset();
    };

    switch (switch_case)
    {
        case 1:
        {
            if(check == -1){
            cout<<"\n\t\tmatch draw\n";
            pause_screen();
            player_draws++;
            }
            else if(player){
                green();
                cout<<"\n\t\t"<<name;
                reset();
                cout<<" you win\n";
                pause_screen();
                player_wins++;
            }
            else{
                red();
                cout<<"\n\t\t"<<name;
                reset();
                cout<<" you lose\n";
                pause_screen();
                player_lose++;
            }
        }
        break;
        
        case 2:
        {
            if(check == -1){
                cout<<"\n\t\tmatch draw\n";
                pause_screen();
                Ai_computer_draws++;
            }
            else if(player){
                green();
                cout<<"\n\t\t"<<name;
                reset();
                cout<<" you win\n";
                pause_screen();
                Ai_computer_wins++;
            }
            else{
                cout<<"\n\t\tAI Computer win\n";
                red();
                cout<<"\t\t"<<name;
                reset();
                cout<<" you lose\n";
                pause_screen();
                Ai_computer_lose++;
            }
        }
        break;
        
        case 3:
        {
            if(check == -1){
                cout<<"\n\t\tmatch draw\n";
                pause_screen();
                cheater_computer_draws++;
            }
            else if(player){
                green();
                cout<<"\n\t\t"<<name;
                reset();
                cout<<" you win\n";
                pause_screen();
                cheater_computer_wins++;
            }
            else{
                cout<<"\n\t\tCheater Computer win\n";
                red();
                cout<<"\t\t"<<name;
                reset();
                cout<<" you lose\n";
                pause_screen();
                cheater_computer_lose++;
            }
        }
    }
}

void while_last_display_input_statement(int *while_case , int switch_Case){
    switch (switch_case)
    {
        int goto_variable;
        case 1:
        {
            cout<<"\n\tFor playing again";
            green();
            cout<<" :PRESS 'Y'";
            reset();
            cout<<"\n\tFor main menu press ";
            blue();
            cout<<":SPACE KEY ~ ' '";
            reset();
            cout<<"\n\tFor emmidiate exit ";
            red();
            cout<<"PRESS (0)";
            reset();
            goto_variable = getch();
            system("cls");
            if(goto_variable == 'y' || goto_variable == 'Y'){
                *while_case = 1;
            }
            else if(goto_variable == ' '){
                *while_case = 0;
            }
            else if(goto_variable == '0'){
                *while_case = 2;
            }
        }
        break;
        
        case 2: 
        {
            cout<<"\n\tFor playing again with AI computer";
            green();
            cout<<" :PRESS 'Y'";
            reset();
            cout<<"\n\tFor main menu press ";
            blue();
            cout<<":SPACE KEY ~ ' '";
            reset();
            cout<<"\n\tFor emmidiate exit ";
            red();
            cout<<"PRESS (0)";
            reset();
            goto_variable = getch();
            system("cls");
            if(goto_variable == 'y' || goto_variable == 'Y'){
                *while_case = 1;
            }
            else if(goto_variable == ' '){
                *while_case = 0;
            }
            else if(goto_variable == '0'){
                *while_case = 2;
            }
        }
        break;
        
        case 3:
        {
            cout<<"\n\tFor playing again with AI computer";
            green();
            cout<<" :PRESS 'Y'";
            reset();
            cout<<"\n\tFor main menu press ";
            blue();
            cout<<":SPACE KEY ~ ' '";
            reset();
            cout<<"\n\tFor emmidiate exit ";
            red();
            cout<<"PRESS (0)";
            reset();
            goto_variable = getch();
            system("cls");
            if(goto_variable == 'y' || goto_variable == 'Y'){
                *while_case = 1;
            }
            else if(goto_variable == ' '){
                *while_case = 0;
            }
            else if(goto_variable == '0'){
                *while_case = 2;
            }
        }
        break;
    }
}

void player_class::status_display(){
    cout<<"\n\n\t\t\t"<<"Total matches played:";
        //telling scores for player opponent
            white();
            int total = player_draws+player_lose+player_wins+Ai_computer_draws+Ai_computer_lose+Ai_computer_wins+cheater_computer_draws+cheater_computer_lose+cheater_computer_wins;
            green();
            cout<<"\t~\t "<<total<<"\n";
            reset();
            yellow();
            cout<<"\t\t\t______________________\t\t___";
            reset();
            cout<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\tHere is your overall playing History ";
    yellow();
    cout<<name<<endl;
    blue();
    cout<<"\t\t\t\t\t\t\t_____________________________________________________________\n";
    reset();
    
        cout<<"\n\n\t\t\t"<<"__Against:__";
        reset();
        green();
        cout<<"\t\t"<<"__WINS__";
        reset();
        red();
        cout<<"\t\t\t"<<"__LOSE__";
        reset();
        blue();
        cout<<"\t\t\t"<<"__DRAW__\n\n\n";
        reset();
        cout<<"\t\t\t"<<"Human:";
        //telling scores for player opponent
        if(player_wins == 0 && player_draws ==0 && player_lose == 0){
            white();
            cout<<"\t\t\t\t\t"<<"_first you have to choose and play this section_\n";
            reset();
        }
        else if(player_draws > 0 || player_lose > 0 || player_wins > 0){
            green();
            cout<<"\t\t\t"<<"   "<<player_wins;
            reset();
            red();
            cout<<"\t\t\t\t"<<"   "<<player_lose<<" ";
            reset();
            blue();
            cout<<"\t\t\t\t"<<"   "<<player_draws<<"\n";
            reset();
        }
        cout<<"\n\t\t\t"<<"AI computer:";
        //telling scores for player opponent
        if(Ai_computer_draws == 0 && Ai_computer_lose == 0 && Ai_computer_wins == 0){
            white();
            cout<<"\t\t\t\t"<<"_first you have to choose and play this section_\n";
            reset();
        }
        else if(Ai_computer_wins > 0 || Ai_computer_draws > 0 || Ai_computer_lose > 0){
            green();
            cout<<"\t\t"<<"   "<<Ai_computer_wins;
            reset();
            red();
            cout<<"\t\t\t\t"<<"   "<<Ai_computer_lose<<" ";
            reset();
            blue();
            cout<<"\t\t\t\t"<<"   "<<Ai_computer_draws<<"\n";
            reset();
        }
        cout<<"\n\t\t\t"<<"Cheater computer:";
        //telling scores for player opponent
        if(cheater_computer_draws == 0 && cheater_computer_lose == 0 && cheater_computer_wins == 0){
            white();
            cout<<"\t\t\t"<<"_first you have to choose and play this section_\n";
            reset();
        }
        else if(cheater_computer_wins > 0 || cheater_computer_lose > 0 || cheater_computer_draws > 0){
            green();
            cout<<"\t"<<"   "<<cheater_computer_wins;
            reset();
            red();
            cout<<"\t\t\t\t"<<"   "<<cheater_computer_lose<<" ";
            reset();
            blue();
            cout<<"\t\t\t\t"<<"   "<<cheater_computer_draws<<"\n";
            reset();
        }
        yellow();
        cout<<"________________________________________________________________________________________________________________________________________\n\n";
        reset();
}

void pause_screen(){
    cout<<"\n\tPlease wait";
    cout<<"\n\tprocessing";
    blue();
    cout<<"............";
    reset();
    Sleep(3100);
    system("cls");
}

void reset_all_game(){
char reset_var = '1';
    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            show_off[i][j] = ' ';
            array[i][j] = reset_var;
            board[i][j] = 2;
            reset_var++;
        }
    }
    check = 1 , player = 0;

}



//color definition
void yellow() {
    printf("\033[1;33m");
}
void white() {
    printf("\033[0;37m");
}
void reset() {
    printf("\033[0m");
}
void orange() {
    printf("\033[38;2;255;165;0m");
}
void red() {
    printf("\033[1;31;1m");
}
void blue() {
    printf("\033[0;34m");
}
void green() {
    printf("\033[0;32m");
}