/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
     int** result = (int**)malloc(numRows * sizeof(int*));
    
 
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    
    for (int i = 0; i < numRows; i++) {
        int cols = i + 1;
        (*returnColumnSizes)[i] = cols;
        
       
        result[i] = (int*)malloc(cols * sizeof(int));
        
      
        result[i][0] = 1;
        result[i][cols - 1] = 1;
        
     
        for (int j = 1; j < cols - 1; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }
    
    *returnSize = numRows;
    return result;
}