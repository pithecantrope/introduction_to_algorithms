#include <stdio.h>
#include <stdlib.h>
#define N 6

typedef struct {
        int data[N];
        unsigned top;
} stack;

stack
newstack(void) {
        return (stack){0};
}

void
printstack(stack s) {
        printf("Stack: top=%u\n\t", s.top);
        for (unsigned i = 0; i < s.top; ++i) {
                printf("%d ", s.data[i]);
        }
        putchar('\n');
}

void
pushstack(stack* s, int x) {
        if (s->top == N - 1) {
                fputs("Overflow\n", stderr);
                abort();
        }
        s->data[s->top++] = x;
}

int
popstack(stack* s) {
        if (s->top == 0) {
                fputs("Underflow\n", stderr);
                abort();
        }
        return s->data[--s->top];
}

typedef struct {
        int data[N];
        unsigned head, tail;
} queue;

queue
newqueue(void) {
        return (queue){0};
}

void
printqueue(queue q) {
        printf("Queue: head=%u tail=%u\n\t", q.head, q.tail);
        if (q.head <= q.tail) {
                for (unsigned i = q.head; i < q.tail; ++i) {
                        printf("%d ", q.data[i]);
                }
        } else {
                for (unsigned i = q.head; i < N; ++i) {
                        printf("%d ", q.data[i]);
                }
                for (unsigned i = 0; i < q.tail; ++i) {
                        printf("%d ", q.data[i]);
                }
        }
        putchar('\n');
}

void
pushqueue(queue* q, int x) {
        if (q->head == q->tail + 1 || (q->head == 0 && q->tail == N - 1)) {
                fputs("Overflow\n", stderr);
                abort();
        }
        q->data[q->tail++] = x;
        if (q->tail == N) {
                q->tail = 0;
        }
}

int
popqueue(queue* q) {
        if (q->head == q->tail) {
                fputs("Underflow\n", stderr);
                abort();
        }
        int x = q->data[q->head++];
        if (q->head == N) {
                q->head = 0;
        }
        return x;
}

int
main(int argc, char* argv[]) {
        (void)argc;
        (void)argv;

        stack s = newstack();
        pushstack(&s, 4);
        pushstack(&s, 1);
        pushstack(&s, 3);
        popstack(&s);
        pushstack(&s, 8);
        popstack(&s);
        printstack(s);

        queue q = newqueue();
        pushqueue(&q, 4);
        pushqueue(&q, 1);
        pushqueue(&q, 3);
        popqueue(&q);
        pushqueue(&q, 8);
        popqueue(&q);
        printqueue(q);

        return 0;
}
