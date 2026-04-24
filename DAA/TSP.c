#include <stdio.h>
struct Item
{
    int weight;
    int profit;
    int ppw;//profit for weight
};
void sort(struct Item items[],int n)
{
    struct Item temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (items[j].ppw < items[j+1].ppw)
            {
                temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
}
int main()
{
    int n,capacity;
    printf("enter the value of n:");
    scanf("%d",&n);
    struct Item itm[n];
    printf("enter the weight and profit for items:");
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &itm[i].weight, &itm[i].profit);
        itm[i].ppw = itm[i].profit / itm[i].weight;
    }
    sort(itm,n);
    float totalprofit = 0;
    printf("enter the capacity:");
    scanf("%d",&capacity);
    for (int i=0; i<n; i++)
    {
        if (itm[i].weight <= capacity)
        {
            capacity -= itm[i].weight;
            totalprofit += itm[i].profit;
        }
        else
        {
            totalprofit += itm[i].ppw*capacity;
            break;
        }
    }
    printf("profit is %f",totalprofit);
    return 0;
}
