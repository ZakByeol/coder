#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX_NAME 21

int main()
{
    char** passwords = NULL;
    char** sites = NULL;
    int number_site,number_searchsite;
    scanf("%d %d",&number_site, &number_searchsite);

    sites = (char **) malloc(number_site * sizeof (char *));
    passwords = (char **) malloc(number_site * sizeof (char *));

    for (int i = 0; i < number_site; ++i) {
        passwords[i] = (char *) malloc( MAX_NAME * sizeof (char ));
        sites[i] = (char *) malloc( MAX_NAME * sizeof (char ));
        scanf("%s %s", sites[i], passwords[i]);
    }

    char searcing_site[20];
    for (int i = 0; i < number_searchsite; ++i) {
        scanf("%s", searcing_site);
        for (int j = 0; j < number_site; ++j) {
            if (strcmp(searcing_site, sites[j]) == 0)
            {
                printf("%s", passwords[j]);
                break;
            }
        }
    }
    return 0;
}