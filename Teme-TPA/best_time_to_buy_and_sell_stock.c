int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int maxProfit(int* prices,int pricesSize)
{   
    int profit=0,curent=0,buy=0;
    buy=prices[0];
    for(int i=0;i<pricesSize;i++)
    {
        if(prices[i]<buy)
            buy=prices[i];
        else
        {
            curent=prices[i]-buy;
            profit=max(curent,profit);
        }
    }
    return profit;
}