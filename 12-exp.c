#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cmpfunc_type int (*__cmp_func)(const void* a, const void* b)

void* elem_from_bytes(void* base, int idx, size_t size_elem) {
    return (base + (size_elem * idx));
}

void __swap(const void* a, const void* b, size_t size) {
    char *p = (char*)a,
         *q = (char*)b;

    for (size_t i = 0; i < size; i++) {
        char temp = p[i];

        p[i] = q[i];
        q[i] = temp;
    }
}

int __partition(void* base, size_t size_elem, int low, int high, cmpfunc_type) {
    int idx = low - 1;
    void* pivot = elem_from_bytes(base, high, size_elem);

    for (int i = low; i <= high - 1; i++) {
        void* temp = elem_from_bytes(base, i, size_elem);

        if (__cmp_func(pivot, temp) > 0) {
            idx++;

            void *p = elem_from_bytes(base, i, size_elem),
                 *q = elem_from_bytes(base, idx, size_elem);

            __swap(p, q, size_elem);
        }
    }

    idx++;

    void *p = elem_from_bytes(base, idx, size_elem),
         *q = elem_from_bytes(base, high, size_elem);

    __swap(p, q, size_elem);

    return idx;
}

void __handle_quicksort(void* base, size_t size_elem, int low, int high, cmpfunc_type) {
    if (low < high) {
        int pi = __partition(base, size_elem, low, high, __cmp_func);

        __handle_quicksort(base, size_elem, low, pi - 1, __cmp_func);
        __handle_quicksort(base, size_elem, pi + 1, high, __cmp_func);
    }
}

void quicksort(void* base, size_t num_elems, size_t size_elem, cmpfunc_type) {
    __handle_quicksort(base, size_elem, 0, num_elems - 1, __cmp_func);
}

// ------------------------------------ //

typedef struct {
    char name[25];
    int age;
} person_t;

person_t newperson(char name[], int age) {
    person_t tmp;

    strcpy(tmp.name, name);
    tmp.age = age;

    return tmp;
}

void printperson(person_t person) {
    printf("{name=%s, age=%d}\n", person.name, person.age);
}

int compareperson(const void* a, const void* b) {
    person_t p = *(person_t*)a;
    person_t q = *(person_t*)b;

    return p.age - q.age;
}

// ------------------------------------ //

person_t* list;
int len;

int main() {
    len = 3;
    list = calloc(len, sizeof(person_t));

    list[0] = newperson("Alvian", 19);
    list[1] = newperson("Gafi", 18);
    list[2] = newperson("Alex", 19);

    // qsort(list, 3, sizeof(person_t), compareperson);
    quicksort(list, len, sizeof(person_t), compareperson);

    for (int i = 0; i < 3; i++) {
        printperson(list[i]);
    }

    // void* base = list;

    // void* a = elem_from_bytes(base, 0, sizeof(person_t));
    // void* b = elem_from_bytes(base, 1, sizeof(person_t));

    // person_t* p = a;
    // person_t* q = b;

    // printperson(*p);
    // printperson(*q);

    // for (int i = 0; i < (int)sizeof(person_t); i++)
    //     printf("%d ", lo[i]);
    // printf("\n");

    return 0;
}