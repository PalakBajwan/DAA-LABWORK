#include <iostream>
using namespace std;

struct Item
{
    int weight;
    int value;
    double ratio;
};

void sortItems(Item items[], int n)
{
    // Sort in decreasing order of value/weight ratio
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[100];

    cout << "Enter weight and value of each item:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> items[i].weight >> items[i].value;

        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sortItems(items, n);

    double totalValue = 0;

    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity)
        {
            // Take the whole item
            capacity = capacity - items[i].weight;
            totalValue = totalValue + items[i].value;
        }
        else
        {
            // Take only the required fraction
            totalValue = totalValue +
                         items[i].ratio * capacity;

            capacity = 0;
        }
    }

    cout << "Maximum value = " << totalValue << endl;

    return 0;
}