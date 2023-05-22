#include <stdio.h>

int S0(const char c[], int i);
int S1(const char c[], int i);
int S2(const char c[], int i);
int S3(const char c[], int i);
int S4(const char c[], int i);
int S5(const char c[], int i);
int S6(const char c[], int i);
int S7(const char c[], int i);
int res = 0;

int is_ab(const char c) {
    if (c == 0) {
        return 0;
    } else if ((c != 'a') & (c != 'b')) {
        return 1;
    }
    return 2;
}

int S1(const char c[], int i) { // bba
    if (is_ab(c[i]) == 1) {
        return (res = -1);
    } else if (is_ab(c[i]) == 0) {
        puts("bba");
        return res = 'b';
    } else if (c[i] == 'a') {
        printf("bba -> baa, ");
        S2(c, ++i);
    } else {
        printf("bba -> bab, ");
        S3(c,++i);
    }
    return 0;
}

int S2(const char c[], int i) { //baa
    if (is_ab(c[i]) == 1) {
        return (res = -1);
    } else if (is_ab(c[i]) == 0) {
        puts("baa");
        return res = 'b';
    } else if (c[i] == 'a') {
        printf("baa -> aaa, ");
        S4(c,++i);
    } else {
        printf("baa -> aab, ");
        S5(c,++i);
    }
    return 0;
}

int S3(const char c[], int i) { //bab
    if (is_ab(c[i]) == 1) {
        return (res = -1);
    } else if (is_ab(c[i]) == 0) {
        puts("bab");
        return res = 'b';
    } else if (c[i] == 'a') {
        printf("bab -> aba, ");
        S6(c,++i);
    } else {
        printf("bab -> abb, ");
        S7(c,++i);
    }
    return 0;
}

int S4(const char c[], int i) { //aaa
    if (is_ab(c[i]) == 1) {
        return (res = -1);
    } else if (is_ab(c[i]) == 0) {
        puts("aaa");
        return res = 'a';
    } else if (c[i] == 'a') {
        printf("aaa -> aaa, ");
        S4(c,++i);
    } else {
        printf("aaa -> aab, ");
        S5(c,++i);
    }
    return 0;
}

int S5(const char c[], int i) { //aab
    if (is_ab(c[i]) == 1) {
        return (res = -1);
    } else if (is_ab(c[i]) == 0) {
        puts("aab");
        return res = 'a';
    } else if (c[i] == 'a') {
        printf("aab -> aba, ");
        S6(c,++i);
    } else {
        printf("aab -> abb, ");
        S7(c,++i);
    }
    return 0;
}

int S6(const char c[], int i) { //aba
    if (is_ab(c[i]) == 1) {
        return (res = -1);
    } else if (is_ab(c[i]) == 0) {
        puts("aba");
        return res = 'a';
    } else if (c[i] == 'a') {
        printf("aba -> baa, ");
        S2(c, ++i);
    } else {
        printf("aba -> bab, ");
        S3(c, ++i);
    }
    return 0;
}

int S7(const char c[], int i) { //abb
    if (is_ab(c[i]) == 1) {
        return (res = -1);
    } else if (is_ab(c[i]) == 0) {
        puts("abb");
        return res = 'a';
    } else if (c[i] == 'a') {
        printf("abb -> bba, ");
        S1(c, i);
    } else {
        printf("abb -> bbb, ");
        S0(c, ++i);
    }
    return 0;
}

int S0(const char c[], int i) { // 00b, 0bb, bbb
    if (is_ab(c[i]) == 1){
        return (res = -1);
    } else if (is_ab(c[i]) == 0) {
        puts("bbb");
        return res = 'b';
    } else if (c[i] == 'a') {
        printf("bbb -> bba, ");
        S1(c,++i);
    } else {
        printf("bbb -> bbb, ");
        S0(c,++i);
    }
    return 0;
}

int main() {
    char c[100];
    int i = 0;
    printf("Enter char sequence for {a,b}: ");
    scanf("%s", c);
    printf("Entered= %s\n", c);

    // start here
//    printf("\nRes= %c\n", res); // debug
    S0(c, i);
//    printf("\nRes= %c\n", res); // debug
    if (res == -1) {
        puts("\nWrong alphabet!!!");
    } else if (res == 'a') {
        puts("\nNicely done =)");
    } else if (res == 'b') {
        puts("\nWrong word!!!");
    }

    return 0;
}
