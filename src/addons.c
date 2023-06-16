#include <stdio.h>

char toupper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

char tolower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

long long __moddi3(long long a, long long b) {
    long long result = a % b;
    if (result < 0) {
        result += b;
    }
    return result;
}

long long __divdi3(long long a, long long b) {
    long long result = a / b;
    if (a < 0 && a % b != 0) {
        result--;
    }
    return result;
}

int fseek(FILE *stream, long offset, int whence) {
    // we check if the file is null
    if (stream == stdin || stream == stdout || stream == stderr) { 
        printf("stream is stdin, stdout or stderr\n");
        return 0;
    }
    // we check the whence
    switch (whence) {
        case SEEK_SET:
            // we check if the offset is valid
            if (offset < 0 || offset >= stream->buffer_size) {
                return 0;
            }
            // we set the buffer position
            stream->buffer_pos = offset;
            break;
        case SEEK_CUR:
            // we set the buffer position
            stream->buffer_pos += offset;
            break;
        case SEEK_END:
            // we set the buffer position
            stream->buffer_pos = stream->buffer_size + offset;
            break;
        default:
            return 0;
    }
    return 0;
}
