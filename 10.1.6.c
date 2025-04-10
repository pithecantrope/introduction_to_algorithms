#include <stdio.h>
#include <stdlib.h>
#define N 6

typedef struct {
        int data[N];
        unsigned top;
} stack;

typedef struct {
        stack en, de;
} queue;

queue
newqueue(void) {
        return (queue){0};
}

void
printqueue(queue q) {
        printf("Queue:\n\t");
        for (unsigned i = q.de.top; i > 0; --i) {
                printf("%d ", q.de.data[i - 1]);
        }
        for (unsigned i = 0; i < q.en.top; ++i) {
                printf("%d ", q.en.data[i]);
        }
        putchar('\n');
}

void
enqueue(queue* q, int x) {
        if (q->en.top == N) {
                fputs("Overflow\n", stderr);
                abort();
        }
        q->en.data[q->en.top++] = x;
}

int
dequeue(queue* q) {
        if (q->de.top == 0) {
                if (q->en.top == 0) {
                        fputs("Underflow\n", stderr);
                        abort();
                }
                while (q->en.top > 0) {
                        q->de.data[q->de.top++] = q->en.data[--q->en.top];
                }
        }
        return q->de.data[--q->de.top];
}

int
main(int argc, char* argv[]) {
        (void)argc;
        (void)argv;

        queue q = newqueue();
        enqueue(&q, 4);
        enqueue(&q, 1);
        enqueue(&q, 3);
        dequeue(&q);
        enqueue(&q, 8);
        dequeue(&q);
        printqueue(q);

        return 0;
}
