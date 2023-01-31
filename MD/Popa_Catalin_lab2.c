#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
struct node{
    int varf;
    struct node* next;
};
struct coada{
    int items[SIZE];
    int front;
    int rear;
};
struct node* createNode(int v);
struct graph{
    int numNod;
    int* visited;
    struct node** adiList;
};
struct node* createNode(int v){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->varf = v;
    newNode->next = NULL;
    return newNode;
}
struct coada* createCoada(){
    struct coada* q = malloc(sizeof(struct coada));
    q->front = -1;
    q->rear = -1;
    return q;
}

struct coada* createCoada();
void enCoada(struct coada* q, int);
int deCoada(struct coada* q);
void display(struct coada* q);
int isEmpty(struct coada* q);
void printCoada(struct coada* q);

struct graph* createGraph(int noduri){
    struct graph* graph = malloc(sizeof(struct graph));
    graph->numNod = noduri;
    graph->adiList = malloc(noduri * sizeof(struct node*));
    graph->visited = malloc(noduri * sizeof(int));
    int i;
    for (i = 0; i < noduri; i++){
        graph->adiList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}


void addEdge(struct graph* graph, int src, int dest){
    struct node* newNode = createNode(dest);
    newNode->next = graph->adiList[src];
    graph->adiList[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adiList[dest];
    graph->adiList[dest] = newNode;
}
void printGraph(struct graph* graph){
    int v;
    for (v = 0; v < graph->numNod; v++){
        struct node* temp = graph->adiList[v];
        printf("\n Lista de adiacenta a varfurilor:%d\n ", v);
        while (temp){
            printf("%d -> ", temp->varf);
            temp = temp->next;
        }
        printf("\n");}
}
void printCoada(struct coada* q){
    int i = q->front;
    if (isEmpty(q)){printf("\n coada e goala");}
    else{printf("\n coada contine \n");
        for (i = q->front; i < q->rear + 1; i++){
            printf("%d ", q->items[i]);}}
}
                                        // parcurgerea in adancime

void DFS(struct graph* graph, int varf){
    struct node* adjList = graph->adiList[varf];
    struct node* temp = adjList;
    graph->visited[varf] = 1;
    printf("vizitat %d \n", varf);
    while (temp != NULL){
        int conVarf = temp->varf;
        if (graph->visited[conVarf] == 0){
            DFS(graph, conVarf);}
        temp = temp->next;}
}

                                         // parcurgerea in latime
void bfs(struct graph* graph, int startVarf){
    struct coada* q = createCoada();
    graph->visited[startVarf] = 1;
    enCoada(q, startVarf);
    while (!isEmpty(q)){
        printCoada(q);
        int currentVarf = deCoada(q);
        printf("\nvizitat %d\n", currentVarf);
        struct node* temp = graph->adiList[currentVarf];
        while (temp){
            int adjVarf = temp->varf;
            if (graph->visited[adjVarf] == 0){
                graph->visited[adjVarf] = 1;
                enCoada(q, adjVarf);
            }
            temp = temp->next;}
    }
}
int isEmpty(struct coada* q){
    if (q->rear == -1)
        return 1;
    else
        return 0;
}
void enCoada(struct coada* q, int value){
    if (q->rear == SIZE - 1)
        printf("\nCoada este plina\n");
    else{
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;}
}
int deCoada(struct coada* q){
    int item;
    if (isEmpty(q)){
        printf("Coada e goala");
        item = -1;
    }
    else{
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear){
            printf("\nResetam coada");
            q->front = q->rear = -1;
        }
    }
    return item;
}

int main(){
    int n,x,y,p,option,tf;
start:
    printf("\n************************\n");
    printf("1.Parcurgerea in adancime.\n");
    printf("2.Parcurgerea in latime.\n");
    printf("\n************************\n");
    printf("\nComanda dorita: \n");
    scanf("%d",&option);
    system("cls");
switch(option){
                                         //Parcurgerea in adancime
case 1:{
    printf("Numarul de noduri:");
    scanf("%d",&n);
    struct graph* graph = createGraph(n);
    printf("Numarul de conexiuni:");
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        printf("Radacina si fiul:");
        scanf("%d %d",&x,&y);
        addEdge(graph, x, y);}
    printGraph(graph);
    printf("De unde incepeti parcurgerea: ");
    scanf("%d",&p);
    DFS(graph, p);
    break;
    }
                                        //Parcurgerea in latime
case 2:{
    printf("Numarul de noduri:");
    scanf("%d",&n);
    struct graph* graph = createGraph(n);
    printf("Numarul de conexiuni:");
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        printf("Radacina si fiul:");
        scanf("%d %d",&x,&y);
        addEdge(graph, x, y);}
    bfs(graph, 0);
    break;}
    default:{
        printf("\n\nAlegeti 1 sau 2\n\n");
        goto start;}
 }
    printf("\n1)Continuare\n \n 0) Inchide programul\n \t [1/0]");
    scanf("%d",&tf);
    if(tf){
        system("cls");
        goto start;
    }
    return 0;
}
