#include <stdio.h>

void wyswietlanie(int n, int wieza[3][n]) {
    int dl = 2 * n;
    for (int i = n - 1; i >= 0; i--) {
        for (int a=0;a<3;a++){
            if (wieza[a][i] == 0 && i>0) { for (int j = 0; j < dl; j++) { if (j == n) { putchar('|'); } else putchar(' '); }}
            else {
                for (int j = 0; j < dl; ++j) {
                    if (i==0){ putchar('=');continue;}
                    if (j > n-wieza[a][i] && j < dl - n+wieza[a][i]) {
                        putchar('#');
                    }
                    else putchar(' ');
                }
            }
            printf("    ");
        }
        putchar('\n');
    }
}

/*algorytm polega na wykonaniu jedynego legalnego ruchu pomi�dzy par� wyznaczonych s�upk�w, a� do u�o�enia wie�y*/
void ukladanie(int n, int wieza[3][n]) {
    int algorytm[] = {0, 1, 0, 2, 1, 2};//algorytm dla liczb parzystych
    if (n % 2 == 0) {
        algorytm[1] = 2;
        algorytm[3] = 1;
    } //zmiana algorytmu na ten pasuj�cy do liczb nieparzystych
    int wysokosci[] = {n - 1, 0, 0};//jak� wyskoko�� maj� poszczeg�lne s�upki
    int i = 0;
    while (wysokosci[2] != n - 1) {
        int slupek1 = algorytm[i % 6];//wyznacza par� s�upk�w na na kt�rych prze�o�ymy kr��ek
        int slupek2 = algorytm[i % 6 + 1];
        int wyskokosc1Slupka = wysokosci[slupek1];
        int wysokosc2Slupka = wysokosci[slupek2];//przypo��dkowanie zmiennym, aby cho� troszk� uczytelni� kod
        //sprawdza na kt�rym s�upku jest wi�kszy kr��ek a nast�pnie je podmienia, oraz aktualizuje wysoko�� s�upk�w
        if (wieza[slupek1][wyskokosc1Slupka] > wieza[slupek2][wysokosc2Slupka] && wieza[slupek2][wysokosc2Slupka]) {
            if (wysokosc2Slupka == 0) { wieza[slupek1][wyskokosc1Slupka] = wieza[slupek2][wysokosc2Slupka]; }
            else { wieza[slupek1][wyskokosc1Slupka + 1] = wieza[slupek2][wysokosc2Slupka]; }
            wieza[slupek2][wysokosc2Slupka] = 0;
            wysokosci[slupek2] -= 1;
            wysokosci[slupek1] += 1;
        } else {
            if (wyskokosc1Slupka == 0) {
                wieza[slupek1][wyskokosc1Slupka + 1] = wieza[slupek2][wysokosc2Slupka];
                wysokosci[slupek1] += 1;
                wieza[slupek2][wysokosc2Slupka] = 0;
                wysokosci[slupek2] -= 1;
                i += 2;
                while(getchar() != '\n');
                wyswietlanie(n, wieza);
                continue;
            } else { wieza[slupek2][wysokosc2Slupka + 1] = wieza[slupek1][wyskokosc1Slupka]; }
            wieza[slupek1][wyskokosc1Slupka] = 0;
            wysokosci[slupek1] -= 1;
            wysokosci[slupek2] += 1;
        }
        while(getchar() != '\n');
        wyswietlanie(n, wieza);
        i += 2;
    }

}
int main() {
    int n;
    scanf("%d", &n);
    int slupki[3][n + 1];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            if (i == 0 && j > 0) { slupki[i][j] = n - j + 1; } else { slupki[i][j] = 0; }
        }
    }/*tworzenie podstawowej wie�y*/
    n += 1;
    ukladanie(n, slupki);
    return 0;
}
