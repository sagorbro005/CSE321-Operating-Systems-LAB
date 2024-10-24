#include <stdio.h>

// Define the structure for an item
typedef struct {
    int quantity;
    float unit_price;
} Item;

int main() {
    Item paratha, vegetable, mineral_water;
    int num_people;
    float total_bill, individual_bill;

    // Take inputs for each item
    printf("Quantity of Paratha: ");
    scanf("%d", &paratha.quantity);
    printf("Unit Price: ");
    scanf("%f", &paratha.unit_price);

    printf("Quantity of Vegetables: ");
    scanf("%d", &vegetable.quantity);
    printf("Unit Price: ");
    scanf("%f", &vegetable.unit_price);

    printf("Quantity of Mineral Water: ");
    scanf("%d", &mineral_water.quantity);
    printf("Unit Price: ");
    scanf("%f", &mineral_water.unit_price);

    // Take input for the number of people
    printf("Number of people: ");
    scanf("%d", &num_people);
    printf("\n");

    // Calculate the total bill
    total_bill = (paratha.quantity * paratha.unit_price) + (vegetable.quantity * vegetable.unit_price) + (mineral_water.quantity * mineral_water.unit_price);

    // Calculate the individual bill
    individual_bill = total_bill / num_people;

    printf("Individual people will pay: %.2f tk\n", individual_bill);

    return 0;
}

