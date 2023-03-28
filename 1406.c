#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char key;
    struct node *prev;
    struct node *next;
} node;

node *head, *tail, *p;

void init(void)
{
    head = (node *)malloc(sizeof(node));
    tail = (node *)malloc(sizeof(node));
    head->prev = head;
    head->next = tail;
    tail->prev = head;
    tail->next = tail;
    p = head;
}

void insert(char c)
{
    node *n = (node *)malloc(sizeof(node));
    n->key = c;
    n->prev = p;
    n->next = p->next;
    p->next->prev = n;
    p = n;
}

void left(void)
{
    if (p != head)
    {
        p = p->prev;
    }
}

void right(void)
{
    if (p != tail->prev)
        p = p->next;
}

void del(void)
{
    if (p != head)
    {
        node *t = p;
        p = p->prev;
        p->next = t->next;
        t->next->prev = p;
        free(t);
    }
}

void print(void)
{
    node *s = head->next;
    while (s != tail)
    {
        printf("%c", s->key);
        s = s->next;
    }
}

void del_all(void)
{
    node *d = head->next;
    while (d != tail)
    {
        node *t = d;
        d = d->next;
        free(t);
    }
    free(head);
    free(tail);
}

int main()
{
    char *arr;
    int m, i;
    char order, c;

    init();
    while ((c = getchar()) != '\n')
        insert(c);
    scanf("%d\n", &m);
    i = 0;
    while (i < m)
    {
        scanf("%c", &order);
        if (order == 'P')
        {
            scanf(" %c", &c);
            insert(c);
        }
        else if (order == 'L')
        {
            left();
        }
        else if (order == 'D')
        {
            right();
        }
        else
        {
            del();
        }
        i++;
    }
    print();
    del_all();
    return (0);
}