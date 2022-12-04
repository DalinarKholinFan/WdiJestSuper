#include <stdio.h>


int ilePol(int n, int tab[n - 1][n - 1]) {
    int ile = 0, przemian = 0;
    int ost[2];
    int chuj = 1;
    while (chuj != 0) {
        chuj=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum;
                if (tab[i][j]==1){chuj+=1;}else continue;
                if(i==0&&j==n-1){sum =tab[i][j-1]+tab[i-1][j];goto there;}
                if(i==n-1&&j==n-1){sum =tab[i][j-1]+tab[i+1][j];goto there;}
                if(i==0&&j==0){sum =tab[i][j+1]+tab[i-1][j];goto there;}
                if(i==n-1&&j==0){sum =tab[i][j+1]+tab[i+1][j];goto there;}
                if (i==0){sum=tab[i+1][j]+tab[i-1][j]+tab[i][j+1];goto there;}
                if (j==0){sum=tab[i-1][j]+tab[i][j+1]+tab[i][j-1];goto there;}
                if (i==n-1){sum=tab[i][j+1]+tab[i][j-1]+tab[i+1][j];goto there;}
                if (j==n-1){sum=tab[i-1][j]+tab[i+1][j]+tab[i][j-1];goto there;}
                sum = tab[i][j-1]+tab[i][j + 1]+tab[i - 1][j]+tab[i + 1][j];
                goto there;
                there:{
                if (sum == 0) {
                    tab[i][j] = 0;
                    ile += 1;
                    continue;
                }
                if (sum == 1) {
                    tab[i][j] = 0;
                    przemian += 1;
                } else {
                    ost[0] = i;
                    ost[1] = j;
                }
                };

            }
        }
        if (przemian==0){tab[ost[0]][ost[1]]=0;}
    }
    return ile;
}


int main() {
    int lozl;
    int abc = 0;
    while ((lozl = getchar()) != '\n') {
        abc += (lozl - 48);
        abc *= 10;
    }
    abc /= 10;
    int zdj[abc][abc];
    /* stworzenie i uzupełnienie tablicy 0 i 1*/ for (int i = 0; i < abc; i++) {
        int par = 0;
        while ((lozl = getchar()) != '\n') {
            if (lozl == ' ') { continue; }
            zdj[i][par] = lozl - '0';
            par += 1;
        }
    }
    int par = 0;
    int lolz = 1;
    int naj1 = 0;
    int naj2 = 0;
    int teraz1 = 0;
    int teraz2 = 0;
    for (int i = 0; i < abc; i++) {
        for (int j = 0; j < abc; j++) {
            if (zdj[i][j] == 1) {
                teraz1 += 1;
                if (teraz1 > naj1) { naj1 = teraz1; }
            } else teraz1 = 0;
            if (zdj[i][par] == 1) {
                teraz2 += 1;
                if (teraz2 > naj2) { naj2 = teraz2; }
            } else teraz2 = 0;
            lozl += 1;
            par += lolz;
        }
        par -= lolz;
        lolz *= -1;
    }
    lolz = 1;
    int x = 1;
    int y = 0;
    int ile = 0;
    int pop = zdj[0][0];
    int ciag = 0;
    int maks = 0;
    for (int qwe = 0; qwe <= (abc * abc) - 2; qwe++) {
        if (zdj[y][x] == 1 && pop == 0) {
            ciag = 1;
            goto there;
        }
        if (zdj[y][x] == 1 && pop == 1) {
            ciag += 1;
            goto there;
        }
        if (pop == 1 && zdj[y][x] == 0) {
            if (ciag > maks) { maks = ciag; }
            ile += 1;
            goto there;
        }
        there:
        {
            pop = zdj[y][x];
            x -= lolz;
            y += lolz;
            if (y < 0 || x < 0 || x > abc - 1 || y > abc - 1) {
                if (x > abc - 1) {
                    x -= 1;
                    y += 2;
                    lolz *= -1;
                    continue;
                }
                if (y > abc - 1) {
                    y -= 1;
                    x += 2;
                    lolz *= -1;
                    continue;
                }
                if (x == -1) { x += 1; }
                if (y == -1) { y += 1; }
                lolz *= -1;
            }
        }
        lozl += 1;
    }
    printf("%d %d %d\n", naj1, naj2, maks);
    if (abc % 3 == 0 && abc > 6) {
        printf("%d\n", ilePol(abc, zdj));
    }

}

