#include <stdio.h>
#include <stdlib.h>

#define hash(v, M) (v % M)
#define hashTwo(v, M) (v % 97 + 1) // saltos esquisitos hihi
#define Key(x) (x.chave)
#define less(a,b) (Key(a) < Key(b))
#define eq(a, b) (a == b)
#define null(A) (Key(ht[A]) == Key(NULLItem))

typedef struct Item{
    int chave;
    long e1, e2;
    long elemento;
} Item; Item NULLItem = {0, 0, 0, 0};

static int N, M = 100;
static Item *ht;

void HTinsert(Item item);
Item HTsearch (int v);

int main(int argc, char const *argv[])
{
	return 0;
}

void HTinsert(Item item){
	int v = Key(item);
	int i = hash(v, M);
	int k = hashTwo(v, M);

	while(!null(i)) i = (i + k) % M;

	ht[i] = item;
	N++;
}

Item HTsearch (int v){
	int i = hash(v, M);
	int k = hashTwo(v, M);

	while(!null(i))
		if(eq(v, Key(ht[i])))
			return ht[i];
		else
			i = (i + k) % M;
		return NULLItem;
}
