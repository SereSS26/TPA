long long max(long long a, long long b) 
{
    if(a>=b)
        return a;
    else
        return b;
}
long long mostPoints(int** questions, int questionsSize, int* questionsColSize) 
{
    long long *dp=(long long*)malloc((questionsSize+1)*sizeof(long long));//vector pentru a memora punctele maxime pana la fiecare intrebare
    //initializam dp cu 0
    for(int i=0;i<=questionsSize;i++) 
    {
        dp[i]=0;
    }
    //iteram in ordine inversa pentru a calcula punctele maxime
    for(int i=questionsSize-1;i>=0;i--) 
    {
        int points=questions[i][0];
        int brainpower=questions[i][1];
        //daca alegem sa rezolvam intrebarea curenta
        int nextIndex=i+brainpower+1;
        long long solve=0;
        if(nextIndex<questionsSize)
        {
            solve=points+dp[nextIndex];
        } 
        else 
        {
            solve=points;
        }
        //daca alegem sa dam skip la intrebarea curenta
        long long skip=dp[i + 1];
        //calculam maximul dintre cele două optiuni
        dp[i]=max(solve,skip);
    }
    long long result=dp[0];
    free(dp);//eliberăm memoria alocata dinamic
    return result;
}