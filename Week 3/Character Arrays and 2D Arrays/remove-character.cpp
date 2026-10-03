// Logic from Trim Spaces Question
void removeAllOccurrencesOfChar(char str[], char c) {
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != c)
           str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
}
