#include <stdio.h>

int S1();
int S2();
int S3();
int S4();
int S5();
int S6();
int S7();

int res = 0;

int gc() {
    int i  = getchar();
    if (i == '\n' || i == EOF || i == 0) {
        return 'e'; // means end of input
    }
    else if (i != 'a' && i != 'b') {
        return 'w'; // wrong letter
    }
    return i; // a or b
}

int S0() {
    int ch = gc();
    if (ch == 'e') {
        puts("bbb");
        return res = 'b';
    } else if (ch == 'w') {
        return res = 'w';
    } else if (ch == 'a') {
        printf("bbb -> bba, ");
        S1();
    } else {
        printf("bbb -> bbb, ");
        S0();
    }
    return '0';
}

int S1() {
    int ch = gc();
    if (ch == 'e') {
        puts("bba");
        return res = 'b';
    } else if (ch == 'w') {
        return res = 'w';
    } else if (ch == 'a') {
        printf("bba -> baa, ");
        S2();
    } else {
        printf("bba -> bab, ");
        S3();
    }
    return '1';
}

int S2() {
    int ch = gc();
    if (ch == 'e') {
        puts("baa");
        return res = 'b';
    } else if (ch == 'w') {
        return res = 'w';
    } else if (ch == 'a') {
        printf("baa -> aaa, ");
        S4();
    } else {
        printf("baa -> aab, ");
        S5();
    }
    return '2';
}

int S3() {
    int ch = gc();
    if (ch == 'e') {
        puts("bab");
        return res = 'b';
    } else if (ch == 'w') {
        return res = 'w';
    } else if (ch == 'a') {
        printf("bab -> aba, ");
        S6();
    } else {
        printf("bab -> abb, ");
        S7();
    }
    return '3';
}

int S4() {
    int ch = gc();
    if (ch == 'e') {
        puts("aaa");
        return res = 'a';
    } else if (ch == 'w') {
        return res = 'w';
    } else if (ch == 'a') {
        printf("aaa -> aaa, ");
        S4();
    } else {
        printf("aaa -> aab, ");
        S5();
    }
    return '4';
}

int S5() {
    int ch = gc();
    if (ch == 'e') {
        puts("aab");
        return res = 'a';
    } else if (ch == 'w') {
        return res = 'w';
    } else if (ch == 'a') {
        printf("aab -> aba, ");
        S6();
    } else {
        printf("aab -> abb, ");
        S7();
    }
    return '5';
}

int S6() {
    int ch = gc();
    if (ch == 'e') {
        puts("aba");
        return res = 'a';
    } else if (ch == 'w') {
        return res = 'w';
    } else if (ch == 'a') {
        printf("aba -> baa, ");
        S2();
    } else {
        printf("aba -> bab, ");
        S3();
    }
    return '6';
}

int S7() {
    int ch = gc();
    if (ch == 'e') {
        puts("abb");
        return res = 'a';
    } else if (ch == 'w') {
        return res = 'w';
    } else if (ch == 'a') {
        printf("abb -> bba, ");
        S1();
    } else {
        printf("abb -> bbb, ");
        S0();
    }
    return '7';
}

int main() {
//    int i;
    printf("Enter char sequence for {a,b}: ");
    int i = S0();

//    printf("\nFinal_res= %c \n", res);
    if (res == 'a') {
        puts("Well done!");
    } else if (res == 'b') {
        puts("Wrong word!!!");
    } else if (res == 'w') {
        puts("Wrong alphabet!!!");
    }

    return 0;
}
