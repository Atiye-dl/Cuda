#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random bytes and write to a file
void generate_random_file(const char *filename, size_t size_in_mb) {
    FILE *file = fopen(filename, "wb");  // Open file in binary write mode
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    size_t bytes_to_write = size_in_mb * 1024 * 1024;  // Convert MB to bytes
    size_t buffer_size = 1024;  // Size of buffer to write at a time
    unsigned char buffer[buffer_size];  // Buffer to hold random bytes

    srand((unsigned int) time(NULL));  // Seed the random number generator

    size_t total_written = 0;  // Total bytes written to the file
    while (total_written < bytes_to_write) {
        // Generate random bytes
        for (size_t i = 0; i < buffer_size; i++) {
            buffer[i] = (unsigned char) rand();
        }

        // Calculate how many bytes to write in this iteration
        size_t bytes_remaining = bytes_to_write - total_written;
        size_t bytes_to_write_now = bytes_remaining < buffer_size ? bytes_remaining : buffer_size;

        // Write random bytes to file
        size_t written = fwrite(buffer, 1, bytes_to_write_now, file);
        if (written != bytes_to_write_now) {
            perror("Failed to write to file");
            fclose(file);
            exit(EXIT_FAILURE);
        }

        total_written += written;
    }

    fclose(file);
    printf("File '%s' of size %zu MB created successfully.\n", filename, size_in_mb);
}

int main() {
    size_t size_in_mb;

    printf("Enter the size of the file in MB: ");
    if (scanf("%zu", &size_in_mb) != 1) {
        fprintf(stderr, "Invalid input.\n");
        exit(EXIT_FAILURE);
    }

    const char *filename = "random_bytes.txt";
    generate_random_file(filename, size_in_mb);

    return 0;
}
