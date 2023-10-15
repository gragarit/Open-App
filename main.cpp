#include <iostream>
#include <string>
#include <windows.h>
#include <stdint.h>

// DEFINE COLORS
#define foreground_white (FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN)
#define fg_black 0

#define intense_blue (FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define intense_white (foreground_white | FOREGROUND_INTENSITY)

#define bg_int_blue (BACKGROUND_BLUE | BACKGROUND_INTENSITY | foreground_white)
#define bg_b 0

#define reset_color (fg_black | foreground_white)

using namespace std;


/*
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
*/

// SCREEN RESOLUTION
void ScreenRes() {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    int client_width = 1200;
    int client_height = 600;

    r.left = 0;
    r.top = 0;
    r.right = client_width;
    r.bottom = client_height;


    MoveWindow(console, r.left, r.top, r.right, r.bottom, TRUE);
};


// LOADING BAR
void LoadingBar() {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, bg_int_blue);

    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    
    int bar1 = 177, bar2 = 219;
    
    cout << "\n\n\n\t\t\t\t\tLoading...";
    cout << "\n\n\n\t\t\t\t";

    for(int i = 0; i < 25; i++){
        cout << (char)bar1;
    }
    
    cout << "\r";
    cout << "\t\t\t\t";

    for(int i = 0; i < 25; i++) {
        cout << (char)bar2;
        Sleep(150);
    }
};

// OPEN PROGRAM FROM OUTSIDE
void znaczki() {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, bg_int_blue);

    int znaczek;

    do{
        

        cout << "1. Włącz aplikacje" << "\n";
        cout << "2. Wyjdź z aplikacji" << "\n";
        cout << "Wybierz opcję: "; cin >> znaczek;

        switch(znaczek) {
            case 1:
                system ("cls");
                LoadingBar();
                system ("start microsoft-edge:");
                SetConsoleTextAttribute(hConsole, reset_color);
                system("cls");
                break;
            case 2:
                system ("cls");
                cout << "Dziękujemy za skorzystanie z programu" << "\n";
                Sleep(1000);
                SetConsoleTextAttribute(hConsole, reset_color);
                system("cls");
                system("exit");
                break;
            default:
                system("cls");
                cout << "Taka opcja nie została dodana" << "\n";
                system("cls");
                break;
        }
    }while(znaczek !=1 && znaczek !=2);
};

int main() {
    //gotoxy(200,50);
    SetConsoleTitleA("Otwieranie innej aplikacji");
    ScreenRes();
    system("cls");
    SetConsoleOutputCP(CP_UTF8);
    znaczki();
    return 0;
};