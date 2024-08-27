#include <stdio.h>

int main() {
    int segment_number, base_address, segment_limit, offset, physical_address;

    printf("Enter segment number: ");
    scanf("%d", &segment_number);
    printf("Enter base address: ");
    scanf("%d", &base_address);
    printf("Enter segment limit: ");
    scanf("%d", &segment_limit);

    printf("Enter offset: ");
    scanf("%d", &offset);

    if (offset >= segment_limit) {
        printf("invalid address\n");
    } else {
        physical_address = base_address + offset;
        printf("Physical Address: %d\n", physical_address);
    }

    return 0;
}