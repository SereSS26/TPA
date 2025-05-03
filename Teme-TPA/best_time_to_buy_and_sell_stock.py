class Solution(object):
    def maxProfit(self, prices):
        profit=0
        curent=0
        buy=prices[0]
        for i in range(0,len(prices)):
            if(prices[i]<buy):
                buy=prices[i]
            else:
                curent=prices[i]-buy
                profit=max(curent,profit)
        return profit