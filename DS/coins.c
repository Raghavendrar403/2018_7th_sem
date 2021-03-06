#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);
//int solve(long , int , long*);

// Complete the getWays function below.
long count = 0;

long getWays(long n, int c_count, long* c) {
    //solve1 = (long *)malloc((n+1)*sizeof(long));
    //for(i = 0; i<n; i++) {
    //	solve1[i] = 0;
    //}
    //int k = solve(n, c_count, c);
    return 1;
}


int solve(long n, int c_count, long *c) {
    printf("LOL %ld \n",n);
    if(n<0) {
        return -1;
    }
    
    if(n == 0) {
            count = count+1;
	    return 1;
    }
    
    int i = 0;
    int k = 0;
    for(i = 0; i<c_count; i++){
	printf("SOLVE %ld %ld\n",n,c[i]);
	if(n-c[i] >= 0) {
		k = solve(n-c[i], c_count, c);
			
	}
        
    }
    
}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nm = split_string(readline());

    char* n_endptr;
    char* n_str = nm[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* m_endptr;
    char* m_str = nm[1];
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    char** c_temp = split_string(readline());

    long* c = malloc(m * sizeof(long));

    for (int i = 0; i < m; i++) {
        char* c_item_endptr;
        char* c_item_str = *(c_temp + i);
        long c_item = strtol(c_item_str, &c_item_endptr, 10);

        if (c_item_endptr == c_item_str || *c_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(c + i) = c_item;
    }

    int c_count = m;

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    long ways = getWays(n, c_count, c);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

