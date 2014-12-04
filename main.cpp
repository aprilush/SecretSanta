#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char first[50];
    char last[50];
    bool receives = false;
};

int main(int argc, char *argv[])
{
    FILE *ifp, *ofp;

    ifp = fopen("/home/laura/Projects/SecretSanta/in.txt", "r");

    if (ifp == NULL) {
      fprintf(stderr, "Can't open input file in.txt!\n");
      exit(1);
    }
    // read people in array of persons

    ofp = fopen("/home/laura/Projects/SecretSanta/out.txt", "w");

    if (ofp == NULL) {
      fprintf(stderr, "Can't open output file out.txt!\n");
      exit(1);
    }

    char first[50];
    char last[50];
    person *people[100] ;
    int count = 0;
    while (fscanf(ifp, "%s %s", first, last) != EOF) {
        people[count] = new person;
        strncpy(people[count]->first, first, 50);
        strncpy(people[count]->last, last, 50);
        count++;
    }

    for (int i=0; i<count; i++)  {
        person *p1 = people[i];
        fprintf(stdout, "giver is: %s\n", p1->first);
        int r = rand() % count;
        person *p2 = people[r];
        // get a person p2 (randomly?)
        bool ok = false;
        while (!ok) {
        // check if receives
        // check if same last name
            r = rand() % count;
            p2 = people[r];
            if (p2->receives == false && strcmp(p1->last, p2->last) != 0) {
                ok = true;
            }
        }
        fprintf(stdout, "receiver is: %s\n\n", p2->first);
        // set receives on p2
        p2->receives = true;

        fprintf(ofp, "%s %s gives to %s %s\n", p1->first, p1->last, p2->first, p2->last);
    }


}
