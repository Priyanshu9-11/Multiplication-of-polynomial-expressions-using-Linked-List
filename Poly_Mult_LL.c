#include <stdio.h>
#include <stdlib.h>

struct list {
    int c;
    int e;
    struct list *next;
};
typedef struct list node;

node *create();
node *polymult(node *, node *);
node *insertpolydesc(node *, int, int);
void display(node *);

int main() {
    node *s1 = NULL, *s2 = NULL, *s3 = NULL;
    char choice = 'y';

    // Create first polynomial
    printf("Enter terms for the first polynomial:\n");
    s1 = create();

    // Create second polynomial
    printf("Enter terms for the second polynomial:\n");
    s2 = create();

    // Multiply the polynomials
    s3 = polymult(s1, s2);

    // Display the result
    printf("Resultant Polynomial after multiplication:\n");
    display(s3);

    return 0;
}

node *insertpolydesc(node *s, int c, int e) {
    node *nn, *t, *prev = NULL;
    t = s;

    while (t != NULL && t->e != e) {
        prev = t;
        t = t->next;
    }

    if (t != NULL) {
        t->c += c;
    } else {
        nn = (node *)malloc(sizeof(node));
        nn->c = c;
        nn->e = e;
        nn->next = NULL;

        if (s == NULL || e > s->e) {
            nn->next = s;
            s = nn;
        } else {
            t = s;
            while (t != NULL && t->e > e) {
                prev = t;
                t = t->next;
            }
            nn->next = prev->next;
            prev->next = nn;
        }
    }

    return s;
}

void display(node *s) {
    node *t = s;
    while (t != NULL) {
        printf("%dx^%d", t->c, t->e);
        if (t->next != NULL) {
            printf(" + ");
        }
        t = t->next;
    }
    printf("\n");
}

node *polymult(node *s1, node *s2) {
    node *s = NULL;
    node *tempx, *ty;
    int c, e;

    for (tempx = s1; tempx != NULL; tempx = tempx->next) {
        for (ty = s2; ty != NULL; ty = ty->next) {
            c = tempx->c * ty->c;
            e = tempx->e + ty->e;
            s = insertpolydesc(s, c, e);
        }
    }
    return s;
}

node *create() {
    node *s = NULL, *p = NULL, *nn;
    int c, e;
    char ano = 'y';

    while (ano == 'y' || ano == 'Y') {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &c, &e);

        nn = (node *)malloc(sizeof(node));
        nn->c = c;
        nn->e = e;
        nn->next = NULL;

        if (s == NULL) {
            s = nn;
        } else {
            p->next = nn;
        }
        p = nn;

        printf("Continue? [y/n]: ");
        fflush(stdin);
        scanf(" %c", &ano);
    }

    return s;
}
