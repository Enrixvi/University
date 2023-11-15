/*Si realizzi una classe astratta Classifica organizzata come una lista ordinata.
Gli elementi della lista siano di tipo SortableElem,definito nel modo seguente:*/
const int NMAX = 50;
typedef char Nome[NMAX];//Nome delle squadre
/*Metodi pubblici da implementare per la classe Classifica.
1.Classifica():costruttore.
2.~Classifica():distruttore.
3. unsigned int Aggiunge(Nome,unsigned int):se la squadra non è presente,la aggiunge
e le assegna un punteggio.Nel caso di squadra già presente,aggiunge il punteggio a 
Restituisce il numero di punti correntemente totalizzati dalla squadra.
4.Svuota():svuota la struttura.
5.Stampa():Stampa la classifica delle squadre presenti nella struttura,in ordine
decrescente di punteggio.
6.unsigned int Count(): conta gli elementi contenuti nella struttura.
7. Elimina (const Nome& n): elimina dalla struttura un eventuale elem.avente nome*/