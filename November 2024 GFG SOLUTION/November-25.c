//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// } Driver Code Ends
// User function Template for C

// Function to find maximum product subarray
int maxProduct(int arr[], int n) {
    int maxProduct = arr[0];
    int maxVal = arr[0], minVal = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i] < 0) {

            int temp = maxVal;
            maxVal = minVal;
            minVal = temp;
        }

        maxVal = (arr[i] > maxVal * arr[i]) ? arr[i] : maxVal * arr[i];
        minVal = (arr[i] < minVal * arr[i]) ? arr[i] : minVal * arr[i];

        maxProduct = (maxProduct > maxVal) ? maxProduct : maxVal;
    }

    return maxProduct;
}

//{ Driver Code Starts.

int main() {
    char ts[1001];
    fgets(ts, sizeof(ts), stdin);
    int t = atoi(ts);
    while (t--) {
        char *line = NULL;
        size_t len = 0;
        long read = getline(&line, &len, stdin);

        int *nums = (int *)malloc(1000000 * sizeof(int));
        int n = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            nums[n++] = atoi(token);
            token = strtok(NULL, " "); // Get the next token
        }
        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i];
        }
        // char ch;
        // scanf("%c", &ch);
        // getchar();
        // Check if the array is sorted using the previously defined function
        int ans = maxProduct(arr, n);
        printf("%d\n", ans);

        printf("%s\n", "~");
        free(nums); // Free dynamically allocated memory for the nums array
        free(line); // Free dynamically allocated memory for the input line
    }

    return 0; // Return 0 to indicate successful execution
}
// } Driver Code Ends
