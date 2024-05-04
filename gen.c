#include <stdio.h>
#include <stdlib.h>

int main(signed argc, char* argv[]){
    srand(atoi(argv[1]));

    // generate test cases with same format as given in problem
    int a = (rand()+1)%20;
    printf("%d\n",a);
    for(int i=0; i<a; i++)
        printf("%d ", (rand()+1)%1000001);
    return 0;
}
