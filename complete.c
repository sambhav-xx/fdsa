#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 256

typedef struct {
    char ch;
    int freq;
} pair;

void swap(pair *a, pair *b) {
    pair temp = *a;
    *a = *b;
    *b = temp;
}

bool compare(pair *a, pair *b) {
    if (a->freq == b->freq) {
        return a->ch <= b->ch;
    }
    return a->freq <= b->freq;
}

void merge(pair *arr, int l, int m, int r) {
    int len1 = m - l;
    int len2 = r - m;

    pair L[len1], R[len2];

    for (int i = 0; i < len1; ++i) {
        L[i] = arr[i + l]; 
    }
    for (int i = 0; i < len2; ++i) {
        R[i] = arr[i + m];
    }

    int i = 0, j = 0, k = l;

    while (i < len1 && j < len2) {
        if (compare(&L[i], &R[j])) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < len1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < len1) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void merge_sort(pair *arr, int l, int r) {
    if (r - l <= 1) {
        return;
    }

    int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m, r);

    merge(arr, l, m, r);
}

void task1(char *s, int n) {
    pair arr[n];

    for (int i = 0; i < n; ++i) {
        arr[i].ch = s[i];
        arr[i].freq = 0;
        
        for (int j = 0; j < n; ++j) {
            if (s[i] == s[j]) {
                ++arr[i].freq;
            }
        }
    }

    merge_sort(arr, 0, n);

    for (int i = 0; i < n; ++i) {
        s[i] = arr[i].ch;
    }
}

void task2(char *s, int n) {
    pair present[SIZE] = {};

    for (int i = 0; i < SIZE; ++i) {
        present[i].ch = i;
        present[i].freq = 0;
    }

    for (int i = 0; i < n; ++i) {
        ++present[s[i]].freq;
    }

    int j = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (present[i].freq > 0) {
            swap(&present[i], &present[j]);
            ++j;
        }
    }

    merge_sort(present, 0, j);

    int k = 0;

    for (int i = 0; i < j; ++i) {
        for (int x = 0; x < present[i].freq; ++x) {
            s[k] = present[i].ch;
            ++k;
        }
    }
}

void random_shuffle(char *s, int n) {
    srand(time(NULL));

    for (int i = n-1; i >= 0; --i) {
        int j = rand() % (i + 1);

        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char s[n];
    scanf("%s", s);

    printf("Task1\nBefore: %s\n", s);
    task1(s, n);
    printf("Sorted: %s\n", s);

    random_shuffle(s, n);

    printf("Task2\nBefore: %s\n", s);
    task2(s, n);
    printf("Sorted: %s\n", s);

    return 0;
}