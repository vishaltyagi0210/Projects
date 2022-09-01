#include<iostream>
#include<string>
#include<conio.h>
#include<time.h>
#include<windows.h>
using namespace std;
//for array;
const int row = 3;
const int column = 3;

//color functions
void yellow();
void white();
void reset();
void orange();
void red();
void blue();
void green();
//functions for additionl text


//sub functions declarations / common functions for checking winner  (last mai hai ye saare).
int row_checking(char[row][column] , int* , int*);
int column_checking(char[row][column] , int* , int*);
int left_diagonal_checking(char[row][column] , int* , int*);
int right_diagonal_checking(char[row][column], int* , int*);
int check_draw(char[row][column]);
void display_status(char*,int,int,int,int,int,int,int,int,int,int,int,int);

//majorly common functions
void display(char[row][column]);
int display_choices(char*);

//1.function declaraation for (two player)
void add_moves(char[row][column] , char , int*);
int check_winner(char[row][column],int*,int*);

//2.function declaration for smart computer playing game
void computer_first_move(char[row][column]);
void add_moves_smartcomputer_and_player(char[row][column],char);
    //sub function of add_move_smartcomputer_and_player function
    int computer_moves(char[row][column]);

//3.function declaration for Ai computer
void Aicomputer_first_move(char[row][column]);
void add_moves_Aicomputer_and_player(char[row][column],char);
    //sub function of Aicomputer_first_move
    int Ai_computer_moves(char[row][column]);

//4.function declaration for cheater computer
void cheater_computer_first_move(char[row][column]);
void add_moves_cheatercomputer_and_player(char[row][column],char);
    //sub function of cheater computer
    int cheater_computer_moves(char[row][column]);


//main function
int main(){
    char name[30];
    int two_player_win = 0, two_player_lose = 0 ,two_player_draw = 0 , smart_computer_wins = 0 ,smart_computer_lose = 0 , smart_computer_draw = 0 , ai_computer_wins = 0, ai_computer_lose = 0 , ai_computer_draw = 0 , cheater_computer_wins = 0 , cheater_computer_lose = 0 , cheater_computer_draw = 0;
    int switch_case;
    int temp = 0;
    char move;
    int player_1 = 1 , player_2 = 1 , check_win = 1;
    char while_case;
    // putting loop for this process continue until user wants to exit;
    do{
        system("cls");
        char array[row][column] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
        //display choices by calling function.
        switch_case = display_choices(name);
        switch (switch_case){
        
        case 1:
        {
            system("cls");
            display(array);
            for(int i = 0; 1 ; i++){
                check_win = check_winner(array,&player_1,&player_2);
                if(check_win == 0){
                    break;
                };
            //taking moves from player.
                if(temp==0){
                    cout<<"Enter your move ";
                    yellow();
                    cout<<name;
                    reset();
                    cout<<": ";
                }
                else{
                    cout<<"Enter your move ";
                    red();
                    cout<<"opponent: ";
                    reset();
                    cout<<": ";
                }
                cin>>move;
                system("cls");
                cout<<endl;
            //replacing 1,2...from player's entered o and x
                add_moves(array,move,&temp);
                display(array);
            };

            //finding who won with the help of pointers player_1 and player_2;
            if(player_1 == 0){
                green();
                cout<<"congratulation ";
                yellow();
                cout<<name<<" ";
                reset();
                cout<<"you win\n";
                two_player_win++;
            }
            else if(player_2 == 0){
                cout<<"player 2 wins 'x'\n";
                two_player_lose++;
            }
            else{
                blue();
                cout<<"match draw.\n";
                reset();
                two_player_draw++;
            }
        }
        break;
        case 2:
        {
            system("cls");
            int check_win_cond;
            player_1 = 1;
            int computer = 1;
            cout<<"if you want to play first press: ";
            green();
            cout<<"enter ";
            reset();
            cout<<"or let computer play first by "; 
            green();
            cout<<"pressing space....";
            reset();
            char a;
            a = getch();
            system("cls");
            if(a == ' '){
                computer_first_move(array);
            }
            display(array);

            //loop for calling functions...........
            for(int i = 0; ; i++){
            check_win_cond = check_winner(array,&player_1,&computer);
            if(check_win_cond == 0){
                break;
            }
            cout<<"Enter your move ";
            yellow();
            cout<<name<<" ";
            reset();
            cin>>move;
            add_moves_smartcomputer_and_player(array,move);
            system("cls");
            display(array);
            }
            //checking who won and increment the variables
            if(player_1 == 0){
                green();
                cout<<"congratulations ";
                yellow();
                cout<<name;
                reset();
                cout<<" you win";
                smart_computer_wins++;
            }
            else if(computer == 0){
                red();
                cout<<"computer is winner\n";
                reset();
                smart_computer_lose++;
            }
            else{
                blue();
                cout<<"maatchh draw\n";
                reset();
                smart_computer_draw++;
            }
        }
        break;/////

        case 3: 
        {
            system("cls");
            int check_win_cond;
            player_1 = 1;
            int computer = 1;
            cout<<"Shortly let me tell you the basic difference between AI and Smart computer so that you can easily understand it \nFor example: you enter your 'o' on cordinates (0,0),(0,1) and co incidently 'x' are on cordinates (0,2),(1,2) so ,...\nIn smart computer case: it will resist you from winning by putting x on (0,1) index but Ai computer don't resist you from winning instead it will put another x on (2,1) and win the game\n\nHope you will understand what did i say\nstart the game by pressing any character from  the keyboard";
            getch();
            system("cls");
            cout<<"\nif you want to play first press: ";
            green();
            cout<<"enter ";
            reset();
            cout<<"or let AI_computer play first by "; 
            green();
            cout<<"pressing space....";
            reset();
            char a;
            a = getch();
            system("cls");
            if(a == ' '){
                Aicomputer_first_move(array);
            }
            display(array);
            //loop for calling functions......
            for(int i = 0; ; i++){
            check_win_cond = check_winner(array,&player_1,&computer);
            if(check_win_cond == 0){
                break;
            }
            cout<<"Enter your move ";
            yellow();
            cout<<name<<" ";
            reset();
            cin>>move;
            add_moves_Aicomputer_and_player(array,move);
            system("cls");
            display(array);
            }
            if(player_1 == 0){
                green();
                cout<<"congratulations ";
                yellow();
                cout<<name;
                reset();
                cout<<" you win";
                ai_computer_wins++;
                
            }
            else if(computer == 0){
                red();
                cout<<"computer is winner\n";
                reset();
                ai_computer_lose++;
            }
            else{
                blue();
                cout<<"maatchh draw\n";
                reset();
                ai_computer_draw++;
            }
        }
        break;

        case 4:
        {
            system("cls");
            int check_win_cond;
            player_1 = 1;
            int computer = 1;
            cout<<"if you want to play first press: ";
            green();
            cout<<"enter ";
            reset();
            cout<<"or let cheater computer play first by "; 
            green();
            cout<<"pressing space....";
            reset();
            char a;
            a = getch();
            system("cls");
            if(a == ' '){
                cheater_computer_first_move(array);
            }
            display(array);
            //for loop for calling function again and again
            for(int i = 0; ; i++){
            check_win_cond = check_winner(array,&player_1,&computer);
            if(check_win_cond == 0){
                break;
            }
            cout<<"Enter your move ";
            yellow();
            cout<<name<<" ";
            reset();
            cin>>move;
            add_moves_cheatercomputer_and_player(array,move);
            system("cls");
            display(array);
            }
            if(player_1 == 0){
                green();
                cout<<"congratulations ";
                yellow();
                cout<<name;
                reset();
                cout<<" you win";
                cheater_computer_wins++;
                
                
            }
            else if(computer == 0){
                red();
                cout<<"computer is winner\n";
                reset();
                cheater_computer_lose++;
            }
            else{
                blue();
                cout<<"maatchh draw\n";
                reset();
                cheater_computer_draw++;
            }
        }
        break;

        case 5: 
        {
            display_status(name,two_player_win,two_player_lose,smart_computer_wins,smart_computer_lose,two_player_draw,smart_computer_draw,ai_computer_wins,ai_computer_lose,ai_computer_draw,cheater_computer_wins,cheater_computer_lose,cheater_computer_draw);
            getch();
            exit(0);
        }
        }
        //while loop stuff
        green();
        cout<<"Thank you for playing with us\n\n";
        reset();
        cout<<"Press any key to ";
        red();
        cout<<"exit ";
        reset();
        cout<<"and press ";
        green();
        cout<<"Space bar";
        reset();
        cout<<" to play again....\n";
        while_case = getch();
    }while(while_case == ' ');
    switch_case != 5?
    display_status(name,two_player_win,two_player_lose,smart_computer_wins,smart_computer_lose , two_player_draw , smart_computer_draw,ai_computer_wins,ai_computer_lose,ai_computer_draw,cheater_computer_wins,cheater_computer_lose,cheater_computer_draw):exit(0);
}


//1.function declaration for player to player game;//////////////////////////////
void add_moves(char array[3][3] , char move , int *temp){
    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            if(array[i][j] == move && *temp){
                array[i][j] = 'x';
                *temp = 0;
            }
            else if(array[i][j] == move && *temp == 0){
                array[i][j] = 'o';
                *temp = 1;
            }
        }
    }
}

//2./////////////////////////////////////////////////////function definition for smart - computer and player play//////////////////////////////////////////

    //code for first move by computer if user wants;
    void computer_first_move(char array[row][column]){
        srand(time(NULL));
        int random = rand()%3;
        int random_ = rand()%3;
        array[random][random_] = 'x';
    };

    //function for taking moves input from player and give computer move also
    void add_moves_smartcomputer_and_player(char array[3][3], char move){
        int j , tempp = 0;
        for(int i = 0; i<row; i++){
            for(j = 0; j<column; j++){
                if(array[i][j] == move){
                    array[i][j] = 'o';
                    computer_moves(array);
                    tempp = 1;
                    break;
                }
                }
                if(tempp){
                    break;
                }
            }
        }
    
    //function for resisting player to win 
    int computer_moves(char array[row][column]){
        int i = 0 , j = 0;
    //code for diagonals
        i = 0 , j = 0;
        //code for left diagonal from (up to down)
        if(array[i][j] == 'o' && array[i+1][j+1] == 'o' &&  (array[i+2][j+2] != 'x' && array[i+2][j+2] != 'o')){
            array[i+2][j+2] = 'x';
            return 0;
        }
        //code for left diagonal from (down to up)
        else if(array[i+1][j+1] == 'o' && array[i+2][j+2] == 'o' &&  (array[i][j] != 'x' && array[i][j] != 'o')){
            array[i][j] = 'x';
            return 0;
        }
        //code for left diagonal middle 
        else if(array[i][j] == 'o' && array[i+2][j+2] == 'o' && (array[i+1][j+1] != 'x' && array[i+1][j+1] != 'o')){
            array[i+1][j+1] = 'x';
            return 0;
        }
        //code for right diagonal from (up to down)
        else if(array[i][j+2] == 'o' && array[i+1][j+1] == 'o' && (array[i+2][j] != 'x' && array[i+2][j] != 'o')){
            array[i+2][j] = 'x';
            return 0;
        }
        //code for right diagonal from (down to up)
        else if(array[i+2][j] == 'o' && array[i+1][j+1] == 'o' && (array[i][j+2] != 'x' && array[i][j+2] != 'o')){
            array[i][j+2] = 'x';
            return 0;
        }
        //code for right diagonal middle
        else if(array[i][j+2] == 'o' && array[i+2][j] == 'o' && (array[i+1][j+1] != 'x' && array[i+1][j+1] != 'o')){
            array[i+1][j+1] = 'x';
            return 0;
        }
    
    //code for rows;
        i = 0 , j = 0;
        for(i = 0; i<row; i++){
        //code for rows (1,2) , (4,5), (7,8) from (left to right)
            if(array[i][j] == 'o' && array[i][j+1] == 'o' && (array[i][j+2] != 'x' && array[i][j+2] != 'o')){
                array[i][j+2] = 'x';
                return 0;
            }
        //code for rows (2,3) , (4,5) , (6,7) from (right to left)
            else if(array[i][j+2] == 'o' && array[i][j+1] =='o' && (array[i][j] != 'x' && array[i][j] != 'o')){
                array[i][j] = 'x';
                return 0;
            }
        //code for mid line from row
            if(array[i][j] == 'o' && array[i][j+2] == 'o' && (array[i][j+1] != 'o' && array[i][j+1] != 'x')){
                array[i][j+1] = 'x';
                return 0;
            }
        }
    
    //code for columns;
        i = 0 , j = 0;
        for(j = 0; j<column; j++){
            if(array[i][j] == 'o' && array[i+1][j] == 'o' && (array[i+2][j] != 'x' && array[i+2][j] != 'o')){
                array[i+2][j] = 'x';
                return 0;
            }
            else if(array[i+2][j] == 'o' && array[i+1][j] == 'o' && (array[i][j] != 'x' && array[i][j] != 'o')){
                array[i][j] = 'x';
                return 0;
            }
            //code for mid line from column 
            else if(array[i][j] == 'o' && array[i+2][j] == 'o' && (array[i+1][j] != 'o' && array[i+1][j] != 'x')){
                array[i+1][j] = 'x';
                return 0;
            }
        }
    //code for computer react on single moves by user
        //for row 1,2 but it excludes row 3 because of j+1 logic;
        i = 0 , j = 0;
        for(i = 0; i<row; i++){
            for(j = 0; j<column-1; j++){
                if(array[i][j] == 'o' && (array[i][j+1] != 'x' && array[i][j+1] != 'o') || (array[1][1] != 'o' && array[1][1] != 'x') || (array[i-1][j] != 'o' && array[i-1][j]!= 'x' && i != 0) || (array[i+1][j] != 'o' && array[i+1][j] != 'x' && i != 3) || (array[i][j+2] != 'o' && array[i][j+2] != 'x')){
                    if(array[i][j+1] != 'x' && array[i][j+1] != 'o'){
                        array[i][j+1] = 'x';
                        return 0;
                    }
                    else if(array[1][1] != 'o' && array[1][1] != 'x'){
                        array[1][1] = 'x';
                        return 0;
                    }
                    else if(array[i-1][j] != 'o' && array[i-1][j]!= 'x' && i != 0){
                        array[i-1][j] = 'x';
                        return 0;
                    }
                    else if(array[i+1][j] != 'o' && array[i+1][j] != 'x' && i != 3){
                        array[i+1][j] = 'x';
                        return 0;
                    }
                    else{
                        array[i][j+2] = 'x';
                        return 0;
                    }
                }
                
            }
        }
        //for column 3 but it excludes row 3 element because of i+1 logic
        i = 0, j = 0;
        for(int i = 0; i<row-1; i++){
            if(array[i][j+2] == 'o' && ((array[i+1][j+2] != 'o' && array[i+1][j+2] != 'x') || (array[1][1] != 'o' && array[1][1] != 'x') || (array[i-1][j+1] != 'x' && array[i-1][j+1] != 'o'))){
                if(array[1][1] != 'o' && array[1][1] != 'x'){
                    array[1][1] = 'x';
                    return 0;
                }
                else if(array[i+1][j+2] != 'o' && array[i+1][j+2] != 'x'){
                    array[i+1][j+2] = 'x';
                    return 0;
                }
                else if(array[i-1][j+1] != 'o' && array[i-1][j+1] != 'x'){
                    array[i-1][j+1] = 'x';
                    return 0;
                }
            }
        }
        //for element (2,2)
        i = 0 , j = 0;
        if(array[2][2] == 'o' && ((array[1][2] != 'o' && array[1][2] != 'x') || (array[1][1] != 'o' && array[1][1] != 'x'))){
            if((array[1][1] != 'o' && array[1][1] != 'x')){
            array[1][1] = 'x';
            }
            else{
                array[1][2] = 'x';
            }
        }
    }

//3.////////////////////////////////////////////////////function declaration for Ai compute./////////////////////////////////////////
    //function for first move
    void Aicomputer_first_move(char array[row][column]){
        srand(time(NULL));
        int random = rand()%3;
        int random_ = rand()%3;
        array[random][random_] = 'x';
    };

    //code for moves
    void add_moves_Aicomputer_and_player(char array[3][3] , char move){
    int j , tempp = 0;
    for(int i = 0; i<row; i++){
        for(j = 0; j<column; j++){
            if(array[i][j] == move){
                array[i][j] = 'o';
                Ai_computer_moves(array);
                tempp = 1;
                break;
            }
            }
            if(tempp){
                break;
            }
        }
    }

    //code for ai logic to play competatively with the player.
    int Ai_computer_moves(char array[row][column]){
        int i = 0 , j = 0;
    //code for diagonals
        i = 0 , j = 0;
        //Ai computer wants to win in diagonal condition from(up to down) left
        if(array[i][j] == 'x' && array[i+1][j+1] == 'x' && (array[i+2][j+2] != 'x' && array[i+2][j+2] != 'o')){
            array[i+2][j+2] = 'x';
            return 0;
        }
        //Ai computer wants to win in diagonal condition from (down to up) left
        else if (array[i+1][j+1] == 'x' && array[i+2][j+2] == 'x' &&  (array[i][j] != 'x' && array[i][j] != 'o')){
            array[i][j] = 'x';
            return 0;
        }
        //ai computer wants to win left diagonal middle
        else if (array[i][j] == 'x' && array[i+2][j+2] == 'x' && (array[i+1][j+1] != 'x' && array[i+1][j+1] != 'o')){
            array[i+1][j+1] = 'x';
            return 0;
        }
        //ai computer wants to win in right diagonal from (up to down)
        else if(array[i][j+2] == 'x' && array[i+1][j+1] == 'x' && (array[i+2][j] != 'x' && array[i+2][j] != 'o')){
            array[i+2][j] = 'x';
            return 0;
        }
        //ai computer want to win in right diagonal from (down to up)
        else if(array[i+2][j] == 'x' && array[i+1][j+1] == 'x' && (array[i][j+2] != 'x' && array[i][j+2] != 'o')){
            array[i][j+2] = 'x';
            return 0;
        }
        //ai computer code for right diagonal middle
        else if(array[i][j+2] == 'x' && array[i+2][j] == 'x' && (array[i+1][j+1] != 'x' && array[i+1][j+1] != 'o')){
            array[i+1][j+1] = 'x';
            return 0;
        };
        //code for left diagonal from (up to down)
        if(array[i][j] == 'o' && array[i+1][j+1] == 'o' &&  (array[i+2][j+2] != 'x' && array[i+2][j+2] != 'o')){
            array[i+2][j+2] = 'x';
            return 0;
        }
        //code for left diagonal from (down to up)
        else if(array[i+1][j+1] == 'o' && array[i+2][j+2] == 'o' &&  (array[i][j] != 'x' && array[i][j] != 'o')){
            array[i][j] = 'x';
            return 0;
        }
        //code for left diagonal middle 
        else if(array[i][j] == 'o' && array[i+2][j+2] == 'o' && (array[i+1][j+1] != 'x' && array[i+1][j+1] != 'o')){
            array[i+1][j+1] = 'x';
            return 0;
        }
        //code for right diagonal from (up to down)
        else if(array[i][j+2] == 'o' && array[i+1][j+1] == 'o' && (array[i+2][j] != 'x' && array[i+2][j] != 'o')){
            array[i+2][j] = 'x';
            return 0;
        }
        //code for right diagonal from (down to up)
        else if(array[i+2][j] == 'o' && array[i+1][j+1] == 'o' && (array[i][j+2] != 'x' && array[i][j+2] != 'o')){
            array[i][j+2] = 'x';
            return 0;
        }
        //code for right diagonal middle
        else if(array[i][j+2] == 'o' && array[i+2][j] == 'o' && (array[i+1][j+1] != 'x' && array[i+1][j+1] != 'o')){
            array[i+1][j+1] = 'x';
            return 0;
        };
    
    //code for rows;
        i = 0 , j = 0;
        if(array[1][0] == 'x' && array[1][1] == 'x' && (array[1][2] != 'x' && array[1][2] != 'o')){
                array[1][2] = 'x';
                return 0;
            }
        for(i = 0; i<row; i++){
    //ai code for rows
        //ai code for rows(1,2) (4,5)(6,7)
        if(array[i][j] == 'x' && array[i][j+1] == 'x' && (array[i][j+2] != 'x' && array[i][j+2] != 'o')){
                array[i][j+2] = 'x';
                return 0;
            }
        //ai code for rows (2,3)(4,5)(6,7) from right to left
        else if(array[i][j+2] == 'x' && array[i][j+1] =='x' && (array[i][j] != 'x' && array[i][j] != 'o')){
                array[i][j] = 'x';
                return 0;
            }
        //ai code for mid line rows
        else if(array[i][j] == 'x' && array[i][j+2] == 'x' && (array[i][j+1] != 'o' && array[i][j+1] != 'x')){
                array[i][j+1] = 'x';
                return 0;
            };
        //code for rows (1,2) , (4,5), (7,8) from (left to right)
            if(array[i][j] == 'o' && array[i][j+1] == 'o' && (array[i][j+2] != 'x' && array[i][j+2] != 'o')){
                array[i][j+2] = 'x';
                return 0;
            }
        //code for rows (2,3) , (4,5) , (6,7) from (right to left)
            else if(array[i][j+2] == 'o' && array[i][j+1] =='o' && (array[i][j] != 'x' && array[i][j] != 'o')){
                array[i][j] = 'x';
                return 0;
            }
        //code for mid line from row
            else if(array[i][j] == 'o' && array[i][j+2] == 'o' && (array[i][j+1] != 'o' && array[i][j+1] != 'x')){
                array[i][j+1] = 'x';
                return 0;
            }
        }
    
    //code for columns;
        i = 0 , j = 0;
        if(array[i][j+1] == 'x' && array[i+1][j+1] == 'x' && (array[i+2][j+1] != 'x' && array[i+2][j+1] != 'o')){
                array[i+2][j+1] = 'x';
                return 0;
        }
        for(j = 0; j<column; j++){
            //ai code for column from up to down
            if(array[i+2][j] == 'x' && array[i+1][j] == 'x' && (array[i][j] != 'x' && array[i][j] != 'o')){
                array[i][j] = 'x';
                return 0;
            }
            else if(array[i][j] == 'x' && array[i+1][j] == 'x' && (array[i+2][j] != 'x' && array[i+2][j] != 'o')){
                array[i+2][j] = 'x';
                return 0;
            }
            else if(array[i][j] == 'x' && array[i+2][j] == 'x' && (array[i+1][j] != 'o' && array[i+1][j] != 'x')){
                array[i+1][j] = 'x';
                return 0;
            };
            if(array[i][j] == 'o' && array[i+1][j] == 'o' && (array[i+2][j] != 'x' && array[i+2][j] != 'o')){
                array[i+2][j] = 'x';
                return 0;
            }
            else if(array[i+2][j] == 'o' && array[i+1][j] == 'o' && (array[i][j] != 'x' && array[i][j] != 'o')){
                array[i][j] = 'x';
                return 0;
            }
            //code for mid line from column 
            else if(array[i][j] == 'o' && array[i+2][j] == 'o' && (array[i+1][j] != 'o' && array[i+1][j] != 'x')){
                array[i+1][j] = 'x';
                return 0;
            }
        }
    //code for computer react on single moves by user
        //for row 1,2 but it excludes row 3 because of j+1 logic;
        i = 0 , j = 0;
        for(i = 0; i<row; i++){
            for(j = 0; j<column-1; j++){
                //for ai
                if(array[i][j] == 'x' && (array[i][j+1] != 'x' && array[i][j+1] != 'o') || (array[1][1] != 'o' && array[1][1] != 'x') || (array[i-1][j] != 'o' && array[i-1][j]!= 'x' && i != 0) || (array[i+1][j] != 'o' && array[i+1][j] != 'x' && i != 3) || (array[i][j+2] != 'o' && array[i][j+2] != 'x')){
                    if(array[1][1] != 'o' && array[1][1] != 'x'){
                        array[1][1] = 'x';
                        return 0;
                    }
                    else if(array[i][j+1] != 'x' && array[i][j+1] != 'o'){
                        array[i][j+1] = 'x';
                        return 0;
                    }
                    else if(array[i-1][j] != 'o' && array[i-1][j]!= 'x' && i != 0){
                        array[i-1][j] = 'x';
                        return 0;
                    }
                    else if(array[i+1][j] != 'o' && array[i+1][j] != 'x' && i != 3){
                        array[i+1][j] = 'x';
                        return 0;
                    }
                    else{
                        array[i][j+2] = 'x';
                        return 0;
                    }
                }
                if(array[i][j] == 'o' && (array[i][j+1] != 'x' && array[i][j+1] != 'o') || (array[1][1] != 'o' && array[1][1] != 'x') || (array[i-1][j] != 'o' && array[i-1][j]!= 'x' && i != 0) || (array[i+1][j] != 'o' && array[i+1][j] != 'x' && i != 3) || (array[i][j+2] != 'o' && array[i][j+2] != 'x')){
                    if(array[1][1] != 'o' && array[1][1] != 'x'){
                        array[1][1] = 'x';
                        return 0;
                    }
                    else if(array[i][j+1] != 'x' && array[i][j+1] != 'o'){
                        array[i][j+1] = 'x';
                        return 0;
                    }
                    else if(array[i-1][j] != 'o' && array[i-1][j]!= 'x' && i != 0){
                        array[i-1][j] = 'x';
                        return 0;
                    }
                    else if(array[i+1][j] != 'o' && array[i+1][j] != 'x' && i != 3){
                        array[i+1][j] = 'x';
                        return 0;
                    }
                    else{
                        array[i][j+2] = 'x';
                        return 0;
                    }
                }
                
            }
        }
        //for column 3 but it excludes row 3 element because of i+1 logic
        i = 0, j = 0;
        for(int i = 0; i<row-1; i++){
            if(array[i][j+2] == 'o' && ((array[i+1][j+2] != 'o' && array[i+1][j+2] != 'x') || (array[1][1] != 'o' && array[1][1] != 'x') || (array[i-1][j+1] != 'x' && array[i-1][j+1] != 'o'))){
                if(array[1][1] != 'o' && array[1][1] != 'x'){
                    array[1][1] = 'x';
                    return 0;
                }
                else if(array[i+1][j+2] != 'o' && array[i+1][j+2] != 'x'){
                    array[i+1][j+2] = 'x';
                    return 0;
                }
                else if(array[i-1][j+1] != 'o' && array[i-1][j+1] != 'x'){
                    array[i-1][j+1] = 'x';
                    return 0;
                }
            }
        }
        //for element (2,2)
        i = 0 , j = 0;
        if(array[2][2] == 'x' && ((array[1][2] != 'o' && array[1][2] != 'x') || (array[1][1] != 'o' && array[1][1] != 'x'))){
            if((array[1][1] != 'o' && array[1][1] != 'x')){
            array[1][1] = 'x';
            return 0;
            }
            else{
                array[1][2] = 'x';
                return 0;
            }
        }
        if(array[2][2] == 'o' && ((array[1][2] != 'o' && array[1][2] != 'x') || (array[1][1] != 'o' && array[1][1] != 'x'))){
            if((array[1][1] != 'o' && array[1][1] != 'x')){
            array[1][1] = 'x';
            return 0;
            }
            else{
                array[1][2] = 'x';
                return 0;
            }
        }
    }

//4.//////////////////////////////////////////////function definition for cheater computer/////////////////////////////////////////
    //display random number;
    void cheater_computer_first_move(char array[row][column]){
        srand(time(NULL));
        int random = rand()%3;
        int random_ = rand()%3;
        array[random][random_] = 'x';
    };

    //add moves in cheater computer
    void add_moves_cheatercomputer_and_player(char array[3][3] , char move){
    int j , tempp = 0;
    for(int i = 0; i<row; i++){
        for(j = 0; j<column; j++){
            if(array[i][j] == move){
                array[i][j] = 'o';
                cheater_computer_moves(array);
                tempp = 1;
                break;
            }
            }
            if(tempp){
                break;
            }
        }
    }

    //logic for cheater computer
    int cheater_computer_moves(char array[row][column]){
    int i = 0 , j = 0;
//code for diagonals
    i = 0 , j = 0;
    //code for left diagonal from (up to down)
    if(array[i][j] == 'o' && array[i+1][j+1] == 'o' &&  (array[i+2][j+2] != 'x' && array[i+2][j+2] != 'o')){
        array[i+2][j+2] = 'x';
    }
    //code for left diagonal from (down to up)
    else if(array[i+1][j+1] == 'o' && array[i+2][j+2] == 'o' &&  (array[i][j] != 'x' && array[i][j] != 'o')){
        array[i][j] = 'x';
    }
    //code for left diagonal middle 
    else if(array[i][j] == 'o' && array[i+2][j+2] == 'o' && (array[i+1][j+1] != 'x' && array[i+1][j+1] != 'o')){
        array[i+1][j+1] = 'x';
    }
    //code for right diagonal from (up to down)
    else if(array[i][j+2] == 'o' && array[i+1][j+1] == 'o' && (array[i+2][j] != 'x' && array[i+2][j] != 'o')){
        array[i+2][j] = 'x';
    }
    //code for right diagonal from (down to up)
    else if(array[i+2][j] == 'o' && array[i+1][j+1] == 'o' && (array[i][j+2] != 'x' && array[i][j+2] != 'o')){
        array[i][j+2] = 'x';
    }
    //code for right diagonal middle
    else if(array[i][j+2] == 'o' && array[i+2][j] == 'o' && (array[i+1][j+1] != 'x' && array[i+1][j+1] != 'o')){
        array[i+1][j+1] = 'x';
    }

//code for rows;
    i = 0 , j = 0;
    for(i = 0; i<row; i++){
    //code for rows (1,2) , (4,5), (7,8) from (left to right)
    if(array[i][j] == 'x' && array[i][j+1] == 'x' && (array[i][j+2] != 'x' && array[i][j+2] != 'o')){
            array[i][j+2] = 'x';
            return 0;
        }
    //code for rows (2,3) , (4,5) , (6,7) from (right to left)
        else if(array[i][j+2] == 'x' && array[i][j+1] =='x' && (array[i][j] != 'x' && array[i][j] != 'o')){
            array[i][j] = 'x';
            return 0;
        }
    //code for mid line from row
        if(array[i][j] == 'x' && array[i][j+2] == 'x' && (array[i][j+1] != 'o' && array[i][j+1] != 'x')){
            array[i][j+1] = 'x';
            return 0;
        }
        if(array[i][j] == 'o' && array[i][j+1] == 'o' && (array[i][j+2] != 'x' && array[i][j+2] != 'o')){
            array[i][j+2] = 'x';
            return 0;
        }
    //code for rows (2,3) , (4,5) , (6,7) from (right to left)
        else if(array[i][j+2] == 'o' && array[i][j+1] =='o' && (array[i][j] != 'x' && array[i][j] != 'o')){
            array[i][j] = 'x';
            return 0;
        }
    //code for mid line from row
        if(array[i][j] == 'o' && array[i][j+2] == 'o' && (array[i][j+1] != 'o' && array[i][j+1] != 'x')){
            array[i][j+1] = 'x';
            return 0;
        }
    }

//code for columns;
    i = 0 , j = 0;
    for(j = 0; j<column; j++){
        if(array[i][j] == 'o' && array[i+1][j] == 'o' && (array[i+2][j] != 'x' && array[i+2][j] != 'o')){
            array[i+2][j] = 'x';
            return 0;
        }
        else if(array[i+2][j] == 'o' && array[i+1][j] == 'o' && (array[i][j] != 'x' && array[i][j] != 'o')){
            array[i][j] = 'x';
            return 0;
        }
        //code for mid line from column 
        else if(array[i][j] == 'o' && array[i+2][j] == 'o' && (array[i+1][j] != 'o' && array[i+1][j] != 'x')){
            array[i+1][j] = 'x';
            return 0;
        }
    }
//code for computer react on single moves by user
    //for row 1,2 but it excludes row 3 because of j+1 logic;
    i = 0 , j = 0;
    for(i = 0; i<row; i++){
        for(j = 0; j<column-1; j++){
            if(array[i][j] == 'o' && (array[i][j+1] != 'x' && array[i][j+1] != 'o') || (array[1][1] != 'o' && array[1][1] != 'x') || (array[i-1][j] != 'o' && array[i-1][j]!= 'x' && i != 0) || (array[i+1][j] != 'o' && array[i+1][j] != 'x' && i != 3) || (array[i][j+2] != 'o' && array[i][j+2] != 'x')){
                if(array[i][j+1] != 'x' && array[i][j+1] != 'o'){
                    array[i][j+1] = 'x';
                    return 0;
                }
                else if(array[1][1] != 'o' && array[1][1] != 'x'){
                    array[1][1] = 'x';
                    return 0;
                }
                else if(array[i-1][j] != 'o' && array[i-1][j]!= 'x' && i != 0){
                    array[i-1][j] = 'x';
                    return 0;
                }
                else if(array[i+1][j] != 'o' && array[i+1][j] != 'x' && i != 3){
                    array[i+1][j] = 'x';
                    return 0;
                }
                else{
                    array[i][j+2] = 'x';
                    return 0;
                }
            }
            
        }
    }
    //for column 3 but it excludes row 3 element because of i+1 logic
    i = 0, j = 0;
    for(int i = 0; i<row-1; i++){
        if(array[i][j+2] == 'o' && ((array[i+1][j+2] != 'o' && array[i+1][j+2] != 'x') || (array[1][1] != 'o' && array[1][1] != 'x') || (array[i-1][j+1] != 'x' && array[i-1][j+1] != 'o'))){
            if(array[1][1] != 'o' && array[1][1] != 'x'){
                array[1][1] = 'x';
                return 0;
            }
            else if(array[i+1][j+2] != 'o' && array[i+1][j+2] != 'x'){
                array[i+1][j+2] = 'x';
                return 0;
            }
            else if(array[i-1][j+1] != 'o' && array[i-1][j+1] != 'x'){
                array[i-1][j+1] = 'x';
                return 0;
            }
        }
    }
    //for element (2,2)
    i = 0 , j = 0;
    if(array[2][2] == 'o' && ((array[1][2] != 'o' && array[1][2] != 'x') || (array[1][1] != 'o' && array[1][1] != 'x'))){
        if((array[1][1] != 'o' && array[1][1] != 'x') || (array[0][2] != 'x' && array[0][2] != 'o')){
        array[1][1] = 'x';
        }
        else if(array[0][2] != 'x' && array[0][2] != 'o'){
            array[0][2] = 'x';
        }
        else{
            array[1][2] = 'x';
        }
    }
}




////////////////////////////////////////////////////////common functions////////////////////////////////////////////////
//sub functions or common functions for finding winner 
    //created single function from sub functions as the name below
    int check_winner(char array[row][column] , int *player_1 , int *player_2){
        int temp = 1;
        //for rows
        temp = row_checking(array,player_1,player_2);
        if(temp == 0){
            return 0;
        }
        //for columns
        temp = column_checking(array,player_1,player_2);
        if(temp == 0){
            return 0;
        }
        //for left diagonal
        temp = left_diagonal_checking(array,player_1,player_2);
        if(temp == 0){
            return 0;
        }
        //for right diagonal
        temp = right_diagonal_checking(array,player_1,player_2);
        if(temp == 0){
            return 0;
        }
        
        //check draw
        temp = check_draw(array);
        if(temp == 0){
            return 0; 
        }
    }

    //sub functions for checking winner
    
    int check_draw(char array[row][column]){
        int temp_ = 0;
        for(int i = 0; i<row; i++){
            for(int j = 0; j < column; j++){
                if(array[i][j] == 'o' || array[i][j] == 'x'){
                    temp_++;
                }; 
            };
        };
        if(temp_ == 9){
            return 0;
        };
    }

    int row_checking(char array[row][column],  int *player_1 , int *player_2){
        int i = 0 , j = 0;
        for( i = 0; i<row; i++){
            if(array[i][j] == 'o' && array[i][j+1] == 'o' && array[i][j+2] == 'o'){
                *player_1 = 0;
                return 0;
            };
            if(array[i][j] == 'x' && array[i][j+1] == 'x' && array[i][j+2] == 'x'){
                *player_2 = 0;
                return 0;
            };
        };
    };

    int column_checking(char array[row][column], int *player_1 , int*player_2){
        int i = 0, j = 0;
        for(j = 0; j < column; j++){
            if(array[i][j] == 'o' && array[i+1][j] == 'o' && array[i+2][j] == 'o'){
                *player_1 = 0;
                return 0;
            };
            if(array[i][j] == 'x' && array[i+1][j] == 'x' && array[i+2][j] == 'x'){
                *player_2 = 0;
                return 0;
            };
        }
    };

    int left_diagonal_checking(char array[row][column] , int *player_1 , int *player_2){
        int i = 0 , j = 0;
        if(array[i][j] == 'o' && array[i+1][j+1] == 'o' && array[i+2][j+2] == 'o'){
            *player_1 = 0;
            return 0;
        };
        if(array[i][j] == 'x' && array[i+1][j+1] == 'x' && array[i+2][j+2] == 'x'){
            *player_2 = 0;
            return 0;
        };
    };

    int right_diagonal_checking(char array[row][column] , int *player_1 , int *player_2){
        int i = 0, j = 0;
        if(array[i][j+2] == 'x' && array[i+1][j+1] == 'x' && array[i+2][j] == 'x'){
                *player_2 = 0;
                return 0;
            };
        if(array[i][j+2] == 'o' && array[i+1][j+1] == 'o' && array[i+2][j] == 'o'){
            *player_1 = 0;
            return 0;
        };
    };

//majorly common functions

    //display all the arrays or you can say it a common function
    void display(char array[row][column]){
        for(int i = 0; i < row; i++){
            for(int j = 0; j<column; j++){
                cout<<" "<<array[i][j];
            }
            cout<<endl;
        }
    }
    
    
    int display_choices(char name[]){
        blue();
        cout<<"\t\t\t\t\tBrief info\n";
        reset();
        yellow();
        cout<<"\t\t\t\t\tTIC TAE TOE\n\n\n";
        reset();
        cout<<"In this game you have 3 AI game modes.\n";
        yellow();
        cout<<"first:";
        reset();
        cout<<"smart computer which resist you from winning\n";
        yellow();
        cout<<"second is: ";
        reset();
        cout<<"Ai computer which definitely gave you a tough competation because it will not just resist you it will also try to win the game\n";
        red();
        cout<<"third is: ";
        reset();
        cout<<"cheater computer do cheatings for winning the game\n\n";
        yellow();
        cout<<"Hope you will enjoy the game";
        reset();
        cout<<"\npress any key to continue";
        yellow();
        cout<<".............";
        reset();
        getch();
        system("cls");
        int switch_case;
        name[30];
        cout<<"Enter your name: ";
        yellow();
        cin.getline(name,30);
        reset();
        system("cls");
        cout<<"press 1: ";
        blue();
        cout<<"for playing the game with your friend\n";
        reset();
        cout<<"Press 2: ";
        blue();
        cout<<"for playing the game with smart computer\n";
        reset();
        cout<<"press 3: ";
        green();
        cout<<"for playing the game with Ai computer\n";
        reset();
        cout<<"Press 4: ";
        blue();
        cout<<"for playing with cheater computer\n";
        reset();
        cout<<"press 5: ";
        reset();
        cout<<"For checking status\n";
        cout<<endl;
        cout<<"Enter your choice"<<" ";
        yellow();
        cout<<name<<": ";
        reset();
        cin>>switch_case;
        return switch_case;
    };
    ///////just for fun...................
    void display_status(char name[],int two_player_win ,int two_player_lose ,int smart_computer_wins , int smart_computer_lose , int two_player_draw , int smart_computer_draw,int ai_computer_wins , int ai_computer_lose , int ai_computer_dwar, int cheater_computer_win , int cheater_computer_lose , int cheater_computer_draw){
        system("cls");
        cout<<"\t\t\t\t\t\t\t"<<"  Here is your playing result ";
        yellow();
        cout<<name<<endl;
        cout<<"\t\t\t"<<"__Against:__";
        reset();
        green();
        cout<<"\t\t"<<"__WINS__";
        reset();
        red();
        cout<<"\t\t\t"<<"__LOSE__";
        reset();
        blue();
        cout<<"\t\t\t"<<"__DRAW__\n\n";
        reset();
        cout<<"\t\t\t"<<"Human:";
        //telling scores for player opponent
        if(two_player_lose == 0 && two_player_win ==0 && two_player_draw == 0){
            white();
            cout<<"\t\t\t\t\t"<<"_first you have to choose and play this section_\n";
            reset();
        }
        else if(two_player_win > 0 || two_player_lose > 0 || two_player_draw > 0){
            green();
            cout<<"\t\t\t"<<"   "<<two_player_win;
            reset();
            red();
            cout<<"\t\t\t\t"<<"   "<<two_player_lose<<" ";
            reset();
            blue();
            cout<<"\t\t\t\t"<<"   "<<two_player_draw<<"\n";
            reset();
        }
        cout<<"\n\t\t\t"<<"smart computer:";
        //telling scores for player opponent
        if(smart_computer_wins == 0 && smart_computer_lose == 0 && smart_computer_draw == 0){
            white();
            cout<<"\t\t\t\t"<<"_first you have to choose and play this section_\n";
            reset();
        }
        else if(smart_computer_wins > 0 || smart_computer_lose > 0 || smart_computer_draw > 0){
            green();
            cout<<"\t\t"<<"   "<<smart_computer_wins;
            reset();
            red();
            cout<<"\t\t\t\t"<<"   "<<smart_computer_lose<<" ";
            reset();
            blue();
            cout<<"\t\t\t\t"<<"   "<<smart_computer_draw<<"\n";
            reset();
        }
        cout<<"\n\t\t\t"<<"Ai computer:";
        //telling scores for player opponent
        if(ai_computer_wins == 0 && ai_computer_lose == 0 && ai_computer_dwar == 0){
            white();
            cout<<"\t\t\t\t"<<"_first you have to choose and play this section_\n";
            reset();
        }
        else if(ai_computer_wins > 0 || ai_computer_lose > 0 || ai_computer_dwar > 0){
            green();
            cout<<"\t\t"<<"   "<<ai_computer_wins;
            reset();
            red();
            cout<<"\t\t\t\t"<<"   "<<ai_computer_lose<<" ";
            reset();
            blue();
            cout<<"\t\t\t\t"<<"   "<<ai_computer_dwar<<"\n";
            reset();
        }
        cout<<"\n\t\t\t"<<"Cheater computer:";
        //telling scores for player opponent
        if(cheater_computer_draw == 0 && cheater_computer_lose ==0 && cheater_computer_win == 0){
            white();
            cout<<"\t\t\t"<<"_first you have to choose and play this section_\n";
            reset();
        }
        else if(cheater_computer_draw > 0 || cheater_computer_lose > 0 || cheater_computer_win > 0){
            green();
            cout<<"\t\t\t"<<"   "<<cheater_computer_win;
            reset();
            red();
            cout<<"\t\t\t\t"<<"   "<<cheater_computer_lose<<" ";
            reset();
            blue();
            cout<<"\t\t\t\t"<<"   "<<cheater_computer_draw<<"\n";
            reset();
        }
        //bhejna ki tayari
        cout<<"\n\n\n"<<"Now you ready to go\n";
            green();
            cout<<"Thankyou for playing ";
            reset();
            yellow();
            cout<<name<<"\n";
            reset();
            cout<<"press any key for exit.........................";
            getch();
    }

//color functions
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
