#include <stdio.h>

// Symbolic Constants
#define FILENAME "DnDMonsterScores.csv"

// Main
int main(void)
{
    FILE * fp;
    char name[256];
    int count = 0;
    float acavg, hpavg = 0;
    float acsum, hpsum = 0;

    fp = fopen(FILENAME,"r");
    // Only keep going if we are able to open the file
    if (NULL!=fp)
    {
        fgets(name,255,fp);
        name[255]='\0';
        printf("Header line was: %s\n",name);

        // Read some important data
        if (fp && !feof(fp))
        {
            int ac,hp,dummy,cha;

            // loop through file's elements and print those desired, only if we can read all of the (9) fields we expect
            while (9==fscanf(fp," %[^,],%d,%d,%d,%d,%d,%d,%d,%d,",
                name,&ac,&hp,&dummy,&dummy,&dummy,&dummy,&dummy,&cha))
            {
                ++count;
                acsum += ac;
                hpsum += hp;
                printf("%d) \"%s\" : AC=%d,HP=%d\n",count,name,ac,hp);
            }
        }

        // Print the Total number of monsters in the file
        printf("\n\nTotal Monster Count = %d\n", count);

        // average out the armor class for all monsters and print
        acavg = (acsum / count);
        printf("Average AC = %.2f\n", acavg);

        // do the same for hit points
        hpavg = (hpsum / count);
        printf("Average HP = %.2f\n", hpavg);

        // If you successfully open a file, you had better close it
        fclose(fp);
    }
    else    // Print an error message if we can't open the file
    {
        printf("Unable to open file %s\n",FILENAME);
    }
}
