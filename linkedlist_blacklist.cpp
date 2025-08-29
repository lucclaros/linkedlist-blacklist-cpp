/*  The LIST class contains nodes with the name and personality score of
    candidates competing in a popularity contest. */

/*  The BLACKLIST class contains negative votes against each candidate. */

/*  The IMPUGNA() function updates the LIST by subtracting one point from
    a candidate for each negative vote in the BLACKLIST. If a candidate
    reaches zero points, they are removed from the list. */

#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#define MAX_VOTOS 15

using namespace std ;
class LISTANEGRA;
class CANDI {
	public :
		char NOM[20];
		int VOTOS ;
		CANDI * SIG ;
};

class LISTA {
	private :
		CANDI * INICIO ;
        CANDI * BUSCAR(char *);
        void MATAR(CANDI *);
	public :
		LISTA() ;
		void MIRAR() ;
		void ELIMINAR(char *);
        void friend IMPUGNA ( LISTA & , LISTANEGRA & );


LISTA :: LISTA ()
{
	int I ;
	CANDI * P ;
	char NOM[][20] = { "PEPE" , "LOLA" , "LAURA" , "CACHO" ,
			   "ANSELMO" , "MARIANO" , "MONICA" , "ANA" ,
			   "EDELMIRO" , "JOSE" , "MIRTA" , "SUSANA" ,
			   "FELIPE" , "ENZO" , "BETO" , "PACO" } ;
	INICIO = NULL ;
	for ( I=0 ; I<16 ; I++ ) {
		P = new CANDI ;
		strcpy ( P->NOM , NOM [ I ] ) ;
		P->VOTOS = 1 + rand()% MAX_VOTOS ;
		P->SIG = INICIO ;
		INICIO = P ;
	}
}
void IMPUGNA ( LISTA & , LISTANEGRA & );
void LISTA :: MIRAR ()
{
	CANDI * P ;
	P = INICIO ;
	cout << "\n\n\n" ;
	while ( P ) {
		printf ( "     %-10s%5d" , P->NOM , P->VOTOS) ;
		P = P->SIG ;
	}
	getch();
}





class PERSONA {
	public :
		char NOM[20];
		PERSONA * SIG ;
};

class LISTANEGRA {
	private :
		PERSONA * INICIO ;
	public :
		LISTANEGRA() ;
		void MIRAR() ;
		void friend IMPUGNA ( LISTA & , LISTANEGRA & );
};

LISTANEGRA :: LISTANEGRA ()
{
	int I ;
	PERSONA * P ;
	char NOM[][20] = { "PEPE" , "LOLA" , "LAURA" , "CACHO" ,
			   "ANSELMO" , "MARIANO" , "MONICA" , "ANA" ,
			   "EDELMIRO" , "JOSE" , "MIRTA" , "SUSANA" ,
			   "FELIPE" , "ENZO" , "BETO" , "PACO" } ;
	INICIO = NULL ;
	for ( I=0 ; I<100 ; I++ ) {
		P = new PERSONA ;
		strcpy ( P->NOM , NOM [ rand()%16 ] ) ;
		P->SIG = INICIO ;
		INICIO = P ;
	}
}

void LISTANEGRA :: MIRAR ()
{
	PERSONA * P ;
	P = INICIO ;
	cout << "\n\n\n" ;
	while ( P ) {
		printf ( "%-10s" , P->NOM ) ;
		P = P->SIG ;
	}
	getch();
}

CANDI * LISTA::BUSCAR(char * S){

    CANDI * P;
    P = INICIO;
    while(P){
        if(strcmpi(P->NOM, S) == 0){
            return P;
        }

        P = P->SIG;
    }

    return NULL;
}

void LISTA::ELIMINAR(char *  S){

    CANDI * P;
    P = BUSCAR(S);

    if(P){
        MATAR(P);
    }
}


void LISTA::MATAR(CANDI * PELIM)
{
    CANDI * P;
    P = INICIO;

    if(INICIO == PELIM){
        INICIO = PELIM->SIG;
        delete PELIM;
        return;
    }

    while(P->SIG != PELIM && P){
        P = P->SIG;
    }
    if(P){
      P->SIG = P->SIG->SIG;
        delete PELIM;
    }

}




int main()
{
	LISTA L ;
	L.MIRAR() ;
	LISTANEGRA N ;
	N.MIRAR() ;

	IMPUGNA ( L , N );

	L.MIRAR() ;
	cout << "\n\n\nFIN DEL PROGRAMA  " ;
	getch();
	return 0 ;
}



void IMPUGNA(LISTA & L, LISTANEGRA & LN){

    CANDI * P;
    P = L.INICIO;
    PERSONA * PP;
    while(P){
        PP = LN.INICIO;
        while(PP){
            if(strcmp(PP->NOM, P->NOM) == 0){
                P->VOTOS = P->VOTOS - 1;
            }
            PP = PP->SIG;
        }
        P = P->SIG;
    }

    P = L.INICIO;
    while(P){
        if(P->VOTOS <= 0){
           L.ELIMINAR(P->NOM);
        }
        P = P->SIG;
    }
}
