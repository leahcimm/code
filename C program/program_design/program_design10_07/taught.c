 int a[10]={1,1,1,1,1,1,1,1,1,1};
    
    keep=x;
    while(1)
    {
        
        if(a[1]%4==3)
        {
            term=term*(-1);
        }
        sum=sum+term;
        x=x*x*x;
        while(1)
        {
            new=a[0]*a[1];
            a[0]=new;
            a[1]++;
            count++;
            if(count==3)
                break;
        }
        term=(x/new);
        if(fabs(term)<toler)
        break;
            
    
    }