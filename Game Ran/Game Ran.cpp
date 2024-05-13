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

//T?t nhiên! D??i ?ây là gi?i thích v? ?o?n mã trò ch?i R?n mà b?n ?ã cung c?p:

/*
1. * *Thi?t l?p B?n ?? : **
-B?n ?? trò ch?i ???c bi?u di?n d??i d?ng l??i v?i kích th??c `WIDTH` (20) và `HEIGHT` (10).
- V? trí ??u r?n ???c theo dõi b?ng t?a ?? `x` và `y`.
- V? trí c?a qu?(m?c tiêu) ???c t?o ng?u nhiên b?ng cách s? d?ng `fruitX` và `fruitY`.

2. * *Vòng l?p Trò ch?i : **
-Trò ch?i ch?y trong m?t vòng l?p cho ??n khi ?i?u ki?n `gameOver` ???c ?áp ?ng.
- Ng??i ch?i có th? ?i?u khi?n r?n di chuy?n b?ng các phím m?i tên('a', 'd', 'w', 's').
- Nh?n 'x' ?? k?t thúc trò ch?i.

3. * *V? Trò ch?i : **
-Hàm `Draw()` xóa màn hình và hi?n th? các ph?n t? c?a trò ch?i.
- ??u r?n ???c bi?u di?n b?ng 'O', qu? b?ng 'F', và các ph?n ?uôi b?ng 'o'.
- Các ph?n ?uôi ???c l?u tr? trong các m?ng `tailX` và `tailY`.

4. * *Logic Trò ch?i : **
-Hàm `Logic()` c?p nh?t tr?ng thái trò ch?i :
-Di chuy?n r?n d?a trên h??ng hi?n t?i(`dir`).
    - X? lý va ch?m v?i t??ng(quay vòng quanh màn hình).
    - Phát hi?n va ch?m v?i ?uôi(k?t thúc trò ch?i).
    - T?ng ?i?m khi r?n ?n qu?.

    5. * *Hàm Main : **
    -Kh?i t?o trò ch?i b?ng `Setup()`.
    - B?t ??u vòng l?p trò ch?i, liên t?c g?i `Draw()`, `Input()`, và `Logic()`.

    T?ng c?ng, mã này th?c hi?n m?t trò ch?i R?n c? b?n.Ng??i ch?i ?i?u khi?n r?n ?n qu? trong khi tránh va ch?m v?i t??ng và ?uôi c?a nó.M?c tiêu là ??t ???c s? ?i?m cao nh?t.????
    */

   