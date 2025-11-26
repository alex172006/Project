#include <stdio.h>
#include <string.h>

struct Item
{
    char name[50];
    int quantity;
    float price;
};

int main()
{
    struct Item items[100];
    int n, i;
    float total = 0.0;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for item %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", items[i].name);
        printf("Quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Price: ");
        scanf("%f", &items[i].price);
    }
    printf("\nSuperShop Bill\n");
    printf("----------------\n");
    for (i = 0; i < n; i++)
    {
        float item_cost = items[i].quantity * items[i].price;
        printf("%s\t%d\t%.2f\t%.2f\n", items[i].name, items[i].quantity, items[i].price, item_cost);
        total += item_cost;
    }

    printf("----------------\n");
    printf("Total:\t%.2f\n", total);

    return 0;
}
