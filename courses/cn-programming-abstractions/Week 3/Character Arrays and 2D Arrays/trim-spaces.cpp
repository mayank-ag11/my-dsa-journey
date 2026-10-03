// https://www.geeksforgeeks.org/c-program-remove-spaces-string/
// Logic: Sort 0 1
void trimSpaces(char str[]) {
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
           str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
}