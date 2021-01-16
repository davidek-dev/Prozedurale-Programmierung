#include <stdio.h>

struct item
{
    int weight;
    int value;
    int stock;
    struct item *next;
};

struct item laptop = { 1500, 1000, 3, NULL};
struct item tablet = { 700, 300, 2, &laptop};
struct item mobile = { 180, 500, 2, &tablet};
struct item *items = &mobile;

int determin(struct item *item_ptr, int max_weight) {
    if (item_ptr->next == NULL) {
        if (item_ptr->stock != 0) {
            if (max_weight > item_ptr->weight) {
                item_ptr->stock--;
                return item_ptr->value + determin(item_ptr, max_weight - item_ptr->weight);
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        if (item_ptr->stock != 0) {
            if (max_weight > item_ptr->weight) {
                item_ptr->stock--;
                return item_ptr->value + determin(item_ptr, max_weight - item_ptr->weight);
            } else {
                return determin(item_ptr->next, max_weight);
            }
        } else {
            return determin(item_ptr->next, max_weight);
        }
    }
}

int main()
{
    printf("\n%d\n", determin(items, 4500));
    return 0;
}
