#include <stdio.h>
#include "basicplayer.h"

// function prototype(s)
void PrintAllStats( BasicPlayer player );

int main(void)
{
    BasicPlayer player;

    while( GetNextPlayer( &player ) )
    {
         PrintAllStats( player );
    }

    return 0;
} // end function main

void PrintAllStats( BasicPlayer player )
{
    int ab;
    int walks;
    int singles;
    int doubles;
    int triples;
    int hr;

    printf( "ID=%d,Name=%s\n\t", player.id, player.name );

    if ((-1)!=(ab=GetStat(player.id,ATBATS)))
    {
        printf("AB=%d ", ab);
    }

    if ((-1)!=(walks=GetStat(player.id,WALKS)))
    {
        printf("Walks=%d ", walks);
    }

    if ((-1)!=(singles=GetStat(player.id,SINGLES)))
    {
        printf("Singles=%d ", singles);
    }

    if ((-1)!=(doubles=GetStat(player.id,DOUBLES)))
    {
        printf("Doubles=%d ", doubles);
    }

    if ((-1)!=(triples=GetStat(player.id,TRIPLES)))
    {
        printf("Triples=%d ", triples);
    }

    if ((-1)!=(hr=GetStat(player.id,HOMERUNS)))
    {
        printf("Homeruns=%d\n", hr);
    }

} // end function PrintAllStats
-- INSERT --                         