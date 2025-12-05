#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 21

typedef struct site {
    char name[MAX_NAME];
    char password[MAX_NAME];
} site;

unsigned int func(const char *str) {
    unsigned int hash = 5381;
    int c;
    while(c = *str++) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

int main() {
    int number_sites, number_search;
    scanf("%d %d", &number_sites, &number_search);

    site* site_list = NULL;
    site_list = (site* ) malloc(2*number_sites * sizeof (site));
    for(int i = 0; i < number_sites; i++) {

        // input
        char n_name[MAX_NAME], n_password[MAX_NAME];
        scanf("%s %s", n_name, n_password);

        unsigned int val = func(n_name) % (2 * number_sites);
        while(site[val].name[0] != '\0') val = (val + 1) % (2 * number_sites);
        strcpy(site[val].name, n_name);
        strcpy(site[val].password, n_password);
    }

    for(int i = 0; i < number_search; i++) {
        char f_name[MAX_NAME];
        scanf("%s", f_name);
        unsigned int val = func(f_name) % (2 * number_sites);
        while(strcmp(site[val].name, f_name) != 0) val = (val + 1) % (2 * number_sites);
        printf("%s\n", site[val].password);
    }
    return 0;
}