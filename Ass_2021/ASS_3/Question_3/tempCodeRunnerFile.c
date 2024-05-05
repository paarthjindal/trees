
    for(int i=0;i<n ; i++){
        nodeptr temp = t->buckets[i].items;
        int count = 0;
        
        while(temp!=NULL){
            printf("<%d %d> ", temp->key , 