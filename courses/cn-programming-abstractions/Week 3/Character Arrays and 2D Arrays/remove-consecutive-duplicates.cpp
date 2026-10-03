// Logic from Trim Spaces Question
void removeConsecutiveDuplicates(char str[]) {
    // Base Case
    if(!str[0])
        return;
    int i = 0, j = 0;
    char temp = str[0];
    while (str[i])
    {
        if (str[i] != temp) {
            str[j++] = temp;
            temp = str[i];
        }
        i++;
    }
    str[j++] = temp;
    str[j] = '\0';
}