char* addBinary(char* a, char* b) {
     int i = strlen(a) - 1, j = strlen(b) - 1, carry = 0, k = 0;
    char* res = (char*)malloc(10010);
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }
    res[k] = '\0';
    for (int l = 0, r = k - 1; l < r; l++, r--) {
        char temp = res[l];
        res[l] = res[r];
        res[r] = temp;
    }
    return res;
}