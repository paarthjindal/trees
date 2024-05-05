long long int main(){
    long long int n;
    scanf("%lld", &n);
    long long int a[n], b[n];
    long long int i=0;
    while(i<n){
        scanf("%lld", &a[i]);
        b[n-i-1]=a[i];
        i++;
    }
    stackptr stack1 = Intial_Stack(n);
    long long int sum=0;
    i=0;
    while(i<n){
        if(IsEmpty(stack1)==1){//stack is empty
            push(stack1 , i);
        }
        else{
            while(IsEmpty(stack1) == 0 && a[i] > a[Top(stack1)] ){
                sum= (i-Top(stack1)+ 1)+sum;
                pop(stack1);
            }
            push(stack1 , i);
        }
        i++;
    }
    stackptr st2 = Intial_Stack(n);
    i=0;
    while(i<n){
        if(IsEmpty(st2)==1){//stack is empty
            push(st2 , i);
        }
        else{
            while(IsEmpty(st2) == 0 && b[i] > b[Top(st2)] ){
                sum = (i-Top(st2)+ 1)+sum;
                pop(st2);
            }
            push(st2 , i);
        }
        i+=1;
    }
    printf("%lld", sum);
}