#include <iostream>
#include <conio.h>
using namespace std;

//Create map
const int WIDTH = 20;
const int HEIGHT = 10;
//Fucntion in game;
bool gameOver; // End game when collide
int x, y, fruitX, fruitY, score; // Location player and point , Broad point
int tailX[100], tailY[100]; // Array coordinates of tail Skake
int nTail; // Emelet tail

enum eDirect { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirect dir;

void Setup() {
    gameOver = false; // Defuad game away false because if gameOver true when game will stop
    dir = STOP; 
    x = WIDTH / 2; 
    y = HEIGHT / 2; 
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
}

void Draw() {
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else {
                bool printTail = false; //new cr
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        printTail = true;
                    }
                }
                if (!printTail)
                    cout << " ";
            }
            if (j == WIDTH - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x >= WIDTH) x = 0; else if (x < 0) x = WIDTH - 1;
    if (y >= HEIGHT) y = 0; else if (y < 0) y = HEIGHT - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++;
    }
}

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
    }
    return 0;
}


/**/

//T?t nhi�n! D??i ?�y l� gi?i th�ch v? ?o?n m� tr� ch?i R?n m� b?n ?� cung c?p:

/*
1. * *Thi?t l?p B?n ?? : **
-B?n ?? tr� ch?i ???c bi?u di?n d??i d?ng l??i v?i k�ch th??c `WIDTH` (20) v� `HEIGHT` (10).
- V? tr� ??u r?n ???c theo d�i b?ng t?a ?? `x` v� `y`.
- V? tr� c?a qu?(m?c ti�u) ???c t?o ng?u nhi�n b?ng c�ch s? d?ng `fruitX` v� `fruitY`.

2. * *V�ng l?p Tr� ch?i : **
-Tr� ch?i ch?y trong m?t v�ng l?p cho ??n khi ?i?u ki?n `gameOver` ???c ?�p ?ng.
- Ng??i ch?i c� th? ?i?u khi?n r?n di chuy?n b?ng c�c ph�m m?i t�n('a', 'd', 'w', 's').
- Nh?n 'x' ?? k?t th�c tr� ch?i.

3. * *V? Tr� ch?i : **
-H�m `Draw()` x�a m�n h�nh v� hi?n th? c�c ph?n t? c?a tr� ch?i.
- ??u r?n ???c bi?u di?n b?ng 'O', qu? b?ng 'F', v� c�c ph?n ?u�i b?ng 'o'.
- C�c ph?n ?u�i ???c l?u tr? trong c�c m?ng `tailX` v� `tailY`.

4. * *Logic Tr� ch?i : **
-H�m `Logic()` c?p nh?t tr?ng th�i tr� ch?i :
-Di chuy?n r?n d?a tr�n h??ng hi?n t?i(`dir`).
    - X? l� va ch?m v?i t??ng(quay v�ng quanh m�n h�nh).
    - Ph�t hi?n va ch?m v?i ?u�i(k?t th�c tr� ch?i).
    - T?ng ?i?m khi r?n ?n qu?.

    5. * *H�m Main : **
    -Kh?i t?o tr� ch?i b?ng `Setup()`.
    - B?t ??u v�ng l?p tr� ch?i, li�n t?c g?i `Draw()`, `Input()`, v� `Logic()`.

    T?ng c?ng, m� n�y th?c hi?n m?t tr� ch?i R?n c? b?n.Ng??i ch?i ?i?u khi?n r?n ?n qu? trong khi tr�nh va ch?m v?i t??ng v� ?u�i c?a n�.M?c ti�u l� ??t ???c s? ?i?m cao nh?t.????
    */

   