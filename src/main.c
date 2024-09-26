#include <stdio.h>
#include <stdlib.h>

void hexToExe(const char *hexFile, const char *exeFile) {
    FILE *input = fopen(hexFile, "r");
    if (!input) {
        perror("Failed to open hex file");
        return;
    }

    FILE *output = fopen(exeFile, "wb");
    if (!output) {
        perror("Failed to open exe file");
        fclose(input);
        return;
    }

    char line[256];
    unsigned int byte;

    while (fgets(line, sizeof(line), input)) {
        char *ptr = line;

        while (*ptr) {
            // Attempt to read a hex value
            if (sscanf(ptr, "0x%2x", &byte) == 1) {
                fputc((char)byte, output);
                // Move pointer past the hex value
                while (*ptr && (*ptr != ',' && *ptr != ' ')) {
                    ptr++;
                }
                if (*ptr) ptr++; // Skip the comma or space
            } else {
                ptr++; // Move to the next character
            }
        }
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.hex> <output.exe>\n", argv[0]);
        return 1;
    }

    hexToExe(argv[1], argv[2]);
    return 0;
}